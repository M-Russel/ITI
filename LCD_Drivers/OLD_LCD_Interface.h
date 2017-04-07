/*
 * LCD_Interface.h
 *
  *  Created on: Dec 21, 2016
 *      Author: Russel
 *  Edited on :January 8,2017
 *  v :2.0
 */

#ifndef OLD_LCD_INTERFACE_H_
#define OLD_LCD_INTERFACE_H_

#define x(V0,V1,V2,V3,V4,V5,V6,V7) y(V0,V1,V2,V3,V4,V5,V6,V7)
#define y(V0,V1,V2,V3,V4,V5,V6,V7) V0##V1##V2##V3##V4##V5##V6##V7


#define LCD_BASE_CGR 0x40
#define LCD_BASE_DDRAM 0x80
#define LCD_SECONDLINE_DDRAM 0b11000000
#define ERROR 1
#define OK 0
#define LCD_FIRST_LINE 1
#define LCD_SECOND_LINE 2
#define LCD_LINE_BASE 0
#define LCD_LINE_END 16
#define LCD_DIGIT_ZERO   0
#define LCD_DIGIT_ONE     1
#define LCD_DIGIT_TWO    2
#define LCD_DIGIT_THREE 3
#define LCD_DIGIT_FOUR  4
#define LCD_DIGIT_FIVE    5
#define LCD_DIGIT_SIX      6
#define LCD_DIGIT_SEVEN 7
#define LCD_DIGIT_EIGHT  8
#define LCD_DIGIT_NINE    9
#define LCD_DIGIT_TEN    10
#define LCD_DIGIT_ELEVEN 11
#define LCD_DIGIT_TWELVE 12
#define LCD_DIGIT_THIRTEEN 13
#define LCD_DIGIT_FOURTEEN 14
#define LCD_DIGIT_FIVTEEN     15





u8 LCD_u8WriteCommand(u8 Copy_Command);
u8 LCD_u8WriteData(u8 Copy_Data);
u8 LCD_u8Init(void);
u8 LCD_u8ClearScreen();
u8 LCD_u8WriteString(u8 Copy_u8String[]);
u8 LCD_u8CursorPosition(u8 Copy_u8LineNumber, u8 Copy_u8DigitNumber);
u8 LCD_u8WriteCgRam(void);
u8 LCD_u8WriteDdRam(void);

#endif /* OLD_LCD_INTERFACE_H_ */
