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
void main(void)
{

// Tasks Number 1 & 2 & 3 varaibles//

	u8 i,j,base_cgr=0x40,base_ddr=0x80,lcd_counter=0;
	u8 Local_TemporaryHolder=0,Local_DigitHolder;
	u8 Local_Counter=0,Local_Counter2=0,Local_FirstDigitFlag=0,Local_SecondDigitFlag=0,Local_ThirdDigitFlag=0,Local_FourthDigitFlag=1;
	u8 Local_PlusFlag=0,Local_MinusFlag=0,Local_DivisionFlag=0,Local_MultiplyFlag=0;
	u8 Local_SignHolder =0;
	u8 Local_TemporaryCounter=0,Local_TemporaryCounter2=0;
	u8 Local_Result=0;
	DIO_u8SetPortDirection(DDR_A,DIO_PORT_OUTPUT); //7 SEGEMENT MODES WIRES Task 1 & 2 &3
	DIO_u8SetPortDirection(DDR_D,DIO_PORT_OUTPUT); // SEVEN SEGEMENTS DATA Task 1 & 2 & 3
	DIO_u8SetPortDirection(DDR_B,DIO_PORT_INPUT); //Task 2 & 3 DIP SWITCH TASK 3 5 SWITCHES
	DIO_u8SetPinDirection (DDR_C,PINA_0,DIO_INPUT); //Task 2 CHOICE SWITCH



	//Task_Number_4 variables

//int y,z;
//DIO_u8SetPortDirection(DDR_B,DIO_PORT_OUTPUT);
//DIO_u8SetPortDirection(DDR_C,DIO_PORT_OUTPUT);

u8 x[3][8]= { {
		  0b00000000,
		  0b00110011,
		  0b01100110,
		  0b11001100,
		  0b01100110,
		  0b00110011,
		  0b00000000,
		  0b00000000
		},{
		  0b00000000,
		  0b11001100,
		  0b01100110,
		  0b00110011,
		  0b01100110,
		  0b11001100,
		  0b00000000,
		  0b00000000
		},
		{
				  0b00000000,
				  0b00100100,
				  0b01100110,
				  0b11000011,
				  0b01100110,
				  0b00100100,
				  0b00000000,
				  0b00000000
		}};


/*u8 name[][8]={  {0b00000001,
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
		}};*/

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

while (1)
{
		//Task_Number_2_LCD

		if (DIO_u8GetPinValue(PINC,PINC_0)==1)
		{
			LCD_u8WriteCommand(0x01);

			delay_ms(30);
			Local_TemporaryHolder = DIO_u8GetPortValue(PINB);
			if (Local_TemporaryHolder <10)
			{
				Local_DigitHolder =Local_TemporaryHolder/10 ;
				LCD_u8WriteData('0'+Local_DigitHolder);
			}
			else if ( Local_TemporaryHolder <100)
			{
			Local_DigitHolder =Local_TemporaryHolder/10 ;
			LCD_u8WriteData('0'+Local_DigitHolder);
			Local_DigitHolder= Local_TemporaryHolder%10;
			LCD_u8WriteData('0'+Local_DigitHolder);
			}
			else if (Local_TemporaryHolder >= 100 && Local_TemporaryHolder<256)
			{

				Local_DigitHolder =Local_TemporaryHolder/100 ;
				LCD_u8WriteData('0'+Local_DigitHolder);
				Local_DigitHolder= (Local_TemporaryHolder%100)/10;
				LCD_u8WriteData('0'+Local_DigitHolder);
				Local_DigitHolder= Local_TemporaryHolder%10;
				LCD_u8WriteData('0'+Local_DigitHolder);
			}
		}
		else if (!(DIO_u8GetPinValue(PINC,PINC_0)==1))
		{


		}



}



}

