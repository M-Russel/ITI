/*
 * DIO_voidSetPortValue.c
 *
 *  Created on: Dec 20, 2016
 *      Author: Russel
 */
#include "../RemoteSystemsTempFiles/DIO_voidSetPortValue.h"


void DIO_voidSetPortValue (u8 Copy_PortName,u8 Copy_PortValue)
{

if(Copy_PortValue == HIGH)
	{
Copy_PortName=PORT_HIGH;

	}

else if (Copy_PortValue == LOW)
	{

		Copy_PortName=PORT_LOW;
	}
else
{

}

}
