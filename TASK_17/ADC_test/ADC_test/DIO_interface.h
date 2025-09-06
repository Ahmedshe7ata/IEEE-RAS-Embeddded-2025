/*
 * DIO_interface.h
 *
 * Created: 7/26/2025 7:53:34 PM
 *  Author: AHMED SHE7ATA
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


        /* MACROS FOR PIN */
#define DIO_PIN0          0 		
#define DIO_PIN1          1
#define DIO_PIN2          2
#define DIO_PIN3          3 
#define DIO_PIN4          4
#define DIO_PIN5          5
#define DIO_PIN6          6
#define DIO_PIN7          7

        /* MACROS FOR PORT */
#define DIO_PORTA         0	
#define DIO_PORTB         1
#define DIO_PORTC         2
#define DIO_PORTD         3

        /* MACROS FOR PINS DIRECTION */
#define DIO_PIN_INPUT     0
#define DIO_PIN_OUTPUT    1

        /* MACROS FOR PIN VALUE */
#define DIO_PIN_LOW       0
#define DIO_PIN_HIGH      1	

       /* MACROS FOR PORTS DIRECTION */
#define DIO_PORT_INPUT     0x00
#define DIO_PORT_OUTPUT    0xff	
		
		/* MACROS FOR PORTS DIRECTION */
#define DIO_PORT_LOW       0x00
#define DIO_PORT_HIGH      0xff			


        /* PINS APIS */
void DIO_setPinDirection        (u8 PortId, u8 PinId, u8 PinDirection);
void DIO_setPinValue            (u8 PortId, u8 PinId, u8 PinValue);
void DIO_getPinValue            (u8 PortId, u8 PinId, u8* PinValue);
void DIO_togglePinValue         (u8 PortId, u8 PinId);
void DIO_setInputPinResistance  (u8 PortId, u8 PinId);
        
		/* PORTS APIS */
void DIO_setPortDirection       (u8 PortId, u8 PortDirection);
void DIO_setPortValue           (u8 PortId, u8 PortValue);
void DIO_getPortValue           (u8 PortId, u8* PortValue);
void DIO_togglePortValue        (u8 PortId);
void DIO_setInputPortResistance (u8 PortId);





#endif /* DIO_INTERFACE_H_ */