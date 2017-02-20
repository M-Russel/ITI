/*
 * STEPPER_interface.h
 *
 *  Created on: Feb 6, 2017
 *      Author: root
 */

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_


u8 STEPPER_u8Init();
u8 STEPPER_u8SetRotateDirectionClockWise(void);
u8 STEPPER_u8SetRotateDirectionCounterClockWise(void);
u8 STEPPER_u8ConvertValue (u8 Copy_u8PinNumber,u8 Copy_u8Value);


#endif /* STEPPER_INTERFACE_H_ */
