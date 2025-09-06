/*
 * EXTI_test.c
 *
 * Created: 8/5/2025 10:56:29 AM
 * Author : pc
 */ 

#define F_CPU 1000000UL
#include <util/delay.h>

    /*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

    /* MCAL */
#include "EXTI_interface.h"
#include "DIO_interface.h"
#include "GI_interface.h"
   /* HAL */
#include "SEG7_interface.h"
#include "SEG7_config.h"   

void func(void); 
void func1(void);

volatile u8 displayFlag = 0;
int main(void)
{
	
	/* Replace with your application code */
	DIO_setPinDirection(DIO_PORTC,DIO_PIN1,DIO_PIN_OUTPUT);// buzzer
	
	DIO_setPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT); // INT0
	
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_INPUT); // INT1
	
	DIO_setPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA, DIO_PIN1, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA, DIO_PIN2, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA, DIO_PIN3, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA, DIO_PIN4, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA, DIO_PIN6, DIO_PIN_OUTPUT);
	
	GI_enable();
	EXTI_INT0SetCallBack(&func);
	EXTI_enable(EXTI_INT0,EXTI_RISING_EDGE);
	
	EXTI_INT1SetCallBack(&func1);
	EXTI_enable(EXTI_INT1,EXTI_RISING_EDGE);
     while (1)
     {
	     if(displayFlag == 1)
	     {
		     for(u8 i=1;i<=9;i++)
		     {
			     SEG7_displaySingleNumber(i);
			     _delay_ms(1000);
		     }
		     displayFlag = 0;  
	     }
     }
     }


     void func(void)
     {
	     DIO_setPinValue(DIO_PORTC,DIO_PIN1, DIO_PIN_LOW);  // Toggle Buzzer
		 _delay_ms(1000);
		 DIO_setPinValue(DIO_PORTC,DIO_PIN1, DIO_PIN_HIGH);
		 _delay_ms(1000);
     }

     void func1(void)
     {
	     displayFlag = 1;   
     }