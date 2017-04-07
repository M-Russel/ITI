/*
 * SPI_prog.c
 *
 *  Created on: Apr 5, 2017
 *      Author: Russel
 */
#include "std_types.h"
#include "utils.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

u8 SPI_u8Init(void)
{
	u8 Local_u8InitStatus=OK;

	SPCR=SPI_REGISTER_VALUE(SPCR_SPR0_STATUS,SPCR_SPR1_STATUS,SPCR_CPHA_STATUS,
			  SPCR_CPOL_STATUS,SPCR_MSTR_STATUS,SPCR_DORD_STATUS,SPCR_SPE_STATUS,
			  SPCR_SPIE_STATUS);

   SPSR=(SPSR_SPI2X<<SPSR_SPI2X_STATUS);
return Local_u8InitStatus;
}

u8 SPI_u8TransmitData(u8 Copy_u8Data)
{
	u8 Local_u8TransmitData=OK;
SPDR = Copy_u8Data;
/* Wait for transmission complete */
while(!(SPSR & (1<<SPSR_SPIF)));

return Local_u8TransmitData;
}

u8 SPI_u8ReceiveData(pu8 Copy_pu8ReceivedData )
{
	u8 Local_u8ReceiveData=OK;
while(!(SPSR & (1<<SPSR_SPIF)));

*Copy_pu8ReceivedData=SPDR;


return Local_u8ReceiveData;
}
