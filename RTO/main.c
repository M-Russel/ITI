/*
 * main.c
 *
 *  Created on: Feb 22, 2017
 *      Author: root
 */

#include "std_types.h"
#include "utils.h"
#include "delay_ms.h"
#include "DIO_Interface.h"
#include "RTO_interface.h"
#include "TIMER0_interface.h"


void Test(void);

u8 flag=0;


void Test(void)
{
	if (flag == 0)
	{
DIO_u8SetPinValue(PIN_0,DIO_HIGH);
flag=1;
	}
	else
	{
		DIO_u8SetPinValue(PIN_0,DIO_LOW);
		flag=0;
	}

}


void main(void)
{
	DIO_voidInitialize();
	TIMER0_init();
    RTO_voidInit();
	Task Task1;
	Task1.ptr=Test;
	Task1.Task_u32Periodicity=TASK_NUMBER1_PERIODICITY;
	Task1.Task_u32First_Delay=TASK_NUMBER1_FIRST_DELAY;
    Task1.state=Running;
	RTO_u8CreatTask(&Task1,0);
	RTO_u8StartTask(0);

while(1)
{



}
return;
}
