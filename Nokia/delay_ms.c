/*
 * Delay.c
 *
 *  Created on: Dec 13, 2016
 *      Author: Russel
 */
#include "delay_ms.h"

void delay_ms(u32 delay_Value){
u32 counter;
while (delay_Value)
{
	//112 is the right one

	for (counter=MIN_FOR_NOP;counter<MAX__FOR_NOP;counter++)
	{
		asm ("nop");

	}

delay_Value--;
}



}

