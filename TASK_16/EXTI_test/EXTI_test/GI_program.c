/*
 * GI_program.c
 *
 * Created: 8/11/2025 2:48:26 AM
 *  Author: pc
 */ 

    /*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

    /* MCAL */
#include "GI_interface.h"




void GI_enable(void)
{
	SET_BIT(SREG, 7);
}

void GI_disable(void)
{
	CLR_BIT(SREG, 7);
}
