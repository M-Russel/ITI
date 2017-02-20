/*
 * SCHEDULAR_u8interface.h
 *
 *  Created on: Feb 15, 2017
 *      Author: root
 */

#ifndef SCHEDULAR_U8INTERFACE_H_
#define SCHEDULAR_U8INTERFACE_H_


#define SCHEDULAR_INITIAL_TASK 0
#define SCHEDULAR_MAXIMUM_TASK 6
#define SCHEDULAR_INITIAL_DELAY 0
#define SCHEDULAR_PERIODICITY_OFFSET 1

#define COUNTER_INITIAL_VALUE 0
#define SECOND 434
#define ZERO 0
#define MINUTE (u32)(60*SECOND)
#define HOUR (u32) (60*MINUTE)
#define DAY    (u32) (24*HOUR)
#define MONTH (u32) (30 * DAY) //518400000
#define STEPPER 2


#define SCHEDULAR_TASKONE_PERIODICITY STEPPER
#define SCHEDULAR_TASKONE_FIRST_DELAY STEPPER

#define SCHEDULAR_TASKTWO_PERIODICITY SECOND
#define SCHEDULAR_TASKTWO_FIRST_DELAY SECOND


#define SCHEDULAR_TASKTHREE_PERIODICITY MINUTE
#define SCHEDULAR_TASKTHREE_FIRST_DELAY MINUTE

#define SCHEDULAR_TASKFOUR_PERIODICITY HOUR
#define SCHEDULAR_TASKFOUR_FIRST_DELAY HOUR

#define SCHEDULAR_TASKFIVE_PERIODICITY DAY
#define SCHEDULAR_TASKFIVE_FIRST_DELAY DAY

#define SCHEDULAR_TASKSIX_PERIODICITY MONTH
#define SCHEDULAR_TASKSIX_FIRST_DELAY MONTH


#define SECONDS_MODULUS 10
#define SECONDS_MAXIMUM 60

#define MINUTES_MODULUS 10
#define MINUTES_MAXIMUM 60

#define HOURS_MODULUS 10
#define HOURS_MAXIMUM 12

#define DAYS_MODULUS 10
#define DAYS_MAXIMUM 31

#define MONTHS_MODULUS 10
#define MONTHS_MAXIMUM 12



void Seconds (void);
void Minutes (void);
void Hours (void);
void Days(void);
void Months(void);
void BUZZER(void);
void Stepper(void);
void SCHEDULAR_voidStart(void);


#endif /* SCHEDULAR_U8INTERFACE_H_ */