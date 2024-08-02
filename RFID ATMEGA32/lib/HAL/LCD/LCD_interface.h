#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "../../../include/std_types.h"
#include "LCD_config.h"


void LCD_VidInit(const char *str);
void LCD_VidCmd(u8 Local_u8Cmd);
void LCD_VidPrintChar(u8 Local_u8Char);
void LCD_VidPrintString(const char *str);
void LCD_VidPrintNumber(int Local_intNumber);
void LCD_VidMoveCursor(u8 Local_u8Row, u8 Local_u8Column);
void LCD_VidDeleteChar(void);
void LCD_VidPrintChar_XY(u8 Copy_u8Data,u8 row, u8 column);
void LCD_VidPrintString_XY(char *Copy_u8Data,u8 row, u8 column);

#endif