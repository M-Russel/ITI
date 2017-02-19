/*
 * main.c


 *
 *  Created on: Dec 5, 2016
 *      Author: Russel
 */
#include <stdio.h>
#include "delay_ms.h"
#include <util/delay.h>
#include "io_ports_atmega32.h"
#include "types.h"
#include "Seven_Segment.h"
#include "Seven_Switch.h"
#include "Led_Color.h"
#include "Initializing.h"
#include "bitCalc.h"
#include "Seven_Segment_p.h"
#define F_CPU 4000000
void main (void)
{


	u8 minute_counter,seconds_counter,mil_counter;
	//int IM,JM,JK;
	DDRD=0xff;
	DDRC=0xff;


	for (minute_counter = 4 ; minute_counter>=0;minute_counter --)
	{
		for (seconds_counter = 59 ; seconds_counter>0;seconds_counter --)
			{

				for (mil_counter = 65 ; mil_counter>0;mil_counter --)
				{

					PORTC=0xDF;
					SEGMENT(PORTD,((mil_counter+29)%10));
					delay_ms(1);
					PORTC=0xff;
					delay_ms(2);

					PORTC=0xEF;
					SEGMENT(PORTD,((mil_counter+29)/10));
					delay_ms(1);
					PORTC=0xff;
					delay_ms(2);

					PORTC=0xF7;
					SEGMENT(PORTD,((seconds_counter)%10));
					delay_ms(2);
					PORTC=0xff;
					delay_ms(2);

					PORTC=0xFB;
					SEGMENT(PORTD,((seconds_counter)/10));
					delay_ms(2);
					PORTC=0xff;
					delay_ms(1);

					PORTC=0xFD;
					SEGMENT(PORTD,(minute_counter));
					delay_ms(2);
					PORTC=0xff;
					delay_ms(1);

					PORTC=0xFE;
					SEGMENT(PORTD,0);
					delay_ms(2);
					PORTC=0xff;
					delay_ms(1);
				}

			}

	}

	while(1)
	{
		PORTC=0xff;

	}
}

