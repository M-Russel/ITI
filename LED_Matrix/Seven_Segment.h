/*
 * Seven_Segment.h
 *
 *  Created on: Dec 7, 2016
 *      Author: Russel
 */

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#define SEGMENT(PORT,NUMBER) do{\
						u8 s[10]={0x3F,0x0C,0x5B,0x5E,0x6C,0x76,0x77,0x1C,0x7F,0x7E};\
(PORT)=(s[NUMBER]);\
}while(0);\

#endif /* SEVEN_SEGMENT_H_ */
