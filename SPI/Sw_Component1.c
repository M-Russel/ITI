/*
 * Sw_Component1.c
 *
 *  Created on: Apr 7, 2017
 *      Author: Russel
 *
 */

#include "std_types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "SPI_interface.h"
#include "delay_ms.h"


void main (void)
{
	u8 Local_u8Data[]="Hello";
	u8 counter=0;
	DIO_voidInitialize();
	SPI_u8Init();

	while (TRUE)
	{
for (counter=0;counter <5;counter++)
{

	SPI_u8TransmitData(Local_u8Data[counter]);
	delay_ms(1000);
}
	}



}
