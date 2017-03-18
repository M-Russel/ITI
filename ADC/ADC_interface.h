/*
 * ADC_interface.h
 *
 *  Created on: Mar 8, 2017
 *      Author: Russel
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_CHANNEL_LIMITATION 0x07

#define VREF 5
#define RESOLUTION 256

u8 ADC_u8Init(void);
u8 ADC_u8ReadADC_Value(u8 ADC_u8Channel,pu8 ADC_pu8CopyReturnValue);
#endif /* ADC_INTERFACE_H_ */
