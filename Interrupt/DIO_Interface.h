/*
 * DIO_Interface.h
 *
 *  Created on: Dec 21, 2016
 *      Author: Russel
 *      Version : 2
 *
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "std_types.h"
#define OK 1
#define ERROR 0

#define DIO_HIGH 1 // DIO PIN AS HIGH LOGIC
#define DIO_LOW 0 // DIO PIN AS LOW LOGIC

#define DIO_INPUT 0 // DIO DIRECTION AS INPUT
#define DIO_OUTPUT 1 // DIO DIRECTION AS OUTPUT

#define DIO_PORT_INPUT 0x00 //DIO FULL PORT AS INPUT
#define DIO_PORT_OUTPUT 0xff // DIO FULL PORT AS OUTPUT

#define DIO_PORT_MIN 0x00 // DIO FULL PORT AS LOW LOGIC
#define DIO_PORT_MAX 0xff //DIO FULL PORT AS HIGH LOGIC
#define DDR_A (&DDRA) // THE ADDRESS OF DATA DIRECTION REGISTER FOR PORT A
#define DDR_B (&DDRB) // THE ADDRESS OF DATA DIRECTION REGISTER FOR PORT B
#define DDR_C (&DDRC) // THE ADDRESS OF DATA DIRECTION REGISTER FOR PORT C
#define DDR_D (&DDRD) // THE ADDRESS OF DATA DIRECTION REGISTER FOR PORT D

#define PORT_A (&PORTA) //THE ADDRESS OF PORT A REGISTER
#define PORT_B (&PORTB) //THE ADDRESS OF PORT B REGISTER
#define PORT_C (&PORTC) //THE ADDRESS OF PORT C REGISTER
#define PORT_D (&PORTD) //THE ADDRESS OF PORT D REGISTER

#define PIN_A (&PINA) //THE ADDRESS OF PIN A REGISTER
#define PIN_B (&PINB) //THE ADDRESS OF PIN B REGISTER
#define PIN_C (&PINC) //THE ADDRESS OF PIN C REGISTER
#define PIN_D (&PIND) //THE ADDRESS OF PIN D REGISTER


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
u8 DIO_u8SetPortDirection(pu8 Copy_pu8DDR , u8 Copy_u8Direction);


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
u8 DIO_u8SetPinDirection(u8 Copy_u8PinNumber , u8 Copy_u8Direction);

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
u8 DIO_u8SetPortValue(pu8 Copy_pu8PortName , u8 Copy_u8PortValue);

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
u8 DIO_u8SetPinValue(u8 Copy_u8PinNumber,u8 Copy_u8PinValue);

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
u8 DIO_u8GetPortValue(u8 Copy_u8PortName,pu8 Copy_pu8ReturnedValue);

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
u8 DIO_u8GetPinValue(u8 Copy_u8PinNumber,pu8 Copy_pu8ReturnedValue);





#endif /* DIO_INTERFACE_H_ */
