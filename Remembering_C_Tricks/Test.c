/*
 * Test.c
 *
 *  Created on: Feb 27, 2017
 *      Author: root
 */

#include <stdio.h>
#include "std_types.h"
void main (void)
{

u8 x[10]={1};
u8 y[10]={};
u8 z[10]={};
u8 h=0;

h=*(u8 *)(0x7ffe9518b9a0);

printf("%d",h);

return ;
}