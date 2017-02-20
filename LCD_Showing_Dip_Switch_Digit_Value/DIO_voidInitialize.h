/*

 * Initializing.c

 *
 *  Created on: Dec 13, 2016
 *      Author: Russel
 */

#ifndef DIO_VOIDINITIALIZE_H_
#define DIO_VOIDINITIALIZE_H_


#include "io_ports_atmega32.h"
#include "DIO_Config.h"
#include "std_types.h"
#include "utils.h"
void DIO_voidInitialize();

#define DDRA_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) DDRA_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7)
#define DDRA_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) 0b##V0##V1##V2##V3##V4##V5##V6##V7


#define DDRB_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) DDRB_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7)
#define DDRB_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) 0b##V0##V1##V2##V3##V4##V5##V6##V7


#define DDRC_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) DDRC_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7)
#define DDRC_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) 0b##V0##V1##V2##V3##V4##V5##V6##V7


#define DDRD_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) DDRD_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7)
#define DDRD_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) 0b##V0##V1##V2##V3##V4##V5##V6##V7


#define PORTA_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) PORTA_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7)
#define PORTA_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) 0b##V0##V1##V2##V3##V4##V5##V6##V7


#define PORTB_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) PORTB_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7)
#define PORTB_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) 0b##V0##V1##V2##V3##V4##V5##V6##V7


#define PORTC_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) PORTC_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7)
#define PORTC_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) 0b##V0##V1##V2##V3##V4##V5##V6##V7


#define PORTD_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) PORTD_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7)
#define PORTD_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) 0b##V0##V1##V2##V3##V4##V5##V6##V7



#endif
