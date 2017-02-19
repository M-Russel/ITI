/*
 * Red.c
 *
 *  Created on: Dec 13, 2016
 *      Author: Russel
 */


#include "Led_Color.h"
void Red(u32 Delay_Value){
u8 counter;

	PORTB=RED_LED;
	for (counter=MAX;counter>MIN;counter--)
	{
			SEGMENT(PORTD,counter%(TEN));
			SEGMENT(PORTA,(counter/(TEN)));
			delay_ms(Delay_Value);

	}





}
