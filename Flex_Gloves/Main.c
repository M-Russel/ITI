/*
 * Main.c
 *
 *  Created on: Mar 25, 2017
 *      Author: root
 */

#include "std_types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "TIMER0_interface.h"
#include "RTO_interface.h"
#include "LCD_Interface.h"


u8 Global_u8Variabl=0;

void LCD_VoidInitialize(void)
{
static u8 Counter=ZERO;
switch (Counter)
{
case 0:
		LCD_u8InitFunctionSet();
	    break;
case 1:
	LCD_u8InitDisplaySettings();

	break;
case 2:
	LCD_u8ClearScreen();
	RTO_u8StopTask(0);
	break;
default :
	break;
}
Counter ++;
}

void LCD_VoidDisableLCDEnable(void)
{
	static Counter2=ZERO;
	DIO_u8SetPinValue(LCD_Enable,DIO_LOW);
	Counter2++;
	if (Counter2>=3)
	{
	RTO_u8StopTask(1);
	}

}


void LCD_VoidWriteDATA(void)
{
	static u8 String_Counter=0,CO=0,h=0;

switch (Global_u8Variabl)
{
case 1:
	LCD_u8WriteString("HELLO",&String_Counter);
    CO++;
    break;
case 2:
	LCD_u8WriteString("How",&String_Counter);
	    CO++;
	    break;
case 3:
	LCD_u8WriteString("Are",&String_Counter);
	 CO++;
	 break;
case 4:
	LCD_u8WriteString("you",&String_Counter);
	    CO++;
	    break;
}
	RTO_u8StartTask(1);
if (CO==String_Counter)
{
	CO=0;
	RTO_u8StopTask(2);
}
else
{

}
}


void Switch_Check(void)
{
u8 Local_u8Temp=ZERO;
DIO_u8GetPinValue(PIN_19,& Local_u8Temp);
if (DIO_HIGH==Local_u8Temp)
{
LCD_u8ClearScreen();
Global_u8Variabl++;
RTO_u8StartTask(2);
}
else
{
if (Global_u8Variabl>=4)
{
Global_u8Variabl=0;
}
}


}


void main(void)
{
DIO_voidInitialize();
TIMER0_init();
RTO_voidInit();
Task Task1;
Task Task2;
Task Task3;
Task Task4;
	Task1.ptr=LCD_VoidInitialize;
	Task1.Task_u32Periodicity=TASK_NUMBER1_PERIODICITY;
	Task1.Task_u32First_Delay=TASK_NUMBER1_FIRST_DELAY;
    Task1.state=Running;
	RTO_u8CreatTask(&Task1,0);
	RTO_u8StartTask(0);


	Task2.ptr=LCD_VoidDisableLCDEnable;
	Task2.Task_u32Periodicity=TASK_NUMBER2_PERIODICITY;
	Task2.Task_u32First_Delay=TASK_NUMBER2_FIRST_DELAY;
    Task2.state=Running;
	RTO_u8CreatTask(&Task2,1);
	RTO_u8StartTask(1);

	Task3.ptr=LCD_VoidWriteDATA;
		Task3.Task_u32Periodicity=TASK_NUMBER3_PERIODICITY;
		Task3.Task_u32First_Delay=TASK_NUMBER3_FIRST_DELAY;
	    Task3.state=Running;
		RTO_u8CreatTask(&Task3,2);
		RTO_u8StartTask(2);


		Task4.ptr=Switch_Check;
		Task4.Task_u32Periodicity=TASK_NUMBER4_PERIODICITY;
		Task4.Task_u32First_Delay=TASK_NUMBER4_FIRST_DELAY;
	    Task4.state=Running;
		RTO_u8CreatTask(&Task4,3);
		RTO_u8StartTask(3);
//LCD_u8Init();
	while (TRUE)
	{

	}

}
