/*
 * DIO_voidSetPinValue.c
 *
 *  Created on: Dec 20, 2016
 *      Author: Russel
 */
#include "../RemoteSystemsTempFiles/DIO_voidSetPinValue.h"

void DIO_voidSetPinValue (u8 Copy_PortName,u8 Copy_PinNumber,u8 Copy_PinValue)
{

if(Copy_PinValue == HIGH)
{

	setBit(Copy_PortName,Copy_PinNumber);
}

else if(Copy_PinValue == LOW)

{

	clrBit(Copy_PortName,Copy_PinNumber);

}



}

