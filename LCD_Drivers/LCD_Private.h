/*
 * LCD_Private.h
 *
 *  Created on: Mar 25, 2017
 *      Author: root
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define LCD_ClearScreen 0b00000001
#define LCD_CursorHome 0b00000010

/* Function Set */

#define x(V0,V1,V2,V3,V4,V5,V6,V7) y(V0,V1,V2,V3,V4,V5,V6,V7)
#define y(V0,V1,V2,V3,V4,V5,V6,V7) 0b##V0##V1##V2##V3##V4##V5##V6##V7

#define LCD_COMMAND(V0,V1,V2,V3,V4,V5,V6,V7) k(V0,V1,V2,V3,V4,V5,V6,V7)
#define k(V0,V1,V2,V3,V4,V5,V6,V7) 0b##V0##V1##V2##V3##V4##V5##V6##V7



#endif /* LCD_PRIVATE_H_ */
