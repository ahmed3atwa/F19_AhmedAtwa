/*
 * MC1_Master_GraduationProject.c
 *
 * Created: 08/06/2021 00:46:37
 * Author : Ahmed
 */ 

#include "UART.h"
#include "LCD.h"
#include "SPI.h"

#define F_CPU 16000000
#include <util/delay.h>



int main(void)
{
    uint8 data = 0;
	
		UART_Init();
		
		LCD_Init();
		
		SPI_Master_Init();
		SPI_Master_InitTrans();
		_delay_ms(1000);
		
		
    while (1) 
    {
				data= UART_Rx();
				
				if(data)
				{
					LCD_WriteChar(data);
					SPI_TransSiver(data);
					data=0;
					
				}
				
    }
}

