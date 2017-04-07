/*
 * ADC_private.h
 *
 *  Created on: Mar 8, 2017
 *      Author: Russel
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ENABLED 1
#define DISABLED 0

#define VREF 5
#define RESOLUTION 256

#define ACSR (*((volatile u8 *)0x28))
#define ADCH (*((volatile u8 *)0x25))
#define ADCL (*((volatile u8 *)0x24))


/*****************************************************/
/*
 * ADC Multiplexer Selection Register
 * */
#define ADMUX (*((volatile u8 *)0x27))
/*
 * Reference Selection Bits:-
 * choose the reference voltage :-
 * 0 0 : AREF,Internal Vref turned off
 * 0 1 : AVCC with external capacitor at AREF pin
 * 1 0 : Reserved
 * 1 1 : Internal 2.56V Voltage Reference with external capacitor at AREF pin
 *
 **/
#define REFS1 7
#define REFS0 6
/*
 * ADC Left Adjust Result :-
 * 1 : Left Adjust ADC
 * 0: Right Adjust ADC
 * */
#define ADLAR 5
/*
 * 4:0 (Analog Channel and Gain Selection Bits
 * choosing the channels from ADC0 : ADC7
 * 2^5=32 different conditions
 */
#define MUX4 4
#define MUX3 3
#define MUX2 2
#define MUX1 1
#define MUX0 0

/*******************************************************/

/*
 * ADC Control and Status Register A
 * */





#define ADCSRA (*((volatile u8 *)0x26))

/*
 *  ADC Enable
 *  */
#define ADEN   7
/*
 * SDC Start Conversion
 */
#define ADSC   6
/*
 * ADC Auto Trigger Enable
 */
#define ADATE 5
/*
 * ADC Interrupt Flag
 */
#define ADIF    4
/*
 * ADC Interrupt Enable
 */
#define ADIE    3
/*
 * 2:0(ADC Prescaler Select Bits)
 * Division Factor
 *
 * 0 0 0 :  2
 * 0 0 1 :  2
 * 0 1 0 :  4
 * 0 1 1 :  8
 * 1 0 0 : 16
 * 1 0 1 : 32
 * 1 1 0 : 64
 * 1 1 1 : 128
 */
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0

/**************************************************************/
/*
 * Special Function I/O Register
 */
#define SFIOR (*((volatile u8 *)0x50))

/* 7:5(ADC Auto Trigger Source)
 *  Whenever ADATE is set to ‘1’, these bits determine the trigger source for ADC conversion.
 *  There are 8 possible trigger sources.
 */

#define ADTS2 7
#define ADTS1 6
#define ADTS0 5

#define SREG (*((u8 *)0x5F)) // GLOBAL INTERRUPT
#define GLOBAL_INTERRUPT                   7



#define ADC_REGISTER_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) ADC_REGISTER_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7)
#define ADC_REGISTER_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) 0b##V0##V1##V2##V3##V4##V5##V6##V7

#endif /* ADC_PRIVATE_H_ */
