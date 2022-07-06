/*
 * program.c
 *
 *  Created on: Dec 4, 2021
 *      Author: Abdalla
 */
#include "../DIO/DIO_interface.h"
#include "MOTOR_Interface.h"



void MOTOR_Inti(void){
	DIO_SetPinDirection(MOTOR_PORT,MOTOR_PIN0,1);
	DIO_SetPinDirection(MOTOR_PORT,MOTOR_PIN1,1);
}
void MOTOR_Stop(void){
	DIO_SetPinValue(MOTOR_PORT,MOTOR_PIN0,0);
	DIO_SetPinValue(MOTOR_PORT,MOTOR_PIN1,0);
}
void MOTOR_TurnRight(void){
	DIO_SetPinValue(MOTOR_PORT,MOTOR_PIN0,0);
	DIO_SetPinValue(MOTOR_PORT,MOTOR_PIN1,1);
}
void MOTOR_TurnLeft(void){
	DIO_SetPinValue(MOTOR_PORT,MOTOR_PIN0,1);
	DIO_SetPinValue(MOTOR_PORT,MOTOR_PIN1,0);
}


void MOTOR_Inti1(void){
	DIO_SetPinDirection(MOTOR1_PORT,MOTOR1_PIN0,1);
	DIO_SetPinDirection(MOTOR1_PORT,MOTOR1_PIN1,1);
}
void MOTOR_Stop1(void){
	DIO_SetPinValue(MOTOR1_PORT,MOTOR1_PIN0,0);
	DIO_SetPinValue(MOTOR1_PORT,MOTOR1_PIN1,0);
}
void MOTOR_TurnRight1(void){
	DIO_SetPinValue(MOTOR1_PORT,MOTOR1_PIN0,0);
	DIO_SetPinValue(MOTOR1_PORT,MOTOR1_PIN1,1);
}
void MOTOR_TurnLeft1(void){
	DIO_SetPinValue(MOTOR1_PORT,MOTOR1_PIN0,1);
	DIO_SetPinValue(MOTOR1_PORT,MOTOR1_PIN1,0);
}

void MOTOR_Inti2(void){
	DIO_SetPinDirection(MOTOR2_PORT,MOTOR2_PIN0,1);
	DIO_SetPinDirection(MOTOR2_PORT,MOTOR2_PIN1,1);
}
void MOTOR_Stop2(void){
	DIO_SetPinValue(MOTOR2_PORT,MOTOR2_PIN0,0);
	DIO_SetPinValue(MOTOR2_PORT,MOTOR2_PIN1,0);
}
void MOTOR_TurnRight2(void){
	DIO_SetPinValue(MOTOR2_PORT,MOTOR2_PIN0,0);
	DIO_SetPinValue(MOTOR2_PORT,MOTOR2_PIN1,1);
}
void MOTOR_TurnLeft2(void){
	DIO_SetPinValue(MOTOR2_PORT,MOTOR2_PIN0,1);
	DIO_SetPinValue(MOTOR2_PORT,MOTOR2_PIN1,0);
}


