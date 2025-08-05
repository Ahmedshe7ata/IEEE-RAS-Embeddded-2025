/*
 * Traffic Light System 1.c
 *
 * Created: 8/3/2025 10:17:21 PM
 * Author : pc
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>

/*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LED_interface.h"
#include "SEG7_interface.h"
#include "SEG7_config.h"


int main(void)
{
	DIO_setPortDirection(PORTC, DIO_PORT_OUTPUT);
	LED_init(DIO_PORTA,DIO_PIN1);
	LED_init(DIO_PORTA,DIO_PIN2);
	LED_init(DIO_PORTA,DIO_PIN3);
	
	SEG7_displaySingleNumber(1);
	
	/* Replace with your application code */
	while (1)
	{
		SEG7_displaySingleNumber(1);
		// RED
		LED_on      (DIO_PORTA,DIO_PIN1);
		_delay_ms(15000);
		
		LED_off     (DIO_PORTA,DIO_PIN1);
		// YELLOW
		LED_on      (DIO_PORTA,DIO_PIN2);
		_delay_ms(5000);
		LED_off     (DIO_PORTA,DIO_PIN2);
		// GREEN
		LED_on      (DIO_PORTA,DIO_PIN3);
		_delay_ms(10000);
		LED_off     (DIO_PORTA,DIO_PIN3);
	}
}


