/*
 * slave.c
 *
 * Created: 3/24/2021 12:00:35 AM
 * Author : VAIO
 */ 

#include <avr/io.h>
#include "CPU_CONFIGURATION.h"
#include "SPI.h"
#include "LED.h"


int main(void)
{
	SPI_Init();
	LED0_Init();
	LED2_Init();
    /* Replace with your application code */
    while (1) 
    {
		switch(SPI_Receive()){
			case 'a' :
			LED0_ON();
			_delay_ms(100);
			LED0_OFF();
			break;
			
			case 'b' :
			LED2_ON();
			_delay_ms(100);
			LED2_OFF();
			break;
			
			case 'c' :
			LED0_ON();
			_delay_ms(100);
			LED0_OFF();
			_delay_ms(100);
			LED2_ON();
			_delay_ms(100);
			LED2_OFF();
			break;
			default:
			LED0_OFF();
			LED2_OFF();
			break;
    }
	}
}

