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

#define x(V0,V1,V2,V3,V4,V5,V6,V7) y(V0,V1,V2,V3,V4,V5,V6,V7)
#define y(V0,V1,V2,V3,V4,V5,V6,V7) V0##V1##V2##V3##V4##V5##V6##V7



u8 LCD_u8WriteCommand(u8 Copy_Command);
u8 LCD_u8WriteData(u8 Copy_Data);
u8 LCD_u8Init(void);
u8 LCD_u8ClearScreen();
u8 LCD_u8WriteString(u8 Copy_u8String[]);
u8 LCD_u8CursorPosition(u8 Copy_u8LineNumber, u8 Copy_u8DigitNumber);
u8 LCD_u8WriteCgRam(void);
u8 LCD_u8WriteDdRam(void);

#endif /* LCD_INTERFACE_H_ */
