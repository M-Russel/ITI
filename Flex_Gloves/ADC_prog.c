/*
 * ADC_prog.c
 *
 *  Created on: Mar 8, 2017
 *      Author: Russel
 */
#include "std_types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "ADC_interface.h"
#include "ADC_config.h"
#include "ADC_private.h"
u8 ADC_u8Init(void)
{

ADMUX|=ADC_REGISTER_VALUE(REFS1_STATUS,REFS0_STATUS,
				ADLAR_STATUS,MUX4_STATUS,MUX3_STATUS,MUX2_STATUS,MUX1_STATUS,MUX0_STATUS);
ADCSRA|=ADC_REGISTER_VALUE(ADEN_STATUS,ADSC_STATUS,ADATE_STATUS, ADIF_STATUS,
				ADIE_STATUS, ADPS2_STATUS, ADPS1_STATUS, ADPS0_STATUS);

//SREG|=(GLOBAL_INTERRUPT_STATUS<<GLOBAL_INTERRUPT);


	return OK;

}

u8 ADC_u8ReadADC_Value(u8 ADC_u8CopyChannel,pu8 ADC_pu8CopyReturnValue)
{
	u8 Local_u8Temp=ZERO;
	//Start `Conversion
	setBit(ADCSRA,ADSC);

	//check on the End of conversion flag
	while(getBit(ADCSRA,ADIF) == 0){}
	//clear the conversion flag by writing one on it
	clrBit(ADCSRA,ADIF);
	Local_u8Temp|=ADCH;
	Local_u8Temp=((Local_u8Temp*VREF*FIXED_POINT)/RESOLUTION);
    *ADC_pu8CopyReturnValue=Local_u8Temp;
return OK;
}
