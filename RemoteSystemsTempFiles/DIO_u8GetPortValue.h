/*
 * DIO_u8GetPortValue.h
 *
 *  Created on: Dec 21, 2016
 *      Author: Russel
 */

#ifndef DIO_U8GETPORTVALUE_H_
#define DIO_U8GETPORTVALUE_H_

#include "types.h"
#include "io_ports_atmega32.h"
#include "bitCalc.h"


#define PORT_VALUE(v0,v1,v2,v3,v4,v5,v6,v7) PORT_Value_INITIAL(v0,v1,v2,v3,v4,v5,v6,v7)
#define PORT_Value_INITIAL(v0,v1,v2,v3,v4,v5,v6,v7) 0b##v0##v1##v2##v3##v4##v5##v6##v7




//u8 DIO_u8GetPortValue(u8 Copy_PortName);






#endif /* DIO_U8GETPORTVALUE_H_ */
