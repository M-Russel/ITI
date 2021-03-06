/*
 * EXTINT_prog.c
 *
 *  Created on: Jan 23, 2017
 *      Author: Russel
 */
#include "std_types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"


#include "EXTINT_config.h"
#include "EXTINT_Interface.h"
#include "EXTINT_private.h"
u8 EXTINT_Initialization(void)
{
/* MCUCR
	MCU Control Register has for bits that we can change
			ISC11  ISC10  ISC01  ISC00
		Interrupt Sense Control
		to choose the when will the microcontroller feels the interrupt
		we change ISC11 ISC10


	*/
/*
	clrBit(MCUCR,PIN0);
	setBit(MCUCR,PIN1);
	setBit(GICR,PIN6);
	setBit(GIFR,PIN6);
	setBit(SREG,PIN7);
*/


	MCUCR|=(ISC11_STATUS<<ISC11)|(ISC10_STATUS<<ISC10)|(ISC01_STATUS<<ISC01)|(ISC00_STATUS<<ISC00);
	GICR |=(INT1_STATUS<<INT1)|(INT0_STATUS<<INT0)|(INT2_STATUS<<INT2);
	GIFR |=(INTF1_STATUS<<INTF1)|(INTF0_STATUS<<INTF0)|(INTF2_STATUS<<INTF2);
	SREG|=(GLOBAL_INTERRUPT_STATUS<<GLOBAL_INTERRUPT);

return OK;
}
