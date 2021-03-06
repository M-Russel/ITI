/*
 * STEPPER_prog.c
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

u8 STEPPER_u8Init()
{


}
u8 STEPPER_u8SetRotateDirectionClockWise(void)
{
 u8 Local_u8Counter=4;

for (Local_u8Counter=4; Local_u8Counter<8;Local_u8Counter++)
{
	STEPPER_u8ConvertValue(COIL_ONE_LEFT,4%(Local_u8Counter));
	STEPPER_u8ConvertValue(COIL_ONE_RIGHT,5%(Local_u8Counter));
	STEPPER_u8ConvertValue(COIL_TWO_LEFT,6%(Local_u8Counter));
	STEPPER_u8ConvertValue(COIL_TWO_RIGHT,7%(Local_u8Counter));
	delay_ms(400);

}
/*STEPPER_u8ConvertValue(COIL_ONE_LEFT,1);
STEPPER_u8ConvertValue(COIL_ONE_RIGHT,1);
STEPPER_u8ConvertValue(COIL_TWO_LEFT,1);
STEPPER_u8ConvertValue(COIL_TWO_RIGHT,0);*/

return 0;

}
u8 STEPPER_u8SetRotateDirectionCounterClockWise(void)
{

	u8 Local_u8Counter = 4;

	for (Local_u8Counter=4; Local_u8Counter<8;Local_u8Counter++)
	{
		STEPPER_u8ConvertValue(COIL_TWO_RIGHT,4%(Local_u8Counter));
		STEPPER_u8ConvertValue(COIL_TWO_LEFT,5%(Local_u8Counter));
		STEPPER_u8ConvertValue(COIL_ONE_RIGHT,6%(Local_u8Counter));
		STEPPER_u8ConvertValue(COIL_ONE_LEFT,7%(Local_u8Counter));
		delay_ms(400);

	}

}

u8 STEPPER_u8ConvertValue (u8 Copy_u8PinNumber,u8 Copy_u8Value)
{
if (Copy_u8Value == 0)
{
	DIO_u8SetPinValue(Copy_u8PinNumber,DIO_LOW);
}
else if (Copy_u8Value>0)
{
	DIO_u8SetPinValue(Copy_u8PinNumber,DIO_HIGH);

}



return 0;
}
