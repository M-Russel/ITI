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
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "LCD_Interface.h"
#include "delay_ms.h"

u8 Local_u8Status = 0;
u8 LCD_u8WriteCommand(u8 Copy_Command)
{
if (DDRA==DIO_PORT_OUTPUT && (getBit(DDRD,PIND_0) & getBit(DDRD,PIND_1) & getBit(DDRD,PIND_2)) == 1 )
	{
	DIO_u8SetPinValue(PIN_2,DIO_LOW);
	DIO_u8SetPinValue(PIN_0,DIO_LOW);
	DIO_u8SetPinValue(PIN_1,DIO_LOW);
	DIO_u8SetPortValue(PORT_D,Copy_Command);
	DIO_u8SetPinValue(PIN_2,DIO_HIGH);
	delay_ms(2);
	DIO_u8SetPinValue(PIN_2,DIO_LOW);
	}
else {
	Local_u8Status=1;
}
	return OK;
}


u8 LCD_u8WriteData(u8 Copy_Data)
{

	if (DDRA==DIO_PORT_OUTPUT && (getBit(DDRD,0) & getBit(DDRD,1) & getBit(DDRD,2)) == 1 )
	{
	DIO_u8SetPinValue(PIN_2,DIO_LOW);
	DIO_u8SetPinValue(PIN_0,DIO_HIGH);
	DIO_u8SetPinValue(PIN_1,DIO_LOW);
	DIO_u8SetPortValue(PORT_D,Copy_Data);
	DIO_u8SetPinValue(PIN_2,DIO_HIGH);
	delay_ms(2);
	DIO_u8SetPinValue(PIN_2,DIO_LOW);
	}
	else {
		Local_u8Status=1;
	}
	return OK;
}

u8 LCD_u8Init(void)
{
	DIO_u8SetPortDirection(DDR_A,DIO_PORT_OUTPUT); //7 SEGEMENT MODES WIRES
	DIO_u8SetPortDirection(DDR_D,DIO_PORT_OUTPUT); // SEVEN SEGEMENTS DATA

 delay_ms(50);

LCD_u8WriteCommand(0b00111000); // 0b 0011NFxx  N Number of lines F Font
delay_ms(2);
LCD_u8WriteCommand(0b00001100); //0b00001DCB 	D Display ON OFF  C Cursor ON OFF B Cursor Blink
delay_ms(2);
LCD_u8WriteCommand(0b00000001); //CLEAR THE LCD


LCD_u8CursorPosition(LCD_FIRST_LINE,3);
	    LCD_u8WriteData('0');
	    LCD_u8WriteData('0');
	    LCD_u8WriteData(':');
	    LCD_u8WriteData('0');
	    LCD_u8WriteData('0');
	    LCD_u8WriteData(':');
	    LCD_u8WriteData('0');
	    LCD_u8WriteData('0');
   LCD_u8CursorPosition(LCD_SECOND_LINE,0);
   LCD_u8WriteString("DATE: 15/02/2017");
return OK;
}

u8 LCD_u8ClearScreen(){
LCD_u8WriteCommand(0b00000001);

return OK;
}

u8 LCD_u8WriteString(u8 Copy_u8String[])
{
u8 Local_u8Counter=0;

while (Copy_u8String[Local_u8Counter] != '\0')
{
LCD_u8WriteData(Copy_u8String[Local_u8Counter]);
Local_u8Counter++;
}


return OK;
}

u8 LCD_u8CursorPosition(u8 Copy_u8LineNumber, u8 Copy_u8DigitNumber)
{
	u8 command;
	if(Copy_u8DigitNumber >= LCD_LINE_BASE && Copy_u8DigitNumber<LCD_LINE_END)
	{
			if (Copy_u8LineNumber==LCD_FIRST_LINE)
			{
				command=LCD_BASE_DDRAM |Copy_u8DigitNumber;
				LCD_u8WriteCommand(command);
			}
			else if (Copy_u8LineNumber == LCD_SECOND_LINE)
			{
				command = LCD_SECONDLINE_DDRAM |Copy_u8DigitNumber;
				LCD_u8WriteCommand(command);

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

LCD_u8WriteCommand(LCD_BASE_CGR);

return OK;
}

u8 LCD_u8WriteDdRam(void){

	LCD_u8WriteCommand(LCD_BASE_DDRAM);
return OK;
}
//AC Address:- 0b1A6:A0
//set ddram address: LCD_voidWriteCommand(0b11000000); write on ddram in the second line data display
//0:7 in previous command it is for CGRAM character generator
// 0b01C5:C
//set cgram address:LCD_voidWriteCommand
