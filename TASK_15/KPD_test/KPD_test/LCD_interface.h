/*
 * LCD_interface.h
 *
 * Created: 7/29/2025 5:52:01 PM
 *  Author: pc
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/* Macros For LCD Shifting Direction */
#define LCD_SHIFT_LEFT      0 
#define LCD_SHIFT_RIGHT     1

/* Macros For LCD Line Id */
#define LCD_LINE_ONE        1
#define LCD_LINE_TWO        2

void LCD_enablePulse(void);
void LCD_init(void);
void LCD_sendCmnd(u8 cmnd);
void LCD_sendChar(u8 data);
void LCD_writeString(u8* string);
void LCD_clear(void);
void LCD_shift(u8 shiftingDirection);
void LCD_goToSpecificPosition(u8 LineNumber, u8 Position);
void LCD_writeNumber(s32 num);  

void LCD_writeHalfPort(u8 value);

#endif /* LCD_INTERFACE_H_ */