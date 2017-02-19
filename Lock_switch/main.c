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
u8 i=3,Counter=3;
DDRD=0x7f; // THE SEVEN SEGMENT'S PORT
DDRA=0x00; // THE SWITCH INPUT PORT
DDRC=0x03; // THE LED OUTPUT
DDRB=0xfE;
while(1)
{

SEGMENT(PORTD,(Counter));


if(PINB & (1<<0))
{
	_delay_ms(300);
		if ( ((getBit(PINA,0))==1) &&
			 ((getBit(PINA,1))==0) &&
			 ((getBit(PINA,2))==1) &&
			 ((getBit(PINA,3))==0) &&
			 ((getBit(PINA,4))==1) &&
			 ((getBit(PINA,5))==0)
			)

		{
			if (Counter==0)
						{
							while(1)
							{
								PORTC=0x02;
								delay_ms(500);
								PORTC=0x00;
								delay_ms(500);

							}
						}
			else{
				 _delay_ms(100);
					while(1)
					{
					  PORTC=0x01;
					}
				}
		}

		else if(!(((getBit(PINA,0))==1) &&
				 ((getBit(PINA,1))==0) &&
				 ((getBit(PINA,2))==1) &&
				 ((getBit(PINA,3))==0) &&
				 ((getBit(PINA,4))==1) &&
				 ((getBit(PINA,5))==0) )
				)
		{
			 if (Counter==0)
			{
				while(1)
				{
					PORTC=0x02;
					delay_ms(500);
					PORTC=0x00;
					delay_ms(500);

				}
			}
			else if ((PINB & (1<<0)) && Counter >0)
			{
				Counter --;
				SEGMENT(PORTD,Counter)
			}

			}
		}



else {

	PORTC=0x00;
}
i--;
}


}

