/*
 * main.c
 *
 *  Created on: Jan 23, 2017
 *      Author: root
 */

#include "std_types.h"
#include "utils.h"
#include "io_ports_atmega32.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "DIO_voidInitialize.h"
#include "delay_ms.h"
#include "avr/interrupt.h"
#include "Mc_Registers.h"

u8 Main_u8Pin=ONE;

ISR( __vector_1 )
{
delay_ms(200);
	Main_u8Pin++;
	Main_u8Pin =Main_u8Pin%3;

}


void main (void)
{

DIO_u8SetPinDirection(INT0,DIO_INPUT);
DIO_u8SetPinDirection(LED1,DIO_OUTPUT);
DIO_u8SetPinDirection(LED2,DIO_OUTPUT);
DIO_u8SetPinDirection(LED2,DIO_OUTPUT);

INT0_Initialization();

while(1)
{

	DIO_u8SetPinValue(Main_u8Pin,DIO_HIGH);
	delay_ms(1000);
	DIO_u8SetPinValue(Main_u8Pin,DIO_LOW);
	delay_ms(1000);

}


return;
}


