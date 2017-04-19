/*
 * LCD_interface.c
 *
 *  Created on: APR 2, 2017
 *      Author: Amir Salama
 *  VERSION 2
 */

#ifndef LCD_interface
#define LCD_interface

	//---------intialization function--------
	u8 LCD_u8Init(void);  //LCD initialization function by which you can configure your LCD to write in one line or two lines, control your
                                 //font 5*8 or 5*11 ,control LCD Display Control, cursor and cursor blinking showing and LCD Clearing

	u8 LCD_u8Clear(void);

	//---------goto xy position on LCD function----------
	u8 LCD_u8GotoXY(u8 Copy_u8X,u8 Copy_u8Y);	//if you put 1 in first arg(LineSelection) you will write in first line if 2 you
	                           // will write in second line --- and second arg you will put value from 0 -> 15
							   //to write in a certain position in specific line according to you choice in first arg


	//---------write string functions-----------
	u8 LCD_u8WriteString(pu8 Copy_u8String,u8 Copy_u8Length);
    u8 LCD_u8WriteInteger(u8 Copy_u8Number);

    u8 LCD_u8TurnOn(void);    //use this function to turn LCD on
    u8 LCD_u8TurnOff(void);   // to turn LCD off

#endif





