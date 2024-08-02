#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

void SPI_Init(void);
void SPI_EnableSlave(void);
void SPI_DisableSlave(void);
void SPI_Transmit(char data);
char SPI_Receive(void);

#endif