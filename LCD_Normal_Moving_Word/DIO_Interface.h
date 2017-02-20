/*
 * DIO_Interface.h
 *
 *  Created on: Dec 21, 2016
 *      Author: Russel
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
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

// getpinvalue (pin number , u8* pinvalue)
//return error status
u8 DIO_u8SetPortDirection(pu8 Copy_DDR , u8 Copy_Direction); // PROTOTYPE OF THE FUNCTION RESPOSIBLE FOR SETTING THE DIRECTION OF A SPECIFIC DATA DIRECTION REGISTER REGISTER
u8 DIO_u8SetPinDirection(pu8 Copy_DDR , u8 Copy_PinNumber , u8 Copy_Direction); // PROTOTYPE OF THE FUNCTION RESPOSIBLE FOR SETTING THE DIRECTION OF A SPECIFIC PIN IN A SPECIFIC DATA DIRECTION  REGISTER
u8 DIO_u8SetPortValue(pu8 Copy_PortName , u8 Copy_PortValue); // PROTOTYPE OF THE FUNCTION RESPOSIBLE FOR SETTING THE VALUE OF A SPECIFIC PORT REGISTER
u8 DIO_u8SetPinValue(pu8 Copy_PortName , u8 Copy_PinNumber,u8 Copy_PinValue); // PROTOTYPE OF THE FUNCTION RESPOSIBLE FOR SETTING THE VALUE OF A SPECIFIC PIN IN A SPECIFIC PORT REGISTER
u8 DIO_u8GetPortValue(u8 Copy_PortName); // PROTOTYPE OF THE FUNCTION RESPOSIBLE FOR GETTING THE VALUE OF A SPECIFIC PIN REGISTER
u8 DIO_u8GetPinValue(u8 Copy_PortName , u8 Copy_PinNumber); // PROTOTYPE OF THE FUNCTION RESPOSIBLE FOR GETTING THE VALUE OF A SPECIFIC PIN IN A SPECIFIC PIN REGISTER





#endif /* DIO_INTERFACE_H_ */