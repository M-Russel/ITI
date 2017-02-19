/*
 * DIO_voidSetPinDirection.h
 *
 *  Created on: Dec 20, 2016
 *      Author: Russel
 */

#ifndef DIO_VOIDSETPINDIRECTION_H_
#define DIO_VOIDSETPINDIRECTION_H_

#include "types.h"
#include "bitCalc.h"



#define INPUT 0
#define OUTPUT 1

void DIO_voidSetPinDirection(u8 Copy_DirectionRegister , u8 Copy_PinNumber , u8 Copy_PinDirection);

/*
#define DIO_VOIDSETPINDIRECTION(PORT_DIRECTION_REGISTER , PIN_NUMBER , PIN_DIRECTION) do{
#if PIN_DIRECTION == OUTPUT \
	setBit(PORT_DIRECTION_REGISTER,PIN_NUMBER);\
#elif PIN_DIRECTION == INPUT \
	clrBit(PORT_DIRECTION_REGISTER,PIN_NUMBER); \
#else \
#endif\
}while(0);\

*/





#endif /* DIO_VOIDSETPINDIRECTION_H_ */
