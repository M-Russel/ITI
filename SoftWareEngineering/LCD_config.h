/*
 * LCD_config.h
 *
 *  Created on: APR 2, 2017
 *      Author: Amir Salama
 *  VERSION 1
 */

#ifndef LCD_config
#define LCD_config

//-----------LCD Control Pins-----------

	#define LCD_u8RS                PIN_8       //Register Select Pin 0 to write cmd and 1 to wrire Data by default to Pin8
	#define LCD_u8RW                PIN_9	  	 //Write/Read Pin 0 to write 1 to read by default to Pin9
	#define LCD_u8ENABLE            PIN_10      //Enable Pin by default to Pin10
	#define LCD_u8ANODEVCC			PIN_11		//ANODE VCC Pin to control LCD screen

//-----------LCD Data or Command Port--------------
//PORTA PORTB PORTC PORTD
	#define LCD_u8DATAPORT          PORTA

#endif





