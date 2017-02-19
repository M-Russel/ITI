/*
 * LCD_Prog.c
 *
 *  Created on: Dec 21, 2016
 *      Author: Russel
 */

#include "std_types.h" // DATA TYPES HEADER FILE
#include "utils.h" // BIT CALCULATION HEADER FILE
#include "io_ports_atmega32.h" // PORTS MAPPING HEADER FILE
#include "DIO_Interface.h" //DIO INTERFACE FILE
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "delay_ms.h"


void LCD_voidWriteCommand(u8 Copy_Command)
{

	DIO_u8SetPinValue(PIN_2,DIO_LOW);

DIO_u8SetPinValue(PIN_0,DIO_LOW);
DIO_u8SetPinValue(PIN_1,DIO_LOW);
DIO_u8SetPortValue(PORT_D,Copy_Command);
DIO_u8SetPinValue(PIN_2,DIO_HIGH);
delay_ms(2);
DIO_u8SetPinValue(PIN_2,DIO_LOW);
}


void LCD_voidWriteData(u8 Copy_Data)
{
	DIO_u8SetPinValue(PIN_2,DIO_LOW);

	DIO_u8SetPinValue(PIN_0,DIO_HIGH);
	DIO_u8SetPinValue(PIN_1,DIO_LOW);
	DIO_u8SetPortValue(PORT_D,Copy_Data);
	DIO_u8SetPinValue(PIN_2,DIO_HIGH);
	delay_ms(2);

	DIO_u8SetPinValue(PIN_2,DIO_LOW);
}

void LCD_voidInit(void)
{

delay_ms(50);

LCD_voidWriteCommand(0b00111000); // 0b 0011NFxx  N Number of lines F Font
delay_ms(2);
LCD_voidWriteCommand(0b00001100); //0b00001DCB 	D Display ON OFF  C Cursor ON OFF B Cursor Blink
delay_ms(2);
LCD_voidWriteCommand(0b00000001); //CLEAR THE LCD

}

//AC Address:- 0b1A6:A0
//set ddram address: LCD_voidWriteCommand(0b11000000); write on ddram in the second line data display
//0:7 in previous command it is for CGRAM character generator
// 0b01C5:C
//set cgram address:LCD_voidWriteCommand
