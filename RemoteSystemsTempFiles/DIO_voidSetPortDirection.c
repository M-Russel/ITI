/*
 * DIO_voidSetPortDirection.c
 *
 *  Created on: Dec 20, 2016
 *      Author: Russel
 */

#include "../RemoteSystemsTempFiles/DIO_voidSetPortDirection.h"

void DIO_voidSetPortDirection(u8 Copy_DirectionRegister,u8 Copy_PortDirection)
{

if( Copy_PortDirection == INPUT)
{
	Copy_DirectionRegister = INPUT_PIN;

}

else if (Copy_PortDirection == OUTPUT)
{

	Copy_DirectionRegister = OUTPUT_PORT;

}

else {

	Copy_DirectionRegister = OUTPUT_PORT;
}




}
