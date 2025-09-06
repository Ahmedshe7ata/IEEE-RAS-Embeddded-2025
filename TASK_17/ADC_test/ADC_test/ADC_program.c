/*
 * ADC_program.c
 *
 * Created: 8/17/2025 1:58:02 AM
 *  Author: pc
 */ 

   /*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

    /* MCAL */
#include "ADC_interface.h"


void ADC_init(void)
{
	// select Vref = AVCC
	SET_BIT(ADMUX, 6);
	CLR_BIT(ADMUX, 7);
	
	// Select Right Adjustment
	CLR_BIT(ADMUX, 5);
	
	// Single Conversion Mode 
    CLR_BIT(ADCSRA, 5);

    // Prescaler 128 For 16MHZ = 125KHZ	
	SET_BIT(ADCSRA, 0);
	SET_BIT(ADCSRA, 1);
	SET_BIT(ADCSRA, 2);
	
	//ADC Enable
	SET_BIT(ADCSRA, 7);
		
}

void ADC_getDigitalValue(u8 channelNum, u16* digitalValue)
{
	// Clear ADMUX Channel Bits
	ADMUX &= 0b11100000;
	
	// Select Channel Number
	ADMUX |= channelNum;

	// -----------------------
	// Dummy Conversion
	// -----------------------
	SET_BIT(ADCSRA, 6);                // Start dummy conversion
	while(0 == GET_BIT(ADCSRA, 4));    // Wait for completion
	SET_BIT(ADCSRA, 4);                // Clear flag

	// -----------------------
	// Real Conversion
	// -----------------------
	SET_BIT(ADCSRA, 6);                // Start real conversion
	while(0 == GET_BIT(ADCSRA, 4));    // Wait for completion
	SET_BIT(ADCSRA, 4);                // Clear flag

	// -----------------------
	// Read digital Value (ADCL first, then ADCH)
	// -----------------------
	u8 low = ADCL;
	u8 high = ADCH;
	*digitalValue = ((u16)high << 8) | low;
}
