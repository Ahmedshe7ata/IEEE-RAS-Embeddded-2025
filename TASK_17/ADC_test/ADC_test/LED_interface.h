/*
 * LED_interface.h
 *
 * Created: 7/28/2025 6:18:59 PM
 *  Author: pc
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

void LED_init    (u8 PortId, u8 PinId);
void LED_on      (u8 PortId, u8 PinId);
void LED_off     (u8 PortId, u8 PinId);
void LED_toggle  (u8 PortId, u8 PinId);




#endif /* LED_INTERFACE_H_ */