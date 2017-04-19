/*
 * std_types.h
 *
 *  Created on: Apr 4, 2017
 *      Author: Russel
 *      Version : 1
 *
 *
 */


#ifndef STD_TYPES_H_
#define STD_TYPES_H_
#define NULL 0x00

#define OK 0
#define ERROR 1

//getting a new type which name is u8 and it represents unsigned character (8 bit)
typedef unsigned char u8;
//getting a new type which name is pu8 and it represents pointer to unsigned character (8 bit)
typedef unsigned char* pu8;


typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;

typedef unsigned short int* pu16;
typedef unsigned long int* pu32;

typedef signed char* ps8;
typedef signed short int* ps16;
typedef signed long int* ps32;

typedef float* pf32;
typedef double* pf64;
#endif /* STD_TYPES_H_ */







