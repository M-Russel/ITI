/*
 * DIO_Prog.c
 *
 *  Created on: Dec 21, 2016
 *      Author: Russel
 */
#include "io_ports_atmega32.h" // PORTS MAPPING HEADER FILE
#include "DIO_voidInitialize.h" // DIO INITIALE VALUES
#include "DIO_Interface.h" //DIO INTERFACE FILE
#include "std_types.h" // DATA TYPES HEADER FILE
#include "utils.h" // BIT CALCULATION HEADER FILE



/* **************************************************************************************************************
 *																												*
 * "DIO_u8SetPortDirection"																					    *
 *   																											*
 * 		-FUNCTION RESPOSIBLE FOR SETTING THE DIRECTION OF A SPECIFIC DATA DIRECTION REGISTER 					*
 * 	TAKES:																										*
 * 		-IT TAKES THE ADDRESS OF THE REQUIRED DATA DIRECTION REGISTER 											*
 * 		-IT TAKES THE DIRECTION THAT WE WANT TO ASSIGN TO THE PREVIOUS DDR										*
 * 	RETURNS:																									*
 * 		-IT RETURNS AN INDICATION OF THE SUCCESS OF THE OPERATION 												*
 * 			-IF THE OPERATION PERFORMED SUCCESSFULLY IT WILL RETURN VALUE OF '0'								*
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '-1'						*
 * 																												*
 * 	NOTE **:-																									*
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE INDICATOR BEFORE PROCEEDING IN YOUR CODE						*
 * 																												*
 * 																												*
 * **************************************************************************************************************/

u8 DIO_u8SetPortDirection(pu8 Copy_pu8_DDR , u8 Copy_u8_Direction) // HEADER OF THE FUNCTION
{

	if(Copy_u8_Direction == DIO_INPUT) // CHECKING ON THE VALUE OF THE DIRECTION IF IT IS INPUT
	{
		*(Copy_pu8_DDR)= DIO_PORT_INPUT; // ASSIGNING THE INPUT VALUE TO THE REQUIRED DDR
		return 0;					// RETURNING TO THE CALLER
	}
	else if (Copy_u8_Direction == DIO_OUTPUT) // CHECKING ON THE VALUE OF THE DIRECTION IF IT IS OUTPUT
	{
		*(Copy_pu8_DDR)=DIO_PORT_OUTPUT; // ASSIGNING THE OUTPUT VALUE TO THE REQUIRED DDR
		return 0; // RETURNING TO THE CALLER
	}
	else // IN CASE OF THE USER ENTERED ANOTHER VALUE RATHER THAN EXPECTED
	{

		*(Copy_pu8_DDR)=DIO_PORT_OUTPUT; //THE DEFAULT VALUE
		return -1; // RETURNING THE ERROR INDICATOR
	}
	return -1; // RETURNING THE ERROR INDICATOR INCASE OF ANY UNEXPECTED EVENT

}

/* **************************************************************************************************************
 *																												*
 * "DIO_u8SetPinDirection"																					    *
 *   																											*
 * 		-FUNCTION RESPOSIBLE FOR SETTING THE DIRECTION OF A SPECIFIC PIN IN A  SPECIFIC DATA DIRECTION REGISTER *
 * 	TAKES:																										*
 * 		-IT TAKES THE ADDRESS OF THE REQUIRED DATA DIRECTION REGISTER											*
 * 		-IT TAKES THE NUMBER OF THE PIN THAT WE WANT TO SET ITS DIRECTION										*
 * 		-IT TAKES THE DIRECTION THAT WE WANT TO ASSIGN TO THE PREVIOUS PIN 										*
 * 	RETURNS:																									*
 * 		-IT RETURNS AN INDICATION OF THE SUCCESS OF THE OPERATION 												*
 * 			-IF THE OPERATION PERFORMED SUCCESSFULLY IT WILL RETURN VALUE OF '0'								*
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '-1'						*
 * 																												*
 * 	NOTE **:-																									*
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE INDICATOR BEFORE PROCEEDING IN YOUR CODE						*
 * 																												*
 * 																												*
 * **************************************************************************************************************/

u8 DIO_u8SetPinDirection(pu8 Copy_pu8_DDR , u8 Copy_u8_PinNumber , u8 Copy_u8_Direction)
{


	if(Copy_u8_Direction == DIO_INPUT)  // CHECKING ON THE VALUE OF THE DIRECTION IF IT IS INPUT
		{
			clrBit(*(Copy_pu8_DDR),Copy_u8_PinNumber);  // ASSIGNING THE INPUT VALUE TO THE REQUIRED PIN
			return 0;                           // RETURNING TO THE CALLER
		}
		else if (Copy_u8_Direction == DIO_OUTPUT) // CHECKING ON THE VALUE OF THE DIRECTION IF IT IS OUTPUT
		{
			setBit(*(Copy_pu8_DDR),Copy_u8_PinNumber); // ASSIGNING THE INPUT VALUE TO THE REQUIRED PIN
			return 0;// RETURNING TO THE CALLER
		}
		else // IN CASE OF THE USER ENTERED ANOTHER VALUE RATHER THAN EXPECTED
		{

				return -1; // RETURNING THE ERROR INDICATOR


		}
return -1;  // RETURNING THE ERROR INDICATOR INCASE OF ANY UNEXPECTED EVENT
}


/* **************************************************************************************************************
 *																												*
 * "DIO_u8SetPortValue"																						    *
 *   																											*
 * 		-FUNCTION RESPOSIBLE FOR SETTING THE VALUE OF A SPECIFIC PORT REGISTER									*
 * 	TAKES:																										*
 * 		-IT TAKES THE NAME OF THE REQUIRED PORT REGISTER														*
 * 		-IT TAKES THE VALUE THAT WE WANT TO ASSIGN TO THE PREVIOUS PORT REGISTER  											*
 * 	RETURNS:																									*
 * 		-IT RETURNS AN INDICATION OF THE SUCCESS OF THE OPERATION 												*
 * 			-IF THE OPERATION PERFORMED SUCCESSFULLY IT WILL RETURN VALUE OF '0'								*
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '-1'						*
 * 																												*
 * 	NOTE **:-																									*
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE INDICATOR BEFORE PROCEEDING IN YOUR CODE						*
 * 																												*
 * 																												*
 * **************************************************************************************************************/

u8 DIO_u8SetPortValue(pu8 Copy_u8_PortName , u8 Copy_PortValue)
{

	while (Copy_PortValue <= DIO_PORT_MAX) // TO MAKE SURE THAT THE ENTERED VALUE IS LEGAL
	{

		(*(Copy_u8_PortName))= Copy_PortValue;  // ASSIGNING THE VALUE TO THE REQUIRED PORT
		return 0;
	}

	return -1;  // RETURNING THE ERROR INDICATOR INCASE OF ANY UNEXPECTED EVENT
}

/* **************************************************************************************************************
 *																												*
 * "DIO_u8SetPinValue"																						    *
 *   																											*
 * 		-FUNCTION RESPOSIBLE FOR SETTING THE VALUE OF A SPECIFIC PIN IN A SPECIFIC PORT REGISTER				*
 * 	TAKES:																										*
 * 		-IT TAKES THE NAME OF THE REQUIRED PORT REGISTER														*
 * 		-IT TAKES THE NUMBER OF THE REQUIRED PIN																*
 * 		-IT TAKES THE VALUE THAT WE WANT TO ASSIGN TO THE PREVIOUS PIN 											*
 * 	RETURNS:																									*
 * 		-IT RETURNS AN INDICATION OF THE SUCCESS OF THE OPERATION 												*
 * 			-IF THE OPERATION PERFORMED SUCCESSFULLY IT WILL RETURN VALUE OF '0'								*
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '-1'						*
 * 																												*
 * 	NOTE **:-																									*
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE INDICATOR BEFORE PROCEEDING IN YOUR CODE						*
 * 																												*
 * 																												*
 * **************************************************************************************************************/



u8 DIO_u8SetPinValue(pu8 Copy_u8_PortName , u8 Copy_u8_PinNumber,u8 Copy_u8_PinValue)
{

		if(Copy_u8_PinValue == DIO_LOW)
				{
				clrBit(*(Copy_u8_PortName),Copy_u8_PinNumber);
				return 0;
				}
		else if (Copy_u8_PinValue == DIO_HIGH)
			{
				setBit(*(Copy_u8_PortName),Copy_u8_PinNumber);
				return 0;
			}
			else
			{
				clrBit(*(Copy_u8_PortName),Copy_u8_PinNumber);

				return -1;
			}

return -1; // RETURNING THE ERROR INDICATOR INCASE OF ANY UNEXPECTED EVENT

}



/* **************************************************************************************************************
 *																												*
 * "DIO_u8GetPortValue"																						    *
 *   																											*
 * 		-FUNCTION RESPOSIBLE FOR GETTING THE VALUE OF A SPECIFIC PIN REGISTER									*
 * 	TAKES:																										*
 * 		-IT TAKES THE NAME OF THE REQUIRED PIN REGISTER															*
 * 	RETURNS:																									*
 * 		-IT RETURNS THE CORRESPONDING VALUE OF THE REQUIRED PIN REGISTER IN YOUR CODE							*
 * 																												*									*
 * 																												*
 * 																												*
 * **************************************************************************************************************/



u8 DIO_u8GetPortValue(u8 Copy_u8_PortName)
{

return Copy_u8_PortName;


}


/* **************************************************************************************************************
 *																												*
 * "DIO_u8GetPinValue"																						    *
 *   																											*
 * 		-FUNCTION RESPOSIBLE FOR GETTING THE VALUE OF A SPECIFIC PIN IN A SPECIFIC PINREGISTER					*
 * 	TAKES:																										*
 * 		-IT TAKES THE NAME OF THE REQUIRED PIN REGISTER															*
 * 		-IT TAKES THE NUMBER OF THE REQUIRED PIN																*
 * 	RETURNS:																									*
 * 		-IT RETURNS THE CORRESPONDING VALUE OF THE REQUIRED PIN IN THE REQUIRED  PIN REGISTER 				    *						*
 * 			-IF THE OPERATION PERFORMED SUCCESSFULLY IT WILL RETURN THE VALUE OF THE PIN						*
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '-1'						*
 * 																												*
 * 	NOTE **:-																									*
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE VALUE BEFORE PROCEEDING IN YOUR CODE							*
 * 																												*
 * 																												*
 * **************************************************************************************************************/

u8 DIO_u8GetPinValue(u8 Copy_u8_PortName , u8 Copy_u8_PinNumber)
{
	while (Copy_u8_PinNumber <= 7)
	{
		return (getBit(Copy_u8_PortName,Copy_u8_PinNumber));
	}

return -1;  // RETURNING THE ERROR INDICATOR INCASE OF ANY UNEXPECTED EVENT
}


