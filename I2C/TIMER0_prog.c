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

u16 TIMER0_u16OverFlowCounter=TIMER0_OVERFLOW_COUNTER_INITIAL;

void (* TIMER0_voidCallBack) (void);


void TIMER0_voidSetTimerCallBack(void (* Copy_voidCallBackFunction)(void))
{
	TIMER0_voidCallBack=Copy_voidCallBackFunction;
}
void TIMER0_init(void)
{
//	SREG=SREG_ENABLED; // global enable
//	TIMSK=TIMER0_ENABLED; // enable timer 0
//TCCR0=0x05; // prescaler and working mood
	TCNT0=TCNT0_INITIAL_VALUE; // Timer initial value

TCCR0=TIMER0_REGISTER_VALUE(FOC0_STATUS,WGM00_STATUS,
		COM01_STATUS,COM00_STATUS,WGM01_STATUS,CS02_STATUS,CS01_STATUS,CS00_STATUS);

//	TCCR0|=(FOC0_STATUS<<FOC0)|(WGM00_STATUS<<WGM00)|(COM01_STATUS<<COM01)|(COM00_STATUS<<COM00)
//					|(WGM01_STATUS<<WGM01)|(CS02_STATUS<<CS02)|(CS01_STATUS<<CS01)|(CS00_STATUS<<CS00);


TIMSK=TIMER0_REGISTER_VALUE(OCIE2_STATUS, TOIE2_STATUS, TICIE1_STATUS,
		OCIE1A_STATUS, OCIE1B_STATUS, TOIE1_STATUS, OCIE0_STATUS, TOIE0_STATUS);

//	TIMSK|=(OCIE0_STATUS<<OCIE0)|(TOIE0_STATUS<<TOIE0);
	//TIFR |=(OCF0_STATUS<<OCF0)|(TOV0_STATUS<<TOV0);
	SREG=(GLOBAL_INTERRUPT_STATUS<<GLOBAL_INTERRUPT);


}
void __vector_11(void)
{
	TIMER0_u16OverFlowCounter++;
	if (TIMER0_OVERFLOW_COUNTER_MAX==TIMER0_u16OverFlowCounter)
	{
		TIMER0_voidCallBack();
		TIMER0_u16OverFlowCounter=TIMER0_OVERFLOW_COUNTER_INITIAL;
		TCNT0=TCNT0_INITIAL_VALUE;
	}
	else {}
}

