/*
 * DIO_voidSetPortDirection.h
 *
 *  Created on: Dec 20, 2016
 *      Author: Russel
 */

#ifndef DIO_VOIDSETPORTDIRECTION_H_
#define DIO_VOIDSETPORTDIRECTION_H_

#include "types.h"
#include "io_ports_atmega32.h"
#define INPUT 0
#define OUTPUT 1
#define INPUT_PIN 0x00
#define OUTPUT_PORT 0xff
void DIO_voidSetPortDirection(u8 Copy_DirectionRegister,u8 Copy_PortDirection);

#endif /* DIO_VOIDSETPORTDIRECTION_H_ */
