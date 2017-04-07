/*
 * LCD_Interface.h
 *
  *  Created on: Dec 21, 2016
 *      Author: Russel
 *  Edited on :January 8,2017
 *  v :2.0
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


#define BASE_CGR 0x40
#define BASE_DDRAM 0x80
#define SECONDLINE_DDRAM 0b11000000
#define ERROR 1
#define OK 0
#define FIRST_LINE 1
#define SECOND_LINE 2
#define LINE_BASE 0
#define LINE_END 16


#define LCD_Enable PIN_18



u8 LCD_u8WriteCommand(u8 Copy_Command);
u8 LCD_u8WriteData(u8 Copy_Data);
u8 LCD_u8WriteData1(u8 Copy_Data);

u8 LCD_u8Init(void);
u8 LCD_u8ClearScreen();
//u8 LCD_u8WriteString(u8 Copy_u8String[]);
u8 LCD_u8WriteString(u8 Copy_u8String[],pu8 Copy_pu8StringCounter);
u8 LCD_u8CursorPosition(u8 Copy_u8LineNumber, u8 Copy_u8DigitNumber);
u8 LCD_u8WriteCgRam(void);
u8 LCD_u8WriteDdRam(void);
u8 LCD_u8InitFunctionSet(void);
u8 LCD_u8InitDisplaySettings(void);


#endif /* LCD_INTERFACE_H_ */
