#pragma once
#define setLow  0x0f
#define clrLow  0xf0
#define setHigh 0xf0
#define clrHigh 0x0f
#define shiftNibbleOffset 4 
#define maskValueLow 0x0f
#define maskValueHigh 0xf0
#define setBit(Reg,bitNum) Reg|=(1<<bitNum)
#define clrBit(Reg,bitNum) Reg&=~(1<<bitNum)
#define toggleBit(Reg,bitNum) Reg^=(1<<bitNum)
#define getBit(Reg,bitNum)    ((Reg>>bitNum)&1)
#define setNibbleLow(Reg)   Reg|=(setLow)
#define clrNibbleLow(Reg)	Reg&=(clrLow)
#define toggleNibbleLow(Reg) Reg^=(setLow)
#define getNibbleLow(Reg)	(Reg & setLow) 
#define assignNibbleLow(Reg,value) Reg=((value & maskValueLow) | (Reg & clrLow))    //still

#define setNibbleHigh(Reg) Reg|=(setHigh)
#define clrNibbleHigh(Reg) Reg&= (clrHigh)
#define toggleNibbleHigh(Reg) Reg^=(setHigh)
#define getNibbleHigh(Reg) ((Reg & setHigh) >> shiftNibbleOffset)
#define assignNibbleHigh(Reg,value) Reg=(((value) << (shiftNibbleOffset) | ((Reg) & (clrHigh)))			//still

