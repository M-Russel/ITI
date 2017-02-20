/*
 * DIO_Prog.c
 *
 *  Created on: Dec 21, 2016
 *      Author: Russel
 *      Version :2
 */
#include "std_types.h" // DATA TYPES HEADER FILE
#include "utils.h" // BIT CALCULATION HEADER FILE
#include "io_ports_atmega32.h" // PORTS MAPPING HEADER FILE
#include "DIO_voidInitialize.h" // DIO INITIALE VALUES
#include "DIO_Interface.h" //DIO INTERFACE FILE
#include "DIO_Private.h"




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
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '1'						*
 * 																												*
 * 	NOTE **:-																									*
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE INDICATOR BEFORE PROCEEDING IN YOUR CODE						*
 * 																												*
 * 																												*
 * **************************************************************************************************************/

u8 DIO_u8SetPortDirection(pu8 Copy_pu8DDR , u8 Copy_u8Direction) // HEADER OF THE FUNCTION
{

	if(Copy_u8Direction == DIO_INPUT) // CHECKING ON THE VALUE OF THE DIRECTION IF IT IS INPUT
	{
		*(Copy_pu8DDR)= DIO_PORT_INPUT; // ASSIGNING THE INPUT VALUE TO THE REQUIRED DDR
		return OK;					// RETURNING TO THE CALLER
	}
	else if (Copy_u8Direction == DIO_OUTPUT) // CHECKING ON THE VALUE OF THE DIRECTION IF IT IS OUTPUT
	{
		*(Copy_pu8DDR)=DIO_PORT_OUTPUT; // ASSIGNING THE OUTPUT VALUE TO THE REQUIRED DDR
		return OK; // RETURNING TO THE CALLER
	}
	else // IN CASE OF THE USER ENTERED ANOTHER VALUE RATHER THAN EXPECTED
	{

		*(Copy_pu8DDR)=DIO_PORT_OUTPUT; //THE DEFAULT VALUE
		return ERROR; // RETURNING THE ERROR INDICATOR
	}
	return ERROR; // RETURNING THE ERROR INDICATOR INCASE OF ANY UNEXPECTED EVENT

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
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '1'						*
 * 																												*
 * 	NOTE **:-																									*
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE INDICATOR BEFORE PROCEEDING IN YOUR CODE						*
 * 																												*
 * 																												*
 * **************************************************************************************************************/

u8 DIO_u8SetPinDirection(u8 Copy_u8PinNumber , u8 Copy_u8Direction) // HEADER OF THE FUNCTION
{

	switch (Copy_u8PinNumber)
	{
	//case 1 ... 3:

	case PIN_0:
	case PIN_1:
	case PIN_2:
	case PIN_3:
	case PIN_4:
	case PIN_5:
	case PIN_6:
	case PIN_7:
		if (Copy_u8Direction == DIO_INPUT) //CHECKING IF THE THE DIRECTION IS INPUT AND THE REQUIRED PIN BELONGS TO DDRA AND ASSIGN
		{                                  //THE CORESSPONDING VALUE
			clrBit(DDRA,(Copy_u8PinNumber%8));
			return OK;// only once
		}
		else if (Copy_u8Direction == DIO_OUTPUT)//CHECKING IF THE THE DIRECTION IS OUTPUT AND THE REQUIRED PIN BELONGS TO DDRA AND ASSIGN
		{                                       //THE CORESSPONDING VALUE
			setBit(DDRA,(Copy_u8PinNumber%8));
			return OK;
		}
		else  //IF THE DIRECTIONE NEITHER INPUT NOR OUTPUT RETURNING AN ERROR SIGNAL
			return ERROR;
		break;

	case PIN_8:
	case PIN_9:
	case PIN_10:
	case PIN_11:
	case PIN_12:
	case PIN_13:
    case PIN_14:
    case PIN_15:
    	if (Copy_u8Direction == DIO_INPUT)//CHECKING IF THE THE DIRECTION IS INPUT AND THE REQUIRED PIN BELONGS TO DDRB AND ASSIGN
    			{							//THE CORESSPONDING VALUE
    				clrBit(DDRB,(Copy_u8PinNumber%8));
    				return OK;
    			}
    			else if (Copy_u8Direction == DIO_OUTPUT)//CHECKING IF THE THE DIRECTION IS OUTPUT AND THE REQUIRED PIN BELONGS TO DDRB AND ASSIGN
    			{							//THE CORESSPONDING VALUE
    				setBit(DDRB,(Copy_u8PinNumber%8));
    				return OK;
    			}
    			else //IF THE DIRECTIONE NEITHER INPUT NOR OUTPUT RETURNING AN ERROR SIGNAL
    				return ERROR;
    		break;
    case PIN_16:
    case PIN_17:
    case PIN_18:
    case PIN_19:
   	case PIN_20 :
   	case PIN_21:
    case PIN_22:
   	case PIN_23:
   		if (Copy_u8Direction == DIO_INPUT)//CHECKING IF THE THE DIRECTION IS INPUT AND THE REQUIRED PIN BELONGS TO DDRC AND ASSIGN
      			{									//THE CORESSPONDING VALUE
       				clrBit(DDRC,(Copy_u8PinNumber%8));
       				return OK;
       			}
       			else if (Copy_u8Direction == DIO_OUTPUT)//CHECKING IF THE THE DIRECTION IS OUTPUT AND THE REQUIRED PIN BELONGS TO DDRC AND ASSIGN
   	  			{									//THE CORESSPONDING VALUE
   	   				setBit(DDRC,(Copy_u8PinNumber%8));
       				return OK;
       			}
   	   			else //IF THE DIRECTIONE NEITHER INPUT NOR OUTPUT RETURNING AN ERROR SIGNAL
   	   				return ERROR;
   		    break;
   	case PIN_24:
   	case PIN_25:
   	case PIN_26:
   	case PIN_27:
   	case PIN_28:
   	case PIN_29:
   	case PIN_30:
   	case PIN_31:
   	   if (Copy_u8Direction == DIO_INPUT)//CHECKING IF THE THE DIRECTION IS INPUT AND THE REQUIRED PIN BELONGS TO DDRD AND ASSIGN
   	  			{								//THE CORESSPONDING VALUE
       				clrBit(DDRD,(Copy_u8PinNumber%8));
       				return OK;
   	       			}
   	       			else if (Copy_u8Direction == DIO_OUTPUT)//CHECKING IF THE THE DIRECTION IS OUTPUT AND THE REQUIRED PIN BELONGS TO DDRA AND ASSIGN
   	   	  			{							//THE CORESSPONDING VALUE
   	   	   			setBit(DDRD,(Copy_u8PinNumber%8));
   	       			return OK;
   	       			}
   	   	   			else //IF THE DIRECTIONE NEITHER INPUT NOR OUTPUT RETURNING AN ERROR SIGNAL
   	   	   				return ERROR;

   		break;

   	default : return ERROR; // IF THE PIN NUMBER WAS INVALID OR OUT OF RANGE
	}
return ERROR;
}


/* **************************************************************************************************************
 *																												*
 * "DIO_u8SetPortValue"																						    *
 *   																											*
 * 		-FUNCTION RESPOSIBLE FOR SETTING THE VALUE OF A SPECIFIC PORT REGISTER									*
 * 	TAKES:																										*
 * 		-IT TAKES THE NAME OF THE REQUIRED PORT REGISTER														*
 * 		-IT TAKES THE VALUE THAT WE WANT TO ASSIGN TO THE PREVIOUS PORT REGISTER  								*
 * 	RETURNS:																									*
 * 		-IT RETURNS AN INDICATION OF THE SUCCESS OF THE OPERATION 												*
 * 			-IF THE OPERATION PERFORMED SUCCESSFULLY IT WILL RETURN VALUE OF '0'								*
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '1'						*
 * 																												*
 * 	NOTE **:-																									*
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE INDICATOR BEFORE PROCEEDING IN YOUR CODE						*
 * 																												*
 * 																												*
 * **************************************************************************************************************/

u8 DIO_u8SetPortValue(pu8 Copy_pu8PortName , u8 Copy_u8PortValue)// HEADER OF THE FUNCTION
{

	while (Copy_u8PortValue <= DIO_PORT_MAX) // TO MAKE SURE THAT THE ENTERED VALUE IS LEGAL
	{

		(*(Copy_pu8PortName))= Copy_u8PortValue;  // ASSIGNING THE VALUE TO THE REQUIRED PORT
		return OK;
	}

	return ERROR;  // RETURNING THE ERROR INDICATOR INCASE OF ANY UNEXPECTED EVENT
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
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '1'						*
 * 																												*
 * 	NOTE **:-																									*
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE INDICATOR BEFORE PROCEEDING IN YOUR CODE						*
 * 																												*
 * 																												*
 * **************************************************************************************************************/



u8 DIO_u8SetPinValue(u8 Copy_u8PinNumber,u8 Copy_u8PinValue)// HEADER OF THE FUNCTION
{
	switch (Copy_u8PinNumber)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		if (Copy_u8PinValue == DIO_LOW) //CHECKING IF THE THE VALUE OF THE  REQUIRED PIN WHICH BELONGS TO DDRA IS LOW AND ASSIGN
 			{								//THE CORESSPONDING VALUE

			clrBit(PORTA,(Copy_u8PinNumber%8));
			return OK;
		}
		else if (Copy_u8PinValue == DIO_HIGH) //CHECKING IF THE THE VALUE OF THE  REQUIRED PIN WHICH BELONGS TO DDRA IS HIGH AND ASSIGN
		{									//THE CORESSPONDING VALUE
			setBit(PORTA,(Copy_u8PinNumber%8));
			return OK;
		}
		else //IF THE VALUE NEITHER HIGH NOR LOW  RETURNING AN ERROR SIGNAL
			return ERROR;
		break;

	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
    case 14:
	case 15:
			if (Copy_u8PinValue == DIO_LOW) //CHECKING IF THE THE VALUE OF THE  REQUIRED PIN WHICH BELONGS TO DDRB IS LOW AND ASSIGN
			{								//THE CORESSPONDING VALUE
				clrBit(PORTB,(Copy_u8PinNumber%8));
				return OK;
			}
			else if (Copy_u8PinValue == DIO_HIGH) //CHECKING IF THE THE VALUE OF THE  REQUIRED PIN WHICH BELONGS TO DDRB IS HIGH AND ASSIGN
			{									 //THE CORESSPONDING VALUE
				setBit(PORTB,(Copy_u8PinNumber%8));
				return OK;
			}
			else //IF THE VALUE NEITHER HIGH NOR LOW RETURNING AN ERROR SIGNAL
				return ERROR;
		break;
    case 16:
    case 17:
    case 18:
    case 19:
   	case 20 :
   	case 21:
    case 22:
   	case 23:
		if (Copy_u8PinValue == DIO_LOW)//CHECKING IF THE THE VALUE OF THE  REQUIRED PIN WHICH BELONGS TO DDRC IS LOW AND ASSIGN
		{								//THE CORESSPONDING VALUE
			clrBit(PORTC,(Copy_u8PinNumber%8));
			return OK;
		}
		else if (Copy_u8PinValue == DIO_HIGH)//CHECKING IF THE THE VALUE OF THE  REQUIRED PIN WHICH BELONGS TO DDRC IS HIGH AND ASSIGN
		{									//THE CORESSPONDING VALUE
			setBit(PORTC,(Copy_u8PinNumber%8));
			return OK;
		}
		else //IF THE VALUE NEITHER HIGH NOR LOW RETURNING AN ERROR SIGNAL
			return ERROR;
	break;

   	case 24:
   	case 25:
   	case 26:
   	case 27:
   	case 28:
   	case 29:
   	case 30:
   	case 31:
		if (Copy_u8PinValue == DIO_LOW)//CHECKING IF THE THE VALUE OF THE  REQUIRED PIN WHICH BELONGS TO DDRD IS LOW AND ASSIGN
		{							  //THE CORESSPONDING VALUE
			clrBit(PORTD,(Copy_u8PinNumber%8));
			return OK;
		}
		else if (Copy_u8PinValue == DIO_HIGH)//CHECKING IF THE THE VALUE OF THE  REQUIRED PIN WHICH BELONGS TO DDRD IS LOW AND ASSIGN
		{									//THE CORESSPONDING VALUE
			setBit(PORTD,(Copy_u8PinNumber%8));
			return OK;
		}
		else //IF THE VALUE NEITHER HIGH NOR LOW RETURNING AN ERROR SIGNAL
			return ERROR;
	break;
	}
return ERROR; // RETURNING THE ERROR INDICATOR INCASE OF ANY UNEXPECTED EVENT



}



/* **************************************************************************************************************
 *																												*
 * "DIO_u8GetPortValue"																						    *
 *   																											*
 * 		-FUNCTION RESPOSIBLE FOR GETTING THE VALUE OF A SPECIFIC PIN REGISTER									*
 * 	TAKES:																										*
 * 		-IT TAKES THE NAME OF THE REQUIRED PIN REGISTER															*
 * 		-IT TAKES A POINT TO RETURN THE VALUE OF THE PORT WITHIN IT 											*
 * 	RETURNS:																									*
 * 		-IT RETURNS THE CORRESPONDING VALUE OF THE REQUIRED PIN REGISTER IN YOUR CODE							*
 * 	 		-IT RETURNS AN INDICATION OF THE SUCCESS OF THE OPERATION 											*
 * 			-IF THE OPERATION PERFORMED SUCCESSFULLY IT WILL RETURN VALUE OF '0'								*
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '1'						*
 																									        	*
 * 																												*
 * 																												*
 * **************************************************************************************************************/



u8 DIO_u8GetPortValue(u8 Copy_u8PortName,pu8 Copy_pu8ReturnedValue) // HEADER OF THE FUNCTION
{

return Copy_u8PortName;


}


/* **************************************************************************************************************
 *																												*
 * "DIO_u8GetPinValue"																						    *
 *   																											*
 * 		-FUNCTION RESPOSIBLE FOR GETTING THE VALUE OF A SPECIFIC PIN IN A SPECIFIC PINREGISTER					*
 * 	TAKES:																										*
 * 		-IT TAKES THE NUMBER OF THE REQUIRED PIN																*
 * 		-IT TAKES POINTER TO RETURN THE VALUE OF THE REQUIRED PIN INTO IT 										*
 * 	RETURNS:																									*
 * 		-IT RETURNS THE CORRESPONDING VALUE OF THE REQUIRED PIN													*
 * 		-IT RETURNS INDICATOR FOR THE STATUS OF THE OPERATION													*
 * 			-IF THE OPERATION PERFORMED SUCCESSFULLY IT WILL RETURN  VALUE OF '0'								*
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '1'						*
 * 																												*
 * 	NOTE **:-																									*
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE VALUE BEFORE PROCEEDING IN YOUR CODE							*
 * 																												*
 * 																												*
 * **************************************************************************************************************/

u8 DIO_u8GetPinValue(u8 Copy_u8PinNumber,pu8 Copy_pu8ReturnedValue) // HEADER OF THE FUNCTION
{
	switch (Copy_u8PinNumber)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
         *(Copy_pu8ReturnedValue)=getBit(PINA,Copy_u8PinNumber);
         return OK;
         break;
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
    case 14:
	case 15:
        *(Copy_pu8ReturnedValue)=getBit(PINB,Copy_u8PinNumber);
        return OK;
        break;
    case 16:
    case 17:
    case 18:
    case 19:
   	case 20 :
   	case 21:
    case 22:
   	case 23:
        *(Copy_pu8ReturnedValue)=getBit(PINC,Copy_u8PinNumber);
        return OK;
        break;
   	case 24:
   	case 25:
   	case 26:
   	case 27:
   	case 28:
   	case 29:
   	case 30:
   	case 31:
        *(Copy_pu8ReturnedValue)=getBit(PIND,Copy_u8PinNumber);
        return OK;
        break;
   	default : return ERROR;
	}
return ERROR;



}


