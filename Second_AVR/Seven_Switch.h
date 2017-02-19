/*
 * Seven_Switch.h
 *
 *  Created on: Dec 7, 2016
 *      Author: Russel
 */

#ifndef SEVEN_SWITCH_H_
#define SEVEN_SWITCH_H_




#define SWI(PORT,NUM) do{ switch(NUM)\
{\
	case 0: PORT=0x3F;\
	break;\
	case 1:PORT=0x0C;\
	break;\
	case 2:PORT=0x5B;\
	break;\
	case 3:PORT=0x5E;\
	break;	\
	case 4:PORT=0x6C;\
	break;\
	case 5:PORT=0x76;\
	break;\
	case 6:PORT=0x77;\
	break;\
	case 7:PORT=0x1C;\
	break;\
	case 8:PORT=0x7F;\
	break;\
	case 9:PORT=0x7E;\
	break;\
}\
}while(0);\

#endif /* SEVEN_SWITCH_H_ */
