/*
 * DIO_voidSetPortValue.h
 *
 *  Created on: Dec 20, 2016
 *      Author: Russel
 */

#ifndef DIO_VOIDSETPORTVALUE_H_
#define DIO_VOIDSETPORTVALUE_H_

#include "types.h"
#include "io_ports_atmega32.h"
#define LOW 0
#define HIGH 1
#define PORT_HIGH 0xff
#define PORT_LOW 0x00

void DIO_voidSetPortValue (u8 Copy_PortName,u8 Copy_PortValue);



#endif /* DIO_VOIDSETPORTVALUE_H_ */
