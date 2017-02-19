/*
 * switch.h
 *
 *  Created on: Jan 12, 2017
 *      Author: Russel
 */

#ifndef SWITCH_H_
#define SWITCH_H_
#define RELEASED 0
#define PUSHED 1
#define PRE_RELEASED 2
#define PRE_PUSHED 3
#define THREESHOLD_MINIMUM 0
#define THREESHOLD_MAXIMUM 10
#define LOOP_MAXIMUM 1
#define LOOP_MINIMUM 0
#define OK 0
#define ERROR 1

#define SWITCH_0 PIN_0
#define SWITCH_1 PIN_1
#define SWITCH_2 PIN_2
#define SWITCH_3 PIN_3
#define SWITCH_4 PIN_4
#define SWITCH_5 PIN_5
#define SWITCH_6 PIN_6
#define SWITCH_7 PIN_7

#define SWITCH_8 PIN_8
#define SWITCH_9 PIN_9
#define SWITCH_10 PIN_10
#define SWITCH_11 PIN_11
#define SWITCH_12 PIN_12
#define SWITCH_13 PIN_13
#define SWITCH_14 PIN_14
#define SWITCH_15 PIN_15

#define SWITCH_16 PIN_16
#define SWITCH_17 PIN_17
#define SWITCH_18 PIN_18
#define SWITCH_19 PIN_19
#define SWITCH_20 PIN_20
#define SWITCH_21 PIN_21
#define SWITCH_22 PIN_22
#define SWITCH_23 PIN_23

#define SWITCH_24 PIN_24
#define SWITCH_24 PIN_24
#define SWITCH_25 PIN_25
#define SWITCH_26 PIN_26
#define SWITCH_27 PIN_27
#define SWITCH_28 PIN_28
#define SWITCH_29 PIN_29
#define SWITCH_30 PIN_30
#define SWITCH_31 PIN_31


u8 SWITCH_voidDebounceDelay();
u8 SWITCH_u8GetStatus(u8 Copy_u8PinNumber,pu8 Copy_pu8PinStatus);


#endif /* SWITCH_H_ */
