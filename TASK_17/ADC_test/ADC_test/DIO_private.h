/*
 * DIO_private.h
 *
 * Created: 9/2/2025 3:57:03 PM
 *  Author: AHMED SHE7ATA
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

                /*DIO_REGISTERS*/

                /*DATA_DIRECTION_REGISTERS*/
#define DDRA        (*(volatile u8*)0x3A)
#define DDRB        (*(volatile u8*)0x37)
#define DDRC        (*(volatile u8*)0x34)
#define DDRD        (*(volatile u8*)0x31)

                /*PORT_REGISTERS*/
#define PORTA        (*(volatile u8*)0x3B)
#define PORTB        (*(volatile u8*)0x38)
#define PORTC        (*(volatile u8*)0x35)
#define PORTD        (*(volatile u8*)0x32)

                /*PIN_REGISTERS*/
#define PINA        (*(volatile u8*)0x39)
#define PINB        (*(volatile u8*)0x36)
#define PINC        (*(volatile u8*)0x33)
#define PIND        (*(volatile u8*)0x30)
                


#endif /* DIO_PRIVATE_H_ */