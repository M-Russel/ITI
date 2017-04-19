/*
 * I2C_private.h
 *
 *  Created on: Apr 10, 2017
 *      Author: Russel
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_



#define TWDR_TWD7 7
#define TWDR_TWD6 6
#define TWDR_TWD5 5
#define TWDR_TWD4 4
#define TWDR_TWD3 3
#define TWDR_TWD2 2
#define TWDR_TWD1 1
#define TWDR_TWD0 0


#define TWCR (*((volatile u8 *)(0x56)))


#define TWCR_TWINT 7
#define TWCR_TWEA 6
#define TWCR_TWSTA 5
#define TWCR_TWSTO 4
#define TWCR_TWWC 3
#define TWCR_TWEN 2
#define TWCR_RESERVED 1
#define TWCR_TWIE 0



#define TWAR (*((volatile u8 *)(0x22)))


#define TWAR_TWA6 7
#define TWAR_TWA5 6
#define TWAR_TWA4 5
#define TWAR_TWA3 4
#define TWAR_TWA2 3
#define TWAR_TWA1 2
#define TWAR_TWA0 1
#define TWAR_TWGCE 0

#define TWSR (*((volatile u8 *)(0x21)))

#define TWSR_TWS7 7
#define TWSR_TWS6 6
#define TWSR_TWS5 5
#define TWSR_TWS4 4
#define TWSR_TWS3 3
#define TWSR_TWS2 2
#define TWSR_TWS1 1
#define TWSR_TWS0 0

#define TWBR (*((volatile u8 *)(0x20)))

#define TWBR_TWBR7 7
#define TWBR_TWBR6 6
#define TWBR_TWBR5 5
#define TWBR_TWBR4 4
#define TWBR_TWBR3 3
#define TWBR_TWBR2 2
#define TWBR_TWBR1 1
#define TWBR_TWBR0 0



#define I2C_REGISTER_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) I2C_REGISTER_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7)
#define I2C_REGISTER_INIT_VALUE(V0,V1,V2,V3,V4,V5,V6,V7) 0b##V7##V6##V5##V4##V3##V2##V1##V0

#endif /* I2C_PRIVATE_H_ */
