#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "../../../include/std_types.h"

// void UART_VidInit(void);
void UART_VidSendByte(u8 Copy_u8Byte);
void UART_VidSendString(const char *str);
u8 UART_u8ReceiveData(void);
u8 UART_u8GetUDR(void);
void UART_VidInit(double D_BaudRate);
#endif