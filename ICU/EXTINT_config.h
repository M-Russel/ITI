/*
 * EXTINT_config.h
 *
 *  Created on: Feb 21, 2017
 *      Author: Russel
 */

#ifndef EXTINT_CONFIG_H_
#define EXTINT_CONFIG_H_


#define ISC11_STATUS DISABLED
#define ISC10_STATUS DISABLED
#define ISC01_STATUS ENABLED
#define ISC00_STATUS ENABLED
//MCU Control and Status Register
#define ISC2_STATUS  DISABLED

//General Interrupt Control Register
#define INT1_STATUS  DISABLED
#define INT0_STATUS  ENABLED
#define INT2_STATUS  DISABLED

//General Interrupt Flag Register
#define INTF1_STATUS DISABLED
#define INTF0_STATUS ENABLED
#define INTF2_STATUS DISABLED

#define GLOBAL_INTERRUPT_STATUS    ENABLED

#endif /* EXTINT_CONFIG_H_ */
