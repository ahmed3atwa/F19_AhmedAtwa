/*
 * SPI.c
 *
 * Created: 03/06/2021 11:13:20
 *  Author: Ahmed
 */ 
#include "SPI.h"

void SPI_Master_Init(void)
{
	DIO_SetPinDir(DIO_PORTB, DIO_PIN6, DIO_PIN_INPUT);  // MISO
	DIO_SetPinDir(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);  // MOSI
	DIO_SetPinDir(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);  // CLOCK
	DIO_SetPinDir(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT);  // SS
	
	SPI->SPCR |= 0x53; // in binary 01010011
	
	DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_HIGH); // SS Pin NO init trans
}

void SPI_Slave_Init(void)
{
		DIO_SetPinDir(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);  // MISO
		DIO_SetPinDir(DIO_PORTB, DIO_PIN5, DIO_PIN_INPUT);  // MOSI
		DIO_SetPinDir(DIO_PORTB, DIO_PIN7, DIO_PIN_INPUT);  // CLOCK
		DIO_SetPinDir(DIO_PORTB, DIO_PIN4, DIO_PIN_INPUT);  // SS
		
		SPI->SPCR |= 0x40; // in binary 01000000
}

void SPI_Master_InitTrans(void)
{
	DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_LOW);
}

void SPI_Master_TermTrans(void)
{
	DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_HIGH);
}

uint8 SPI_TransSiver(uint8 data)
{
	uint8 rec_data=0;
	
	SPI->SPDR=data;
	
	while(GET_BIT(SPI->SPSR,7)==0);
	
	rec_data= SPI->SPDR;
	
	return rec_data;
}