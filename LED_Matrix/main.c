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
#include "led_matrix_names.h"
#define F_CPU 4000000
void main (void)
{

	u8 counter=0;


DDRA=0xff;
DDRD=0xff;
	while(1)
	{

//THE R
		for (counter = 0; counter <= 7; counter++) {
			PORTA = R[counter][0];
			PORTD = 0b00000001;
			delay_ms(3);
			PORTA = 0x00;
			PORTD = 0x00;
			delay_ms(4);

			PORTA = R[counter][1];
			PORTD = 0b00000010;
			delay_ms(3);

			PORTA = 0x00;
			PORTD = 0x00;
			delay_ms(4);

			PORTA = R[counter][2];
			PORTD = 0b00000100;
			delay_ms(3);
			PORTA = 0x00;
			PORTD = 0x00;
			delay_ms(4);
			PORTA = R[counter][3];
			PORTD = 0b00001000;
			delay_ms(3);
			PORTA = 0x00;
			PORTD = 0x00;
			delay_ms(4);
			PORTA = R[counter][4];
			PORTD = 0b00010000;
			delay_ms(3);
			PORTA = 0x00;
			PORTD = 0x00;
			delay_ms(4);

			PORTA = R[counter][5];
			PORTD = 0b00100000;
			delay_ms(3);
			PORTA = 0x00;
			PORTD = 0x00;
			delay_ms(4);

			PORTA = R[counter][6];
			PORTD = 0b01000000;
			delay_ms(3);
			PORTA = 0x00;
			PORTD = 0x00;
			delay_ms(4);

			PORTA = R[counter][7];
			PORTD = 0b10000000;
			delay_ms(3);
			PORTA = 0x00;
			PORTD = 0x00;
			delay_ms(4);

		}

//THE U
		for (counter = 0; counter <= 11; counter++) {
					PORTA = U[counter][0];
					PORTD = 0b00000001;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);

					PORTA = U[counter][1];
					PORTD = 0b00000010;
					delay_ms(3);

					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);

					PORTA = U[counter][2];
					PORTD = 0b00000100;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);
					PORTA = U[counter][3];
					PORTD = 0b00001000;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);
					PORTA = U[counter][4];
					PORTD = 0b00010000;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);

					PORTA = U[counter][5];
					PORTD = 0b00100000;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);

					PORTA = U[counter][6];
					PORTD = 0b01000000;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);

					PORTA = U[counter][7];
					PORTD = 0b10000000;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);

					PORTA = U[counter][8];
					PORTD = 0b00000001;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);

					PORTA = U[counter][9];
					PORTD = 0b00000010;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);

					PORTA = U[counter][10];
					PORTD = 0b00000100;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);

					PORTA = U[counter][11];
					PORTD = 0b0001000;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);


				}


//THE S1
		for (counter = 0; counter <= 9; counter++) {
					PORTA = S1[counter][0];
					PORTD = 0b00000001;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);

					PORTA = S1[counter][1];
					PORTD = 0b00000010;
					delay_ms(3);

					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);

					PORTA = S1[counter][2];
					PORTD = 0b00000100;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);
					PORTA = S1[counter][3];
					PORTD = 0b00001000;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);
					PORTA = S1[counter][4];
					PORTD = 0b00010000;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);

					PORTA = S1[counter][5];
					PORTD = 0b00100000;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);

					PORTA = S1[counter][6];
					PORTD = 0b01000000;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);

					PORTA = S1[counter][7];
					PORTD = 0b10000000;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);

					PORTA = S1[counter][8];
					PORTD = 0b00000001;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);

					PORTA = S1[counter][9];
					PORTD = 0b00000010;
					delay_ms(3);
					PORTA = 0x00;
					PORTD = 0x00;
					delay_ms(4);




	}

//THE S2
		for (counter = 0; counter <= 9; counter++) {
							PORTA = S1[counter][0];
							PORTD = 0b00000001;
							delay_ms(3);
							PORTA = 0x00;
							PORTD = 0x00;
							delay_ms(4);

							PORTA = S1[counter][1];
							PORTD = 0b00000010;
							delay_ms(3);

							PORTA = 0x00;
							PORTD = 0x00;
							delay_ms(4);

							PORTA = S1[counter][2];
							PORTD = 0b00000100;
							delay_ms(3);
							PORTA = 0x00;
							PORTD = 0x00;
							delay_ms(4);
							PORTA = S1[counter][3];
							PORTD = 0b00001000;
							delay_ms(3);
							PORTA = 0x00;
							PORTD = 0x00;
							delay_ms(4);
							PORTA = S1[counter][4];
							PORTD = 0b00010000;
							delay_ms(3);
							PORTA = 0x00;
							PORTD = 0x00;
							delay_ms(4);

							PORTA = S1[counter][5];
							PORTD = 0b00100000;
							delay_ms(3);
							PORTA = 0x00;
							PORTD = 0x00;
							delay_ms(4);

							PORTA = S1[counter][6];
							PORTD = 0b01000000;
							delay_ms(3);
							PORTA = 0x00;
							PORTD = 0x00;
							delay_ms(4);

							PORTA = S1[counter][7];
							PORTD = 0b10000000;
							delay_ms(3);
							PORTA = 0x00;
							PORTD = 0x00;
							delay_ms(4);

							PORTA = S1[counter][8];
							PORTD = 0b00000001;
							delay_ms(3);
							PORTA = 0x00;
							PORTD = 0x00;
							delay_ms(4);

							PORTA = S1[counter][9];
							PORTD = 0b00000010;
							delay_ms(3);
							PORTA = 0x00;
							PORTD = 0x00;
							delay_ms(4);




			}




}}
