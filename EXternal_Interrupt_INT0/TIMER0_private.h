/*
 * TIMER0_private.h
 *
 *  Created on: Feb 8, 2017
 *      Author: root
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCNT0 (*((volatile u8 *)0x52)) //VALUE OF THE COUNTER

#define OCR0 (*((volatile u8 *)0x5C))

#define ENABLED 1
#define DISABLED 0


#define SREG_ENABLED 0x80
#define SREG_DISABLED 0x00
#define TIMER0_ENABLED 0x01


// Timer/Counter Control Register
#define TCCR0 (*((volatile u8 *)0x53))

#define FOC0 7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02  2
#define CS01  1
#define CS00  0



//Timer Interrupt Mask Register TIMSK
#define TIMSK (*((volatile u8 *)0x59))



#define OCIE2      7
#define TOIE2      6
#define TICIE1      5
#define OCIE1A    4
#define OCIE1B    3
#define TOIE1      2
#define OCIE0      1
#define TOIE0      0

//TIMER INTERRUPT FLAG REGISTER TIFR
#define TIFR volatile(*((u8 *)0x58))

#define OCF2    7
#define TOV2    6
#define ICF1      5
#define OCF1A  4
#define OCF1B  3
#define TOV1    2
#define OCF0    1
#define TOV0    0


//
#define SREG (*((volatile u8 *)0x5F)) // GLOBAL INTERRUPT
#define GLOBAL_INTERRUPT                   7



#endif /* TIMER0_PRIVATE_H_ */
