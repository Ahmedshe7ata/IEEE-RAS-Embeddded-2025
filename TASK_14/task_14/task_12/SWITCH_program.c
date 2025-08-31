/*
 * SWITCH_program.c
 *
 * Created: 9/11/2022 7:33:13 PM
 *  Author: AMIT
 */

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "SWITCH_interface.h"


void SWITCH_init(u8 PortId, u8 PinId)
{
	DIO_setPinDirection(PortId,PinId,DIO_PIN_INPUT);
}


void SWITCH_getState(u8 PortId, u8 PinId,u8* switchSate)
{
	u8 state;
	DIO_getPinValue(PortId,PinId,&state);
	
	if(DIO_PIN_HIGH == state)
	{
		*switchSate = SWITCH_PRESSED;
	}
	else
	{
		*switchSate = SWITCH_NOT_PRESSED;
	}
}
