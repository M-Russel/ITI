/*
 * Mc_Registers.h
 *
 *  Created on: Jan 23, 2017
 *      Author: Russel
 *
 */

#ifndef EXTINT_INTERFACE_H_
#define EXTINT_INTERFACE_H_

#define LED1 0
#define LED2 1
#define LED3 2
#define ZERO 0
#define MAX 4
#define ONE 1
 void __vector_1(void)__attribute__((signal,__INTR_ATTRS));
u8 EXTINT_Initialization(void);

#endif /* EXTINT_INTERFACE_H_ */
