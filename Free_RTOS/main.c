/*
 * main.c
 *
 *  Created on: Mar 28, 2017
 *      Author: root
 */

#include "FreeRTOS.h"
#include "task.h"


void task1(void *pr)
{
DDRA|=(1<<0);

while (1)
{

PORTA^=(1<<0);
vTaskDelay(537);

}


}

void main (void)
{

	//word = size of data memory
	//the stack size for the task deteremined by (size of the 32 GP registers + size of PSW register + size of PC )

xTaskCreate(task1,"Hamada",80,NULL,1,NULL);
vTaskStartScheduler();

}
