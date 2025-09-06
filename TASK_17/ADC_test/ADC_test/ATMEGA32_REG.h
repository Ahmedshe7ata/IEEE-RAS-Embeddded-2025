/*
 * ATMEGA32_REG.h
 *
 * Created: 7/26/2025 7:54:38 PM
 *  Author: pc
 */ 


#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

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

  

               /*  EXTERNAL INTERRUPT REGISTERS */
			   
// MCU Control Register
#define MCUCR         (*(volatile u8*) 0x55)

// MCU Control and Status Register	
#define MCUCSR        (*(volatile u8*) 0x54)

// General Interrupt Control Register
#define GICR          (*(volatile u8*) 0x5B)

// General Interrupt Flag Register
#define GIFR          (*(volatile u8*) 0x5A)

// Status Register
#define SREG          (*(volatile u8*) 0x5F)


                /* ADC REGISTERS */	

// ADC Multiplexer selection Register				
#define ADMUX         (*(volatile u8*) 0x27) 
 
// ADC Control and Status Register A
#define ADCSRA        (*(volatile u8*) 0x26) 

// The ADC Data Register
#define ADCL          (*(volatile u8*) 0x24)    
#define ADCH          (*(volatile u8*) 0x25)
#define ADC_u16       (*(volatile u8*) 0x24)
 

// Special Function IO Register   
#define SFIOR         (*(volatile u8*) 0x50)


#endif /* ATMEGA32_REG_H_ */