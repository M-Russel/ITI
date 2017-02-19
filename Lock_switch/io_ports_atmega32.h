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

#define PORTA_0 0x01
#define PORTA_1 0x02
#define PORTA_2 0x04
#define PORTA_3 0x08
#define PORTA_4 0x10
#define PORTA_5 0x20
#define PORTA_6 0x40
#define PORTA_7 0x80

#define PORTB_0 0x01
#define PORTB_1 0x02
#define PORTB_2 0x04
#define PORTB_3 0x08
#define PORTB_4 0x10
#define PORTB_5 0x20
#define PORTB_6 0x40
#define PORTB_7 0x80

#define PORTC_0 0x01
#define PORTC_1 0x02
#define PORTC_2 0x04
#define PORTC_3 0x08
#define PORTC_4 0x10
#define PORTC_5 0x20
#define PORTC_6 0x40
#define PORTC_7 0x80

#define PORTD_0 0x01
#define PORTD_1 0x02
#define PORTD_2 0x04
#define PORTD_3 0x08
#define PORTD_4 0x10
#define PORTD_5 0x20
#define PORTD_6 0x40
#define PORTD_7 0x80



#define PINA_0 0x01
#define PINA_1 0x02
#define PINA_2 0x04
#define PINA_3 0x08
#define PINA_4 0x10
#define PINA_5 0x20
#define PINA_6 0x40
#define PINA_7 0x80


#define PINB_0 0x01
#define PINB_1 0x02
#define PINB_2 0x04
#define PINB_3 0x08
#define PINB_4 0x10
#define PINB_5 0x20
#define PINB_6 0x40
#define PINB_7 0x80


#define PINC_0 0x01
#define PINC_1 0x02
#define PINC_2 0x04
#define PINC_3 0x08
#define PINC_4 0x10
#define PINC_5 0x20
#define PINC_6 0x40
#define PINC_7 0x80


#define PIND_0 0x01
#define PIND_1 0x02
#define PIND_2 0x04
#define PIND_3 0x08
#define PIND_4 0x10
#define PIND_5 0x20
#define PIND_6 0x40
#define PIND_7 0x80




#endif /* IO_PORTS_ATMEGA32_H_ */
