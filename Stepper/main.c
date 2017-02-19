/*
 * main.c
 *
 *  Created on: Feb 6, 2017
 *      Author: root
 */

#include "std_types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "STEPPER_interface.h"
#include "delay_ms.h"


#define INITIAL_LOOP_COUNTER 0
#define MAXIMUM_LOOP_COUNTER 4
#define COIL_ONE_LEFT 16 //blue
#define COIL_ONE_RIGHT 17 //pink
#define COIL_TWO_LEFT 18 //yellow
#define COIL_TWO_RIGHT 19 //orange
#define SWITCH_1 0


void main (void)
{

u8 Local_u8InputValue;

/*

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


//	DIO_u8SetPinValue(COIL_ONE_LEFT,DIO_HIGH);
	}
*/
DIO_u8Initialize();
//STEPPER_u8Init();
while (1)
{
/*DIO_u8GetPinValue(SWITCH_1,&Local_u8InputValue);
if(Local_u8InputValue == DIO_HIGH)
{
DIO_u8SetPinValue(COIL_ONE_LEFT,DIO_LOW);
DIO_u8SetPinValue(COIL_ONE_RIGHT,DIO_HIGH);
DIO_u8SetPinValue(COIL_TWO_LEFT,DIO_HIGH);
DIO_u8SetPinValue(COIL_TWO_RIGHT,DIO_HIGH);

delay_ms(500);

DIO_u8SetPinValue(COIL_ONE_LEFT,DIO_HIGH);
DIO_u8SetPinValue(COIL_ONE_RIGHT,DIO_LOW);
DIO_u8SetPinValue(COIL_TWO_LEFT,DIO_HIGH);
DIO_u8SetPinValue(COIL_TWO_RIGHT,DIO_HIGH);

delay_ms(500);

DIO_u8SetPinValue(COIL_ONE_LEFT,DIO_HIGH);
DIO_u8SetPinValue(COIL_ONE_RIGHT,DIO_HIGH);
DIO_u8SetPinValue(COIL_TWO_LEFT,DIO_LOW);
DIO_u8SetPinValue(COIL_TWO_RIGHT,DIO_HIGH);

delay_ms(500);

DIO_u8SetPinValue(COIL_ONE_LEFT,DIO_HIGH);
DIO_u8SetPinValue(COIL_ONE_RIGHT,DIO_HIGH);
DIO_u8SetPinValue(COIL_TWO_LEFT,DIO_HIGH);
DIO_u8SetPinValue(COIL_TWO_RIGHT,DIO_LOW);

delay_ms(500);

DIO_u8SetPinValue(COIL_ONE_LEFT,DIO_HIGH);
DIO_u8SetPinValue(COIL_ONE_RIGHT,DIO_HIGH);
DIO_u8SetPinValue(COIL_TWO_LEFT,DIO_HIGH);
DIO_u8SetPinValue(COIL_TWO_RIGHT,DIO_LOW);

delay_ms(500);


DIO_u8SetPinValue(COIL_ONE_LEFT,DIO_HIGH);
DIO_u8SetPinValue(COIL_ONE_RIGHT,DIO_HIGH);
DIO_u8SetPinValue(COIL_TWO_LEFT,DIO_LOW);
DIO_u8SetPinValue(COIL_TWO_RIGHT,DIO_HIGH);

delay_ms(500);

DIO_u8SetPinValue(COIL_ONE_LEFT,DIO_HIGH);
DIO_u8SetPinValue(COIL_ONE_RIGHT,DIO_LOW);
DIO_u8SetPinValue(COIL_TWO_LEFT,DIO_HIGH);
DIO_u8SetPinValue(COIL_TWO_RIGHT,DIO_HIGH);

delay_ms(500);

DIO_u8SetPinValue(COIL_ONE_LEFT,DIO_LOW);
DIO_u8SetPinValue(COIL_ONE_RIGHT,DIO_HIGH);
DIO_u8SetPinValue(COIL_TWO_LEFT,DIO_HIGH);
DIO_u8SetPinValue(COIL_TWO_RIGHT,DIO_HIGH);
delay_ms(500);
}

else if (Local_u8InputValue == DIO_LOW)
{}*/
STEPPER_u8SetRotateDirectionClockWise();


}
return;
}


