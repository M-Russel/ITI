/*
 * LCD_Interface.h
 *
 *  Created on: Dec 21, 2016
 *      Author: Russel
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define x(V0,V1,V2,V3,V4,V5,V6,V7) y(V0,V1,V2,V3,V4,V5,V6,V7)
#define y(V0,V1,V2,V3,V4,V5,V6,V7) V0##V1##V2##V3##V4##V5##V6##V7



void LCD_voidWriteCommand(u8 Copy_Command);
void LCD_voidWriteData(u8 Copy_Data);
void LCD_voidInit(void);


#endif /* LCD_INTERFACE_H_ */
