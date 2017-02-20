/*

#include "std_types.h"
#include "utils.h"
#include "io_ports_atmega32.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "switch.h"

u8 SWITCH_u8GetStatus(u8 Copy_u8PinNumber,pu8 Copy_pu8PinStatus)
{
u8  Local_u8TempPinValue=DIO_LOW,Local_u8SwitchStatus=OK;
static u8 Local_u8ReturnStatus=RELEASED , Local_u8ThreesholdCounter=THREESHOLD_MINIMUM;


//READS THE PIN VALUE
DIO_u8GetPinValue(Copy_u8PinNumber,&Local_u8TempPinValue);
//SWITCH ON THE PIN VALUE

	if(DIO_HIGH==Local_u8TempPinValue && Local_u8ReturnStatus == RELEASED)
	{

		Local_u8ThreesholdCounter ++;
		Local_u8ReturnStatus = PRE_PUSHED;

	}
	else if(DIO_LOW==Local_u8TempPinValue && Local_u8ReturnStatus == PRE_PUSHED)
	{

		Local_u8ThreesholdCounter = THREESHOLD_MINIMUM;

	}
	else if(DIO_HIGH==Local_u8TempPinValue && Local_u8ReturnStatus == PRE_PUSHED)
	{
		Local_u8ThreesholdCounter ++;

		if (THREESHOLD_MAXIMUM==Local_u8ThreesholdCounter )
		{

			Local_u8ReturnStatus = PUSHED;
			Local_u8ThreesholdCounter = THREESHOLD_MINIMUM;
		}
	}
	else if (DIO_LOW==Local_u8TempPinValue && Local_u8ReturnStatus == PUSHED)
	{
		Local_u8ReturnStatus = PRE_RELEASED;
		Local_u8ThreesholdCounter ++;

	}

	else if (DIO_HIGH==Local_u8TempPinValue && Local_u8ReturnStatus == PRE_RELEASED)
	{
		Local_u8ThreesholdCounter = THREESHOLD_MINIMUM;

	}

	else if (DIO_LOW==Local_u8TempPinValue && Local_u8ReturnStatus == PRE_RELEASED)
	{
		Local_u8ThreesholdCounter ++;

		if (THREESHOLD_MAXIMUM==Local_u8ThreesholdCounter )
		{
			Local_u8ReturnStatus = RELEASED;
			Local_u8ThreesholdCounter = THREESHOLD_MINIMUM;

		}
	}
	else
		Local_u8SwitchStatus = ERROR;

return Local_u8SwitchStatus ;
}

