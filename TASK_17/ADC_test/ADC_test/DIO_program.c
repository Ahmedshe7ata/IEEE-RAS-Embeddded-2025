/*
 * DIO_program.c
 *
 * Created: 7/26/2025 7:52:46 PM
 *  Author: AHMED SHE7ATA
 */

    /*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

    /* MCAL */
#include "DIO_interface.h"
#include "DIO_private.h"


                    /* PIN APIS */
void DIO_setPinDirection(u8 PortId, u8 PinId, u8 PinDirection)
{
    switch(PortId)
    {
		case DIO_PORTA:
		if(DIO_PIN_OUTPUT == PinDirection)
        {
            SET_BIT(DDRA,PinId);
        }
        else
        {
            CLR_BIT(DDRA,PinId);
        }
		break;

		case DIO_PORTB:
		if(DIO_PIN_OUTPUT == PinDirection)
        {
            SET_BIT(DDRB,PinId);
        }
        else
        {
            CLR_BIT(DDRB,PinId);
        }
		break;

		case DIO_PORTC:
		if(DIO_PIN_OUTPUT == PinDirection)
        {
            SET_BIT(DDRC,PinId);
        }
        else
        {
            CLR_BIT(DDRC,PinId);
        }
		break;

		case DIO_PORTD:
		if(DIO_PIN_OUTPUT == PinDirection)
        {
            SET_BIT(DDRD,PinId);
        }
        else
        {
            CLR_BIT(DDRD,PinId);
        }
		break;
	}
}

void DIO_setPinValue(u8 PortId, u8 PinId, u8 PinValue)
{
	switch(PortId)
	{
		case DIO_PORTA:
		if(DIO_PIN_HIGH==PinValue)
        {
			SET_BIT(PORTA, PinId);
		}
		else
		{
			CLR_BIT(PORTA, PinId);
		}
		break;
	}

    switch(PortId)
	{
		case DIO_PORTB:
		if(DIO_PIN_HIGH==PinValue)
        {
			SET_BIT(PORTB, PinId);
		}
		else
		{
			CLR_BIT(PORTB, PinId);
		}
		break;
	}

    switch(PortId)
	{
		case DIO_PORTC:
		if(DIO_PIN_HIGH==PinValue)
        {
			SET_BIT(PORTC, PinId);
		}
		else
		{
			CLR_BIT(PORTC, PinId);
		}
		break;
	}

    switch(PortId)
	{
		case DIO_PORTD:
		if(DIO_PIN_HIGH==PinValue)
        {
			SET_BIT(PORTD, PinId);
		}
		else
		{
			CLR_BIT(PORTD, PinId);
		}
		break;
	}

}

void DIO_togglePinValue  (u8 PortId, u8 PinId)
{
	switch(PortId)
	{
		case DIO_PORTA:
		TOG_BIT(PORTA, PortId);
		break;

        case DIO_PORTB:
		TOG_BIT(PORTB, PortId);
		break;

		case DIO_PORTC:
		TOG_BIT(PORTC, PortId);
		break;

		case DIO_PORTD:
		TOG_BIT(PORTD, PortId);
	    break;
	}
}

void DIO_getPinValue(u8 PortId, u8 PinId, u8* PinValue)
{
	switch(PortId)
	{
		case DIO_PORTA:
		if(1 == GET_BIT(PINA, PinId))
		{
			*PinValue = DIO_PIN_HIGH;
        }
        else
        {
			*PinValue = DIO_PIN_LOW;
        }
		break;

		case DIO_PORTB:
		if(1 == GET_BIT(PINB, PinId))
		{
			*PinValue = DIO_PIN_HIGH;
        }
        else
        {
			*PinValue = DIO_PIN_LOW;
        }
		break;

		case DIO_PORTC:
		if(1 == GET_BIT(PINC, PinId))
		{
			*PinValue = DIO_PIN_HIGH;
        }
        else
        {
			*PinValue = DIO_PIN_LOW;
        }
		break;

		case DIO_PORTD:
		if(1 == GET_BIT(PIND, PinId))
		{
			*PinValue = DIO_PIN_HIGH;
        }
        else
        {
			*PinValue = DIO_PIN_LOW;
        }
		break;
	}

}

void DIO_setInputPinResistance (u8 PortId, u8 PinId)
{
	switch(PortId)
	{
		case 0: //PORTA
		SET_BIT(PORTA, PinId);
		break;

		case 1: //PORTB
		SET_BIT(PORTB, PinId);
		break;

		case 2: //PORTC
		SET_BIT(PORTC, PinId);
		break;

		case 3: //PORTD
		SET_BIT(PORTD, PinId);
		break;
	}
}


                /* PORT APIS */

void DIO_setPortDirection(u8 PortId, u8 PortDirection)
{
	switch(PortId)
    {
		case DIO_PORTA:
		if(DIO_PORT_OUTPUT == PortDirection)
		{
			DDRA = 0xff;  //0b11111111
		}
		else
		{
			DDRA = 0x00;  //0b00000000
		}
        break;

        case DIO_PORTB:
        if(DIO_PORT_OUTPUT == PortDirection)
		{
			DDRB = 0xff;  //0b11111111
		}
		else
		{
			DDRB = 0x00;  //0b00000000
		}
        break;

		case DIO_PORTC:  //PORTC
		if(DIO_PORT_OUTPUT == PortDirection)
		{
			DDRC = 0xff;  //0b11111111
		}
		else
		{
			DDRC = 0x00;  //0b00000000
		}
        break;

		case DIO_PORTD:  //PORTD
		if(DIO_PORT_OUTPUT == PortDirection)
		{
			DDRD = 0xff;  //0b11111111
		}
		else
		{
			DDRD = 0x00;  //0b00000000
		}
        break;
    }

}

void DIO_setPortValue(u8 PortId, u8 PortValue)
{
	switch(PortId)
	{
		case DIO_PORTA:
		PORTA = PortValue;
		break;

		case DIO_PORTB:
		PORTB = PortValue;
		break;

		case DIO_PORTC:
		PORTC = PortValue;
		break;

		case DIO_PORTD:
		PORTD = PortValue;
		break;
	}
}

void DIO_getPortValue(u8 PortId, u8* PortValue)
{
	switch(PortId)
	{
	    case DIO_PORTA:
		*PortValue = PINA;
		break;

		case DIO_PORTB:
		*PortValue = PINB;
		break;

		case DIO_PORTC:
		*PortValue = PINC;
		break;

		case DIO_PORTD:
		*PortValue = PIND;
		break;
	}
}

void DIO_togglePortValue(u8 PortId)
{
	switch(PortId)
	{
		case DIO_PORTA:
		PORTA = ~PORTA;
		break;

		case DIO_PORTB:
		PORTB = ~PORTB;
		break;

		case DIO_PORTC:
		PORTC = ~PORTC;
		break;

		case DIO_PORTD:
		PORTD = ~PORTD;
		break;

	}
}

void DIO_setInputPortResistance (u8 PortId)
{
	switch(PortId)
	{
		case 0: //PORTA
		PORTA = 0xff;
		break;

		case 1: //PORTB
		PORTB = 0xff;
		break;

		case 2: //PORTC
		PORTC = 0xff;
		break;

		case 3: //PORTD
		PORTD = 0xff;
		break;
	}
}