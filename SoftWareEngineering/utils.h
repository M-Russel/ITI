/*
 * utils.h
 *
 *  Created on: Apr 4, 2017
 *      Author: Russel
 *      Version : 1
 *
 */

#ifndef UTILS_H_
#define UTILS_H_


//Setting the bit (bitNum) inside the register (Reg) with one
#define SETBIT(Reg,bitNum) Reg|=(1<<bitNum)
//Setting the bit (bitNum) inside the register (Reg) with Zero (clearing it)
#define CLRBIT(Reg,bitNum) Reg&=~(1<<bitNum)
//returning the value of the bit (bitNum) from the register (Reg)
#define GETBIT(Reg,bitNum)    ((Reg>>bitNum)&1)


#endif /*  UTILS_H_  */
