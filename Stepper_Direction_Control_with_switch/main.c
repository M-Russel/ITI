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

DIO_u8Initialize();
STEPPER_u8Init();
while (1)
{
	//Traditional way
	/*
DIO_u8GetPinValue(SWITCH_1,&Local_u8InputValue);
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
{}
*/

DIO_u8GetPinValue(SWITCH_1,&Local_u8InputValue);
if(Local_u8InputValue == DIO_HIGH)
{

	STEPPER_u8SetRotateDirectionClockWise();

}

else if (Local_u8InputValue == DIO_LOW)
{
	STEPPER_u8SetRotateDirectionCounterClockWise();

}
}
return;
}


