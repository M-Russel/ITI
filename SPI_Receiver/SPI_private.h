/*
 * SPI_private.h
 *
 *  Created on: Apr 5, 2017
 *      Author: Russel
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_




#define SPI_REGISTER_VALUE(BIT0,BIT1,BIT2,BIT3,BIT4,BIT5,BIT6,BIT7) SPI_REGISTER(BIT0,BIT1,BIT2,BIT3,BIT4,BIT5,BIT6,BIT7)
#define SPI_REGISTER(BIT0,BIT1,BIT2,BIT3,BIT4,BIT5,BIT6,BIT7) 0b##BIT7##BIT6##BIT5##BIT4##BIT3##BIT2##BIT1##BIT0

/*SPI Data Register :- */
#define SPDR (*((volatile pu8)(0x2F)))





/*SPI Status Register */
#define SPSR (*((volatile pu8)(0x2E)))
/*SPI Interrupt Flag
 *
 *
 * */
#define SPSR_SPIF    7
/*Write COLlision Flag*/
#define SPSR_WCOL 6
/*SPI Speed Bit*/
#define SPSR_SPI2X  0




/*SPI Control Register */
#define SPCR (*((volatile pu8)(0x2D)))

/*SPI Interrupt Enable
 * SPIE = 1 Interrupt enabled
 * SPIE = 0 Interrupt disabled
 * */
#define SPCR_SPIE     7
/*SPI  Enable
 * SPE = 1 SPI Enabled
 * SPE = 0 SPI Disabled
 * */
#define SPCR_SPE      6
/*Data order
 *DORD = 1 LSB first.
 * DORD = 0 MSB Second.
 *  */
#define SPCR_DORD  5
/*Master Slave Select
 * MSTR = 1 Master
 * MSTR = 0 Slave
 *  */
#define SPCR_MSTR   4
/*Clock Polarity
 * CPOL = 0  Leading Edge: Rising  Trailing Edge: Falling
 * CPOL = 1  Leading Edge: Falling  Trailing Edge: Rising
 * */
#define SPCR_CPOL   3
/*Clock Phase
 * CPHA
 * CPHA =0  Leading Edge: Sample  Trailing Edge: Setup
 * CPHA = 1 Leading Edge: Setup    Trailing Edge: Sample
 * */
#define SPCR_CPHA   2

/*SPI Clock Rate
 * SPI2X SPR1 SPR0   SCK Frequency
	0 	      0       0     f osc / 4
	0        0       1     f osc / 16
	0        1       0     f osc / 64
	0        1       1     f osc / 128
	1        0       0     f osc / 2
	1        0       1     f osc / 8
	1        1       0     f osc / 32
	1        1       1     f osc / 64

 * */
#define SPCR_SPR1    1
#define SPCR_SPR0    0

#endif /* SPI_PRIVATE_H_ */
