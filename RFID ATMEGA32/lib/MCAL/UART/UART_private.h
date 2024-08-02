#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#include "../../include/std_types.h"

#define UDR *((volatile u8 *)0x2C)   // USART I/O Data Register
#define UCSRA *((volatile u8 *)0x2B) // USART Control and Status Register A
#define UCSRB *((volatile u8 *)0x2A) // USART Control and Status Register B

#define UCSRC *((volatile u8 *)0x40) // USART Control and Status Register C
#define UBRRH *((volatile u8 *)0x40) // USART Baud Rate Register High
#define UBRRL *((volatile u8 *)0x29) // USART Baud Rate Register Low

#define UCSRA_MPCM 0 // Multi-processor Communication Mode
#define UCSRA_U2X 1  //  Double the USART Transmission Speed
#define UCSRA_PE 2   //  Parity Error
#define UCSRA_DOR 3  // Data OverRun
#define UCSRA_FE 4   //  Frame Error
#define UCSRA_UDRE 5 // USART Data Register Empty
#define UCSRA_TXC 6  // USART Transmit Complete
#define UCSRA_RXC 7  // USART Receive Complete

#define UCSRB_TXEN 3  // TRANSMITTER ENABLE
#define UCSRB_RXEN 4  // RECEIVER ENABLE
#define UCSRB_UDRIE 5 // USART Data Register Empty Interrupt Enable
#define UCSRB_TXCIE 6 // TX Complete Interrupt Enable
#define UCSRB_RXCIE 7 // RX Complete Interrupt Enable

#define UCSRC_UCSZ0 1 // CHARCTER SIZE 0
#define UCSRC_UCSZ1 2 // CHARCTER SIZE 1
#define UCSRC_URSEL 7 // REGISTER SELECT 1->UCSRC , 0->UBRRH

#endif