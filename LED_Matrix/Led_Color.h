/*
 * Led_Color.h
 *
 *  Created on: Dec 13, 2016
 *      Author: Russel
 */

#ifndef LED_COLOR_H_
#define LED_COLOR_H_

#include "io_ports_atmega32.h"
#include "delay_ms.h"
#include "Seven_Segment.h"
#include "types.h"

#define MAX 60
#define MIN 0
#define TEN 10
#define SECOND 1000
#define MAX_WAIT 5
#define ZERO 0
#define GREEN_LED PORTB_0
#define ORANGE_LED PORTB_1
#define RED_LED PORTB_2

void Red(u32 Delay_Value);
void Orange(u32 Delay_Value);
void Green(u32 Delay_Value);

#endif /* LED_COLOR_H_ */
