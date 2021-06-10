/*
 * UART.c
 *
 * Created: 02/06/2021 19:03:14
 *  Author: Ahmed
 */ 

#include "UART.h"

void UART_Init(void)
{
	uint32 UBBR_Val=0;
	
	SET_BIT(DDRD,1); // Tx pin output
	CLR_BIT(DDRD,0); // Rx pin output
	
	SET_BIT(UCSRB,4); // Enable Tx
	SET_BIT(UCSRB,3); // Enable Rx
	
	UCSRC |= 0x86;
	
	UBBR_Val=(160000) / (16*96) - 1; // Set Baud rate
	UBRRL= UBBR_Val;
	
}

void UART_Tx(uint8 data)
{
	UDR = data;
	while(GET_BIT(UCSRA,5)==0);
	
}

void UART_TxString (uint8* str)
{
	uint8 i=0;
	
	while (str[i] != '\0')
	{
		UART_Tx(str[i]);
		i++;
	}
}

uint8 UART_Rx(void)
{
	uint8 data = 0;
	
	while (GET_BIT(UCSRA,7)==0);
	
	data = UDR;
	
	return data;
	
}
