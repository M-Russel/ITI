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

 //u8 i , j ;

/*	u32 i,j;
	*((u8 *)0x31)=0x7e;
	*((u8 *)0x32)=0x00;

*/
u8 q,i,j,k,z,w;
//	while(1)
/*	{

		*((u8 *)0x32)=0x7e;
		for (i=0;i<65000;i++)
		{
			for (j=0 ; j <61;j++)
			{
				asm ("nop");
			}
		}
		*((u8 *)0x32)=0x00;
				for (i=0;i<65000;i++)
				{
					for (j=0 ; j <61;j++)
					{
						asm ("nop");
					}
				}
	}
*/

	Initializing();
while(1)
{
/*
	for(q=5;q>=0;q--)
	{
		PORTB=0xfD;
		SEGMENT_P(PORTA,q);
		delay_ms(2);
		for(z=60;z>=0;z--)
		{
			PORTB=0x0xf


		}


	}

	*/

/*	for(i=60;i>0;i--)
	{
		for(j=0;j<=63;j++)
		{
			PORTB=0x02;
			SEGMENT(PORTA,i%10);
			_delay_ms(2);
			PORTB=0x01;
			SEGMENT(PORTA,i/10);
			_delay_ms(2);
			PORTB=0x03;

		}

	}


*/




/*
if (PIND==0x01)
{
setBit(PORTD,1);
}
else
		{clrBit(PORTD,1);}


*/

	/*Green(SECOND);
	Orange(SECOND);
	Red(SECOND);*/
/*
for(i=60;i>0;i--)
{
	for(j=0;j<=63;j++)
	{
		PORTA=0x02;
		SEGMENT(PORTD,i%10);
		delay_ms(8);
		PORTA=0x01;
		SEGMENT(PORTD,i/10);
		delay_ms(8);
		PORTA=0x03;

	}

}


for(i=5;i>0;i--)
{
	for(j=0;j<=63;j++)
	{
		PORTA=0x02;
		SEGMENT(PORTD,i%10);
		delay_ms(8);
		PORTA=0x01;
		SEGMENT(PORTD,i/10);
		delay_ms(8);

	}

}

*/

/*
	PORTB=0x01;
	SEGMENT(PORTA,6);
	delay_ms(8);
	PORTB=0x03;
	PORTB=0x02;
	SEGMENT(PORTA,0);
	delay_ms(8);
	PORTB=0x03;
*/


//_delay_ms(8);


//1
	_delay_ms(1000);
	PORTA=0b00000010; //GND
	PORTB=0b00010000; //VCC
	_delay_ms(2);

	PORTA=0b11111101; //GND
	PORTB=0b00011110; //VCC
	_delay_ms(2);
	PORTA=0b11111111; //GND
	PORTB=0b00000000; //VCC
	_delay_ms(1000);

	PORTA=0b00000010; //GND
	PORTB=0b00100000; //VCC
	_delay_ms(2);
	PORTA=0b11111101; //GND
	PORTB=0b00111100; //VCC
	PORTA=0b11111111; //GND
		PORTB=0b00000000; //VCC
	_delay_ms(1000);

	PORTA=0b00000010; //GND
	PORTB=0b01000000; //VCC
	_delay_ms(2);
	PORTA=0b11111101; //GND
	PORTB=0b01111000; //VCC
	_delay_ms(2);
	PORTA=0b11111111; //GND
		PORTB=0b00000000; //VCC
	_delay_ms(1000);

	PORTA=0b00000010; //GND
	PORTB=0b10000000; //VCC
	_delay_ms(2);
	PORTA=0b11111101; //GND
	PORTB=0b11110000; //VCC
	_delay_ms(2);

	PORTA=0b11111111; //GND
		PORTB=0b00000000; //VCC
	_delay_ms(1000);
	PORTA=0b11111101; //GND
	PORTB=0b11000000; //VCC
	_delay_ms(1000);
	PORTA=0b11111101; //GND
	PORTB=0b11100000; //VCC

	_delay_ms(1000);
	PORTA=0b11111101; //GND
	PORTB=0b11000000; //VCC

	_delay_ms(1000);
	PORTA=0b11111101; //GND
	PORTB=0b10000000; //VCC

	_delay_ms(1000);
	PORTA=0b11111101; //GND
	PORTB=0b00000000; //VCC
	_delay_ms(1000);



/*
//2
	PORTA=0b11110111; //GND
	PORTB=0b00010000; //VCC
	delay_ms(2);
//3

	PORTA=0b11101111; //GND
	PORTB=0b00100000; //VCC
	delay_ms(2);
//4

	PORTA=0b11111101; //GND
	PORTB=0b01000000; //VCC
	delay_ms(2);

//5
	PORTA=0b11111011; //GND
	PORTB=0b00100000; //VCC
	delay_ms(2);

//6
	PORTA=0b11011111; //GND
	PORTB=0b00010000; //VCC
	delay_ms(2);
//7
	PORTA=0b10111111; //GND
	PORTB=0b00001000; //VCC
	delay_ms(2);
//8
	PORTA=0b11011111; //GND
	PORTB=0b00000100; //VCC
	delay_ms(2);

//9
	PORTA=0b11110111; //GND
	PORTB=0b00000010; //VCC
	delay_ms(2);
//10
	PORTA=0b01111111; //GND
	PORTB=0b00000001; //VCC
	delay_ms(2);

//11
	PORTA=0b10111111; //GND
	PORTB=0b00000010; //VCC
	delay_ms(2);

//12
	PORTA=0b10111111; //GND
	PORTB=0b00000010; //VCC
	delay_ms(2);
//13
	PORTA=0b11101111; //GND
	PORTB=0b00000100; //VCC
	delay_ms(2);

*/

}
}
/*PORTD=0x01;
PORTD=0x00;
asm("NOP");


PORTD=0x01;
asm("NOP");
*/

// COUNTER
/*
_delay_ms(1000);
PORTD=0x3F;//0

_delay_ms(1000);//1
PORTD=0x0C;

_delay_ms(1000);//2
PORTD=0x5B;

_delay_ms(1000);
PORTD=0x5E;//3

_delay_ms(1000);
PORTD=0x6C;//4

_delay_ms(1000);
PORTD=0x76;//5

_delay_ms(1000);
PORTD=0x77;//6

_delay_ms(1000);
PORTD=0x1C;//7

_delay_ms(1000);
PORTD=0x7F;//8
_delay_ms(1000);
PORTD=0x7E;//9
*/


