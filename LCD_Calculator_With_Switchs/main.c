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




		if (DIO_u8GetPinValue(PINB,PINB_0)==1)
		{
			delay_ms(30);
			while(DIO_u8GetPinValue(PINB,PINB_0)==1)
			{
				LCD_u8WriteCommand(0b00000001);//CLEAR
				Local_TemporaryCounter = (Local_Counter%10);
				LCD_u8WriteData('0'+Local_TemporaryCounter);
				delay_ms(200);
				Local_Counter++;
				Local_FirstDigitFlag = 1;

			}
		}

		else if (!(DIO_u8GetPinValue(PINB,PINB_0)==1))
		{}



	if (DIO_u8GetPinValue(PINB,PINB_1)==1 && Local_FirstDigitFlag == 1)
	{
		delay_ms(30);
		while(DIO_u8GetPinValue(PINB,PINB_1)==1)
		{
			LCD_u8WriteCommand(0b00000001);//CLEAR
			LCD_u8WriteData('0'+Local_TemporaryCounter);
			LCD_u8WriteData('+');
			Local_SignHolder='+';
			delay_ms(200);
			Local_SecondDigitFlag=1;
			Local_PlusFlag=1;
			Local_MinusFlag=0;
			Local_DivisionFlag=0;
			Local_MultiplyFlag=0;
				if (DIO_u8GetPinValue(PINB,PINB_1)==1 && Local_FirstDigitFlag == 1)
					{
						LCD_u8WriteCommand(0b00000001);//CLEAR
						LCD_u8WriteData('0'+Local_TemporaryCounter);
						LCD_u8WriteData('-');
						Local_SignHolder='-';
						delay_ms(200);
						Local_SecondDigitFlag=1;
						Local_PlusFlag=0;
						Local_MinusFlag=1;
						Local_DivisionFlag=0;
						Local_MultiplyFlag=0;
					}
				if (DIO_u8GetPinValue(PINB,PINB_1)==1 && Local_FirstDigitFlag == 1)
					{
						LCD_u8WriteCommand(0b00000001);//CLEAR
						LCD_u8WriteData('0'+Local_TemporaryCounter);
						LCD_u8WriteData('*');
						Local_SignHolder='*';
						delay_ms(200);
						Local_SecondDigitFlag=1;
						Local_PlusFlag=0;
						Local_MinusFlag=0;
						Local_DivisionFlag=0;
						Local_MultiplyFlag=1;
					}
				if (DIO_u8GetPinValue(PINB,PINB_1)==1 && Local_FirstDigitFlag == 1)
					{
						LCD_u8WriteCommand(0b00000001);//CLEAR
						LCD_u8WriteData('0'+Local_TemporaryCounter);
						LCD_u8WriteData('/');
						Local_SignHolder='/';
						delay_ms(200);
						Local_SecondDigitFlag=1;
						Local_PlusFlag=0;
						Local_MinusFlag=0;
						Local_DivisionFlag=1;
						Local_MultiplyFlag=0;
					}


		}


	}
	else if (!(DIO_u8GetPinValue(PINB,PINB_1)==1)) {}

	if (DIO_u8GetPinValue(PINB,PINB_2)==1 && Local_FirstDigitFlag == 1 && Local_SecondDigitFlag == 1)
	{

		delay_ms(30);
					while(DIO_u8GetPinValue(PINB,PINB_2)==1)
					{
						LCD_u8WriteCommand(0b00000001);//CLEAR
						Local_TemporaryCounter2 = (Local_Counter2%10);
						LCD_u8WriteData('0'+Local_TemporaryCounter);
						LCD_u8WriteData(Local_SignHolder);
						LCD_u8WriteData('0'+Local_TemporaryCounter2);
						delay_ms(200);
						Local_Counter2++;
						Local_ThirdDigitFlag = 1;

					}
	}
	else if (!(DIO_u8GetPinValue(PINB,PINB_2)==1 && Local_FirstDigitFlag == 1 && Local_SecondDigitFlag == 1))
	{}

	if (DIO_u8GetPinValue(PINB,PINB_3)==1 && Local_FirstDigitFlag == 1 && Local_SecondDigitFlag == 1 && Local_ThirdDigitFlag==1 && Local_FourthDigitFlag==1)
		{
		delay_ms(30);
			switch (Local_SignHolder)
				{
				case '+':
						{
							Local_Result=Local_TemporaryCounter + Local_TemporaryCounter2;
							LCD_u8WriteCommand(0b00000001);//CLEAR
							LCD_u8WriteData('0'+Local_TemporaryCounter);
							LCD_u8WriteData(Local_SignHolder);
							LCD_u8WriteData('0'+Local_TemporaryCounter2);
							LCD_u8WriteData('=');
							LCD_u8WriteData('0'+Local_Result);
						}
					break;
				case '-':
						{
							Local_Result=Local_TemporaryCounter - Local_TemporaryCounter2;
							LCD_u8WriteCommand(0b00000001);//CLEAR
							LCD_u8WriteData('0'+Local_TemporaryCounter);
							LCD_u8WriteData(Local_SignHolder);
							LCD_u8WriteData('0'+Local_TemporaryCounter2);
							LCD_u8WriteData('=');
							LCD_u8WriteData('0'+Local_Result);
						}

					break;
				case '*':
						{
							Local_Result=Local_TemporaryCounter * Local_TemporaryCounter2;

							//handle in case greater than 9




							LCD_u8WriteCommand(0b00000001);//CLEAR
							LCD_u8WriteData('0'+Local_TemporaryCounter);
							LCD_u8WriteData(Local_SignHolder);
							LCD_u8WriteData('0'+Local_TemporaryCounter2);
							LCD_u8WriteData('=');
							LCD_u8WriteData('0'+Local_Result);
						}
					break;
				case '/':
						{
							if (Local_TemporaryCounter2==0 )
							{
								LCD_u8WriteCommand(0b00000001);//CLEAR
								LCD_u8WriteData('E');
								LCD_u8WriteData('R');
								LCD_u8WriteData('R');
								LCD_u8WriteData('O');
								LCD_u8WriteData('R');

									break;
							}
							else
							{
							Local_Result=Local_TemporaryCounter / Local_TemporaryCounter2;
							LCD_u8WriteCommand(0b00000001);//CLEAR
							LCD_u8WriteData('0'+Local_TemporaryCounter);
							LCD_u8WriteData(Local_SignHolder);
							LCD_u8WriteData('0'+Local_TemporaryCounter2);
							LCD_u8WriteData('=');
							LCD_u8WriteData('0'+Local_Result);
							}
						}
					break;
				default :
					break;
				}

			Local_FourthDigitFlag=0;

		}



	}
}

