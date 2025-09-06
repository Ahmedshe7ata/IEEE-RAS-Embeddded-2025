/*
 * EXTI_program.c
 *
 * Created: 8/5/2025 10:57:04 AM
 *  Author: pc
 */ 



    /*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

    /* MCAL */
#include "EXTI_interface.h"

void(*pCallBack)(void) = NULL;
void(*p1CallBack)(void) = NULL;


void EXTI_enable(u8 interruptSource, u8 interruptTriggerEdge)
{
	switch(interruptSource)
	{
		case EXTI_INT0:
		if(interruptTriggerEdge == EXTI_RISING_EDGE)
		{
			SET_BIT(MCUCR, 0);
			SET_BIT(MCUCR, 1);
		}
		else if(interruptTriggerEdge == EXTI_FALLLING_EDGE)
        {
			CLR_BIT(MCUCR, 0);
			SET_BIT(MCUCR, 1);
		}
		else if(interruptTriggerEdge == EXTI_LOW_LEVEL) 
		{
			CLR_BIT(MCUCR, 0);
			CLR_BIT(MCUCR, 1);
		}
        else if(interruptTriggerEdge == EXTI_ANY_LOGICAL_CHANGE)
		{
			SET_BIT(MCUCR, 0);
			CLR_BIT(MCUCR, 1);
		} 		
						
		SET_BIT(GICR, 6); //enable EXTI0
		break;
		
		case EXTI_INT1:
		if(interruptTriggerEdge == EXTI_RISING_EDGE)
		{
			SET_BIT(MCUCR, 2);
			SET_BIT(MCUCR, 3);
		}
		else if(interruptTriggerEdge == EXTI_FALLLING_EDGE)
        {
			CLR_BIT(MCUCR, 2);
			SET_BIT(MCUCR, 3);
		}
		else if(interruptTriggerEdge == EXTI_LOW_LEVEL) 
		{
			CLR_BIT(MCUCR, 2);
			CLR_BIT(MCUCR, 3);
		}
        else if(interruptTriggerEdge == EXTI_ANY_LOGICAL_CHANGE)
		{
			SET_BIT(MCUCR, 2);
			CLR_BIT(MCUCR, 3);
		} 		
						
		SET_BIT(GICR, 7);   //enable EXTI1
		break;
		
		case EXTI_INT2:
		if(interruptTriggerEdge == EXTI_RISING_EDGE)
		{
			SET_BIT(MCUCSR, 6);
		}
		else if(interruptTriggerEdge == EXTI_FALLLING_EDGE)
        {
			CLR_BIT(MCUCSR, 6);
	    }
				
		SET_BIT(GICR, 5); //enable EXTI2
		break;
		
	}
}

void EXTI_disable(u8 interruptSource)
{
	switch(interruptSource)
	{
		case EXTI_INT0:
		CLR_BIT(GICR, 6);    //disable EXTI0
		break;
		
		case EXTI_INT1:
		CLR_BIT(GICR, 7);    //disable EXTI1
		break;
		
		case EXTI_INT2:
		CLR_BIT(GICR, 5);   //disable EXTI2
		break;
	}
}

void EXTI_INT0SetCallBack(void(*ptr)(void))
{ 	
	pCallBack = ptr;
}

void __vector_1(void) __attribute__ ((signal));
void __vector_1(void)
{
	pCallBack();
}

void EXTI_INT1SetCallBack(void(*ptr1)(void))
{
	p1CallBack = ptr1;
}

void __vector_2(void) __attribute__ ((signal));
void __vector_2(void)
{
	p1CallBack();
}