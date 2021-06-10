/*
 * MC2_Slave_GraduationProject.c
 *
 * Created: 08/06/2021 14:40:35
 * Author : Ahmed
 */ 

#include "SPI.h"
#include "LED.h"


int main(void)
{
	
    uint8 tx_data=0;
	uint8 rx_data=0;
	
	
	LED1_Init();
	SPI_Slave_Init();
	LED0_Init();
	LED1_Init();
	
	
    while (1) 
    {
		rx_data = SPI_TransSiver(tx_data);
		
		switch (rx_data)
		{
			case 49:
			LED0_On();
			break;
			
			case 50:
			LED0_Off();
			break;
			
			case 51:
			LED1_On();
			break;
			
			case 52:
			LED1_Off();
			break;
			
			default:
			break;
		}
		
	}
}
