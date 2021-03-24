/*
 * LED_CONFIG.h
 *
 * Created: 2/21/2021 5:55:04 PM
 *  Author: VAIO
 */ 

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_
#include "CPU_CONFIGURATION.h"
/*LED0 Port*/
#define LED0_PORT DIO_PORTC
/*LED0 pin*/
#define LED0_PIN  DIO_PIN2
/*LED0 LED1 LED2 Directions*/
#define LED_OUTPUT DIO_PIN_OUTPUT
/*LED0 LED1 LED2 States*/
#define LED_HIGH DIO_PIN_HIGH
#define LED_LOW  DIO_PIN_LOW

/*LED1 Port*/
#define LED1_PORT DIO_PORTC
/*LED1 pin*/
#define LED1_PIN  DIO_PIN7

/*LED2 Port*/
#define LED2_PORT DIO_PORTD
/*LED2 pin*/
#define LED2_PIN  DIO_PIN3

#endif /* LED_CONFIG_H_ */