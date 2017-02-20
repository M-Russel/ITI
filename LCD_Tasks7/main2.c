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
void main16(void)
{

// Tasks Number 1 & 2 & 3 varaibles//

	u8 i,j,k,base_cgr=0x40,base_ddr=0x80,lcd_counter=0;
    u8 LCD_FirstLineOffset=0x80,LCD_SecondLineOffset=0xc0;



	DIO_u8SetPortDirection(DDR_A,DIO_PORT_OUTPUT); //7 SEGEMENT MODES WIRES Task 1 & 2 &3
	DIO_u8SetPortDirection(DDR_D,DIO_PORT_OUTPUT); // SEVEN SEGEMENTS DATA Task 1 & 2 & 3
	DIO_u8SetPortDirection(DDR_B,DIO_PORT_INPUT); //Task 2 & 3 DIP SWITCH TASK 3 5 SWITCHES
	DIO_u8SetPinDirection (DDR_C,PINA_0,DIO_INPUT); //Task 2 CHOICE SWITCH




u8 name[][8]={
		{
		  0b00000000,
		  0b00000001,
		  0b00000001,
		  0b00000001,
		  0b00001111,
		  0b00000000,
		  0b00000000,
		  0b00000000
		},{
		  0b00000000,
		  0b00011110,
		  0b00010010,
		  0b00011110,
		  0b00000011,
		  0b00000010,
		  0b00000100,
		  0b00011000
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
		  0b00010011,
		  0b00010010,
		  0b00011110,
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

LCD_u8Init();
LCD_u8WriteCommand(0b00000001);

for (i=0;i<8;i++)
			{

				for (j=0;j<8;j++)
				{
					LCD_u8WriteCommand(base_cgr+lcd_counter);
					LCD_u8WriteData(name[i][j]);
					lcd_counter++;
				}

			}


/*
	LCD_u8WriteCommand(0b01000000);
    LCD_u8WriteData(name[0][0]);
	LCD_u8WriteData(name[0][1]);
	LCD_u8WriteData(name[0][2]);
	LCD_u8WriteData(name[0][3]);
	LCD_u8WriteData(name[0][4]);
	LCD_u8WriteData(name[0][5]);
	LCD_u8WriteData(name[0][6]);
	LCD_u8WriteData(name[0][7]);
	LCD_u8WriteCommand(0b10000000);
	LCD_u8WriteData(0x00);


	LCD_u8WriteCommand(0b01000001);
    LCD_u8WriteData(name[1][0]);
	LCD_u8WriteData(name[1][1]);
	LCD_u8WriteData(name[1][2]);
	LCD_u8WriteData(name[1][3]);
	LCD_u8WriteData(name[1][4]);
	LCD_u8WriteData(name[1][5]);
	LCD_u8WriteData(name[1][6]);
	LCD_u8WriteData(name[1][7]);
	LCD_u8WriteCommand(0b10000001);
	LCD_u8WriteData(0x01);


	LCD_u8WriteCommand(0b01000010);
    LCD_u8WriteData(name[2][0]);
	LCD_u8WriteData(name[2][1]);
	LCD_u8WriteData(name[2][2]);
	LCD_u8WriteData(name[2][3]);
	LCD_u8WriteData(name[2][4]);
	LCD_u8WriteData(name[2][5]);
	LCD_u8WriteData(name[2][6]);
	LCD_u8WriteData(name[2][7]);
	LCD_u8WriteCommand(0b10000010);
	LCD_u8WriteData(0x02);


	LCD_u8WriteCommand(0b01000011);
    LCD_u8WriteData(name[3][0]);
	LCD_u8WriteData(name[3][1]);
	LCD_u8WriteData(name[3][2]);
	LCD_u8WriteData(name[3][3]);
	LCD_u8WriteData(name[3][4]);
	LCD_u8WriteData(name[3][5]);
	LCD_u8WriteData(name[3][6]);
	LCD_u8WriteData(name[3][7]);
	LCD_u8WriteCommand(0b10000011);
	LCD_u8WriteData(0x03);


	LCD_u8WriteCommand(0b01000100);
    LCD_u8WriteData(name[4][0]);
	LCD_u8WriteData(name[4][1]);
	LCD_u8WriteData(name[4][2]);
	LCD_u8WriteData(name[4][3]);
	LCD_u8WriteData(name[4][4]);
	LCD_u8WriteData(name[4][5]);
	LCD_u8WriteData(name[4][6]);
	LCD_u8WriteData(name[4][7]);
	LCD_u8WriteCommand(0b10000100);
	LCD_u8WriteData(0x04);


	LCD_u8WriteCommand(0b01000101);
    LCD_u8WriteData(name[5][0]);
	LCD_u8WriteData(name[5][1]);
	LCD_u8WriteData(name[5][2]);
	LCD_u8WriteData(name[5][3]);
	LCD_u8WriteData(name[5][4]);
	LCD_u8WriteData(name[5][5]);
	LCD_u8WriteData(name[5][6]);
	LCD_u8WriteData(name[5][7]);
	LCD_u8WriteCommand(0b10000101);
	LCD_u8WriteData(0x05);

	LCD_u8WriteCommand(0b01000110);
    LCD_u8WriteData(name[6][0]);
	LCD_u8WriteData(name[6][1]);
	LCD_u8WriteData(name[6][2]);
	LCD_u8WriteData(name[6][3]);
	LCD_u8WriteData(name[6][4]);
	LCD_u8WriteData(name[6][5]);
	LCD_u8WriteData(name[6][6]);
	LCD_u8WriteData(name[6][7]);
	LCD_u8WriteCommand(0b10000110);
	LCD_u8WriteData(0x06);

	LCD_u8WriteCommand(0b01000111);
    LCD_u8WriteData(name[7][0]);
	LCD_u8WriteData(name[7][1]);
	LCD_u8WriteData(name[7][2]);
	LCD_u8WriteData(name[7][3]);
	LCD_u8WriteData(name[7][4]);
	LCD_u8WriteData(name[7][5]);
	LCD_u8WriteData(name[7][6]);
	LCD_u8WriteData(name[7][7]);
	LCD_u8WriteCommand(0b10000111);
	LCD_u8WriteData(0x07);
	*/
//RIGHT
	while (1)
	{


   //Task_Number_5_LCD

					//LCD_u8WriteCommand(base_ddr);



		LCD_u8WriteCommand(0b00000001);

				LCD_u8WriteCommand(0b10000000);

					for (i=0;i<8;i++)
					{

						LCD_u8WriteData(i);

					}




					delay_ms(500);
				LCD_u8WriteCommand(0b00000001);
				LCD_u8WriteCommand(0b11000010);

						for (i=0;i<8;i++)
						{

							LCD_u8WriteData(i);

						}

				delay_ms(500);

				LCD_u8WriteCommand(0b00000001);
				LCD_u8WriteCommand(0b10000100);

				for (i = 0; i < 8; i++) {

					LCD_u8WriteData(i);

				}


				delay_ms(500);
				LCD_u8WriteCommand(0b00000001);
				LCD_u8WriteCommand(0b11000101);

				for (i = 0; i < 8; i++) {

					LCD_u8WriteData(i);

				}
				delay_ms(500);

				LCD_u8WriteCommand(0b00000001);
				LCD_u8WriteCommand(0b10000111);

				for (i = 0; i < 8; i++) {

					LCD_u8WriteData(i);

				}

				delay_ms(500);
				LCD_u8WriteCommand(0b00000001);
				LCD_u8WriteCommand(0b11001000);

				for (i = 0; i < 8; i++) {

					LCD_u8WriteData(i);

				}

//==============================================================
				delay_ms(500);

				LCD_u8WriteCommand(0b00000001);
				LCD_u8WriteCommand(0b10000111);

				for (i = 0; i < 8; i++) {

					LCD_u8WriteData(i);

				}

				delay_ms(500);
				LCD_u8WriteCommand(0b00000001);
				LCD_u8WriteCommand(0b11000101);

				for (i = 0; i < 8; i++) {

					LCD_u8WriteData(i);

				}

				delay_ms(500);

				LCD_u8WriteCommand(0b00000001);
				LCD_u8WriteCommand(0b10000100);

				for (i = 0; i < 8; i++) {

					LCD_u8WriteData(i);

				}

				delay_ms(500);
			LCD_u8WriteCommand(0b00000001);
			LCD_u8WriteCommand(0b11000010);

					for (i=0;i<8;i++)
					{

						LCD_u8WriteData(i);

					}
					delay_ms(500);
		LCD_u8WriteCommand(0b00000001);
		LCD_u8WriteCommand(0b10000000);

		for (i = 0; i < 8; i++) {

			LCD_u8WriteData(i);

		}

		delay_ms(500);

	}
}






