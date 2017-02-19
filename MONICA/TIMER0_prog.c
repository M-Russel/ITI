/*
 * TIMER0_prog.c
 *
 *  Created on: Feb 8, 2017
 *      Author: root
 */

#include "std_types.h"
#include "utils.h"
#include "TIMER0_config.h"
#include "TIMER0_private.h"
#include "TIMER0_interface.h"




void TIMER0_init(void)
{
//	SREG=SREG_ENABLED; // global enable
//	TIMSK=TIMER0_ENABLED; // enable timer 0
//TCCR0=0x05; // prescaler and working mood
	TCNT0=TCNT0_INITIAL_VALUE; // Timer initial value



	TCCR0|=(FOC0_STATUS<<FOC0)|(WGM00_STATUS<<WGM00)|(COM01_STATUS<<COM01)|(COM00_STATUS<<COM00)
					|(WGM01_STATUS<<WGM01)|(CS02_STATUS<<CS02)|(CS01_STATUS<<CS01)|(CS00_STATUS<<CS00);


	TIMSK|=(OCIE2_STATUS<<OCIE2)|(TOIE2_STATUS<<TOIE2)|(TICIE1_STATUS<<TICIE1)|(OCIE1A_STATUS<<OCIE1A)
						|(OCIE1B_STATUS<<OCIE1B)|(TOIE1_STATUS<<TOIE1)|(OCIE0_STATUS<<OCIE0)|(TOIE0_STATUS<<TOIE0);

	SREG|=(GLOBAL_INTERRUPT_STATUS<<GLOBAL_INTERRUPT);

}