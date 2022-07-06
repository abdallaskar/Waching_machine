/*
 * MOTOR_Interface.h
 *
 *  Created on: Dec 4, 2021
 *      Author: Abdalla
 */

#ifndef MOTOR_MOTOR_INTERFACE_H_
#define MOTOR_MOTOR_INTERFACE_H_

void MOTOR_Inti(void);
void MOTOR_Stop(void);
void MOTOR_TurnRight(void);
void MOTOR_TurnLeft(void);

void MOTOR_Inti1(void);
void MOTOR_Stop1(void);
void MOTOR_TurnRight1(void);
void MOTOR_TurnLeft1(void);

void MOTOR_Inti2(void);
void MOTOR_Stop2(void);
void MOTOR_TurnRight2(void);
void MOTOR_TurnLeft2(void);


#define MOTOR_PORT  1
#define MOTOR_PIN0  6
#define MOTOR_PIN1  7

#define MOTOR1_PORT  1
#define MOTOR1_PIN0  2
#define MOTOR1_PIN1  3

#define MOTOR2_PORT  1
#define MOTOR2_PIN0  0
#define MOTOR2_PIN1  1


#endif /* MOTOR_MOTOR_INTERFACE_H_ */
