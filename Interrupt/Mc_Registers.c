/*
 * Mc_Registers.c
 *
 *  Created on: Jan 23, 2017
 *      Author: root
 */
#include "std_types.h"
#include "utils.h"
#include "io_ports_atmega32.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "DIO_voidInitialize.h"
#include "delay_ms.h"
#include "avr/interrupt.h"
#include "Mc_Registers.h"

u8 INT0_Initialization(void)
{
/* MCUCR
	MCU Control Register has for bits that we can change
			ISC11  ISC10  ISC01  ISC00
		Interrupt Sense Control
		to choose the when will the microcontroller feels the interrupt
		we change ISC11 ISC10


	*/
	clrBit(MCUCR,PIN0);
	setBit(MCUCR,PIN1);
	setBit(GICR,PIN6);
	setBit(GIFR,PIN6);
	setBit(SREG,PIN7);


return OK;
}
