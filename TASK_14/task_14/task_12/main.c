/*
 * task_12.c
 *
 * Created: 8/31/2025 1:04:46 AM
 * Author : pc
 */ 




	

	#define SW_FORWARD   DIO_PIN0
	#define SW_BACKWARD  DIO_PIN1
	#define SW_LEFT      DIO_PIN2
	#define SW_RIGHT     DIO_PIN3
	#define SW_STOP      DIO_PIN4

	#define F_CPU 8000000UL
	#include <util/delay.h>

	#include "STD_TYPES.h"
	#include "BIT_MATH.h"
	#include "ATMEGA32_REG.h"

	/* MCAL */
	#include "DIO_interface.h"

	/* HAL */
	#include "SWITCH_interface.h"

	/* --- Switches (on PORTB, PB0..PB4) --- */
	#define SW_PORT          DIO_PORTB
	#define SW_FORWARD_PIN   DIO_PIN0
	#define SW_BACKWARD_PIN  DIO_PIN1
	#define SW_LEFT_PIN      DIO_PIN2
	#define SW_RIGHT_PIN     DIO_PIN3
	#define SW_STOP_PIN      DIO_PIN4

	/* --- Motors pin mapping (fixed, no re-defines) --- */
	/* Motor1 (L293D#1 output pair) */
	#define M1_PORT   DIO_PORTD
	#define M1_IN1    DIO_PIN2
	#define M1_IN2    DIO_PIN3

	/* Motor2 (L293D#1 other pair or L293D#2) */
	#define M2_PORT   DIO_PORTD
	#define M2_IN1    DIO_PIN4
	#define M2_IN2    DIO_PIN5

	/* Motor3 (L293D#2) */
	#define M3_PORT   DIO_PORTC
	#define M3_IN1    DIO_PIN2
	#define M3_IN2    DIO_PIN3

	/* Motor4 (L293D#2 other pair) */
	#define M4_PORT   DIO_PORTC
	#define M4_IN1    DIO_PIN4
	#define M4_IN2    DIO_PIN5

	/* Motor5 (third L293D used: first pair) */
	#define M5_PORT   DIO_PORTA
	#define M5_IN1    DIO_PIN2
	#define M5_IN2    DIO_PIN3

	/* motor commands */
	#define M_STOP      0U
	#define M_FORWARD   1U
	#define M_BACKWARD  2U

	/* debounce */
	#define DEBOUNCE_MS 20

	/* Helper: set motor pins according to command */
	static void Motor_Set(u8 PortId, u8 PinIn1, u8 PinIn2, u8 cmd)
	{
		switch(cmd)
		{
			case M_FORWARD:
			DIO_setPinValue(PortId, PinIn1, DIO_PIN_HIGH);
			DIO_setPinValue(PortId, PinIn2, DIO_PIN_LOW);
			break;
			case M_BACKWARD:
			DIO_setPinValue(PortId, PinIn1, DIO_PIN_LOW);
			DIO_setPinValue(PortId, PinIn2, DIO_PIN_HIGH);
			break;
			case M_STOP:
			default:
			DIO_setPinValue(PortId, PinIn1, DIO_PIN_LOW);
			DIO_setPinValue(PortId, PinIn2, DIO_PIN_LOW); /* coast */
			break;
		}
	}

	/* group motions */
	static void Motors_All_Stop(void)
	{
		Motor_Set(M1_PORT, M1_IN1, M1_IN2, M_STOP);
		Motor_Set(M2_PORT, M2_IN1, M2_IN2, M_STOP);
		Motor_Set(M3_PORT, M3_IN1, M3_IN2, M_STOP);
		Motor_Set(M4_PORT, M4_IN1, M4_IN2, M_STOP);
		Motor_Set(M5_PORT, M5_IN1, M5_IN2, M_STOP);
	}

	static void Motors_All_Forward(void)
	{
		Motor_Set(M1_PORT, M1_IN1, M1_IN2, M_FORWARD);
		Motor_Set(M2_PORT, M2_IN1, M2_IN2, M_FORWARD);
		Motor_Set(M3_PORT, M3_IN1, M3_IN2, M_FORWARD);
		Motor_Set(M4_PORT, M4_IN1, M4_IN2, M_FORWARD);
		Motor_Set(M5_PORT, M5_IN1, M5_IN2, M_FORWARD);
	}

	static void Motors_All_Backward(void)
	{
		Motor_Set(M1_PORT, M1_IN1, M1_IN2, M_BACKWARD);
		Motor_Set(M2_PORT, M2_IN1, M2_IN2, M_BACKWARD);
		Motor_Set(M3_PORT, M3_IN1, M3_IN2, M_BACKWARD);
		Motor_Set(M4_PORT, M4_IN1, M4_IN2, M_BACKWARD);
		Motor_Set(M5_PORT, M5_IN1, M5_IN2, M_BACKWARD);
	}

	static void Motors_Turn_Left(void)
	{
		/* Example layout: M1,M2 = left; M3 = center; M4,M5 = right */
		Motor_Set(M1_PORT, M1_IN1, M1_IN2, M_BACKWARD);
		Motor_Set(M2_PORT, M2_IN1, M2_IN2, M_BACKWARD);
		Motor_Set(M3_PORT, M3_IN1, M3_IN2, M_STOP);
		Motor_Set(M4_PORT, M4_IN1, M4_IN2, M_FORWARD);
		Motor_Set(M5_PORT, M5_IN1, M5_IN2, M_FORWARD);
	}

	static void Motors_Turn_Right(void)
	{
		Motor_Set(M1_PORT, M1_IN1, M1_IN2, M_FORWARD);
		Motor_Set(M2_PORT, M2_IN1, M2_IN2, M_FORWARD);
		Motor_Set(M3_PORT, M3_IN1, M3_IN2, M_STOP);
		Motor_Set(M4_PORT, M4_IN1, M4_IN2, M_BACKWARD);
		Motor_Set(M5_PORT, M5_IN1, M5_IN2, M_BACKWARD);
	}

	/* Read switch with debounce */
	static u8 ReadSwitchStable(u8 PortId, u8 PinId)
	{
		u8 s1, s2;
		SWITCH_getState(PortId, PinId, &s1);
		_delay_ms(DEBOUNCE_MS);
		SWITCH_getState(PortId, PinId, &s2);

		if (s1 == s2) return s1;
		return SWITCH_NOT_PRESSED;
	}

	int main(void)
	{
		u8 forward_state, backward_state, left_state, right_state, stop_state;

		/* init switches (use your SWITCH_init) */
		SWITCH_init(SW_PORT, SW_FORWARD_PIN);
		SWITCH_init(SW_PORT, SW_BACKWARD_PIN);
		SWITCH_init(SW_PORT, SW_LEFT_PIN);
		SWITCH_init(SW_PORT, SW_RIGHT_PIN);
		SWITCH_init(SW_PORT, SW_STOP_PIN);

		/* motor pins -> outputs */
		DIO_setPinDirection(M1_PORT, M1_IN1, DIO_PIN_OUTPUT);
		DIO_setPinDirection(M1_PORT, M1_IN2, DIO_PIN_OUTPUT);

		DIO_setPinDirection(M2_PORT, M2_IN1, DIO_PIN_OUTPUT);
		DIO_setPinDirection(M2_PORT, M2_IN2, DIO_PIN_OUTPUT);

		DIO_setPinDirection(M3_PORT, M3_IN1, DIO_PIN_OUTPUT);
		DIO_setPinDirection(M3_PORT, M3_IN2, DIO_PIN_OUTPUT);

		DIO_setPinDirection(M4_PORT, M4_IN1, DIO_PIN_OUTPUT);
		DIO_setPinDirection(M4_PORT, M4_IN2, DIO_PIN_OUTPUT);

		DIO_setPinDirection(M5_PORT, M5_IN1, DIO_PIN_OUTPUT);
		DIO_setPinDirection(M5_PORT, M5_IN2, DIO_PIN_OUTPUT);

		Motors_All_Stop();

		while (1)
		{
			forward_state  = ReadSwitchStable(SW_PORT, SW_FORWARD_PIN);
			backward_state = ReadSwitchStable(SW_PORT, SW_BACKWARD_PIN);
			left_state     = ReadSwitchStable(SW_PORT, SW_LEFT_PIN);
			right_state    = ReadSwitchStable(SW_PORT, SW_RIGHT_PIN);
			stop_state     = ReadSwitchStable(SW_PORT, SW_STOP_PIN);

			if (stop_state == SWITCH_PRESSED) {
				Motors_All_Stop();
			}
			else if (forward_state == SWITCH_PRESSED) {
				Motors_All_Forward();
			}
			else if (backward_state == SWITCH_PRESSED) {
				Motors_All_Backward();
			}
			else if (left_state == SWITCH_PRESSED) {
				Motors_Turn_Left();
			}
			else if (right_state == SWITCH_PRESSED) {
				Motors_Turn_Right();
			}
			else {
				Motors_All_Stop();
			}

			_delay_ms(30);
		}

		return 0;
	}
   


