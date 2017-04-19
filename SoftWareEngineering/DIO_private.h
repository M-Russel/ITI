/*
 * DIO_Private.h
 *
 *  Created on: Apr 4, 2017
 *      Author: Russel
 *      Version : 1
 */


/*
 * io_ports.h
 *
 *  Created on: Dec 6, 2016
 *      Author: Russel
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_




/*
 * REGISTER_VALUE
*This macro just concatenate the input parameters sent through it
*we have used these two macros trick because this is what should be done while trying to concatenate
*variables which are already another macro so it takes the input parameters and put them in reverse
*way to make V7=MSB and V0=LSB
*so the user can assign them from 0:7 which makes more sense
*/
#define REGISTER_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) REGISTER_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7)
#define REGISTER_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) 0b##V7##V6##V5##V4##V3##V2##V1##V0

/*
 * the following preprocessing macros are to prevent the user to set a pin as input
 * and then assign a value to it which will change its physical behavior from pull down to pull up
 * */
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



#endif /* DIO_PRIVATE_H_*/
