/*
 * EXTINT_private.h
 *
 *  Created on: Feb 21, 2017
 *      Author: Russel
 */

#ifndef EXTINT_PRIVATE_H_
#define EXTINT_PRIVATE_H_

#define ENABLED 1
#define DISABLED 0

//MicroController Unit Control Register
#define MCUCR (*((volatile u8 *)0x55))
#define SE      7
#define SM2   6
#define SM1   5
#define SM0   4
#define ISC11 3
#define ISC10 2
#define ISC01 1
#define ISC00 0
//MCU Control and Status Register
#define MCUCSR (*((volatile u8 *)0x54))
#define JTD       7
#define ISC2     6
#define JTRF     4
#define WDRF   3
#define BORF    2
#define EXTRF   1
#define PORF     0

//General Interrupt Control Register
#define GICR (*((volatile u8 * )0x5B))
#define INT1  7
#define INT0  6
#define INT2  5
#define IVSEL 1
#define IVCE   0
//General Interrupt Flag Register
#define GIFR (*((volatile u8 *)0x5A))
#define INTF1 7
#define INTF0 6
#define INTF2 5


//External Interrupt signals
#define INT0_PIN 26
#define INT1_PIN 27


#define SREG (*((volatile u8 *)0x5F)) // GLOBAL INTERRUPT
#define GLOBAL_INTERRUPT                   7

#endif /* EXTINT_PRIVATE_H_ */
