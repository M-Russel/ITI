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
#include "io_ports_atmega32.h" // PORTS MAPPING HEADER FILE
#include "DIO_Interface.h"
#include "util/delay.h"
#include "LCD_Interface.h"
#include "pripherals.h"
#include "Buzzer.h"
#include "switch.h"

void main(void)
{



u8 Status;
	DIO_voidInitialize();
DIO_u8SetPinDirection(MOTOR_DIRECTION_ONE_UPPER,DIO_OUTPUT);
DIO_u8SetPinDirection(MOTOR_DIRECTION_ONE_LOWER,DIO_INPUT);
DIO_u8SetPinDirection(MOTOR_DIRECTION_TWO_UPPER,DIO_OUTPUT);
DIO_u8SetPinDirection(MOTOR_DIRECTION_TWO_LOWER,DIO_OUTPUT);

/*
u8 Local_u8KeyPadPinValue=0;

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

*/


while (1)
{
/*

DIO_u8SetPinValue(KEYPAD_FIRST_ROW,DIO_HIGH);
DIO_u8GetPinValue(KEYPAD_FIRST_COLOUMN,&Local_u8KeyPadPinValue);
if (Local_u8KeyPadPinValue)
{
DIO_u8SetPinValue(KEYPAD_FIRST_LED,DIO_HIGH);
}
else {}
DIO_u8SetPinValue(KEYPAD_SECOND_LED,DIO_LOW);
DIO_u8SetPinValue(KEYPAD_THIRD_LED,DIO_LOW);
DIO_u8SetPinValue(KEYPAD_FOURTH_LED,DIO_LOW);





}
*/
/*
DIO_u8SetPinValue(MOTOR_DIRECTION_TWO_UPPER,DIO_LOW);
delay_ms(10);
DIO_u8SetPinValue(MOTOR_DIRECTION_ONE_UPPER,DIO_HIGH);
delay_ms(3000);



DIO_u8SetPinValue(MOTOR_DIRECTION_ONE_UPPER,DIO_LOW);
delay_ms(10);
DIO_u8SetPinValue(MOTOR_DIRECTION_TWO_UPPER,DIO_HIGH);

delay_ms(3000);*/

SWITCH_u8GetStatus(PIN_17,&Status);
//DIO_u8GetPinValue(PIN_17,&Status);
/*

	if (Status == DIO_HIGH)
	{
		DIO_u8SetPinValue(PIN_16,DIO_HIGH);
	}
	else if  (Status == DIO_LOW)
	{

		DIO_u8SetPinValue(PIN_16,DIO_LOW);
	}
*/


if (PUSHED==Status)
{

DIO_u8SetPinValue(PIN_16,DIO_HIGH);
}
else if (RELEASED == Status)
{
	DIO_u8SetPinValue(PIN_16,DIO_LOW);

}
}

}


