/*
 * _7SEG_program.c
 *
 * Created: 8/3/2025 8:33:28 PM
 *  Author: pc
 */ 
/*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "SEG7_interface.h"
#include "SEG7_config.h"



void SEG7_displaySingleNumber(u8 Number)
{
    u8 SegmentEncoding[10] = {
        0b00111111, // 0
        0b00000110, // 1
        0b01011011, // 2
        0b01001111, // 3
        0b01100110, // 4
        0b01101101, // 5
        0b01111101, // 6
        0b00000111, // 7
        0b01111111, // 8
        0b01101111  // 9
    };

    if(Number <= 9)
    {
        PORTNUM = SegmentEncoding[Number];
    }
}

		
 