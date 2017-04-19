/*
 * I2C_interface.h
 *
 *  Created on: Apr 10, 2017
 *      Author: Russel
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#define TWDR (*((volatile u8 *)(0x23)))


u8 I2C_u8Init(void);
u8 I2C_u8Start(void);
u8 I2C_u8Stop(void);
u8 I2C_u8WriteByte(u8 Copy_u8SlaveAddress,u8 Copy_u8DataByte);
u8 I2C_u8ContinueWrite(u8 Copy_u8DataByte);
u8 I2C_u8ReadByte(u8 Copy_u8SlaveAddress);
u8 I2C_u8ContinueRead(u8 Copy_u8SlaveAddress);



#endif /* I2C_INTERFACE_H_ */
