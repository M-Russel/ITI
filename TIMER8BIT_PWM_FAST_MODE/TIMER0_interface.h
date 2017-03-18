/*
 * TIMER0_interface.h
 *
 *  Created on: Feb 8, 2017
 *      Author: root
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


void TIMER0_init(void);
void __vector_11(void) __attribute__((signal,__INTR_ATTRS));

#endif /* TIMER0_INTERFACE_H_ */
