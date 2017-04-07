/*
 * TIMER0_interface.h
 *
 *  Created on: Feb 8, 2017
 *      Author: root
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#define TCNT0 (*((u8 *)0x52)) //VALUE OF THE COUNTER

/*
 * For Crystal = 4M/HZ
 * Prescaler = 1
 * Tic = 10 ms;
 *#define TIMER0_OVERFLOW_COUNTER_INITIAL 0
 *#define TIMER0_OVERFLOW_COUNTER_MAX 157
 *#define TCNT0_INITIAL_VALUE 192
 *
 */


/*
 * For Crystal = 4M/HZ
 * Prescaler = 1
 * Tic = 2 ms;
 */
 #define TIMER0_OVERFLOW_COUNTER_INITIAL 0
 #define TIMER0_OVERFLOW_COUNTER_MAX 32
 #define TCNT0_INITIAL_VALUE 192



void TIMER0_init(void);
void __vector_11(void) __attribute__((signal,__INTR_ATTRS));
void TIMER0_voidSetTimerCallBack(void (* Copy_voidCallBackFunction)(void));

#endif /* TIMER0_INTERFACE_H_ */
