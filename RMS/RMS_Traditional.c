/*
 *RMS_Traditional.c
 *
 *  Created on: Feb 20, 2017
 *      Author: Russel
 */

#include "std_types.h"
#include "utils.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "DIO_Private.h"
#include "TIMER0_private.h"
#include "TIMER0_interface.h"
#include "TIMER0_config.h"
#include "SCHEDULAR_u8interface.h"

typedef struct {

	u32 SCHEDULAR_u32Periodicity;
	u32 SCHEDULAR_u32FirstDelay;
	void (*ptr)(void);

} Task;

Task swTask[SCHEDULAR_MAXIMUM_TASK] = { { SCHEDULAR_TASKONE_PERIODICITY,
		SCHEDULAR_TASKONE_FIRST_DELAY, Set_u8Pins }, {
		SCHEDULAR_TASKTWO_PERIODICITY, SCHEDULAR_TASKTWO_FIRST_DELAY,
		clr_u8FirstPin }, { SCHEDULAR_TASKTHREE_PERIODICITY,
		SCHEDULAR_TASKTHREE_FIRST_DELAY, clr_u8SecondPin }, {
		SCHEDULAR_TASKFOUR_PERIODICITY, SCHEDULAR_TASKFOUR_FIRST_DELAY,
		clr_u8ThirdPin }

};

void Set_u8Pins(void) {
	DIO_u8SetPinValue(PIN_0, DIO_HIGH);
	DIO_u8SetPinValue(PIN_1, DIO_HIGH);
	DIO_u8SetPinValue(PIN_2, DIO_HIGH);
}
void clr_u8FirstPin(void) {
	DIO_u8SetPinValue(PIN_0, DIO_LOW);

}
void clr_u8SecondPin(void) {
	DIO_u8SetPinValue(PIN_1, DIO_LOW);

}
void clr_u8ThirdPin(void) {
	DIO_u8SetPinValue(PIN_2, DIO_LOW);

}
u16 OVNB = OVERFLOW_COUNTER_INITIAL;
void __vector_11(void) {

	OVNB++;

	if (OVERFLOW_COUNTER_MAX == OVNB) {
		SCHEDULAR_voidStart();
		TCNT0 = TCNT0_INITIAL_VALUE;
		OVNB = OVERFLOW_COUNTER_INITIAL;
	}

	else {

	}
}

void main(void) {
	DIO_voidInitialize();
	TIMER0_init();

	while (1) {

	}

	return;
}

void SCHEDULAR_voidStart(void) {
	u8 SCHEDULAR_u8Counter;
	for (SCHEDULAR_u8Counter = SCHEDULAR_INITIAL_TASK;
			SCHEDULAR_u8Counter < SCHEDULAR_MAXIMUM_TASK;
			SCHEDULAR_u8Counter++) {
		if (swTask[SCHEDULAR_u8Counter].SCHEDULAR_u32FirstDelay
				== SCHEDULAR_INITIAL_DELAY) {
			(swTask[SCHEDULAR_u8Counter].ptr)();
			swTask[SCHEDULAR_u8Counter].SCHEDULAR_u32FirstDelay =
					swTask[SCHEDULAR_u8Counter].SCHEDULAR_u32Periodicity
							- SCHEDULAR_PERIODICITY_OFFSET;
		} else {
			swTask[SCHEDULAR_u8Counter].SCHEDULAR_u32FirstDelay--;

		}

	}

}
