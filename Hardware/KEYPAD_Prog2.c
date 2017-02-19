/*

 * KEYPAD_Prog.c
 *
 *  Created on: Jan 30, 2017
 *      Author: root

#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "switch.h"
#include "KEYPAD.h"

typedef union KEYPAD_RowValues
{
	u8


};

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
	u8 KEYPAD_u8SuccedStatus=OK,Local_u8ColoumnValue=DIO_HIGH,Local_u8RowFlag=KEYPAD_DEFAULT_FLAG,Local_u8ColoumnFlag;
	u8 Local_u8RowCounter=KEYPAD_COUNTER_INITIAL,Local_u8ColoumnCounter=KEYPAD_COUNTER_INITIAL;
u8 Local_u8KeyPressed [4][4]={{KEYPAD_ROW1COLUMN1,KEYPAD_ROW1COLUMN2,KEYPAD_ROW1COLUMN3,KEYPAD_ROW1COLUMN4},
														{KEYPAD_ROW2COLUMN1,KEYPAD_ROW2COLUMN2,KEYPAD_ROW2COLUMN3,KEYPAD_ROW2COLUMN4},
														{KEYPAD_ROW3COLUMN1,KEYPAD_ROW3COLUMN2,KEYPAD_ROW3COLUMN3,KEYPAD_ROW3COLUMN4},
														{KEYPAD_ROW4COLUMN1,KEYPAD_ROW4COLUMN2,KEYPAD_ROW3COLUMN3,KEYPAD_ROW4COLUMN4}};

u8 Local_u8RowsValue[4]={KEYPAD_ROW1ON,KEYPAD_ROW2ON,KEYPAD_ROW3ON,KEYPAD_ROW4ON};
u8 Local_u8Rows[4]={KEYPAD_ROW1,KEYPAD_ROW2,KEYPAD_ROW3,KEYPAD_ROW4};
u8 Local_u8Coloumns[4]={KEYPAD_Coloumn1,KEYPAD_Coloumn2,KEYPAD_Coloumn3,KEYPAD_Coloumn4};
for (Local_u8RowCounter=KEYPAD_COUNTER_INITIAL;KEYPAD_COUNTER_MAXIMUM>Local_u8RowCounter;Local_u8RowCounter++)
{

	switch(Local_u8RowsValue[Local_u8RowCounter])
	{
	case KEYPAD_ROW1ON:
						{

							DIO_u8SetPinValue(SWITCH_0, DIO_LOW);
							DIO_u8SetPinValue(SWITCH_1, DIO_HIGH);
							DIO_u8SetPinValue(SWITCH_2, DIO_HIGH);
							DIO_u8SetPinValue(SWITCH_3, DIO_HIGH);
							Local_u8RowFlag=KEYPAD_ROW1SELECTED;
							break;
						}
	case KEYPAD_ROW2ON:
						{
								DIO_u8SetPinValue(SWITCH_0, DIO_HIGH);
								DIO_u8SetPinValue(SWITCH_1, DIO_LOW);
								DIO_u8SetPinValue(SWITCH_2, DIO_HIGH);
								DIO_u8SetPinValue(SWITCH_3, DIO_HIGH);
								Local_u8RowFlag=KEYPAD_ROW2SELECTED;
								break;
							}

	case KEYPAD_ROW3ON:
							{
							DIO_u8SetPinValue(SWITCH_0, DIO_HIGH);
							DIO_u8SetPinValue(SWITCH_1, DIO_HIGH);
							DIO_u8SetPinValue(SWITCH_2, DIO_LOW);
							DIO_u8SetPinValue(SWITCH_3, DIO_HIGH);
							Local_u8RowFlag=KEYPAD_ROW3SELECTED;
									break;
							}

	case KEYPAD_ROW4ON:
							{
							DIO_u8SetPinValue(SWITCH_0, DIO_HIGH);
							DIO_u8SetPinValue(SWITCH_1, DIO_HIGH);
							DIO_u8SetPinValue(SWITCH_2, DIO_HIGH);
							DIO_u8SetPinValue(SWITCH_3, DIO_LOW);
							Local_u8RowFlag=KEYPAD_ROW4SELECTED;
							break;
							}
	}

	for (Local_u8ColoumnCounter=KEYPAD_COUNTER_INITIAL;KEYPAD_COUNTER_MAXIMUM>Local_u8ColoumnCounter;Local_u8ColoumnCounter++)
	{
		DIO_u8GetPinValue(Local_u8Coloumns[Local_u8ColoumnCounter],&Local_u8ColoumnValue);
		if(!Local_u8ColoumnValue)
		{
		Local_u8ColoumnFlag =KEYPAD_Coloumn1SELECTED;
		}
		else
		{
			//DO NOTHING
		}

		switch (Local_u8RowFlag)
		{



		}

	}



	if (KEYPAD_ROW1ON==Local_u8RowsValue[Local_u8RowCounter])
	{
		DIO_u8SetPinValue(SWITCH_0, DIO_LOW);
		DIO_u8SetPinValue(SWITCH_1, DIO_HIGH);
		DIO_u8SetPinValue(SWITCH_2, DIO_HIGH);
		DIO_u8SetPinValue(SWITCH_3, DIO_HIGH);

	}
	else if (KEYPAD_ROW2ON==Local_u8RowsValue[Local_u8RowCounter])
	{
		DIO_u8SetPinValue(SWITCH_0, DIO_HIGH);
		DIO_u8SetPinValue(SWITCH_1, DIO_LOW);
		DIO_u8SetPinValue(SWITCH_2, DIO_HIGH);
		DIO_u8SetPinValue(SWITCH_3, DIO_HIGH);

	}
	else if (KEYPAD_ROW3ON==Local_u8RowsValue[Local_u8RowCounter])
	{
		DIO_u8SetPinValue(SWITCH_0, DIO_HIGH);
		DIO_u8SetPinValue(SWITCH_1, DIO_HIGH);
		DIO_u8SetPinValue(SWITCH_2, DIO_LOW);
		DIO_u8SetPinValue(SWITCH_3, DIO_HIGH);

	}
	else if (KEYPAD_ROW4ON==Local_u8RowsValue[Local_u8RowCounter])
	{
		DIO_u8SetPinValue(SWITCH_0, DIO_HIGH);
		DIO_u8SetPinValue(SWITCH_1, DIO_HIGH);
		DIO_u8SetPinValue(SWITCH_2, DIO_HIGH);
		DIO_u8SetPinValue(SWITCH_3, DIO_LOW);

	}



}


return KEYPAD_u8SuccedStatus;
}


*/
