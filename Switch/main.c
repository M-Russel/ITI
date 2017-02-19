/*
 * main.c


 *
 *  Created on: Dec 21, 2016
 *      Author: Russel
 */
#include <stdio.h>
#include "delay_ms.h"
#include "std_types.h" // DATA TYPES HEADER FILE
#include "utils.h" // BIT CALCULATION HEADER FILE
#include "DIO_voidInitialize.h" // DIO INITIALE VALUES
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "io_ports_atmega32.h" // PORTS MAPPING HEADER FILE
#include "util/delay.h"
#include "LCD_Interface.h"
#include "pripherals.h"



void main(void)
{

u8 Local_u8KeyPadPinValue=0;
	DIO_voidInitialize(0);

	DIO_u8SetPinDirection(KEYPAD_FIRST_ROW,DIO_OUTPUT);
	DIO_u8SetPinDirection(KEYPAD_FIRST_COLOUMN,DIO_INPUT);
	DIO_u8SetPinDirection(KEYPAD_FIRST_LED,DIO_OUTPUT);

	DIO_u8SetPinDirection(KEYPAD_SECOND_ROW,DIO_OUTPUT);
	DIO_u8SetPinDirection(KEYPAD_SECOND_COLOUMN,DIO_INPUT);
	DIO_u8SetPinDirection(KEYPAD_SECOND_LED,DIO_OUTPUT);

	DIO_u8SetPinDirection(KEYPAD_THIRD_ROW,DIO_OUTPUT);
	DIO_u8SetPinDirection(KEYPAD_THIRD_COLOUMN,DIO_INPUT);
	DIO_u8SetPinDirection(KEYPAD_THIRD_LED,DIO_OUTPUT);

	DIO_u8SetPinDirection(KEYPAD_FOURTH_ROW,DIO_OUTPUT);
	DIO_u8SetPinDirection(KEYPAD_FOURTH_COLOUMN,DIO_INPUT);
	DIO_u8SetPinDirection(KEYPAD_FOURTH_LED,DIO_OUTPUT);



while (1)
{

DIO_u8setPinValue(KEYPAD_FIRST_ROW,DIO_HIGH);

DIO_u8GetPinValue(KEYPAD_FIRST_COLOUMN,&Local_u8KeyPadPinValue);
 //if (*)



}

}




