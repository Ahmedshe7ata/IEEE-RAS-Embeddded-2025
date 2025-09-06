/*
 * KPD_test.c
 *
 * Created: 8/1/2025 9:12:40 PM
 * Author : pc
 */ 

#define F_CPU 1000000UL
#include <util/delay.h>

     /*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

    /* MCAL */
#include "DIO_interface.h"
    
    /* HAL */
#include "KPD_interface.h"
#include "KPD_config.h"
#include "LCD_interface.h"
#include "LCD_config.h"


	
	int main(void)
	{
		u8 keyValue = 0;
		u8 num1 = 0, num2 = 0, opr = 0, result = 0;

		
		        /* Data Pins For LCD */
		DIO_setPinDirection(DIO_PORTD, DIO_PIN4, DIO_PIN_OUTPUT);
		DIO_setPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);
		DIO_setPinDirection(DIO_PORTD, DIO_PIN6, DIO_PIN_OUTPUT);
		DIO_setPinDirection(DIO_PORTD, DIO_PIN7, DIO_PIN_OUTPUT);
		
		       /* Rows For Keypad */
		DIO_setPinDirection(DIO_PORTC, DIO_PIN3, DIO_PIN_INPUT);
		DIO_setPinDirection(DIO_PORTC, DIO_PIN4, DIO_PIN_INPUT);
		DIO_setPinDirection(DIO_PORTC, DIO_PIN5, DIO_PIN_INPUT);
		DIO_setPinDirection(DIO_PORTC, DIO_PIN6, DIO_PIN_INPUT);
		
		DIO_setInputPinResistance(DIO_PORTC, DIO_PIN3);
		DIO_setInputPinResistance(DIO_PORTC, DIO_PIN4);
		DIO_setInputPinResistance(DIO_PORTC, DIO_PIN5);
		DIO_setInputPinResistance(DIO_PORTC, DIO_PIN6);
		
		DIO_setPinDirection(DIO_PORTB, DIO_PIN1, DIO_PIN_OUTPUT);
		DIO_setPinDirection(DIO_PORTB, DIO_PIN2, DIO_PIN_OUTPUT);
		DIO_setPinDirection(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);
		
				/* Cols For Keypad */
		DIO_setPinDirection(DIO_PORTA, DIO_PIN4, DIO_PIN_OUTPUT);
		DIO_setPinDirection(DIO_PORTA, DIO_PIN5, DIO_PIN_OUTPUT);
		DIO_setPinDirection(DIO_PORTA, DIO_PIN6, DIO_PIN_OUTPUT);
		DIO_setPinDirection(DIO_PORTA, DIO_PIN7, DIO_PIN_OUTPUT);
		
		
		
				while(1)
				{
					LCD_init();
					keyValue = KPD_NOT_PRESSED;
					do { KPD_getValue(&keyValue); _delay_ms(20); } while(keyValue == KPD_NOT_PRESSED);
					num1 = keyValue - '0';
					LCD_sendChar(keyValue);
					_delay_ms(100);

					keyValue = KPD_NOT_PRESSED;
					do { KPD_getValue(&keyValue); _delay_ms(20); } while(keyValue == KPD_NOT_PRESSED);
					opr = keyValue;
					LCD_sendChar(opr);
					_delay_ms(100);

					
					keyValue = KPD_NOT_PRESSED;
					do { KPD_getValue(&keyValue); _delay_ms(20); } while(keyValue == KPD_NOT_PRESSED);
					num2 = keyValue - '0';
					LCD_sendChar(keyValue);
					_delay_ms(100);

					
					keyValue = KPD_NOT_PRESSED;
					do { KPD_getValue(&keyValue); _delay_ms(20); } while(keyValue != '#');
					LCD_sendChar('=');
					_delay_ms(100);

					
					switch(opr)
					{
						case '+': result = num1 + num2; break;
						case '*': result = num1 * num2; break;
					}

					LCD_writeNumber(result);
					_delay_ms(3000);
					LCD_clear();				
				}

	}
 

	
	
   
		
		



 
