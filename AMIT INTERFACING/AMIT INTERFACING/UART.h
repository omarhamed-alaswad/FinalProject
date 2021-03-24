/*
 * UART.h
 *
 * Created: 3/18/2021 3:03:00 PM
 *  Author: VAIO
 */ 


#ifndef UART_H_
#define UART_H_
#include "UART_CONFIG.h"

void UART_Init(void);
void UART_Transmit(Uint8t data);
Uint8t UART_Receive(void);
UART_Status UART_RECEIVE(Uint8t* data);

#endif /* UART_H_ */