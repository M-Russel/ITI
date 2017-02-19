/*
 * Red.c
 *
 *  Created on: Dec 13, 2016
 *      Author: Russel
 */

#include "Led_Color.h"


void Orange(u32 Delay_Value){
	u8 counter;


PORTB=ORANGE_LED;
//		_delay_ms(1000);


		for (counter=MAX_WAIT;counter>MIN;counter--)
		{
			SEGMENT(PORTA,ZERO);
			SEGMENT(PORTD,(int)(counter%(TEN)));
			delay_ms(Delay_Value);
		}
}
