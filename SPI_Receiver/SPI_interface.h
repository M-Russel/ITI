/*
 * SPI_interface.h
 *
 *  Created on: Apr 5, 2017
 *      Author: Russel
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_



u8 SPI_u8Init(void);
u8 SPI_u8TransmitData(u8 Copy_u8Data);
u8 SPI_u8ReceiveData(pu8 Copy_pu8ReceivedData );

#endif /* SPI_INTERFACE_H_ */
