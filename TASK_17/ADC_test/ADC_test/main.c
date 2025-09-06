/*
 * ADC_test.c
 *
 * Created: 8/17/2025 1:57:16 AM
 * Author : pc
 */

   /*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

    /* MCAL */
#include "DIO_interface.h"
#include "ADC_interface.h"

    /* HAL */
#include "LED_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"


int main(void)
{
	DIO_setPinDirection(DIO_PORTA, DIO_PIN1, DIO_PIN_INPUT);
	
	LED_init(DIO_PORTC, DIO_PIN2);
	LED_init(DIO_PORTC, DIO_PIN7);
	LED_init(DIO_PORTD, DIO_PIN3);
	LED_init(DIO_PORTB, DIO_PIN4);
	LED_init(DIO_PORTB, DIO_PIN5);
	LED_init(DIO_PORTB, DIO_PIN6);
	LED_init(DIO_PORTB, DIO_PIN7);
	LED_init(DIO_PORTD, DIO_PIN1);
	
	
	DIO_setPinDirection(DIO_PORTB, DIO_PIN1, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB, DIO_PIN2, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);

	       /* Data Pins For LCD */
	DIO_setPinDirection(DIO_PORTD, DIO_PIN4, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTD, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTD, DIO_PIN7, DIO_PIN_OUTPUT);

	ADC_init();
	LCD_init();

	LCD_clear();

	u16 digitalValue, analogValue;
	u32 digital2;
    /* Replace with your application code */
    while (1)
    {
			

		ADC_getDigitalValue(ADC_CHANNEL_1, &digitalValue);
		analogValue = ((u32)digitalValue*5000)/1024;
		
		
				
		LCD_goToSpecificPosition(LCD_LINE_ONE,0);
		LCD_writeString("ADC:");
		LCD_writeNumber(digitalValue);
		
		
		LCD_writeString(" & perc:");
		digital2 = ((u32)digitalValue * 100)/1024;
		LCD_writeNumber(digital2);
			
				
		if(digitalValue < 128)       
		{
			LED_on(DIO_PORTC, DIO_PIN2);
			LED_off(DIO_PORTC, DIO_PIN7);
			LED_off(DIO_PORTD, DIO_PIN3);
			LED_off(DIO_PORTB, DIO_PIN4);
			LED_off(DIO_PORTB, DIO_PIN5);
			LED_off(DIO_PORTB, DIO_PIN6);
			LED_off(DIO_PORTB, DIO_PIN7);
			LED_off(DIO_PORTD, DIO_PIN1);
		}
		else if(digitalValue < 256)  
		{
			LED_off(DIO_PORTC, DIO_PIN2);
			LED_on(DIO_PORTC, DIO_PIN7);
			LED_off(DIO_PORTD, DIO_PIN3);
			LED_off(DIO_PORTB, DIO_PIN4);
			LED_off(DIO_PORTB, DIO_PIN5);
			LED_off(DIO_PORTB, DIO_PIN6);
			LED_off(DIO_PORTB, DIO_PIN7);
			LED_off(DIO_PORTD, DIO_PIN1);
		}
		else if(digitalValue < 384)                       
		{
			LED_off(DIO_PORTC, DIO_PIN2);
			LED_off(DIO_PORTC, DIO_PIN7);
			LED_on(DIO_PORTD, DIO_PIN3);
			LED_off(DIO_PORTB, DIO_PIN4);
			LED_off(DIO_PORTB, DIO_PIN5);
			LED_off(DIO_PORTB, DIO_PIN6);
			LED_off(DIO_PORTB, DIO_PIN7);
			LED_off(DIO_PORTD, DIO_PIN1);
		}
		else if(digitalValue < 512)
		{
			LED_off(DIO_PORTC, DIO_PIN2);
			LED_off(DIO_PORTC, DIO_PIN7);
			LED_off(DIO_PORTD, DIO_PIN3);
			LED_on(DIO_PORTB, DIO_PIN4);
			LED_off(DIO_PORTB, DIO_PIN5);
			LED_off(DIO_PORTB, DIO_PIN6);
			LED_off(DIO_PORTB, DIO_PIN7);
			LED_off(DIO_PORTD, DIO_PIN1);
		}
		else if(digitalValue < 640)
		{
			LED_off(DIO_PORTC, DIO_PIN2);
			LED_off(DIO_PORTC, DIO_PIN7);
			LED_off(DIO_PORTD, DIO_PIN3);
			LED_off(DIO_PORTB, DIO_PIN4);
			LED_on(DIO_PORTB, DIO_PIN5);
			LED_off(DIO_PORTB, DIO_PIN6);
			LED_off(DIO_PORTB, DIO_PIN7);
			LED_off(DIO_PORTD, DIO_PIN1);
		}
		else if(digitalValue < 768)
		{
			LED_off(DIO_PORTC, DIO_PIN2);
			LED_off(DIO_PORTC, DIO_PIN7);
			LED_off(DIO_PORTD, DIO_PIN3);
			LED_off(DIO_PORTB, DIO_PIN4);
			LED_off(DIO_PORTB, DIO_PIN5);
			LED_on(DIO_PORTB, DIO_PIN6);
			LED_off(DIO_PORTB, DIO_PIN7);
			LED_off(DIO_PORTD, DIO_PIN1);
		}
		else if(digitalValue < 896)
		{
			LED_off(DIO_PORTC, DIO_PIN2);
			LED_off(DIO_PORTC, DIO_PIN7);
			LED_off(DIO_PORTD, DIO_PIN3);
			LED_off(DIO_PORTB, DIO_PIN4);
			LED_off(DIO_PORTB, DIO_PIN5);
			LED_off(DIO_PORTB, DIO_PIN6);
			LED_on(DIO_PORTB, DIO_PIN7);
			LED_off(DIO_PORTD, DIO_PIN1);
		}
		else if(digitalValue < 1024)
		{
			LED_off(DIO_PORTC, DIO_PIN2);
			LED_off(DIO_PORTC, DIO_PIN7);
			LED_off(DIO_PORTD, DIO_PIN3);
			LED_off(DIO_PORTB, DIO_PIN4);
			LED_off(DIO_PORTB, DIO_PIN5);
			LED_off(DIO_PORTB, DIO_PIN6);
			LED_off(DIO_PORTB, DIO_PIN7);
			LED_on(DIO_PORTD, DIO_PIN1);
		}
		
    }
}

