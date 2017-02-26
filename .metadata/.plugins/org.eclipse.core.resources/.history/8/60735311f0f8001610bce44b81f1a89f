/*
 * main.c
 *
 *  Created on: Jan 23, 2017
 *      Author: Russel
 */

#include "std_types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "delay_ms.h"
#include "EXTINT_Interface.h"

u8 Main_u8Pin=ONE;

//ISR( __vector_1 )
//{
//delay_ms(200);
//	Main_u8Pin++;
//	Main_u8Pin =Main_u8Pin%3;
//
//}


volatile void __vector_1(void)
{

	toggleBit(PORTA,PIN_0);


}

void main (void)
{


EXTINT_Initialization();

while(1)
{

//	DIO_u8SetPinValue(Main_u8Pin,DIO_HIGH);
//	delay_ms(1000);
//	DIO_u8SetPinValue(Main_u8Pin,DIO_LOW);
//	delay_ms(1000);

}


return;
}


