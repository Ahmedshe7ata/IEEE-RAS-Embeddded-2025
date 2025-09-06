/*
 * KPD_program.c
 *
 * Created: 8/1/2025 9:13:38 PM
 *  Author: pc
 */ 

    /*UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

    /* MCAL */
#include "DIO_interface.h"
 
    /* HAL */
#include "KPD_interface.h"
#include "KPD_config.h"


void KPD_getValue(u8* returnedValue)
{
	u8 ColoumnsPins[4] = {KPD_COL0_PIN,KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN};
	u8 RowsPins[4]	   = {KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
    u8 KPD_chars[4][4] = KPD_KEYS;
	*returnedValue = KPD_NOT_PRESSED; 
	u8 ColsCounter;
	u8 RowsCounter;
	u8 PinValue;
	u8 PinFlag = 0;
	
	for(ColsCounter=0; ColsCounter<4; ++ColsCounter)
	{
		// Activate Each Cols
		DIO_setPinValue(KPD_COLS_PORT, ColoumnsPins[ColsCounter], DIO_PIN_LOW);
		
		//Loop To Check Rows Values
		for(RowsCounter=0; RowsCounter<4; ++RowsCounter)
		{
			DIO_getPinValue(KPD_ROWS_PORT,RowsPins[RowsCounter],&PinValue);
			if(0 == PinValue)
			{
			    *returnedValue = KPD_chars[RowsCounter][ColsCounter];
				while(0 == PinValue)
				{
					DIO_getPinValue(KPD_ROWS_PORT,RowsPins[RowsCounter],&PinValue);
				}
			    PinFlag = 1;
			    break;
			}
		}
		// Deactive current col
		DIO_setPinValue(KPD_COLS_PORT, ColoumnsPins[ColsCounter], DIO_PIN_HIGH);
		if(1 == PinFlag)
		{
			break;
		}
	}		
}	 
	 