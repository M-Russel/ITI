/*
 * io_ports.h
 *
 *  Created on: Dec 6, 2016
 *      Author: Russel
 */

#ifndef IO_PORTS_ATMEGA32_H_
#define IO_PORTS_ATMEGA32_H_

#define DDRA (*((u8 *)0x3A))    //Data Direction Register For Port A
#define PORTA (*((u8 *)0x3B))  //Output for Port A
#define PINA (*((u8 *)0x39))  //Input for Port A
#define DDRB (*((u8 *)0x37))   //Data Direction Register For Port B
#define PORTB (*((u8 *)0x38)) //Output Register for Port B
#define PINB (*((u8 *)0x36)) //Input Register for Port B
#define DDRC (*((u8 *)0x34))   //Data Direction Register For Port C
#define PORTC (*((u8 *)0x35)) //Output Register for Port C
#define PINC (*((u8 *)0x33)) //Input Register for Port C
#define DDRD (*((u8 *)0x31))   //Data Direction Register For Port D
#define PORTD (*((u8 *)0x32)) //Output Register for Port D
#define PIND (*((u8 *)0x30)) //Input Register for Port D
#define MCUCR  (*((u8 *)0x55))
#define GICR  (*((u8 *)0x5B))
#define GIFR  (*((u8 *)0x5A))
#define SREG  (*((u8 *)0x5F))




#define PORTA_0 0
#define PORTA_1 1
#define PORTA_2 2
#define PORTA_3 3
#define PORTA_4 4
#define PORTA_5 5
#define PORTA_6 6
#define PORTA_7 7

#define PORTB_0 0
#define PORTB_1 1
#define PORTB_2 2
#define PORTB_3 3
#define PORTB_4 4
#define PORTB_5 5
#define PORTB_6 6
#define PORTB_7 7

#define PORTC_0 0
#define PORTC_1 1
#define PORTC_2 2
#define PORTC_3 3
#define PORTC_4 4
#define PORTC_5 5
#define PORTC_6 6
#define PORTC_7 7

#define PORTD_0 0
#define PORTD_1 1
#define PORTD_2 2
#define PORTD_3 3
#define PORTD_4 4
#define PORTD_5 5
#define PORTD_6 6
#define PORTD_7 7



#define PINA_0 0
#define PINA_1 1
#define PINA_2 2
#define PINA_3 3
#define PINA_4 4
#define PINA_5 5
#define PINA_6 6
#define PINA_7 7


#define PINB_0 0
#define PINB_1 1
#define PINB_2 2
#define PINB_3 3
#define PINB_4 4
#define PINB_5 5
#define PINB_6 6
#define PINB_7 7


#define PINC_0 0
#define PINC_1 1
#define PINC_2 2
#define PINC_3 3
#define PINC_4 4
#define PINC_5 5
#define PINC_6 6
#define PINC_7 7


#define PIND_0 0
#define PIND_1 1
#define PIND_2 2
#define PIND_3 3
#define PIND_4 4
#define PIND_5 5
#define PIND_6 6
#define PIND_7 7




#endif /* IO_PORTS_ATMEGA32_H_ */
