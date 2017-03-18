/*

 * main.c
 *
 *  Created on: Feb 8, 2017
 *      Author: root


//MOTOR DIRECTION WITH TIMER

#include "std_types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "TIMER0_private.h"
#include "TIMER0_interface.h"
#include "TIMER0_config.h"
#include "delay_ms.h"



#define CLOCK_WISE 1
#define COUNTER_CLOCK_WISE 2



u16 OVNB=OVERFLOW_COUNTER_INITIAL; // counter
u8 TIMER2_u8DirectionFlag=CLOCK_WISE;
void __vector_11(void)
{

OVNB++;

if (OVERFLOW_COUNTER_MAX == OVNB)
{

	if (CLOCK_WISE == TIMER2_u8DirectionFlag)
	{
		DIO_u8SetPinValue(PIN_16,DIO_HIGH);
		DIO_u8SetPinValue(PIN_17,DIO_LOW);
		TIMER2_u8DirectionFlag=COUNTER_CLOCK_WISE;
	}
	else if (COUNTER_CLOCK_WISE == TIMER2_u8DirectionFlag)
	{

		DIO_u8SetPinValue(PIN_16,DIO_LOW);
		DIO_u8SetPinValue(PIN_17,DIO_HIGH);
		TIMER2_u8DirectionFlag=CLOCK_WISE;
	}


    OVNB=OVERFLOW_COUNTER_INITIAL;
	TCNT0=TCNT0_INITIAL_VALUE;
}
else
{
}

}


void main2(void)
{

DIO_voidInitialize();
TIMER0_init();

while (1)
{


}

return;
}


*/
