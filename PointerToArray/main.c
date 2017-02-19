/*
 * main.c
 *
 *  Created on: Feb 6, 2017
 *      Author: root
 */

#include "stdio.h"
#include "std_types.h"


u8 func (u8 (* Local_u8Array)[3][4]);


int main (void)
{

	u8 array[2][3][4]={
			{
					{1,1,1,1 },
					{ 1,1,1,1  },
					{ 1,1,1,1  }
			},
			{
					{ 1,1,1,1  },
					{ 1,1,1,1  },
					{ 1,1,1,1 }
			}

	};

	u8 value=0;

	value=func (array);


	printf("%d",value);
	return 0 ;
}

u8 func (u8 (* Local_u8Array)[3][4])

{
	u8 Local_u8Sum=0;
	u8 i =0,j=0,k=0;
	for (k=0;k<2;k++)
	{
		for (i=0;i<3;i++)
		{
			for (j=0;j<4;j++)
			{

				Local_u8Sum=Local_u8Sum+(Local_u8Array[k][i][j]);
			}

		}
	}
	return Local_u8Sum;
}

