/*

 * main.c
 *
 *  Created on: Feb 8, 2017
 *      Author: root



//BLINKING WITH TIMER


#include "std_types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "TIMER0_private.h"
#include "TIMER0_interface.h"
#include "TIMER0_config.h"
#include "delay_ms.h"


#define LED_LOW 0
#define LED_HIGH 1

void func1 (void);
void func2 (void);
void func3 (void);

#define on 1
#define off 0


typedef struct {

	u8 Periodicity;
	u8 First_Delay;
	void (*ptr)(void);


}Task;

Task swTask[3]={
		{1,0,func1},
		{3,0,func2},
		{5,0,func3}

};


u8 Green_Flag=0,red_Flag=0,blue_Flag=0;

void (*arr[3])(void)={func1,func2,func3};

void func1 (void)
{
	if (off == Green_Flag)
	{
		DIO_u8SetPinValue(PIN_0,DIO_HIGH);
		Green_Flag=on;
	}
	else
		if (on == Green_Flag)
		{
			DIO_u8SetPinValue(PIN_0,DIO_LOW);
			Green_Flag=off;

		}
}


void func2 (void)
{
	if (off == red_Flag)
	{
		DIO_u8SetPinValue(PIN_1,DIO_HIGH);
		red_Flag=on;
	}
	else
		if (on == red_Flag)
		{
			DIO_u8SetPinValue(PIN_1,DIO_LOW);
			red_Flag=off;

		}
}


void func3 (void)
{
	if (off == blue_Flag)
	{
		DIO_u8SetPinValue(PIN_2,DIO_HIGH);
		blue_Flag=on;
	}
	else
		if (on == blue_Flag)
		{
			DIO_u8SetPinValue(PIN_2,DIO_LOW);
			blue_Flag=off;

		}
}





u16 OVNB=OVERFLOW_COUNTER_INITIAL;
 void __vector_11(void)
{
	//u8 counter = 0;
	OVNB1++;
	OVNB2++;
	OVNB3++;

if (OVERFLOW1_COUNTER_MAX == OVNB1)
{

	arr[0]();

    OVNB1=OVERFLOW1_COUNTER_INITIAL;

}
else
{
}
if (OVERFLOW2_COUNTER_MAX == OVNB2)
{

	arr[1]();

    OVNB2=OVERFLOW2_COUNTER_INITIAL;

}
else
{
}

if (OVERFLOW3_COUNTER_MAX == OVNB3)
{

	arr[2]();

    OVNB3=OVERFLOW3_COUNTER_INITIAL;

}
else
{
}


	 OVNB++;

	 if(OVERFLOW_COUNTER_MAX==OVNB)
	 {
		 schedular();
		 TCNT0=TCNT0_INITIAL_VALUE;
		 OVNB=OVERFLOW_COUNTER_INITIAL;
	 }

	 else
	 {


	 }
}

void main(void)
{


DIO_voidInitialize();
TIMER0_init();

while (1)
{



}

return;
}


void schedular (void)
{
	u8 i;
	for (i=0;i<3;i++)
	{
		if (swTask[i].First_Delay==0)
		{
			(swTask[i].ptr)();
			swTask[i].First_Delay=swTask[i].Periodicity-1;
		}
		else
		{
			swTask[i].First_Delay--;


		}

	}





}
*/
