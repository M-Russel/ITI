/*
 * KEYPAD_Prog.c
 *
 *  Created on: Jan 30, 2017
 *      Author: root
 */
#include "std_types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "switch.h"
#include "KEYPAD.h"

/*typedef union KEYPAD_RowValues
{
	u8


};*/

u8 KEYPAD_u8Init(void)
{
	DIO_u8SetPinDirection(PIN_16,DIO_OUTPUT);
	DIO_u8SetPinDirection(PIN_17,DIO_OUTPUT);
	DIO_u8SetPinDirection(PIN_18,DIO_OUTPUT);
	DIO_u8SetPinDirection(PIN_19,DIO_OUTPUT);

	DIO_u8SetPinDirection(PIN_20,DIO_INPUT);
	DIO_u8SetPinDirection(PIN_21,DIO_INPUT);
	DIO_u8SetPinDirection(PIN_22,DIO_INPUT);
	DIO_u8SetPinDirection(PIN_23,DIO_INPUT);

	DIO_u8SetPinValue(PIN_16, DIO_HIGH);
	DIO_u8SetPinValue(PIN_17, DIO_HIGH);
	DIO_u8SetPinValue(PIN_18, DIO_HIGH);
	DIO_u8SetPinValue(PIN_19, DIO_HIGH);

	DIO_u8SetPinValue(PIN_20, DIO_HIGH);
	DIO_u8SetPinValue(PIN_21, DIO_HIGH);
	DIO_u8SetPinValue(PIN_22, DIO_HIGH);
	DIO_u8SetPinValue(PIN_23, DIO_HIGH);

return OK;
}

u8 KEYPAD_u8GetKeyValue(u8 Copy_u8PinNumber,pu8 Copy_pu8KeyStatus)
{


	u8 Local_u8KeypadPins[8]={KEYPAD_ROW1,KEYPAD_ROW2,KEYPAD_ROW3,KEYPAD_ROW4,KEYPAD_Coloumn1,KEYPAD_Coloumn2,KEYPAD_Coloumn3,KEYPAD_Coloumn4};

	u8 Local_u8RowsValue [4]={KEYPAD_ROW1ON,KEYPAD_ROW2ON,KEYPAD_ROW3ON,KEYPAD_ROW4ON};

	u8 Local_u8KeypadSuccedStatus=ERROR, Local_u8Counter=KEYPAD_ROWS_COUNTER_INITIAL,Local_u8BitCounter=KEYPAD_BITNUMBERS_INITIAL;

	u8 Local_u8ColoumnValue=DIO_HIGH;

	for (Local_u8Counter=KEYPAD_ROWS_COUNTER_INITIAL;KEYPAD_ROWS_COUNTER_MAXIMUM;Local_u8Counter++)
	{
		for (Local_u8BitCounter=KEYPAD_BITNUMBERS_INITIAL;KEYPAD_BITNUMBERS_MAXIMUM>Local_u8BitCounter;Local_u8BitCounter++)
		{
			if ( LOW==getBit(Local_u8RowsValue[Local_u8Counter],(Local_u8BitCounter)))
					{
					DIO_u8SetPinValue(Local_u8KeypadPins[Local_u8Counter],DIO_LOW);
					}
			else if( HIGH==getBit((Local_u8RowsValue[Local_u8Counter]),(Local_u8BitCounter)))
			{
				DIO_u8SetPinValue(Local_u8KeypadPins[Local_u8Counter],DIO_HIGH);
			}
		}


		for (Local_u8Counter=KEYPAD_COLOUMN_COUNTER_INITIAL;KEYPAD_COLOUMN_COUNTER_MAXIMUM<Local_u8Counter;Local_u8Counter)
		{
			DIO_u8GetPinValue(KEYPAD_Coloumn1,&Local_u8ColoumnValue);
			if(Local_u8ColoumnValue==DIO_LOW)
			{



			}
		}
	}

return  Local_u8KeypadSuccedStatus;
}


