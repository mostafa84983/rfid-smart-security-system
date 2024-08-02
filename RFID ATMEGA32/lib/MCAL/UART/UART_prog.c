
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

#include "../../../include/bitmanip.h"


void UART_VidInit(double D_BaudRate)
{

	UBRRL=F_CPU/((D_BaudRate*8)-1);
	UBRRH=0;
	UCSRA |=1<<UCSRA_U2X;
	UCSRB |=1<<UCSRB_RXEN;								// Enable Receive
	UCSRB |=1<<UCSRB_TXEN;								// Enable Transmit
	UCSRC=0b10000110;

}

void UART_VidSendByte(u8 Copy_u8Byte)
{
while (!(UCSRA&(1<<UCSRA_UDRE)));                // Wait while register is free
		UDR=Copy_u8Byte;  // your data
	while (!( UCSRA & (1<<UCSRA_UDRE)));
}

void UART_VidSendString(const char *str)
{
    while (*str)
        UART_VidSendByte(*str++);
}

u8 UART_u8ReceiveData(void)
{
    // Polling until receive complete
    while (!((UCSRA&(1<<UCSRA_RXC))>>UCSRA_RXC))
        ;
    return UDR;
}

u8 UART_u8GetUDR(void){
    return UDR;
}
