/*
 * UART_Interface.h
 *
 *  Created on: Mar 13, 2017
 *      Author: Russel
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_



u8 UART_u8Init(void);
u8 UART_u8Recieve(void);
u8 UART_u8Transmit(u8 Copy_u8Data);

#endif /* UART_INTERFACE_H_ */
