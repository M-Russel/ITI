/*
 * UART_Private.h
 *
 *  Created on: Mar 13, 2017
 *      Author: Russel
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define ENABLED 1
#define DISABLED 0


#define UDR (*((volatile u8 *)0x2C))


#define UCSRA (*((volatile u8 *)0x2B))

#define RXC 7
#define TXC 6
#define UDRE 5
#define FE  4
#define DOR 3
#define PE 2
#define U2X 1
#define MPCM 0

#define UCSRB (*((volatile u8 *)0x2A))


#define RXCIE 7
#define TXCIE 6
#define UDRIE 5
#define RXEN 4
#define TXEN 3
#define UCSZ2 2
#define RXB8 1
#define TXB 0

#define UCSRC (*((volatile u8 *)0x40))

#define URSEL 7
#define UMSEL 6
#define UPM1 5
#define UPM0 4
#define USBS 3
#define UCSZ1 2
#define UCSZ0 1
#define UCPOL 0


#define UBRRL (*((volatile u8 *)0x29))


#define REGISTER_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) REGISTER_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7)
#define REGISTER_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) 0b##V0##V1##V2##V3##V4##V5##V6##V7



#endif /* UART_PRIVATE_H_ */
