/*
 * DIO_voidSetPinValue.h
 *
 *  Created on: Dec 20, 2016
 *      Author: Russel
 */

#ifndef DIO_VOIDSETPINVALUE_H_
#define DIO_VOIDSETPINVALUE_H_

#include "types.h"
#include "io_ports_atmega32.h"
#include "bitCalc.h"

#define HIGH 1
#define LOW 0

void DIO_voidSetPinValue (u8 Copy_PortName,u8 Copy_PinNumber,u8 Copy_PinValue);

#endif /* DIO_VOIDSETPINVALUE_H_ */
