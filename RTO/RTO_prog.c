/*
 * RTO_prog.c
 *
 *  Created on: Feb 22, 2017
 *      Author: Russel
 */
#include "std_types.h"
#include "RTO_interface.h"
#include "RTO_config.h"
#include "RTO_private.h"
#include "TIMER0_interface.h"
#include "DIO_Interface.h"

static Task *RTO_TaskScheduler[RTO_MAXIMUM_TASK_NUMBER];
static u8 RTO_u8Status=RTO_OK;

void RTO_voidInit(void)
{
	// The call back function
	u8 RTO_u8Counter=RTO_SCHEDULAR_INITIAL_TASK;
	for (RTO_u8Counter=RTO_SCHEDULAR_INITIAL_TASK;RTO_MAXIMUM_TASK_NUMBER>RTO_u8Counter;RTO_u8Counter++)
	{
		 RTO_TaskScheduler[RTO_u8Counter]=NULL;
	}
	TIMER0_voidSetTimerCallBack(RTO_voidSchedular);
}
u8 RTO_u8CreatTask(Task *Copy_pTaskPointer,u8 Copy_u8TaskPriority)
{
	if (RTO_MAXIMUM_TASK_NUMBER>Copy_u8TaskPriority )
	{
		RTO_TaskScheduler[Copy_u8TaskPriority]=Copy_pTaskPointer;
		RTO_u8Status=RTO_OK;
	}
	else
	{
		RTO_u8Status=RTO_ERROR;
	}
return RTO_u8Status;

}
u8 RTO_u8DeleteTask(u8 Copy_u8TaskPriority)
{
	if (RTO_MAXIMUM_TASK_NUMBER>Copy_u8TaskPriority && RTO_TaskScheduler[Copy_u8TaskPriority]->ptr!=NULL)
		{
			RTO_TaskScheduler[Copy_u8TaskPriority]=NULL;
			RTO_u8Status=RTO_OK;

		}
	else
		{
			RTO_u8Status=RTO_ERROR;
		}

	return RTO_u8Status;

}
u8 RTO_u8StartTask(u8 Copy_u8TaskPriority)
{
	if (RTO_MAXIMUM_TASK_NUMBER>Copy_u8TaskPriority && RTO_TaskScheduler[Copy_u8TaskPriority]->ptr!=NULL)
		{
			RTO_TaskScheduler[Copy_u8TaskPriority]->state=Running;
			RTO_u8Status=RTO_OK;

}
	else
		{
			RTO_u8Status=RTO_ERROR;
		}

	return RTO_u8Status;

}
u8 RTO_u8StopTask(u8 Copy_u8TaskPriority)
{
	if (RTO_MAXIMUM_TASK_NUMBER>Copy_u8TaskPriority && RTO_TaskScheduler[Copy_u8TaskPriority]->ptr!=NULL)
		{

			RTO_TaskScheduler[Copy_u8TaskPriority]->state=Paused;
			RTO_u8Status=RTO_OK;
		}
	else
		{
			RTO_u8Status=RTO_ERROR;
		}
	return RTO_u8Status;

}

static void RTO_voidSchedular(void)
{

	u8 RTO__u8SchedularCounter;
		for (RTO__u8SchedularCounter=RTO_SCHEDULAR_INITIAL_TASK;RTO_MAXIMUM_TASK_NUMBER>RTO__u8SchedularCounter;RTO__u8SchedularCounter++)
		{
			//valid pointer + status

			if( ((RTO_TaskScheduler[RTO__u8SchedularCounter]) != NULL)&& ((RTO_TaskScheduler[RTO__u8SchedularCounter]->state) !=Paused))
			{


				if (RTO_TaskScheduler[RTO__u8SchedularCounter]->Task_u32First_Delay== RTO_SCHEDULAR_INITIAL_TASK)
					{

						(RTO_TaskScheduler[RTO__u8SchedularCounter]->ptr)();
						RTO_TaskScheduler[RTO__u8SchedularCounter]->Task_u32First_Delay=RTO_TaskScheduler[RTO__u8SchedularCounter]->Task_u32Periodicity-RTO_Schedular_PERIODICITY_OFFSET;
					}
				else
					{
						RTO_TaskScheduler[RTO__u8SchedularCounter]->Task_u32First_Delay--;
					}
			}
			else
			{


			}
		}


}
