/*
 * Fast_PWM.c
 *
 *  Created on: Feb 26, 2017
 *      Author: Russel
 */

#include "std_types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "TIMER0_private.h"
#include "TIMER0_interface.h"
#include "TIMER0_config.h"

void main (void)
{

	DIO_voidInitialize();
	TIMER0_init();

while(1)
{}

}
