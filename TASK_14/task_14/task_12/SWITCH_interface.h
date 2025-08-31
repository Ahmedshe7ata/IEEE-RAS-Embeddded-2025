/*
 * SWITCH_interface.h
 *
 * Created: 9/11/2022 7:33:26 PM
 *  Author: AMIT
 */ 


#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_
 
#define SWITCH_PRESSED             DIO_PIN_HIGH
#define SWITCH_NOT_PRESSED         DIO_PIN_LOW

void SWITCH_init    (u8 PortId, u8 PinId);
void SWITCH_getState(u8 PortId, u8 PinId,u8* switchSate);

#endif /* SWITCH_INTERFACE_H_ */