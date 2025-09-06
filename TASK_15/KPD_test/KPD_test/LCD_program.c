/*
 * LCD_program.c
 *
 * Created: 7/29/2025 5:51:41 PM
 *  Author: pc
 */ 
#define F_CPU 16000000UL 
#include <util/delay.h> 

    /*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

    /* MCAL */
#include "DIO_interface.h"
 
    /* HAL */
#include "LCD_interface.h"
#include "LCD_config.h"

void LCD_enablePulse(void)
{
    DIO_setPinValue(DIO_PORTB, DIO_PIN3, DIO_PIN_HIGH);
    _delay_us(1);
    DIO_setPinValue(DIO_PORTB, DIO_PIN3, DIO_PIN_LOW);
    _delay_us(100);
}	

void LCD_init(void)
{
	
	_delay_ms(35);
	//Set Rs Pin = 0 (write command)
	DIO_setPinValue(DIO_PORTB, DIO_PIN1, DIO_PIN_LOW);
	
	//Set R/W pin = 0 (write)
    DIO_setPinValue(DIO_PORTB, DIO_PIN2, DIO_PIN_LOW);
	
	LCD_writeHalfPort(0b0010);
	
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(DIO_PORTB, DIO_PIN3, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(DIO_PORTB, DIO_PIN3, DIO_PIN_LOW);
		
	LCD_sendCmnd(0b00100000);
	
	_delay_us(45);
	//Display on off control(Display on, Cursor on, Blink on)
	LCD_sendCmnd(0b00001111);
	
	_delay_us(45);
	//Clear Display
	LCD_sendCmnd(0b00000001);
	
	_delay_ms(2);
	//Set Entry Mode
	LCD_sendCmnd(0b00000110);
	
	
}


void LCD_sendCmnd(u8 cmnd)
{
	//Set Rs Pin = 0 (write command)
	DIO_setPinValue(DIO_PORTB, DIO_PIN1, DIO_PIN_LOW);
	
	//Set R/W pin = 0 (write)
    DIO_setPinValue(DIO_PORTB, DIO_PIN2, DIO_PIN_LOW);
	
    //Write The Most 4 Bits of Command on Data Pins
    LCD_writeHalfPort(cmnd>>4);
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(DIO_PORTB, DIO_PIN3, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(DIO_PORTB, DIO_PIN3, DIO_PIN_LOW);
	
	//Write The least 4 Bits of Command on Data Pins
    LCD_writeHalfPort(cmnd);
 	/* Enable Pulse *//* H => L */
    DIO_setPinValue(DIO_PORTB, DIO_PIN3, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(DIO_PORTB, DIO_PIN3, DIO_PIN_LOW);
	
}
void LCD_sendChar(u8 data)
{
	
	//Set Rs Pin = 1 (write data)
	DIO_setPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_HIGH);
	
	//Set R/W pin = 0 (write)
    DIO_setPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_PIN_LOW);
	
    //Write The Most 4 Bits of data on Data Pins
    LCD_writeHalfPort(data>>4);
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);
	
	//Write The least 4 Bits of data on Data Pins
    LCD_writeHalfPort(data);
 	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT, LCD_EN_PIN, DIO_PIN_LOW);
	
}

void LCD_writeString(u8* string)
{
	u8 counter=0;
	while(string[counter] != '\0')
	{
		LCD_sendChar(string[counter]);
		++counter;
	}		
}

void LCD_clear(void)
{
	LCD_sendCmnd(0b00000001);
	_delay_ms(2);
}

void LCD_shift(u8 shiftingDirection)
{
	if(LCD_SHIFT_RIGHT == shiftingDirection)
	{
		LCD_sendCmnd(0b00011100);
		_delay_us(45);
	}
	else if(LCD_SHIFT_LEFT == shiftingDirection)
	{
		LCD_sendCmnd(0b00011000);
		_delay_us(45);
	}		
		
}

void LCD_goToSpecificPosition(u8 LineNumber, u8 Position)
{
	if(LCD_LINE_ONE == LineNumber)
	{
		LCD_sendCmnd(0x80 + Position);
	}
	else if(LCD_LINE_TWO == LineNumber)
	{
		LCD_sendCmnd(0xc0 + Position);
	}

}


void LCD_writeHalfPort(u8 value)
{
	if(1 == GET_BIT(value, 0))
	{
		DIO_setPinValue(LCD_D4_PORT, LCD_D4_PIN, DIO_PIN_HIGH);
	}		
	else 
	{
		DIO_setPinValue(LCD_D4_PORT, LCD_D4_PIN, DIO_PIN_LOW);
	}
	
	if(1 == GET_BIT(value, 1))
	{
		DIO_setPinValue(LCD_D5_PORT, LCD_D5_PIN, DIO_PIN_HIGH);
	}		
	else 
	{
		DIO_setPinValue(LCD_D5_PORT, LCD_D5_PIN, DIO_PIN_LOW);
	}
	
	if(1 == GET_BIT(value, 2))
	{
		DIO_setPinValue(LCD_D6_PORT, LCD_D6_PIN, DIO_PIN_HIGH);
	}		
	else 
	{
		DIO_setPinValue(LCD_D6_PORT, LCD_D6_PIN, DIO_PIN_LOW);
	}
	
	if(1 == GET_BIT(value, 3))
	{
		DIO_setPinValue(LCD_D7_PORT, LCD_D7_PIN, DIO_PIN_HIGH);
	}		
	else 
	{
		DIO_setPinValue(LCD_D7_PORT, LCD_D7_PIN, DIO_PIN_LOW);
	}
	
}

void LCD_writeNumber(s32 num)
{
	char buffer[16];   
	u8 i = 0;

	if(num < 0)
	{
		LCD_sendChar('-');  
		num = -num;         
	}

	
	if(num == 0)
	{
		LCD_sendChar('0');
		return;
	}

	
	while(num > 0)
	{
		buffer[i] = (num % 10) + '0';  
		num /= 10;
		i++;
	}


	while(i > 0)
	{
		i--;
		LCD_sendChar(buffer[i]);
	}
}
