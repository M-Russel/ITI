/*
#include "DIO_Config.h"
 * DIO_voidSetPinDirection.c
 *
 *  Created on: Dec 20, 2016
 *      Author: Russel
 */
#include "../RemoteSystemsTempFiles/DIO_voidSetPinDirection.h"

void DIO_voidSetPinDirection(u8 Copy_DirectionRegister , u8 Copy_PinNumber , u8 Copy_PinDirection)
{
if (Copy_PinDirection == INPUT)
{
	clrBit(Copy_DirectionRegister,Copy_PinNumber);
}
else if (Copy_PinDirection == OUTPUT)
{
	setBit(Copy_DirectionRegister,Copy_PinNumber);
}
else

{}


}
