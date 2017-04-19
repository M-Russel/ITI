/*
 * LCD_prog.c
 *
 *  Created on: APR 2, 2017
 *      Author: Amir Salama
 *  VERSION 2
 */

#include"Limits.h"
#include"utils.h"
#include"std_types.h"
#include"DIO_interface.h"

#include"LCD_interface.h"
#include"LCD_config.h"
#include"LCD_private.h"

/* ***************************************************************************************************************
 *																												 *
 * "LCD_u8Init"																									 *
 *   																											 *
 * 		-FUNCTION RESPOSIBLE FOR Initializing the hardware and the initial configuration values                  *
 * 	TAKES:																										 *
 * 		-No Input arguments                                              										 *
 * 	RETURNS:																								     *
 * 		-IT RETURNS AN INDICATION OF THE SUCCESS OF THE OPERATION 												 *
 * 			-IF THE OPERATION PERFORMED SUCCESSFULLY IT WILL RETURN VALUE OF '0'							     *
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '1'					     *
 * 																												 *
 * 	NOTE **:-																						             *
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE INDICATOR BEFORE PROCEEDING IN YOUR CODE			             *
 * 																												 *
 * 																												 *
 * ***************************************************************************************************************/

u8 LCD_u8Init(void)
{
	u8 Local_u8CheckError=OK;   // Variable to store the return status of LCD_u8Init Function
	u8 Local_u8FuncState;  		// Variable to store the return status of each Function in LCD_u8Init

	u8 Local_u8Data;      //local variable to store the configuration values as a specific Command to be ready to send it to LCD_u8WriteCommand

	Local_u8FuncState=DIO_u8SetPortValue(DIO_PORT_HIGH,&LCD_u8DATAPORT);    //initialize LCD data port(as chosen in config file) to output direction
	if(ERROR==Local_u8FuncState)        //if any function called inside this function return ERROR it will effect on the return of this function to return ERROR
	{
		Local_u8CheckError=ERROR;
	}

	Local_u8FuncState=DIO_u8SetPinDirection(LCD_u8RS,DIO_OUTPUT);           // initialize LCD control PINs(as chosen in config file) to output direction
	if(ERROR==Local_u8FuncState)
	{
		Local_u8CheckError=ERROR;
	}

	Local_u8FuncState=DIO_u8SetPinDirection(LCD_u8RW,DIO_OUTPUT);
	if(ERROR==Local_u8FuncState)
	{
		Local_u8CheckError=ERROR;
	}

	Local_u8FuncState=DIO_u8SetPinDirection(LCD_u8ENABLE,DIO_OUTPUT);
	if(ERROR==Local_u8FuncState)
	{
		Local_u8CheckError=ERROR;
	}

	Local_u8FuncState=DIO_u8SetPinDirection(LCD_u8ANODEVCC,DIO_OUTPUT);
	if(ERROR==Local_u8FuncState)
	{
		Local_u8CheckError=ERROR;
	}

	Local_u8FuncState=DIO_u8SetPinValue(LCD_u8ANODEVCC,DIO_LOW);   //to initialize LCD without turnning it on
	if(ERROR==Local_u8FuncState)
	{
		Local_u8CheckError=ERROR;
	}


	_delay_ms(50);      // delay for 50 mseconds to be ready to get a command
	Local_u8Data = PRIVATE_u8SETLCDCMD(0,0,1,1,LCD_u8LINESNO,LCD_u8FONT,0,0);    //number of lines 0 for one line, 1 for 2 line & font type
	Local_u8FuncState=LCD_u8WriteCommand(Local_u8Data);
	if(ERROR==Local_u8FuncState)
	{
		Local_u8CheckError=ERROR;
	}

	_delay_ms(2);

	Local_u8Data = PRIVATE_u8SETLCDCMD(0,0,0,0,1,LCD_u8DISPLAY,LCD_u8CURSOR,LCD_u8CURSORBLINK);
	Local_u8FuncState=LCD_u8WriteCommand(Local_u8Data);
	if(ERROR==Local_u8FuncState)
	{
		Local_u8CheckError=ERROR;
	}
	_delay_ms(2);

	return Local_u8CheckError;
}

/* ***************************************************************************************************************
 *																												 *
 * "LCD_u8Clear"																								 *
 *   																											 *
 * 		-FUNCTION RESPOSIBLE FOR IClear LCD and return cursor to home position(first character in the first line)*
 * 	TAKES:																										 *
 * 		-No Input arguments                                              										 *
 * 	RETURNS:																								     *
 * 		-IT RETURNS AN INDICATION OF THE SUCCESS OF THE OPERATION 												 *
 * 			-IF THE OPERATION PERFORMED SUCCESSFULLY IT WILL RETURN VALUE OF '0'							     *
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '1'					     *
 * 																												 *
 * 	NOTE **:-																						             *
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE INDICATOR BEFORE PROCEEDING IN YOUR CODE			             *
 * 																												 *
 * 																												 *
 * ***************************************************************************************************************/


u8 LCD_u8Clear(void)
{
	u8 Local_u8CheckError;
	Local_u8CheckError = LCD_u8WriteCommand(LCD_u8ClearScreenCommand);  // to clear LCD

	return Local_u8CheckError;
}

/* ***************************************************************************************************************
 *																												 *
 * "LCD_u8WriteCommand"																						     *
 *   																											 *
 * 		-FUNCTION RESPOSIBLE FOR sending commands to LCD data pins												 *
 * 	TAKES:																										 *
 * 		-This function should take one input argument															 *
 *			1	Copy_u8Command: 																				 *
 *			Type: unsigned char(u8)																				 *
 *			Description: represents the command which user wants to send										 *
 *																												 *
 * 	RETURNS:																								     *
 * 		-IT RETURNS AN INDICATION OF THE SUCCESS OF THE OPERATION 												 *
 * 			-IF THE OPERATION PERFORMED SUCCESSFULLY IT WILL RETURN VALUE OF '0'							     *
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '1'					     *
 * 																												 *
 * 	NOTE **:-																						             *
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE INDICATOR BEFORE PROCEEDING IN YOUR CODE			             *
 * 																												 *
 * 																												 *
 * ***************************************************************************************************************/


u8 LCD_u8WriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8CheckError=OK;   // Variable to store the return status of LCD_u8WriteCommand Function
	u8 Local_u8FuncState;  		// Variable to store the return status of each Function in LCD_u8WriteCommadn

	Local_u8FuncState=DIO_u8SetPinValue(LCD_u8RS,DIO_LOW);       //rs=0  to write command on LCD
	if(ERROR==Local_u8FuncState)
	{
		Local_u8CheckError=ERROR;
	}

	Local_u8FuncState=DIO_u8SetPinValue(LCD_u8RW,DIO_LOW);       	//r/w=0  to write on LCD either data or command
	if(ERROR==Local_u8FuncState)
	{
		Local_u8CheckError=ERROR;
	}

	Local_u8FuncState=DIO_u8SetPortValue(Copy_u8Command,&LCD_u8DATAPORT);	 // to send this command to LCD
	if(ERROR==Local_u8FuncState)
	{
		Local_u8CheckError=ERROR;
	}

	Local_u8FuncState=DIO_u8SetPinValue(LCD_u8ENABLE,DIO_HIGH);   //enable high for 2ms
	if(ERROR==Local_u8FuncState)
	{
		Local_u8CheckError=ERROR;
	}

	_delay_ms(2);

	Local_u8FuncState=DIO_u8SetPinValue(LCD_u8ENABLE,DIO_LOW);
	if(ERROR==Local_u8FuncState)
	{
		Local_u8CheckError=ERROR;
	}


	return Local_u8CheckError;
}

/* ***************************************************************************************************************
 *																												 *
 * "LCD_u8WriteData"																						     *
 *   																											 *
 * 		-FUNCTION RESPOSIBLE FOR sending data to LCD data pins	                                                 *
 * 	TAKES:																										 *
 * 		-This function should take one input argument															 *
 *			1	Copy_u8Data: 																				     *
 *			Type: unsigned char(u8)																				 *
 *			Description: represents the data which user wants to send										     *
 *																												 *
 * 	RETURNS:																								     *
 * 		-IT RETURNS AN INDICATION OF THE SUCCESS OF THE OPERATION 												 *
 * 			-IF THE OPERATION PERFORMED SUCCESSFULLY IT WILL RETURN VALUE OF '0'							     *
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '1'					     *
 * 																												 *
 * 	NOTE **:-																						             *
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE INDICATOR BEFORE PROCEEDING IN YOUR CODE			             *
 * 																												 *
 * 																												 *
 * ***************************************************************************************************************/



u8 LCD_u8WriteData(u8 Copy_u8data)
{
	u8 Local_u8CheckError=OK;   // Variable to store the return status of LCD_u8WriteData Function
	u8 Local_u8FuncState;  		// Variable to store the return status of each Function in LCD_u8WriteCommadn

	Local_u8FuncState=DIO_u8SetPinValue(LCD_u8RS,DIO_HIGH);         //rs=1  to write data on LCD
	if(ERROR==Local_u8FuncState)
	{
		Local_u8CheckError=ERROR;
	}

    Local_u8FuncState=DIO_u8SetPinValue(LCD_u8RW,DIO_LOW);      	//r/w=0  to write on LCD either data or command
	if(ERROR==Local_u8FuncState)
	{
		Local_u8CheckError=ERROR;
	}

	Local_u8FuncState=DIO_u8SetPortValue(Copy_u8data,&LCD_u8DATAPORT);   // to send this data to LCD
	if(ERROR==Local_u8FuncState)
	{
		Local_u8CheckError=ERROR;
	}

	Local_u8FuncState=DIO_u8SetPinValue(LCD_u8ENABLE,DIO_HIGH);     //enable high for 2ms
	if(ERROR==Local_u8FuncState)
	{
		Local_u8CheckError=ERROR;
	}

	_delay_ms(2);

	Local_u8FuncState=DIO_u8SetPinValue(LCD_u8ENABLE,DIO_LOW);
	if(ERROR==Local_u8FuncState)
	{
		Local_u8CheckError=ERROR;
	}

	return Local_u8CheckError;
}

/* ***************************************************************************************************************
 *																												 *
 * "LCD_u8WriteString"																						     *
 *   																											 *
 * 		-FUNCTION RESPOSIBLE FOR sending string to print it on LCD data pins	                                 *
 * 	TAKES:																										 *
 * 		-This function should take two input arguments															 *
 *			1	Copy_pu8String: 																			     *
 *			     Type: pointer to unsigned char(pu8)															 *
 *			     Description: represents the characters which user wants to send								 *
 *			2	Copy_u8Length: 																					 *
 *			     Type: unsigned char(u8)																		 *
 *			     Description: represents the string length which user wants to write on LCD Screen				 *
 *																												 *
 *																												 *
 *																												 *
 * 	RETURNS:																								     *
 * 		-IT RETURNS AN INDICATION OF THE SUCCESS OF THE OPERATION 												 *
 * 			-IF THE OPERATION PERFORMED SUCCESSFULLY IT WILL RETURN VALUE OF '0'							     *
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '1'					     *
 * 																												 *
 * 	NOTE **:-																						             *
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE INDICATOR BEFORE PROCEEDING IN YOUR CODE			             *
 * 																												 *
 * 																												 *
 * ***************************************************************************************************************/

u8 LCD_u8WriteString(pu8 Copy_u8String,u8 Copy_u8Length)
{
	u8 Local_u8CheckError=OK;   // Variable to store the return status of LCD_u8WriteString Function
	u8 Local_u8FuncState;  		// Variable to store the return status of each Function in LCD_u8WriteString

	u8 Local_u8Counter;

	for(Local_u8Counter=0 ; Local_u8Counter<Copy_u8Length ; Local_u8Counter++)  // loop to send this string character by character
	{
		Local_u8FuncState=LCD_u8WriteData(Copy_u8String[Local_u8Counter]);
		if(ERROR==Local_u8FuncState)
		{
			Local_u8CheckError=ERROR;
		}
	}
	return Local_u8CheckError;
}

/* ***************************************************************************************************************
 *																												 *
 * "LCD_u8GotoXY"																		        			     *
 *   																											 *
 * 		-FUNCTION RESPOSIBLE FOR going by cursor to specific position on lcd	                                 *
 * 	TAKES:																										 *
 * 		-This function should take two input arguments															 *
 *			1	Copy_u8X: 																						 *
 *			Type: unsigned char(u8)																				 *
 *			Description: represents the horizontal position														 *
 *			2	Copy_u8Y: 																						 *
 *			Type: unsigned char(u8)																				 *
 *			Description: represents the vertical position														 *
 *																												 *
 *																												 *
 *																												 *
 *																												 *
 * 	RETURNS:																								     *
 * 		-IT RETURNS AN INDICATION OF THE SUCCESS OF THE OPERATION 												 *
 * 			-IF THE OPERATION PERFORMED SUCCESSFULLY IT WILL RETURN VALUE OF '0'							     *
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '1'					     *
 * 																												 *
 * 	NOTE **:-																						             *
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE INDICATOR BEFORE PROCEEDING IN YOUR CODE			             *
 * 																												 *
 * 																												 *
 * ***************************************************************************************************************/


u8 LCD_u8GotoXY(u8 Copy_u8X,u8 Copy_u8Y)
{
	u8 Local_u8CheckError=OK;   // Variable to store the return status of LCD_u8WriteString Function
	u8 Local_u8FuncState;  		// Variable to store the return status of each Function in LCD_u8WriteString

	if( 0 <= Copy_u8Y && 15 >= Copy_u8Y )    //checking condition if Y position within LCD columns range (from 0 to 15)
	{
		if( LOCAL_u8LCDLINE1 == Copy_u8X )   // if X indicates to LCD first line
		{
			Local_u8FuncState=LCD_u8WriteCommand(LOCAL_u8LCDFIRSTLINE+Copy_u8Y);   // move the cursor to first line and shifted by Y value
			if(ERROR==Local_u8FuncState)
			{
				Local_u8CheckError=ERROR;
			}
		}

		else if( LOCAL_u8LCDLINE2 == Copy_u8X )  // if X indicates to LCD first line
		{
			Local_u8FuncState=LCD_u8WriteCommand(LOCAL_u8LCDSECONDLINE+Copy_u8Y);   // move the cursor to second line and shifted by Y value
			if(ERROR==Local_u8FuncState)
			{
				Local_u8CheckError=ERROR;
			}
		}

		else  // if X indicates neither LCD first line nor second line
		{
			Local_u8CheckError=ERROR;
		}
	}

	else
	{
		Local_u8CheckError = ERROR;
	}

	return Local_u8CheckError;
}

/* ***************************************************************************************************************
 *																												 *
 * "LCD_u8WriteInteger"																		        			 *
 *   																											 *
 * 		-FUNCTION RESPOSIBLE FOR sending integer to print it on LCD data pins	                                 *
 * 	TAKES:																										 *
 * 		-This function should take one input argument															 *
 *			 1-	Copy_u8Number: 																					 *
 *			   Type: unsigned char (u8)																  			 *
 *			   Description: represents the number which user wants to write on LCD Screen						 *
 *																												 *
 *																												 *
 * 	RETURNS:																								     *
 * 		-IT RETURNS AN INDICATION OF THE SUCCESS OF THE OPERATION 												 *
 * 			-IF THE OPERATION PERFORMED SUCCESSFULLY IT WILL RETURN VALUE OF '0'							     *
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '1'					     *
 * 																												 *
 * 	NOTE **:-																						             *
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE INDICATOR BEFORE PROCEEDING IN YOUR CODE			             *
 * 																												 *
 * 																												 *
 * ***************************************************************************************************************/



u8 LCD_u8WriteInteger(u8 Copy_u8Number)
{
	u8 Local_u8CheckError;   // Variable to store the return status of LCD_u8WriteIntegerFunction
	u8 Local_u8Digit;        // variable to hold the input number digit by digit to save it in Local_u8StringArr array which declared below
	u8 Local_u8Num;          // variable to hold the input number to process on it to know the number of digits of this input number
	u8 Local_u8NumLength=0;  // variable used as a counter to count the number of digits of this input number and used as an index of the Local_u8StringArr
	u8 Local_u8StringLength; // variable used as a counter to count the number of digits of this input number and used as a second argumnet to WriteString func
	u8 Local_u8StringArr[3]; // array to store the input number as an array of characters


	Local_u8Num = Copy_u8Number;

    while(Local_u8Num != 0)         // loop till the input number is equal to zero
    {
    	Local_u8Num = Local_u8Num / 10;    // division by 10 to minimize the number of digits of the input number by one till this number equal to zero to know number of its digits
        Local_u8NumLength++;
    }

	Local_u8StringLength=Local_u8NumLength;
    Local_u8NumLength--;        //decrement the number of didgits to can use this variable as an index of the array because the array index starts with zero

    while(Copy_u8Number != 0)
    {
    	Local_u8Digit = Copy_u8Number % 10;         // the remainder refers to the digit on the right side
    	Copy_u8Number = Copy_u8Number / 10;         // the quotient to truncate this digit to know the next one in the next iteration
    	Local_u8StringArr[Local_u8NumLength]=Local_u8Digit+'0';   // add zero character to convert the digit to character
        Local_u8NumLength--;    // to store the next digit in the previous elemnt to get the final string like the input number in the same order
    }

    Local_u8CheckError=LCD_u8WriteString(Local_u8StringArr,Local_u8StringLength);

    return Local_u8CheckError;
}


/* ***************************************************************************************************************
 *																												 *
 * "LCD_u8TurnOn"																								 *
 *   																											 *
 * 		-FUNCTION RESPOSIBLE FOR turning LCD on   															     *
 * 	TAKES:																										 *
 * 		-No Input arguments                                              										 *
 * 	RETURNS:																								     *
 * 		-IT RETURNS AN INDICATION OF THE SUCCESS OF THE OPERATION 												 *
 * 			-IF THE OPERATION PERFORMED SUCCESSFULLY IT WILL RETURN VALUE OF '0'							     *
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '1'					     *
 * 																												 *
 * 	NOTE **:-																						             *
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE INDICATOR BEFORE PROCEEDING IN YOUR CODE			             *
 * 																												 *
 * 																												 *
 * ***************************************************************************************************************/



u8 LCD_u8TurnOn(void)
{
	u8 Local_u8CheckError;   // Variable to store the return status of LCD_u8WriteIntegerFunction
	Local_u8CheckError=DIO_u8SetPinValue(LCD_u8ANODEVCC,DIO_HIGH);  // set LCD vcc pin to high to turn it on

	return Local_u8CheckError;
}

/* ***************************************************************************************************************
 *																												 *
 * "LCD_u8TunrOff"																								 *
 *   																											 *
 * 		-FUNCTION RESPOSIBLE FOR turning LCD off                                   								 *
 * 	TAKES:																										 *
 * 		-No Input arguments                                              										 *
 * 	RETURNS:																								     *
 * 		-IT RETURNS AN INDICATION OF THE SUCCESS OF THE OPERATION 												 *
 * 			-IF THE OPERATION PERFORMED SUCCESSFULLY IT WILL RETURN VALUE OF '0'							     *
 * 			-IF THE OPERATION HAD ANY TROUBLE FOR ANY REASON IT WILL RETURN VALUE OF '1'					     *
 * 																												 *
 * 	NOTE **:-																						             *
 * 		IT IS PREFERED TO CHECK THE VALUE OF THE INDICATOR BEFORE PROCEEDING IN YOUR CODE			             *
 * 																												 *
 * 																												 *
 * ***************************************************************************************************************/



u8 LCD_u8TurnOff(void)
{
	u8 Local_u8CheckError;   // Variable to store the return status of LCD_u8WriteIntegerFunction
	Local_u8CheckError=DIO_u8SetPinValue(LCD_u8ANODEVCC,DIO_LOW);   // set LCD anodevcc pin to low to turn it off

	return Local_u8CheckError;
}
