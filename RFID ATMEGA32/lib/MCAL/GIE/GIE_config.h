#ifndef GIE_CONFIG_H_
#define GIE_CONFIG_H_

#define SREG_I 7 //INTERRUPT PIN

/*  ISR VECTORS */
// EXT INT
#define INT0_VECT _VECTOR(1)
#define INT1_VECT _VECTOR(2)
#define INT2_VECT _VECTOR(3)
// UART
#define UART_RXC_VECT _VECTOR(13)
// ADC
#define ADC_VECT _VECTOR(16)

#endif