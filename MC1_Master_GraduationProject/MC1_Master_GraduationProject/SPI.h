/*
 * SPI.h
 *
 * Created: 03/06/2021 11:13:30
 *  Author: Ahmed
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"

void SPI_Master_Init(void);

void SPI_Slave_Init(void);

void SPI_Master_InitTrans(void);

void SPI_Master_TermTrans(void);

uint8 SPI_TransSiver(uint8 data);




#endif /* SPI_H_ */