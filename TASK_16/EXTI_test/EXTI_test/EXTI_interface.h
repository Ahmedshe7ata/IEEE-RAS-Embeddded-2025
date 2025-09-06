/*
 * EXTI_interface.h
 *
 * Created: 8/5/2025 10:57:53 AM
 *  Author: pc
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/* MACROS FOR INTERRUPT SOURCE */
#define EXTI_INT0                      0
#define EXTI_INT1                      1
#define EXTI_INT2                      2

/* MACROS FOR INTERRUPT TRIGGER EDGE */
#define EXTI_RISING_EDGE               0 
#define EXTI_FALLLING_EDGE             1 
#define EXTI_LOW_LEVEL                 2 
#define EXTI_ANY_LOGICAL_CHANGE        3 




                    /* APIS PROTOTYPES */
void EXTI_enable(u8 interruptSource, u8 interruptTriggerEdge);
void EXTI_disable(u8 interruptSource);
void EXTI_INT0SetCallBack(void(*ptr)(void));
void EXTI_INT1SetCallBack(void(*ptr)(void));


#endif /* EXTI_INTERFACE_H_ */