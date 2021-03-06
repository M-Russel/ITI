/*
 * DIO_Private.h
 *
 *  Created on: Dec 21, 2016
 *      Author: Russel
 *      Version : 2
 *
 */

// include after configuration

/*
 * io_ports.h
 *
 *  Created on: Dec 6, 2016
 *      Author: Russel
 */

#ifndef IO_PORTS_ATMEGA32_H_
#define IO_PORTS_ATMEGA32_H_









#define PORTA_0 0
#define PORTA_1 1
#define PORTA_2 2
#define PORTA_3 3
#define PORTA_4 4
#define PORTA_5 5
#define PORTA_6 6
#define PORTA_7 7

#define PORTB_0 0
#define PORTB_1 1
#define PORTB_2 2
#define PORTB_3 3
#define PORTB_4 4
#define PORTB_5 5
#define PORTB_6 6
#define PORTB_7 7

#define PORTC_0 0
#define PORTC_1 1
#define PORTC_2 2
#define PORTC_3 3
#define PORTC_4 4
#define PORTC_5 5
#define PORTC_6 6
#define PORTC_7 7

#define PORTD_0 0
#define PORTD_1 1
#define PORTD_2 2
#define PORTD_3 3
#define PORTD_4 4
#define PORTD_5 5
#define PORTD_6 6
#define PORTD_7 7



#define PINA_0 0
#define PINA_1 1
#define PINA_2 2
#define PINA_3 3
#define PINA_4 4
#define PINA_5 5
#define PINA_6 6
#define PINA_7 7


#define PINB_0 0
#define PINB_1 1
#define PINB_2 2
#define PINB_3 3
#define PINB_4 4
#define PINB_5 5
#define PINB_6 6
#define PINB_7 7


#define PINC_0 0
#define PINC_1 1
#define PINC_2 2
#define PINC_3 3
#define PINC_4 4
#define PINC_5 5
#define PINC_6 6
#define PINC_7 7


#define PIND_0 0
#define PIND_1 1
#define PIND_2 2
#define PIND_3 3
#define PIND_4 4
#define PIND_5 5
#define PIND_6 6
#define PIND_7 7




#endif /* IO_PORTS_ATMEGA32_H_ */


//Enumeration instead of hashs

#include "std_types.h"
#define OK 1
#define ERROR 0



#define DIO_PORT_MIN 0x00 // DIO FULL PORT AS LOW LOGIC
#define DIO_PORT_MAX 0xff //DIO FULL PORT AS HIGH LOGIC
#define DDR_A (&DDRA) // THE ADDRESS OF DATA DIRECTION REGISTER FOR PORT A
#define DDR_B (&DDRB) // THE ADDRESS OF DATA DIRECTION REGISTER FOR PORT B
#define DDR_C (&DDRC) // THE ADDRESS OF DATA DIRECTION REGISTER FOR PORT C
#define DDR_D (&DDRD) // THE ADDRESS OF DATA DIRECTION REGISTER FOR PORT D

#define PORT_A (&PORTA) //THE ADDRESS OF PORT A REGISTER
#define PORT_B (&PORTB) //THE ADDRESS OF PORT B REGISTER
#define PORT_C (&PORTC) //THE ADDRESS OF PORT C REGISTER
#define PORT_D (&PORTD) //THE ADDRESS OF PORT D REGISTER

#define PIN_A (&PINA) //THE ADDRESS OF PIN A REGISTER
#define PIN_B (&PINB)
#define PIN_C (&PINC) //THE ADDRESS OF PIN C REGISTER
#define PIN_D (&PIND) //THE ADDRESS OF PIN D REGISTER


#define REGISTER_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) REGISTER_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7)
#define REGISTER_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) 0b##V7##V6##V5##V4##V3##V2##V1##V0


#if DIO_u8PIN_0_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_0_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_1_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_1_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_2_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_2_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_3_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_3_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_4_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_4_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_5_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_5_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_6_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_6_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_7_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_7_INITIAL DIO_LOW
#endif








#if DIO_u8PIN_8_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_8_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_9_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_9_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_10_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_10_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_11_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_11_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_12_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_12_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_13_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_13_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_14_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_14_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_15_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_15_INITIAL DIO_LOW
#endif





#if DIO_u8PIN_16_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_16_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_17_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_17_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_18_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_18_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_19_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_19_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_20_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_20_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_21_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_21_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_22_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_22_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_23_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_23_INITIAL DIO_LOW
#endif



#if DIO_u8PIN_24_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_24_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_25_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_25_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_26_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_26_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_27_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_27_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_28_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_28_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_29_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_29_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_30_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_30_INITIAL DIO_LOW
#endif

#if DIO_u8PIN_31_DIRECTION == DIO_INPUT
	#define DIO_u8PIN_31_INITIAL DIO_LOW
#endif


