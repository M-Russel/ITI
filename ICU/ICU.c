/*
 * ICU.c
 *
 *  Created on: Feb 21, 2017
 *      Author: root
 */


#include "std_types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "TIMER0_private.h"
#include "TIMER0_interface.h"
#include "TIMER0_config.h"
#include "EXTINT_Interface.h"
#include "EXTINT_config.h"
#include "EXTINT_private.h"
#include "ICU_interface.h"
volatile u8 EDGE_u8FLAG = RISING_EDGE;
volatile u16 OVNB=OVERFLOW_COUNTER_INITIAL;
 u8 Ton_Counter=0;
 u8 Toff_Counter = 0;
void Task_u8RisingEdge (void)
{
MCUCR&=FALLING_EDGE_MODE;
EDGE_u8FLAG=FALLING_EDGE;
Ton_Counter++;

}


void Task_u8FallingEdge (void)
{
	MCUCR&=RISING_EDGE_MODE;
	EDGE_u8FLAG=EXIT;
	Toff_Counter++;
}

void __vector_1(void)
{
if (RISING_EDGE == EDGE_u8FLAG)
{
	Task_u8RisingEdge();
}
else if (FALLING_EDGE == EDGE_u8FLAG)
{
	Task_u8FallingEdge();
}
else
{
}

}

void __vector_11(void) {

	OVNB++;

	if (OVERFLOW_COUNTER_MAX == OVNB) {

		TCNT0 = TCNT0_INITIAL_VALUE;
		OVNB = OVERFLOW_COUNTER_INITIAL;
	}

	else {

	}
}

void main(void) {
	DIO_voidInitialize();
	//TIMER0_init();
	EXTINT_Initialization();
	while (1) {

	}

	return;
}

