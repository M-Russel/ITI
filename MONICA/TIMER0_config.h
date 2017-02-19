/*
 * TIMER0_config.h
 *
 *  Created on: Feb 8, 2017
 *      Author: root
 */

#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_


// Timer/Counter Control Register Configuration
#define FOC0_STATUS		 DISABLED
#define WGM00_STATUS    DISABLED
#define COM01_STATUS     DISABLED
#define COM00_STATUS     DISABLED
#define WGM01_STATUS    DISABLED
#define CS02_STATUS        ENABLED
#define CS01_STATUS        DISABLED
#define CS00_STATUS        ENABLED

//Timer Interrupt Mask Register Configuration
#define OCIE2_STATUS     DISABLED
#define TOIE2_STATUS     DISABLED
#define TICIE1_STATUS     DISABLED
#define OCIE1A_STATUS   DISABLED
#define OCIE1B_STATUS   DISABLED
#define TOIE1_STATUS     DISABLED
#define OCIE0_STATUS     DISABLED
#define TOIE0_STATUS     ENABLED


#define OVERFLOW_COUNTER_INITIAL 0
#define OVERFLOW_COUNTER_MAX 15
#define TCNT0_INITIAL_VALUE 159


//Global Interrupt Configuration
#define GLOBAL_INTERRUPT_STATUS    ENABLED


//Output Compare Register

#define OCR0_VALUE

#endif /* TIMER0_CONFIG_H_ */