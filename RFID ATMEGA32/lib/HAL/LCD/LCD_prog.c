#include "LCD_interface.h"

#include "../../../include/bitmanip.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include <util/delay.h>
#include <stdio.h>

/* generate high pulse for 1 ms to enable lcd (latch data from Dx pins to registers) */
static void LCD_VidSendPulse(void){
	DIO_VidSetPinValue(LCD_PORT, LCD_E, PinHigh);
	_delay_ms(1);
	DIO_VidSetPinValue(LCD_PORT, LCD_E, PinLow);
	_delay_ms(1);
}

/* Send nibble on D4 ~ D7 (4-bit mode) */
static void LCD_VidSendNibble(u8 data){
	u8 Local_u8LowNibble = data & 0x0F;
	u8 Local_u8HighNibble = (data & 0xF0) >> 4;
	
	// send high nibble
	DIO_VidSetLowNibbleValue(LCD_PORT, Local_u8HighNibble, LCD_D4);
	// latch the nibble to lcd
	LCD_VidSendPulse();
	// send low nibble
	DIO_VidSetLowNibbleValue(LCD_PORT, Local_u8LowNibble, LCD_D4);
	// latch the nibble to lcd
	LCD_VidSendPulse();
}

/* Initialize LCD */
void LCD_VidInit(const char *str){
	_delay_ms(50);
	
	// Set LCD pins as output
	for (et_Pin LCDPin = LCD_RS; LCDPin <= LCD_D7; LCDPin++){
		DIO_VidSetPinDirection(LCD_PORT, LCDPin, Output);
	}

	DIO_VidSetPinValue(LCD_PORT, LCD_E, PinLow);
	
	LCD_VidCmd(LCD_HOME);
	LCD_VidCmd(LCD_2LINE_4BIT);
	LCD_VidCmd(LCD_CURSOR_OFF);
	LCD_VidCmd(LCD_CLEAR);
	LCD_VidCmd(LCD_INCREMENT_CURSOR);

	// print startup message
	LCD_VidPrintString(str);
	_delay_ms(1400);

	LCD_VidCmd(LCD_CLEAR);
}

/* Send Command */
void LCD_VidCmd(u8 Local_u8Cmd){
	// set rs as cmd
	DIO_VidSetPinValue(LCD_PORT, LCD_RS, PinLow);
	// Send command
	LCD_VidSendNibble(Local_u8Cmd);
}

/* Print Character */
void LCD_VidPrintChar(u8 Local_u8Char){
	// set rs as data
	DIO_VidSetPinValue(LCD_PORT, LCD_RS, PinHigh);
	// Send data
	LCD_VidSendNibble(Local_u8Char);
} 

/* Print String */
void LCD_VidPrintString(const char *str){
	while (*str){
		LCD_VidPrintChar(*str++);
	} 
}

/* Print Integer */
void LCD_VidPrintNumber(int Local_intNumber){
	char str[20];
	sprintf(str, "%d", Local_intNumber);
	LCD_VidPrintString(str);
}

/* Move cursor to specified position */
void LCD_VidMoveCursor(u8 Local_u8Row, u8 Local_u8Column){
	u8 Local_u8Command;// the command which will set the position of the cursor
	
	/* in case of wrong input set the cursor to the first position of the LCD*/
	if (Local_u8Row > 2 || Local_u8Row < 1 || Local_u8Column > 16 || Local_u8Column < 1){
		Local_u8Command = LCD_HOME;
	}

	/*set the position of cursor depend on the selected row and column*/
	if (1 == Local_u8Row){
		Local_u8Command = LCD_1ST_LINE + Local_u8Column - 1;
	}

	else if (2 == Local_u8Row){
		Local_u8Command = LCD_2ND_LINE + Local_u8Column - 1;
	}
	
	// set the position  of the cursor
	LCD_VidCmd(Local_u8Command); 
}

/* Delete last charachter */
void LCD_VidDeleteChar(void){
	LCD_VidCmd(LCD_CURSOR_LEFT);
	LCD_VidPrintChar(' ');
	LCD_VidCmd(LCD_CURSOR_LEFT);
}

void LCD_VidPrintChar_XY(u8 Copy_u8Data,u8 row, u8 column){
	LCD_VidMoveCursor(row, column);
	LCD_VidPrintChar(Copy_u8Data);
}

void LCD_VidPrintString_XY(char *Copy_u8Data,u8 row, u8 column){
	LCD_VidMoveCursor(row, column);
	LCD_VidPrintString(Copy_u8Data);
}
