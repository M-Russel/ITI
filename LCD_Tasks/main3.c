/*
 * main.c


 *
 *  Created on: Dec 21, 2016
 *      Author: Russel
 */
#include <stdio.h>
#include "delay_ms.h"
#include "LCD_Interface.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "io_ports_atmega32.h" // PORTS MAPPING HEADER FILE
#include "DIO_voidInitialize.h" // DIO INITIALE VALUES
#include "util/delay.h"

#include "std_types.h" // DATA TYPES HEADER FILE
#include "utils.h" // BIT CALCULATION HEADER FILE
void main65(void)
{



	u8 w=0,i=0,j=0,k=9,base_cgr=0x40,base_ddr=0x80,lcd_counter=0;
    u8 LCD_FirstLineOffset=0x80,LCD_SecondLineOffset=0xc0,LCD_FirstLineEndOffset=0x8f,LCD_SecondLineEndOffset=0x79;



	DIO_u8SetPortDirection(DDR_A,DIO_PORT_OUTPUT); //7 SEGEMENT MODES WIRES Task 1 & 2 &3
	DIO_u8SetPortDirection(DDR_D,DIO_PORT_OUTPUT); // SEVEN SEGEMENTS DATA Task 1 & 2 & 3
	DIO_u8SetPortDirection(DDR_B,DIO_PORT_INPUT); //Task 2 & 3 DIP SWITCH TASK 3 5 SWITCHES
	DIO_u8SetPinDirection (DDR_C,PINA_0,DIO_INPUT); //Task 2 CHOICE SWITCH

	/*u8 name_Eng_LED[][8]={  {0b00000001,
			  0b00000001,
			  0b00000001,
			  0b00000001,
			  0b00000001,
			  0b00000001,
			  0b00000001,
			  0b00011111},
			{
			 0b00000000,
			 0b00011110,
			 0b00010010,
			 0b00011110,
			 0b00000010,
			 0b00000010,
			 0b00000100,
			 0b00011000
			},
			{
			  0b00000000,
			  0b00000000,
			  0b00000000,
			  0b00000000,
			  0b00011111,
			  0b00000000,
			  0b00000000,
			  0b00000000
			},
			{
			  0b00000000,
			  0b00000000,
			  0b00011110,
			  0b00010010,
			  0b00010010,
			  0b00010010,
			  0b00011110,
			  0b00000000
			},
			{
			  0b00000000,
			  0b00000000,
			  0b00000000,
			  0b00000000,
			  0b00011111,
			  0b00000000,
			  0b00000000,
			  0b00000000
			},{
			  0b00000000,
			  0b00000100,
			  0b00001010,
			  0b00000001,
			  0b00011111,
			  0b00000000,
			  0b00000000,
			  0b00000000
			},{
			  0b00000000,
			  0b00000000,
			  0b00000000,
			  0b00000000,
			  0b00011111,
			  0b00000000,
			  0b00000000,
			  0b00000000
			},{
			  0b00000000,
			  0b00000000,
			  0b00011110,
			  0b00010010,
			  0b00010010,
			  0b00010010,
			  0b00011110,
			  0b00000000
			}};
*/


u8 name_Eng[8]={"Russel"};
u8 name_Arb[]={

		  0b00000000,
		  0b00000001,
		  0b00000001,
		  0b00000001,
		  0b00001111,
		  0b00000000,
		  0b00000000,
		  0b00000000
		,
		  0b00000000,
		  0b00011110,
		  0b00010010,
		  0b00011110,
		  0b00000011,
		  0b00000010,
		  0b00000100,
		  0b00011000
		,
		  0b00000000,
		  0b00000000,
		  0b00000000,
		  0b00000000,
		  0b00011111,
		  0b00000000,
		  0b00000000,
		  0b00000000
		,
		  0b00000000,
		  0b00000000,
		  0b00011110,
		  0b00010010,
		  0b00010011,
		  0b00010010,
		  0b00011110,
		  0b00000000
		,
		  0b00000000,
		  0b00000000,
		  0b00000000,
		  0b00000000,
		  0b00011111,
		  0b00000000,
		  0b00000000,
		  0b00000000
		,
		  0b00000000,
		  0b00000100,
		  0b00001010,
		  0b00000001,
		  0b00011111,
		  0b00000000,
		  0b00000000,
		  0b00000000
		,
		  0b00000000,
		  0b00000000,
		  0b00000000,
		  0b00000000,
		  0b00011111,
		  0b00000000,
		  0b00000000,
		  0b00000000
		,
		  0b00000000,
		  0b00000000,
		  0b00011110,
		  0b00010010,
		  0b00010010,
		  0b00010010,
		  0b00011110,
		  0b00000000
		};

LCD_u8Init();
LCD_u8WriteCommand(0b00000001);
lcd_counter=0;

LCD_u8WriteCommand(base_cgr);
for (i=0;i<=63;i++)
{
					LCD_u8WriteData(name_Arb[i]);


}

LCD_u8WriteCommand(base_ddr);

for (j=0;j<6;j++)
{
	for (i=0;i<k;i++)
	{

		if (i==(k-1))
		{
			LCD_u8WriteCommand(LCD_FirstLineEndOffset-i);
			LCD_u8WriteData(name_Eng[j]);
		}
		else
		{
			LCD_u8WriteCommand(LCD_FirstLineEndOffset-i);
			LCD_u8WriteData(name_Eng[j]);
			delay_ms(200);
			LCD_u8WriteCommand(LCD_FirstLineEndOffset-i);
			LCD_u8WriteData(' ');

		}
	}
		--k;
	}


LCD_u8WriteCommand(LCD_SecondLineOffset);

k=12;
w=7;
for (j=0;j<8;j++)
{
	for (i=0;i<k;i++)
	{

		if (i==(k-1))
		{
			LCD_u8WriteCommand(LCD_SecondLineOffset+i);
			LCD_u8WriteData(w);
			break;
		}
		else
		{
			LCD_u8WriteCommand(LCD_SecondLineOffset+i);
			LCD_u8WriteData(w);
			delay_ms(200);
			LCD_u8WriteCommand(LCD_SecondLineOffset+i);
			LCD_u8WriteData(' ');

		}
	}
		--k;
		w--;
	}




	while (1)
	{



	}
/*
		LCD_u8WriteCommand((LCD_FirstLineEndOffset-0x03));
		LCD_u8WriteData('R');
		delay_ms(300);
		LCD_u8WriteCommand(0b00000001);

		LCD_u8WriteCommand(LCD_FirstLineEndOffset-0x06);
		LCD_u8WriteData('R');
		delay_ms(300);
		LCD_u8WriteCommand(0b00000001);

		LCD_u8WriteCommand(LCD_FirstLineEndOffset-0x09);
		LCD_u8WriteData('R');
		delay_ms(300);
		LCD_u8WriteCommand(0b00000001);

		LCD_u8WriteCommand(LCD_FirstLineEndOffset-0x0C);
		LCD_u8WriteData('R');
		delay_ms(300);
		LCD_u8WriteCommand(0b00000001);

*/

}





