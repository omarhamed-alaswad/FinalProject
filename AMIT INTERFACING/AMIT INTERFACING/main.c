/*
 * AMIT INTERFACING.c
 *
 * Created: 1/29/2021 3:27:47 PM
 * Author : VAIO
 */ 

#include <avr/io.h>
#include "LED.h"
#include "SEV_SEG.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "ADC.h"
#include "TIMER0.h"
#include "UART.h"
#include "SPI.h"





int main(void){
	LED0_Init();
	UART_Init();
	SPI_Init();
	SPI_SlaveSelect(0);
	while (1)
	{

		switch(UART_Receive())
		{
			case 'a':
			LED0_ON();
			_delay_ms(100);
			LED0_OFF();
			SPI_Transmit('a');
			_delay_ms(100);
			break;
			
			case 'b':
			LED0_ON();
			_delay_ms(100);
			LED0_OFF();
			_delay_ms(100);
			LED0_ON();
			_delay_ms(100);
			LED0_OFF();
			_delay_ms(100);
			SPI_Transmit('b');
			_delay_ms(100);
			break;
			case 'c':
			
			LED0_ON();
			_delay_ms(100);
			LED0_OFF();
			_delay_ms(100);
			LED0_ON();
			_delay_ms(100);
			LED0_OFF();
			_delay_ms(100);
			LED0_ON();
			_delay_ms(100);
			LED0_OFF();
			_delay_ms(100);
			SPI_Transmit('c');	
			_delay_ms(100);	
			default:
			LED0_OFF();
			break;	
		}
		
	}
}
	
	
	
	

/*int main(void)
{
	
	LED0_Init();
	UART_Init();
	
	//UART_Transmit('a');
	while (1)
	{

		switch(UART_Receive())
		{
			case 'a':
			LED0_ON();
			_delay_ms(250);
			LED0_OFF();
			break;
			case 'b':
			LED0_OFF();
			_delay_ms(250);
			LED0_ON();
			
		}
		
	}
}*/
		/*LED0_Init();
		
		IMER0_OVF_SETDELAY(1000); for normal mode
		TIMER0_CTC_SETDELAY(1000,255);
		TIMER0_START();*/
		
		
	
	/* Replace with your application code */
/*	while (1) /*Super loop - Infinite loop*/
/*	
	{
		
		
		
	}
}
		
	 
	


ISR(TIMER0_OVF_vect){  
	static Uint32t cnt=0;
	cnt++;
	if(cnt==NUM_OVF){
		LED0_TGL();
		cnt=0;
		TCNT0=INITIAL_VALUE;
		
	}
	
	}


ISR(TIMER0_COMP_vect){  /*timer for CTC mode*/
/*	static Uint32t cntr=0;
	cntr++;
	if(cntr==NUM_CTC){
		LED0_TGL();
		cntr=0;
		TCNT0=INITIAL_VALUE;
	}
}


/*
		SEVSEG_Init();
		
		LCD_Init();
		KEYPAD_Init();
		Uint8t btn=0;
		LCD_WRITE_STR("welcome");
		_delay_ms(250);
		LCD_CLEAR();
		_delay_ms(100);
		/*
		
	/*	LCD_WRITE_DTA('m');*/
	/*LCD_WRITE_STR("HAMED");*/
	
	/*LCD_WRITE_NBR(1141995);*/
		
		
	/*
	/* Replace with your application code */
	/*while (1) /*Super loop - Infinite loop
	{
		\	SEVSEG_DISPLAY(87);

			}
		
		} */
	
	
	/*
		
		UART_Init();
		LED0_Init();

		
		UART_Transmit('a');
		



		while(1){
			if(UART_Receive() == 'a')
			{
				LED0_ON();
				_delay_ms(100);
				LED0_OFF();
				_delay_ms(100);
				LED0_ON();
				_delay_ms(100);

			}
			if(UART_Receive() == 'T')
			{
				LED0_TGL();
				_delay_ms(1000);
				LED0_ON();
				_delay_ms(1000);
				LED0_TGL();
				_delay_ms(1000);
				LED0_ON();
				_delay_ms(1000);
			}
		}
	}*/ 