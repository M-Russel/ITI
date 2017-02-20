/*
 * Initializing.h
 *
 *  Created on: Dec 13, 2016
 *      Author: Russel
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#define DIO_INPUT 0 //DIO_INPUT VALUE
#define DIO_OUTPUT 1 // DIO_OUTPUT VALUE

#define DIO_LOW 0
#define DIO_HIGH 1


/****************************
 * DIRECTION  FOR PORTS  *
 * **************************/


#define DIO_u8PINA_0_DIRECTION DIO_OUTPUT
#define DIO_u8PINA_1_DIRECTION DIO_OUTPUT
#define DIO_u8PINA_2_DIRECTION DIO_OUTPUT
#define DIO_u8PINA_3_DIRECTION DIO_OUTPUT
#define DIO_u8PINA_4_DIRECTION DIO_OUTPUT
#define DIO_u8PINA_5_DIRECTION DIO_OUTPUT
#define DIO_u8PINA_6_DIRECTION DIO_OUTPUT
#define DIO_u8PINA_7_DIRECTION DIO_OUTPUT

#define DIO_u8PINB_0_DIRECTION DIO_INPUT
#define DIO_u8PINB_1_DIRECTION DIO_INPUT
#define DIO_u8PINB_2_DIRECTION DIO_INPUT
#define DIO_u8PINB_3_DIRECTION DIO_INPUT
#define DIO_u8PINB_4_DIRECTION DIO_INPUT
#define DIO_u8PINB_5_DIRECTION DIO_INPUT
#define DIO_u8PINB_6_DIRECTION DIO_INPUT
#define DIO_u8PINB_7_DIRECTION DIO_INPUT


#define DIO_u8PINC_0_DIRECTION DIO_INPUT
#define DIO_u8PINC_1_DIRECTION DIO_INPUT
#define DIO_u8PINC_2_DIRECTION DIO_INPUT
#define DIO_u8PINC_3_DIRECTION DIO_INPUT
#define DIO_u8PINC_4_DIRECTION DIO_INPUT
#define DIO_u8PINC_5_DIRECTION DIO_INPUT
#define DIO_u8PINC_6_DIRECTION DIO_INPUT
#define DIO_u8PINC_7_DIRECTION DIO_INPUT


#define DIO_u8PIND_0_DIRECTION DIO_INPUT
#define DIO_u8PIND_1_DIRECTION DIO_INPUT
#define DIO_u8PIND_2_DIRECTION DIO_INPUT
#define DIO_u8PIND_3_DIRECTION DIO_INPUT
#define DIO_u8PIND_4_DIRECTION DIO_INPUT
#define DIO_u8PIND_5_DIRECTION DIO_INPUT
#define DIO_u8PIND_6_DIRECTION DIO_INPUT
#define DIO_u8PIND_7_DIRECTION DIO_INPUT

/****************************
 * INITIAL VALUES FOR PORTS *
 * **************************/



//PORT A INITIAL VALUES
#define DIO_u8PINA_0_INITIAL DIO_LOW
#define DIO_u8PINA_1_INITIAL DIO_LOW
#define DIO_u8PINA_2_INITIAL DIO_LOW
#define DIO_u8PINA_3_INITIAL DIO_LOW
#define DIO_u8PINA_4_INITIAL DIO_LOW
#define DIO_u8PINA_5_INITIAL DIO_LOW
#define DIO_u8PINA_6_INITIAL DIO_LOW
#define DIO_u8PINA_7_INITIAL DIO_LOW


//PORT B INITIAL VALUES
#define DIO_u8PINB_0_INITIAL DIO_LOW
#define DIO_u8PINB_1_INITIAL DIO_LOW
#define DIO_u8PINB_2_INITIAL DIO_LOW
#define DIO_u8PINB_3_INITIAL DIO_LOW
#define DIO_u8PINB_4_INITIAL DIO_LOW
#define DIO_u8PINB_5_INITIAL DIO_LOW
#define DIO_u8PINB_6_INITIAL DIO_LOW
#define DIO_u8PINB_7_INITIAL DIO_LOW


//PORT C INITIAL VALUES
#define DIO_u8PINC_1_INITIAL DIO_LOW
#define DIO_u8PINC_2_INITIAL DIO_LOW
#define DIO_u8PINC_3_INITIAL DIO_LOW
#define DIO_u8PINC_4_INITIAL DIO_LOW
#define DIO_u8PINC_5_INITIAL DIO_LOW
#define DIO_u8PINC_6_INITIAL DIO_LOW
#define DIO_u8PINC_7_INITIAL DIO_LOW

//PORT D INITIAL VALUES
#define DIO_u8PIND_0_INITIAL DIO_LOW
#define DIO_u8PIND_1_INITIAL DIO_LOW
#define DIO_u8PIND_2_INITIAL DIO_LOW
#define DIO_u8PIND_3_INITIAL DIO_LOW
#define DIO_u8PIND_4_INITIAL DIO_LOW
#define DIO_u8PIND_5_INITIAL DIO_LOW
#define DIO_u8PIND_6_INITIAL DIO_LOW
#define DIO_u8PIND_7_INITIAL DIO_LOW







#if DIO_u8PINA_0_DIRECTION == DIO_INPUT
	#define DIO_u8PINA_0_INITIAL DIO_LOW
#endif

#if DIO_u8PINA_1_DIRECTION == DIO_INPUT
	#define DIO_u8PINA_1_INITIAL DIO_LOW
#endif

#if DIO_u8PINA_2_DIRECTION == DIO_INPUT
	#define DIO_u8PINA_2_INITIAL DIO_LOW
#endif

#if DIO_u8PINA_3_DIRECTION == DIO_INPUT
	#define DIO_u8PINA_3_INITIAL DIO_LOW
#endif

#if DIO_u8PINA_4_DIRECTION == DIO_INPUT
	#define DIO_u8PINA_4_INITIAL DIO_LOW
#endif

#if DIO_u8PINA_5_DIRECTION == DIO_INPUT
	#define DIO_u8PINA_5_INITIAL DIO_LOW
#endif

#if DIO_u8PINA_6_DIRECTION == DIO_INPUT
	#define DIO_u8PINA_6_INITIAL DIO_LOW
#endif

#if DIO_u8PINA_7_DIRECTION == DIO_INPUT
	#define DIO_u8PINA_7_INITIAL DIO_LOW
#endif








#if DIO_u8PINC_0_DIRECTION == DIO_INPUT
	#define DIO_u8PINC_0_INITIAL DIO_LOW
#endif

#if DIO_u8PINC_1_DIRECTION == DIO_INPUT
	#define DIO_u8PINC_1_INITIAL DIO_LOW
#endif

#if DIO_u8PINC_2_DIRECTION == DIO_INPUT
	#define DIO_u8PINC_2_INITIAL DIO_LOW
#endif

#if DIO_u8PINC_3_DIRECTION == DIO_INPUT
	#define DIO_u8PINC_3_INITIAL DIO_LOW
#endif

#if DIO_u8PINC_4_DIRECTION == DIO_INPUT
	#define DIO_u8PINC_4_INITIAL DIO_LOW
#endif

#if DIO_u8PINC_5_DIRECTION == DIO_INPUT
	#define DIO_u8PINC_5_INITIAL DIO_LOW
#endif

#if DIO_u8PINC_6_DIRECTION == DIO_INPUT
	#define DIO_u8PINC_6_INITIAL DIO_LOW
#endif

#if DIO_u8PINC_7_DIRECTION == DIO_INPUT
	#define DIO_u8PINC_7_INITIAL DIO_LOW
#endif





#if DIO_u8PIND_0_DIRECTION == DIO_INPUT
	#define DIO_u8PIND_0_INITIAL DIO_LOW
#endif

#if DIO_u8PIND_1_DIRECTION == DIO_INPUT
	#define DIO_u8PIND_1_INITIAL DIO_LOW
#endif

#if DIO_u8PIND_2_DIRECTION == DIO_INPUT
	#define DIO_u8PIND_2_INITIAL DIO_LOW
#endif

#if DIO_u8PIND_3_DIRECTION == DIO_INPUT
	#define DIO_u8PIND_3_INITIAL DIO_LOW
#endif

#if DIO_u8PIND_4_DIRECTION == DIO_INPUT
	#define DIO_u8PIND_4_INITIAL DIO_LOW
#endif

#if DIO_u8PIND_5_DIRECTION == DIO_INPUT
	#define DIO_u8PIND_5_INITIAL DIO_LOW
#endif

#if DIO_u8PIND_6_DIRECTION == DIO_INPUT
	#define DIO_u8PIND_6_INITIAL DIO_LOW
#endif

#if DIO_u8PIND_7_DIRECTION == DIO_INPUT
	#define DIO_u8PIND_7_INITIAL DIO_LOW
#endif



#endif /* DIO_CONFIG_H_ */