/*
 * main.c
 *
 *  Created on: Feb 8, 2017
 *      Author: root
 */


//BLINKING WITH TIMER


#include "std_types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "TIMER0_private.h"
#include "TIMER0_interface.h"
#include "TIMER0_config.h"
#include "LCD_Interface.h"
#include "STEPPER_interface.h"
#include "delay_ms.h"
#include "SCHEDULAR_u8interface.h"





 typedef struct {

	u32 SCHEDULAR_u32Periodicity;
	u32 SCHEDULAR_u32FirstDelay;
	void (*ptr)(void);




}Task;





 Task swTask[SCHEDULAR_MAXIMUM_TASK]={
		 {SCHEDULAR_TASKONE_PERIODICITY,SCHEDULAR_TASKONE_FIRST_DELAY,Stepper},
		{SCHEDULAR_TASKTWO_PERIODICITY,SCHEDULAR_TASKTWO_FIRST_DELAY,Seconds},
		{SCHEDULAR_TASKTHREE_PERIODICITY,SCHEDULAR_TASKTHREE_FIRST_DELAY,Minutes},
		{SCHEDULAR_TASKFOUR_PERIODICITY,SCHEDULAR_TASKFOUR_FIRST_DELAY,Hours},
		{SCHEDULAR_TASKFIVE_PERIODICITY,SCHEDULAR_TASKFIVE_FIRST_DELAY,Days},
		{SCHEDULAR_TASKSIX_PERIODICITY,SCHEDULAR_TASKSIX_FIRST_DELAY,Months}



};

 u8 Seconds_u8Counter=COUNTER_INITIAL_VALUE;
 u16 Minutes_u16Counter=COUNTER_INITIAL_VALUE;
 u32 Hours_u32Counter=COUNTER_INITIAL_VALUE;
 u32 Days_u32Counter=COUNTER_INITIAL_VALUE;
u8 Buzzer_Flag=0;
void Seconds (void)
{

	LCD_u8CursorPosition(LCD_FIRST_LINE,LCD_DIGIT_EIGHT);
	u8 First_Digit,Second_Digit;
	Seconds_u8Counter++;
	Seconds_u8Counter=Seconds_u8Counter%SECONDS_MAXIMUM;
	First_Digit=Seconds_u8Counter/SECONDS_MODULUS;
	Second_Digit=Seconds_u8Counter%SECONDS_MODULUS;
	LCD_u8WriteData(':');
    LCD_u8WriteData(First_Digit+'0');
    LCD_u8WriteData(Second_Digit+'0');
if(Buzzer_Flag==1)
{
    DIO_u8SetPinValue(PIN_3,DIO_LOW);
    Buzzer_Flag=0;

}
}


void Minutes (void)
{
	LCD_u8CursorPosition(LCD_FIRST_LINE,LCD_DIGIT_FIVE);
	u8 First_Digit,Second_Digit;
	Minutes_u16Counter++;
	Minutes_u16Counter=Minutes_u16Counter%MINUTES_MAXIMUM;
	First_Digit=Minutes_u16Counter/MINUTES_MODULUS;
	Second_Digit=Minutes_u16Counter%MINUTES_MODULUS;
	LCD_u8WriteData(':');
    LCD_u8WriteData(First_Digit+'0');
    LCD_u8WriteData(Second_Digit+'0');
    DIO_u8SetPinValue(PIN_3,DIO_HIGH);
    Buzzer_Flag++;


}



void Hours (void)
{

	    LCD_u8CursorPosition(LCD_FIRST_LINE,LCD_DIGIT_THREE);
		u8 First_Digit,Second_Digit;
		Hours_u32Counter++;
		Hours_u32Counter=Hours_u32Counter%HOURS_MAXIMUM;
		First_Digit=Hours_u32Counter/HOURS_MODULUS;
		Second_Digit=Hours_u32Counter%HOURS_MODULUS;
	    LCD_u8WriteData(First_Digit+'0');
	    LCD_u8WriteData(Second_Digit+'0');
	    if (Buzzer_Flag==0)
	    {
	    DIO_u8SetPinValue(PIN_8,DIO_HIGH);
	    Buzzer_Flag++;
	    }
}



void Days(void)
{

    LCD_u8CursorPosition(LCD_SECOND_LINE,LCD_DIGIT_SIX);
	u8 First_Digit,Second_Digit;
	Days_u32Counter++;
	Days_u32Counter=Days_u32Counter%DAYS_MAXIMUM;
	First_Digit=Days_u32Counter/DAYS_MODULUS;
	Second_Digit=Days_u32Counter%DAYS_MODULUS;
	LCD_u8WriteData(':');
    LCD_u8WriteData(First_Digit+'0');
    LCD_u8WriteData(Second_Digit+'0');

}


void Months(void)
{
	}

void Stepper(void)
{
STEPPER_u8SetRotateDirectionClockWise();

}
u16 OVNB=OVERFLOW_COUNTER_INITIAL;
 void __vector_11(void)
{

	 OVNB++;

	 if(OVERFLOW_COUNTER_MAX==OVNB)
	 {
		 SCHEDULAR_voidStart();
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
	LCD_u8Init();
	TIMER0_init();

while (1)
{



}

return ;
}


void SCHEDULAR_voidStart(void)
{
	u8 SCHEDULAR_u8Counter;
	for (SCHEDULAR_u8Counter=SCHEDULAR_INITIAL_TASK;SCHEDULAR_u8Counter<SCHEDULAR_MAXIMUM_TASK;SCHEDULAR_u8Counter++)
	{
		if (swTask[SCHEDULAR_u8Counter].SCHEDULAR_u32FirstDelay== SCHEDULAR_INITIAL_DELAY)
		{
			(swTask[SCHEDULAR_u8Counter].ptr)();
			swTask[SCHEDULAR_u8Counter].SCHEDULAR_u32FirstDelay=swTask[SCHEDULAR_u8Counter].SCHEDULAR_u32Periodicity-SCHEDULAR_PERIODICITY_OFFSET;
		}
		else
		{
			swTask[SCHEDULAR_u8Counter].SCHEDULAR_u32FirstDelay--;


		}

	}





}
