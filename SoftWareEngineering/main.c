/*
 * main.c
 *
 *  Created on: Apr 5, 2017
 *      Author: M.Saeed
 */


#include"../libraries/stdTypes.h"
#include"../DIO/DIO_interface.h"
#include"../lcd/LCD_interface.h"


#define ON_OFF_SWITCH 0
#define MODE_BUTTON 1
#define UP_BUTTON 2
#define DOWN_BUTTON 3
#define HOME_MODE 1
#define TEMPERATURE_MODE 2
#define FAN_SPEED_MODE 3
#define DEFAULT_MODE HOME_MODE
#define MAX_TEMPERATURE 30
#define MIN_TEMPERATURE 18
#define DEFAULT_TEMPERATURE 20
#define MAX_FAN_SPEED 3
#define MIN_FAN_SPEED 1
#define DEFAULT_FAN_SPEED MIN_FAN_SPEED

/////////
 #define AC_Templine (1) // temperature line on LCD
 #define AC_FANline (2) // fan speed line on LCD
 #define AC_FirstColumn (0)
//global Variables. 


void AC_ModeButtonCheck(void); 
void AC_DownButtonCheck(void);
void AC_DownButtonCheck(void);
void AC_voidUpdateDisplay(void);
u8 AC_u8Mode;
u8 AC_u8Temperature;
u8 AC_u8FanSpeed;

int main (void)
{
	u8 Local_u8OnOffButtonState; 
	
	DIO_u8Init();
	SWPANEL_u8Init();
	while(1)
	{
		Local_u8OnOffButtonState
		// read on off button
		SWPANEL_u8GetStableValue(ON_OFF_SWITCH, &Local_u8OnOffButtonState);
		if(Local_u8OnOffButtonState == SWPANEL_u8PRESSED)
		{
			LCD_u8turnOn();
			LCD_u8Init();
			delay(5000);
			AC_u8Mode = HOME_MODE;
			AC_u8Temperature = DEFAULT_TEMPERATURE;
			AC_u8FanSpeed = DEFAULT_FAN_SPEED;

			// SWPANEL_u8GetStableValue(ON_OFF_SWITCH, &Local_u8OnOffButtonState);
			while(Local_u8OnOffButtonState == SWPANEL_u8PRESSED) // on
			{
				
				AC_ModeButtonCheck();
				AC_upButtonCheck();
				AC_DownButtonCheck();
				
				AC_voidUpdateDisplay();
				// update on/off button state for loop condition check
				SWPANEL_u8GetStableValue(ON_OFF_SWITCH, &Local_u8OnOffButtonState);
				if(Local_u8OnOffButtonState == SWPANEL_u8NOT_PRESSED)
				{
					delay(5000);
					LCD_u8TurnOff();
				}
			}
		}
	}
	return 0;
}


static void AC_voidUpdateDisplay(void){
	
	
		
switch (AC_u8Mode){
	
	case TEMPERATURE_MODE:
	// print the temp details from the fist line 
	LCD_u8GoTo(LCD_FirstColumn,AC_Templine);
	LCD_u8WriteString(">");// selection ARROW
	LCD_u8WriteString("TEMP: ");
	LCD_u8WriteInteger(AC_u8TemperatureValue); // print the value of temp
	LCD_u8WriteString("C");// print unit
	//ptint the Fan Speed Mode
	LCD_u8GoTo(LCD_FirstColumn,AC_FANline);
	LCD_u8WriteString("FAN:  ");
	LCD_u8WriteInteger(AC_u8FanSpeedValue);
	break;
	case FAN_SPEED_MODE: 
	LCD_u8GoTo(LCD_FirstColumn,AC_Templine);
	LCD_u8WriteString("TEMP: ");
	LCD_u8WriteInteger(AC_u8TemperatureValue); // print the value of temp
	LCD_u8WriteString("C");// print unit
	//ptint the Fan Speed Mode
	LCD_u8GoTo(LCD_FirstColumn,AC_FANline);
	LCD_u8WriteString(">");// selection ARROW
	LCD_u8WriteString("FAN:  ");
	LCD_u8WriteInteger(AC_u8FanSpeedValue);
	break;
	case: HOME_MODE: 
	LCD_u8GoTo(LCD_FirstColumn,AC_Templine);
	LCD_u8WriteString("TEMP: ");
	LCD_u8WriteInteger(AC_u8TemperatureValue); // print the value of temp
	LCD_u8WriteString("C");// print unit
	//ptint the Fan Speed Mode
	LCD_u8GoTo(LCD_FirstColumn,AC_FANline);
	LCD_u8WriteString("FAN:  ");
	LCD_u8WriteInteger(AC_u8FanSpeedValue);
	break;
	default: 
	LCD_u8GoTo(LCD_FirstColumn,AC_Templine);
	LCD_u8WriteString("TEMP: ");
	LCD_u8WriteInteger(AC_u8TemperatureValue); // print the value of temp
	LCD_u8WriteString("C");// print unit
	//ptint the Fan Speed Mode
	LCD_u8GoTo(LCD_FirstColumn,AC_FANline);
	LCD_u8WriteString("FAN:  ");
	LCD_u8WriteInteger(AC_u8FanSpeedValue);
	break; 
}
return; 
}



static  void AC_upButtonCheck(void){
		u8 Local_u8UpButtonState;
		SWPANEL_u8GetStableValue(UP_BUTTON, &Local_u8UpButtonState);// read sw value
		if (Local_u8UpButtonState)// check if pressed
		{
				switch(AC_u8Mode)// check the mode 
				{
					case HOME_MODE:
					break;
					case TEMPERATURE_MODE:  
					// wait until up button released
					do
					{
						// update up button state
						SWPANEL_u8GetStableValue(UP_BUTTON, &Local_u8UpButtonState);
					}
					while(Local_u8UpButtonState == SWPANEL_u8PRESSED);
					if(MAX_TEMPERATURE==AC_u8TemperatureValue){//check if temp reaches the max 
					AC_u8TemperatureValue=MAX_TEMPERATURE;
					}else {
					AC_u8TemperatureValue++; 	
					}
					break;
					case FAN_SPEED_MODE: 
					// wait until up button released
					do
					{
						// update up button state
						SWPANEL_u8GetStableValue(UP_BUTTON, &Local_u8UpButtonState);
					}
					while(Local_u8UpButtonState == SWPANEL_u8PRESSED);
					if(MAX_FAN_SPEED==AC_u8FanSpeedValue){//check if temp reaches the max 
					AC_u8FanSpeedValue=MAX_FAN_SPEED;
					}else {
					AC_u8FanSpeedValue++; 	
					}
					break;
					default:
					break: 
					
				}
				
		}else{
		
		}

		return; 
}

	
static  void AC_DownButtonCheck(void){
		u8 Local_u8DownButtonState;
		SWPANEL_u8GetStableValue(DOWN_BUTTON, &Local_u8DownButtonState);// read sw value
		if (Local_u8DownButtonState)// check if pressed
		{
				switch(AC_u8Mode)// check the mode 
				{
					case HOME_MODE:
					//THIS BUTTON HAVE NO EFFECT IN HOME MODE 
					break;
					case TEMPERATURE_MODE:  
					// wait until up button released
					do
					{
						// update up button state
						SWPANEL_u8GetStableValue(DOWN_BUTTON, &Local_u8DownButtonState);
					}
					while(Local_u8DownButtonState == SWPANEL_u8PRESSED);
					if(MIN_TEMPERATURE==AC_u8TemperatureValue){//check if temp reaches the max 
					AC_u8TemperatureValue=MIN_TEMPERATURE;
					}else {
					AC_u8TemperatureValue--; 	
					}
					break;
					case FAN_SPEED_MODE: 
					// wait until up button released
					do
					{
						// update up button state
						SWPANEL_u8GetStableValue(DOWN_BUTTON, &Local_u8DownButtonState);
					}
					while(Local_u8DownButtonState == SWPANEL_u8PRESSED);
					if(MIN_FAN_SPEED==AC_u8FanSpeedValue){//check if temp reaches the max 
					AC_u8FanSpeedValue=MIN_FAN_SPEED;
					}else {
					AC_u8FanSpeedValue--; 	
					}
					break;
					default:
					break: 
					
				}
				
		}else{
		// no else condition here
		}

		return; 
}

static void AC_ModeButtonCheck(void){
		u8 Local_u8ModeButtonState;
		SWPANEL_u8GetStableValue(DOWN_BUTTON, &Local_u8ModeButtonState);// read sw value
			if(Local_u8ModeButtonState==SWPANEL_u8PRESSED)
			{
			do
			{
						// update up button state
			SWPANEL_u8GetStableValue(MODE_BUTTON, &Local_u8ModeButtonState);
			}
			while(Local_u8ModeButtonState == SWPANEL_u8PRESSED);	
			if(FAN_SPEED_MODE==AC_u8Mode){
				AC_u8Mode=HOME_MODE; 
			}else{
				AC_u8Mode++;
			}
			}else{
				// buttun is not pressed 
				
			}
			
	return; 	
}
