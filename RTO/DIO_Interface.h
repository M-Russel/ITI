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

#define DIO_HIGH 1 // DIO PIN AS HIGH LOGIC
#define DIO_LOW 0 // DIO PIN AS LOW LOGIC

#define DIO_INPUT 0 // DIO DIRECTION AS INPUT
#define DIO_OUTPUT 1 // DIO DIRECTION AS OUTPUT

#define DIO_PORT_INPUT 0x00 //DIO FULL PORT AS INPUT
#define DIO_PORT_OUTPUT 0xff // DIO FULL PORT AS OUTPUT


#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
#define PIN_8 8
#define PIN_9 9
#define PIN_10 10
#define PIN_11 11
#define PIN_12 12
#define PIN_13 13
#define PIN_14 14
#define PIN_15 15
#define PIN_16 16
#define PIN_17 17
#define PIN_18 18
#define PIN_19 19
#define PIN_20 20
#define PIN_21 21
#define PIN_22 22
#define PIN_23 23
#define PIN_24 24
#define PIN_25 25
#define PIN_26 26
#define PIN_27 27
#define PIN_28 28
#define PIN_29 29
#define PIN_30 30
#define PIN_31 31



void DIO_voidInitialize(void);

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
