/*
 * SERVO.c
 *
 * Created: 3/19/2021 8:19:36 PM
 *  Author: VAIO
 */ 

#include "SERVO.h"

void SERVO_Init(void)
{
	TIMER1_FASTPWM_ICR_Init();
	TIMER1_FASTPWM_ICR_START();
}
void SERVO_ANGLE(Uint8t angle)
{
	TIMER1_FASTPWM_ICR_SETDUTY(angle);
}