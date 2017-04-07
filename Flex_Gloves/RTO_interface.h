/*
 * RTO_interface.h
 *
 *  Created on: Feb 22, 2017
 *      Author: Russel
 */

#ifndef RTO_INTERFACE_H_
#define RTO_INTERFACE_H_


typedef enum
{Paused,Running}Task_State;

typedef struct
{
	u32 Task_u32Periodicity;
	u32 Task_u32First_Delay;
	void (* ptr)(void);
	Task_State state;

}Task;


void RTO_voidInit(void);
u8 RTO_u8CreatTask(Task *Copy_pTaskPointer,u8 Copy_u8TaskPriority);
u8 RTO_u8DeleteTask(u8 Copy_u8TaskPriority);
u8 RTO_u8StartTask(u8 Copy_u8TaskPriority);
u8 RTO_u8StopTask(u8 Copy_u8TaskPriority);
static void RTO_voidSchedular(void);

#define TASK_NUMBER1_PERIODICITY 5
#define TASK_NUMBER1_FIRST_DELAY 25


#define TASK_NUMBER2_PERIODICITY 5
#define TASK_NUMBER2_FIRST_DELAY 27

#define TASK_NUMBER3_PERIODICITY 5
#define TASK_NUMBER3_FIRST_DELAY 60


#define TASK_NUMBER4_PERIODICITY 160
#define TASK_NUMBER4_FIRST_DELAY 160
//
//#define TASK_NUMBER2_PERIODICITY 1
//#define TASK_NUMBER2_FIRST_DELAY 6
//
//#define TASK_NUMBER2_PERIODICITY 1
//#define TASK_NUMBER2_FIRST_DELAY 6

#endif /* RTO_INTERFACE_H_ */
