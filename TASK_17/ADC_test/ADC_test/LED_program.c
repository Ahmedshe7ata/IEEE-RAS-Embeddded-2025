/*
 * LED_program.c
 *
 * Created: 7/28/2025 6:18:30 PM
 *  Author: pc
 */ 
 /*UTILES_LIB*/
 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #include "ATMEGA32_REG.h"

 /* MCAL */
 #include "DIO_interface.h"
 
 /* HAL */
 #include "LED_interface.h"
 
void LED_init(u8 PortId, u8 PinId)
{
	DIO_setPinDirection(PortId, PinId, DIO_PIN_OUTPUT);
}


void LED_on(u8 PortId, u8 PinId)
{
	DIO_setPinValue(PortId, PinId, DIO_PIN_HIGH);
}

void LED_off(u8 PortId, u8 PinId)
{
	DIO_setPinValue(PortId, PinId, DIO_PIN_LOW);
}

void LED_toggle(u8 PortId, u8 PinId)
{
	DIO_togglePinValue(PortId, PinId);
}



