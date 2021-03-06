/*
 * SPI_config.h
 *
 *  Created on: Apr 5, 2017
 *      Author: Russel
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#define ENABLED 1
#define DISABLED 0



/*SPI Control Register */
/*SPI Interrupt Enable
 * SPIE = 1 Interrupt enabled
 * SPIE = 0 Interrupt disabled
 * */
#define SPCR_SPIE_STATUS    DISABLED
/*SPI  Enable
 * SPE = 1 SPI Enabled
 * SPE = 0 SPI Disabled
 * */
#define SPCR_SPE_STATUS      ENABLED
/*Data order
 *DORD = 1 LSB first.
 * DORD = 0 MSB Second.
 *  */
#define SPCR_DORD_STATUS  DISABLED
/*Master Slave Select
 * MSTR = 1 Master
 * MSTR = 0 Slave
 *  */
#define SPCR_MSTR_STATUS   DISABLED
/*Clock Polarity
 * CPOL = 0  Leading Edge: Rising  Trailing Edge: Falling
 * CPOL = 1  Leading Edge: Falling  Trailing Edge: Rising
 * */
#define SPCR_CPOL_STATUS   DISABLED
/*Clock Phase
 * CPHA
 * CPHA =0  Leading Edge: Sample  Trailing Edge: Setup
 * CPHA = 1 Leading Edge: Setup    Trailing Edge: Sample
 * */
#define SPCR_CPHA_STATUS   ENABLED

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
#define SPCR_SPR1_STATUS    DISABLED
#define SPCR_SPR0_STATUS    ENABLED


/*SPI Status Register */
/*SPI Speed Bit*/
#define SPSR_SPI2X_STATUS   DISABLED

#endif /* SPI_CONFIG_H_ */
