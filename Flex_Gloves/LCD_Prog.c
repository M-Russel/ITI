/*
 * LCD_Prog.c
 *
 *  Created on: Dec 21, 2016
 *      Author: Russel
 *  Edited on :January 8,2017
 *  v :2.0
 */
#include "std_types.h" // DATA TYPES HEADER FILE
#include "utils.h" // BIT CALCULATION HEADER FILE
#include "DIO_Interface.h" //DIO INTERFACE FILE
#include "DIO_Private.h"
#include "LCD_Private.h"
#include "LCD_config.h"
#include "LCD_Interface.h"
#include "delay_ms.h"









u8 Local_u8Status = 0;
/*u8 LCD_u8WriteCommand(u8 Copy_Command)
{

	DIO_u8SetPinValue(LCD_Enable,DIO_LOW);
	DIO_u8SetPinValue(LCD_RS,DIO_LOW);
	DIO_u8SetPinValue(LCD_RW,DIO_LOW);
	DIO_u8SetPortValue(&LCD_DataRegisterPORT,Copy_Command);
	DIO_u8SetPinValue(LCD_Enable,DIO_HIGH);
	delay_ms(2);
	DIO_u8SetPinValue(LCD_Enable,DIO_LOW);


	return OK;
}*/

u8 LCD_u8WriteCommand(u8 Copy_Command)
{

	DIO_u8SetPinValue(LCD_Enable,DIO_LOW);
	DIO_u8SetPinValue(LCD_RS,DIO_LOW);
	DIO_u8SetPinValue(LCD_RW,DIO_LOW);
	DIO_u8SetPortValue(&LCD_DataRegisterPORT,Copy_Command);
	DIO_u8SetPinValue(LCD_Enable,DIO_HIGH);

	return OK;
}

u8 LCD_u8WriteData1(u8 Copy_Data)
{


	DIO_u8SetPinValue(LCD_Enable,DIO_LOW);
	DIO_u8SetPinValue(LCD_RS,DIO_HIGH);
	DIO_u8SetPinValue(LCD_RW,DIO_LOW);
	DIO_u8SetPortValue(&LCD_DataRegisterPORT,Copy_Data);
	DIO_u8SetPinValue(LCD_Enable,DIO_HIGH);
	delay_ms(2);
	DIO_u8SetPinValue(LCD_Enable,DIO_LOW);

	return OK;
}


u8 LCD_u8WriteData(u8 Copy_Data)
{


	DIO_u8SetPinValue(LCD_Enable,DIO_LOW);
	DIO_u8SetPinValue(LCD_RS,DIO_HIGH);
	DIO_u8SetPinValue(LCD_RW,DIO_LOW);
	DIO_u8SetPortValue(&LCD_DataRegisterPORT,Copy_Data);
	DIO_u8SetPinValue(LCD_Enable,DIO_HIGH);

	return OK;
}

u8 LCD_u8DisableLCDEnable(void)
{
	DIO_u8SetPinValue(LCD_Enable,DIO_LOW);

return OK;
}

/*u8 LCD_u8Init(void)
{

u8 LCD_u8FunctionSet=ZERO;
u8 LCD_u8DisplaySettings=ZERO;

LCD_u8FunctionSet = LCD_COMMAND(FS_DB7,FS_DB6,FS_DB5,FS_DB4,FS_DB3,FS_DB2
		,FS_DB1,FS_DB0);
 //delay_ms(50);

 LCD_u8DisplaySettings=LCD_COMMAND(DS_DB7,DS_DB6,DS_DB5,DS_DB4,DS_DB3,DS_DB2
			,DS_DB1,DS_DB0);

LCD_u8WriteCommand(LCD_u8FunctionSet); // 0b 0011NFxx  N Number of lines F Font
delay_ms(2);
LCD_u8WriteCommand(LCD_u8DisplaySettings); //0b00001DCB 	D Display ON OFF  C Cursor ON OFF B Cursor Blink
delay_ms(2);
LCD_u8WriteCommand(LCD_ClearScreen); //CLEAR THE LCD

return OK;
}*/

u8 LCD_u8InitFunctionSet(void)
{

u8 LCD_u8FunctionSet=ZERO;

LCD_u8FunctionSet = LCD_COMMAND(FS_DB7,FS_DB6,FS_DB5,FS_DB4,FS_DB3,FS_DB2
		,FS_DB1,FS_DB0);
LCD_u8WriteCommand(LCD_u8FunctionSet);

return OK;
}
u8 LCD_u8InitDisplaySettings(void)
{
	u8 LCD_u8DisplaySettings=ZERO;
LCD_u8DisplaySettings=LCD_COMMAND(DS_DB7,DS_DB6,DS_DB5,DS_DB4,DS_DB3,DS_DB2
			,DS_DB1,DS_DB0);

LCD_u8WriteCommand(LCD_u8DisplaySettings);
return OK;
}


u8 LCD_u8ClearScreen(){
LCD_u8WriteCommand(LCD_ClearScreen);

return OK;
}

/*u8 LCD_u8WriteString(u8 Copy_u8String[])
{
u8 Local_u8Counter=0;

while (Copy_u8String[Local_u8Counter] != '\0')
{
LCD_u8WriteData(Copy_u8String[Local_u8Counter]);
Local_u8Counter++;
}


return OK;
}*/

u8 LCD_u8WriteString(u8 Copy_u8String[],pu8 Copy_pu8StringCounter)
{
static u8 Local_u8Counter=0,Local_u8StringSize=0;

while (Copy_u8String[Local_u8Counter] != '\0')
{
Local_u8Counter++;
}
*Copy_pu8StringCounter=Local_u8Counter;
if (Local_u8StringSize!=Local_u8Counter)
{
LCD_u8WriteData(Copy_u8String[Local_u8StringSize]);
Local_u8StringSize++;
}
else
{

}
return OK;
}





u8 LCD_u8CursorPosition(u8 Copy_u8LineNumber, u8 Copy_u8DigitNumber)
{
	if(Copy_u8DigitNumber >= LINE_BASE && Copy_u8DigitNumber<LINE_END)
	{
			if (Copy_u8LineNumber==FIRST_LINE)
			{
				LCD_u8WriteCommand(BASE_DDRAM |Copy_u8DigitNumber);
			}
			else if (Copy_u8LineNumber == SECOND_LINE)
			{
				LCD_u8WriteCommand(SECONDLINE_DDRAM |Copy_u8DigitNumber);

			}
			else
			{
				Local_u8Status=1;
			}
	}

	else {
		Local_u8Status=1;


	}

	return OK;
}
u8 LCD_u8WriteCgRam(void)
{

LCD_u8WriteCommand(BASE_CGR);

return OK;
}

u8 LCD_u8WriteDdRam(void){

	LCD_u8WriteCommand(BASE_DDRAM);
return OK;
}
//AC Address:- 0b1A6:A0
//set ddram address: LCD_voidWriteCommand(0b11000000); write on ddram in the second line data display
//0:7 in previous command it is for CGRAM character generator
// 0b01C5:C
//set cgram address:LCD_voidWriteCommand
