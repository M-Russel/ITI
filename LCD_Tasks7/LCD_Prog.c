/*
 * LCD_Prog.c
 *
 *  Created on: Dec 21, 2016
 *      Author: Russel
 *  Edited on :January 8,2017
 *  v :2.0
 */

#include "io_ports_atmega32.h" // PORTS MAPPING HEADER FILE
#include "DIO_voidInitialize.h" // DIO INITIALE VALUES
#include "DIO_Interface.h" //DIO INTERFACE FILE
#include "delay_ms.h"
#include "std_types.h" // DATA TYPES HEADER FILE
#include "utils.h" // BIT CALCULATION HEADER FILE

#define BASE_CGR 0x40
#define BASE_DDRAM 0x80
#define SECONDLINE_DDRAM 0b11000000
#define ERROR 1
#define OK 0
#define FIRST_LINE 1
#define SECOND_LINE 2
#define LINE_BASE 0
#define LINE_END 16








u8 Local_u8Status = 0;
u8 LCD_u8WriteCommand(u8 Copy_Command)
{
if (DDRA==DIO_PORT_OUTPUT && (getBit(DDRD,PIND_0) & getBit(DDRD,PIND_1) & getBit(DDRD,PIND_2)) == 1 )
	{
	DIO_u8SetPinValue(PORT_A,PINA_2,DIO_LOW);
	DIO_u8SetPinValue(PORT_A,PINA_0,DIO_LOW);
	DIO_u8SetPinValue(PORT_A,PINA_1,DIO_LOW);
	DIO_u8SetPortValue(PORT_D,Copy_Command);
	DIO_u8SetPinValue(PORT_A,PINA_2,DIO_HIGH);
	delay_ms(2);
	DIO_u8SetPinValue(PORT_A,PINA_2,DIO_LOW);
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
	DIO_u8SetPinValue(PORT_A,PINA_2,DIO_LOW);
	DIO_u8SetPinValue(PORT_A,PINA_0,DIO_HIGH);
	DIO_u8SetPinValue(PORT_A,PINA_1,DIO_LOW);
	DIO_u8SetPortValue(PORT_D,Copy_Data);
	DIO_u8SetPinValue(PORT_A,PINA_2,DIO_HIGH);
	delay_ms(2);
	DIO_u8SetPinValue(PORT_A,PINA_2,DIO_LOW);
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
