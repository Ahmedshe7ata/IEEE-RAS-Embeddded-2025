/*
 * LCD_config.h
 *
 * Created: 7/29/2025 5:53:32 PM
 *  Author: pc
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_RS_PORT             DIO_PORTB
#define LCD_RW_PORT             DIO_PORTB
#define LCD_EN_PORT             DIO_PORTB

/* DATA PORTS */
#define LCD_D4_PORT             DIO_PORTD
#define LCD_D5_PORT             DIO_PORTD
#define LCD_D6_PORT             DIO_PORTD
#define LCD_D7_PORT             DIO_PORTD

/* DATA PINS */
#define LCD_D4_PIN              DIO_PIN4
#define LCD_D5_PIN              DIO_PIN5
#define LCD_D6_PIN              DIO_PIN6
#define LCD_D7_PIN              DIO_PIN7


#define LCD_RS_PIN              DIO_PIN1
#define LCD_RW_PIN              DIO_PIN2
#define LCD_EN_PIN              DIO_PIN3



#endif /* LCD_CONFIG_H_ */