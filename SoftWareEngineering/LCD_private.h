/*
 * LCD_private.h
 *
 *  Created on: APR 2, 2017
 *      Author: Amir Salama
 *  VERSION 1
 */

#ifndef LCD_private
#define LCD_private

	#define PRIVATE_u8SETLCDCMD(Copy_u8PinNo7,Copy_u8PinNo6,Copy_u8PinNo5,Copy_u8PinNo4,Copy_u8PinNo3,Copy_u8PinNo2,Copy_u8PinNo1,Copy_u8PinNo0)        Private_u8ConcHelper1(Copy_u8PinNo7,Copy_u8PinNo6,Copy_u8PinNo5,Copy_u8PinNo4,Copy_u8PinNo3,Copy_u8PinNo2,Copy_u8PinNo1,Copy_u8PinNo0)
	#define Private_u8ConcHelper1(Copy_u8PinNo7,Copy_u8PinNo6,Copy_u8PinNo5,Copy_u8PinNo4,Copy_u8PinNo3,Copy_u8PinNo2,Copy_u8PinNo1,Copy_u8PinNo0)   0b##Copy_u8PinNo7##Copy_u8PinNo6##Copy_u8PinNo5##Copy_u8PinNo4##Copy_u8PinNo3##Copy_u8PinNo2##Copy_u8PinNo1##Copy_u8PinNo0

	#define LCD_u8ClearScreenCommand		    0X01
	#define LOCAL_u8LCDFIRSTLINE     		    128
	#define LOCAL_u8LCDSECONDLINE        		192
	#define LOCAL_u8LCDLINE1     			    1
    #define LOCAL_u8LCDLINE2     			    2

	//-----------DEfault LCD Configuration Pins--------------
	#define LCD_u8LINESNO           DIO_HIGH       //one Lines/two line ---> 0/1
	#define LCD_u8FONT              DIO_HIGH       //font size is 5*8/5*11 ---->   0/1
	#define LCD_u8DISPLAY           DIO_HIGH       //display off/on  ---> 0/1
	#define LCD_u8CURSOR            DIO_LOW        //Cursor off/on   --->0/1
	#define LCD_u8CURSORBLINK       DIO_LOW       //Cursor blink off/on  --->0/1



	//---------write Command function--------
	u8 LCD_u8WriteCommand(u8 Copy_u8Command);   //through this function you can configure RS to 1 and write a Command by it you can to write
	                             //on your LCD on first line or second line and with any offset


	//---------write data function-----------
	u8 LCD_u8WriteData(u8 Copy_u8data);   //through this function you can configure RS to 0 and send your data you want
	                            //to display it on your LCD by Char


#endif
