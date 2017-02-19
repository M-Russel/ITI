/*
 * Stepper.c
 *
 *  Created on: Jan 18, 2017
 *      Author: Russel
 */

#include <stdio.h>
#include "delay_ms.h"
#include "std_types.h" // DATA TYPES HEADER FILE
#include "utils.h" // BIT CALCULATION HEADER FILE
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "io_ports_atmega32.h" // PORTS MAPPING HEADER FILE
#include "util/delay.h"
#include "LCD_Interface.h"
#include "pripherals.h"
#include "Stepper.h"

void main2 (void)
{

u8 Stepper_u8PatternZero[]={DIO_HIGH,DIO_LOW,DIO_LOW,DIO_LOW};
u8 Stepper_u8PatternOne[]={DIO_LOW,DIO_HIGH,DIO_LOW,DIO_LOW};
u8 Stepper_u8PatternTwo[]={DIO_LOW,DIO_LOW,DIO_HIGH,DIO_LOW};
u8 Stepper_u8PatternThree[]={DIO_LOW,DIO_LOW,DIO_LOW,DIO_HIGH};
u8 Stepper_u8Counter=0;
DIO_voidInitialize();

DIO_u8SetPinDirection(COIL_ONE_LEFT,DIO_OUTPUT);//blue
DIO_u8SetPinDirection(COIL_ONE_RIGHT,DIO_OUTPUT);//pink
DIO_u8SetPinDirection(COIL_TWO_LEFT,DIO_OUTPUT);//yellow
DIO_u8SetPinDirection(COIL_TWO_RIGHT,DIO_OUTPUT);//orange


while (1)
{


	for (Stepper_u8Counter=INITIAL_LOOP_COUNTER;Stepper_u8Counter<MAXIMUM_LOOP_COUNTER;Stepper_u8Counter++)
	{
		DIO_u8SetPinValue(COIL_ONE_LEFT,Stepper_u8PatternZero[Stepper_u8Counter]);
		DIO_u8SetPinValue(COIL_ONE_RIGHT,Stepper_u8PatternOne[Stepper_u8Counter]);
		DIO_u8SetPinValue(COIL_TWO_LEFT,Stepper_u8PatternTwo[Stepper_u8Counter]);
		DIO_u8SetPinValue(COIL_TWO_RIGHT,Stepper_u8PatternThree[Stepper_u8Counter]);

	}

/*

DIO_u8SetPinValue(COIL_ONE_LEFT,DIO_HIGH);
DIO_u8SetPinValue(COIL_ONE_RIGHT,DIO_LOW);
DIO_u8SetPinValue(COIL_TWO_LEFT,DIO_LOW);
DIO_u8SetPinValue(COIL_TWO_RIGHT,DIO_LOW);
delay_ms(5);

DIO_u8SetPinValue(COIL_ONE_LEFT,DIO_LOW);
DIO_u8SetPinValue(COIL_ONE_RIGHT,DIO_HIGH);
DIO_u8SetPinValue(COIL_TWO_LEFT,DIO_LOW);
DIO_u8SetPinValue(COIL_TWO_RIGHT,DIO_LOW);
delay_ms(5);

DIO_u8SetPinValue(COIL_ONE_LEFT,DIO_LOW);
DIO_u8SetPinValue(COIL_ONE_RIGHT,DIO_LOW);
DIO_u8SetPinValue(COIL_TWO_LEFT,DIO_HIGH);
DIO_u8SetPinValue(COIL_TWO_RIGHT,DIO_LOW);
delay_ms(5);

DIO_u8SetPinValue(COIL_ONE_LEFT,DIO_LOW);
DIO_u8SetPinValue(COIL_ONE_RIGHT,DIO_LOW);
DIO_u8SetPinValue(COIL_TWO_LEFT,DIO_LOW);
DIO_u8SetPinValue(COIL_TWO_RIGHT,DIO_HIGH);
delay_ms(5);
*/

DIO_u8SetPinValue(COIL_ONE_LEFT,DIO_HIGH);
}



return;
}
