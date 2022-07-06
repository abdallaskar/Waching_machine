/*
 * main.c
 *
 *  Created on: Aug 26, 2021
 *      Author: abdalla
 */

#include "DIO/DIO_interface.h"
#include "LCD/LCD_Interface.h"
#include "MOTOR/MOTOR_Interface.h"
#include "LIB/STD_TYPE.h"
#include <util/delay.h>

int main() {
	u8 door = 1;          // specify door status

	// LCD print welcome
	LCD_Init();
	LCD_PrintString(" Welcome ");
	_delay_ms(500);
	LCD_SendCommond(0x01);               // clear LCD
	LCD_PrintString("door is open");    // by default door is open
	LCD_SetCursorPostion(0, 1);
	LCD_PrintString("close the door");

	//  Door washing machine
	DIO_SetPinDirection(DIO_PORTB, PIN4, 0);
	DIO_SetPinValue(DIO_PORTB, PIN4, 1);

	// check the status of door
	while (door != 0) {
		door = DIO_GetPinValue(DIO_PORTB, PIN4);
		if (door == 0) {
			_delay_ms(250);
			if (door == 0) {
				LCD_SetCursorPostion(0, 0);
				LCD_PrintString(" door is closed ");
				_delay_ms(150);
				LCD_SendCommond(0x01);
				LCD_PrintString("select washing ");
				LCD_SetCursorPostion(0, 1);
				LCD_PrintString("    mode ");
			}
		}
	}

	//Initial  motor water && motor washing
	MOTOR_Inti1();
	MOTOR_Inti();
	MOTOR_Inti2();
	// select timer
	LCD_SendCommond(0x01);
	LCD_PrintString("select timer ");

	DIO_SetPinDirection(DIO_PORTD, PIN5, 0);
	DIO_SetPinValue(DIO_PORTD, PIN5, 1);
	DIO_SetPinDirection(DIO_PORTD, PIN6, 0);
	DIO_SetPinValue(DIO_PORTD, PIN6, 1);
	DIO_SetPinDirection(DIO_PORTD, PIN7, 0);
	DIO_SetPinValue(DIO_PORTD, PIN7, 1);

	LCD_SendCommond(0x01);
	LCD_PrintString("select timer ");
	LCD_SendCommond(0x01);
	LCD_PrintString("timer = 0 ");

	u8 coun_time = 0;
	u8 add = 1;
	u8 sub = 1;
	u8 ok = 1;

	while (ok != 0) {
		add = DIO_GetPinValue(DIO_PORTD, PIN7);
		sub = DIO_GetPinValue(DIO_PORTD, PIN6);
		ok = DIO_GetPinValue(DIO_PORTD, PIN5);

		if (add == 0) {
			_delay_ms(250);
			if (add == 0) {
				coun_time++;
				LCD_SendCommond(0x01);
				LCD_PrintString("timer = ");
				u8 num = coun_time * 5;
				LCD_PrintNum(num);
			}
		}
		if (sub == 0) {
			_delay_ms(250);
			if (sub == 0) {
				coun_time--;
				LCD_SendCommond(0x01);
				LCD_PrintString("timer = ");
				u8 num = coun_time * 5;
				LCD_PrintNum(num);
			}
		}
		if (ok == 0) {
			_delay_ms(250);
			if (ok == 0) {
				break;
			}
		}
		add = 1;
		sub = 1;

	}

	// pull up button mode of washing
	DIO_SetPinDirection(DIO_PORTB, PIN5, 0);
	DIO_SetPinValue(DIO_PORTB, PIN5, 1);

	LCD_SendCommond(0x01);
	LCD_PrintString("select washing");
	LCD_SetCursorPostion(0, 1);
	LCD_PrintString("mode");
	u8 mode = 1;        // mode of washing

	while (mode != 0) {

		mode = DIO_GetPinValue(DIO_PORTB, PIN5);
		// main mode
		if (mode == 0) {
			_delay_ms(250);
			if (mode == 0) {
				u8 counter = 0;
				// The tap is opened
				LCD_SendCommond(0x01);
				LCD_PrintString("The tap is opened");
				MOTOR_TurnLeft1();
				_delay_ms(500);
				MOTOR_Stop1();

				LCD_SendCommond(0x01);
				LCD_PrintString("water is entering");
				DIO_SetPinDirection(DIO_PORTD, PIN3, 1); // led is open
				DIO_SetPinValue(DIO_PORTD, PIN3, 1);
				_delay_ms(5000);

				LCD_SendCommond(0x01);
				LCD_PrintString("The tap is closed");
				DIO_SetPinValue(DIO_PORTD, PIN3, 0); // led is close

				MOTOR_TurnRight1();
				_delay_ms(500);
				MOTOR_Stop1();
				_delay_ms(100);
				// LCD

				LCD_SendCommond(0x01);
				LCD_PrintString("  Washing ");

				while (counter < coun_time) {
					MOTOR_TurnRight();
					_delay_ms(500);
					MOTOR_Stop();
					_delay_ms(100);
					MOTOR_TurnLeft();
					_delay_ms(500);
					MOTOR_Stop();
					_delay_ms(100);
					counter++;
				}
			}
		}

	}
	LCD_SendCommond(0x01);
	LCD_PrintString(" Finish washing ");
	_delay_ms(100);

	//
	LCD_SendCommond(0x01);
	LCD_PrintString("tap is pend ");
	MOTOR_TurnRight2();
	_delay_ms(500);
	MOTOR_Stop2();
	LCD_SendCommond(0x01);
	LCD_PrintString("water discharge");
	DIO_SetPinDirection(DIO_PORTD, PIN4, 1); // led is open
	DIO_SetPinValue(DIO_PORTD, PIN4, 1);
	_delay_ms(1000);

	// Drying
	LCD_SendCommond(0x01);
	LCD_PrintString("start drying");
	MOTOR_TurnLeft();
	_delay_ms(5000);
	MOTOR_Stop();
	_delay_ms(100);

	LCD_SendCommond(0x01);
	LCD_PrintString(" Finish drying ");
	_delay_ms(100);

	LCD_SendCommond(0x01);
	LCD_PrintString("tap is closed ");
	MOTOR_TurnLeft2();
	_delay_ms(500);

	DIO_SetPinValue(DIO_PORTD, PIN4, 0);
	MOTOR_Stop2();
	LCD_SendCommond(0x01);
	LCD_PrintString(" washing finish ");


	while (1) {

	}

	return 0;
}
