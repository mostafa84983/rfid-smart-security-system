#include "SPI.h"

// Initialize SPI interface
void SPI_Init(void) {
    // Set MOSI, SCK as Output
    DDRB = (1<<PB5)|(1<<PB7);
    // Enable SPI, Set as Master
    // Prescaler: Fosc/16, Enable Interrupts
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}

// Enable the SPI Slave device
void SPI_EnableSlave(void) {
    // Set Slave Select (SS) to low
    PORTB &= ~(1<<PB4);
}

// Disable the SPI Slave device
void SPI_DisableSlave(void) {
    // Set Slave Select (SS) to high
    PORTB |= (1<<PB4);
}

// Send a byte of data via SPI
void SPI_Transmit(char data) {
    // Start transmission
    SPDR = data;
    // Wait for transmission complete
    while(!(SPSR & (1<<SPIF)));
}

// Receive a byte of data via SPI
char SPI_Receive(void) {
    // Wait for reception complete
    while(!(SPSR & (1<<SPIF)));
    // Return Data Register
    return SPDR;
}
