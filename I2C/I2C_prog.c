/*
 * I2C_prog.c
 *
 *  Created on: Apr 10, 2017
 *      Author: Russel
 */
#include "std_types.h"
#include "utils.h"
#include "I2C_interface.h"
#include "I2C_config.h"
#include "I2C_private.h"

u8 I2C_u8Init(void) {
	//TWINT TWEA TWSTA TWSTO TWWC TWEN – TWIE
	TWCR = I2C_REGISTER_VALUE(TWCR_TWIE_STATUS, TWCR_RESERVED_STATUS,
			TWCR_TWEN_STATUS, TWCR_TWWC_STATUS, TWCR_TWSTO_STATUS,
			TWCR_TWSTA_STATUS, TWCR_TWEA_STATUS, TWCR_TWINT_STATUS);
	TWBR = I2C_REGISTER_VALUE(TWBR_TWBR0_STATUS, TWBR_TWBR1_STATUS,
			TWBR_TWBR2_STATUS, TWBR_TWBR3_STATUS, TWBR_TWBR4_STATUS,
			TWBR_TWBR5_STATUS, TWBR_TWBR6_STATUS, TWBR_TWBR7_STATUS);
	TWSR = 0x01;

}
u8 I2C_u8Start(void) {
//Start Condition`
//	setBit(TWCR, TWCR_TWSTA);
//	setBit(TWCR,TWCR_TWEN);
//wait until the event flag interrupt
	TWCR=(1<<TWCR_TWINT)|(1<<TWCR_TWSTA)|(1<<TWCR_TWEN);
	while (FALSE == getBit(TWCR, TWCR_TWINT));
	setBit(TWCR, TWCR_TWINT);
//clear the stop condition
	setBit(TWCR, TWCR_TWSTA);
	return OK;

}
u8 I2C_u8Stop(void) {
//start stop bit
	//setBit(TWCR, TWCR_TWSTO);
	//setBit(TWCR,TWCR_TWEN);

	TWCR = (1<<TWCR_TWINT)|(1<<TWCR_TWEN)|(1<<TWCR_TWSTO)
	return OK;
}
u8 I2C_u8WriteByte(u8 Copy_u8SlaveAddress, u8 Copy_u8DataByte) {
	//send the slave address and the write operation
	//setBit(TWCR,TWCR_TWEN);
	Copy_u8SlaveAddress = (Copy_u8SlaveAddress << 1);

	TWDR = Copy_u8SlaveAddress;
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	//clear the event interrupt flag
	//setBit(TWCR, TWCR_TWINT);
	//wait until the event happens
	while (FALSE == getBit(TWCR, TWCR_TWINT))
		;
	//send the data
	TWDR = Copy_u8DataByte;
//clear the event interrupt flag
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	//setBit(TWCR,TWCR_TWEN);
//wait until the event happens
	while (FALSE == getBit(TWCR, TWCR_TWINT))
		;
	return OK;
}
u8 I2C_u8ContinueWrite(u8 Copy_u8DataByte) {
	TWDR = Copy_u8DataByte;
	//clear the event interrupt flag
	//setBit(TWCR, TWCR_TWINT);
	//setBit(TWCR, TWCR_TWEN);
	//wait until the event happens
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);
	while (FALSE == getBit(TWCR, TWCR_TWINT))
		;
}
u8 I2C_u8ReadByte(u8 Copy_u8SlaveAddress) {
	Copy_u8SlaveAddress = (Copy_u8SlaveAddress << 1);
	//setting the read operation
	setBit(Copy_u8SlaveAddress, 0);

	//send the slave address and the read operation
	TWDR = Copy_u8SlaveAddress;
	//clear the flag to wait for the acknowledge
	//setBit(TWCR, TWCR_TWINT);
	//setBit(TWCR,TWCR_TWEN);
	//wait until the event happens
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);

	while (FALSE == getBit(TWCR, TWCR_TWINT))
		;
	//clear the flag to tell the slave that u r ready to read
	//setBit(TWCR, TWCR_TWINT);
	//setBit(TWCR,TWCR_TWEN);
	//wait until the ack event happens
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);

	while (FALSE == getBit(TWCR, TWCR_TWINT))
		;
	//read the value in the register
	return TWDR;

}
u8 I2C_u8ContinueRead(u8 Copy_u8SlaveAddress) {
//	setBit(TWCR, TWCR_TWINT);
	//setBit(TWCR, TWCR_TWEN);
	TWCR = (1<<TWCR_TWINT) | (1<<TWCR_TWEN);

	while (FALSE == getBit(TWCR, TWCR_TWINT))
		;
	return TWDR;
}
