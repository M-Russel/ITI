/*
 * main.c
 *
 *  Created on: Apr 4, 2017
 *      Author: root
 */
#include "std_types.h"
#include "utils.h"
#include "DIO_Interface.h"

void main (void)
{

DIO_u8Init();
DIO_u8SetPortValue(DIO_PORT_HIGH,&PORTA);
DIO_u8SetPinValue(PIN_8,DIO_HIGH);
while (1)
{



}


}
