/*
 * Seven_Segment.h
 *
 *  Created on: Dec 7, 2016
 *      Author: Russel
 */

#ifndef SEVEN_SEGMENT_H_P
#define SEVEN_SEGMENT_H_P

#define SEGMENT_P(PORT,NUMBER) do{\
						u8 s[10]={0x7F,0x0C,0xB7,0x9F,0xDC,0xDB,0xFB,0x0E,0xFF,0xDF};\
(PORT)=(s[NUMBER]);\
}while(0);\

#endif /* SEVEN_SEGMENT_H_ */
