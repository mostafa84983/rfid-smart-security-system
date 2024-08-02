#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_RS Pin1 // Register Select
#define LCD_E  Pin2 // Enable
#define LCD_D4 Pin3 // Data 4
#define LCD_D5 Pin4 // Data 5
#define LCD_D6 Pin5 // Data 6
#define LCD_D7 Pin6 // Data 7

#define LCD_PORT Port_A

#define LCD_CLEAR 0x01 // clear screen
#define LCD_HOME 0x02 // set cursor to home
#define LCD_INCREMENT_CURSOR 0x06 // left to right
#define LCD_DECREMENT_CURSOR 0x04 // right to left
#define LCD_CURSOR_OFF 0x0C // Display ON cursor off
#define LCD_CURSOR_BLINKING 0x0E // Display ON cursor blinking ( _ )
#define LCD_CURSOR_FIXED 0x0F // Display ON cursor blinking ( [] )
#define LCD_2LINE_4BIT 0x28 // 2 lines, 5x8 matrix, 4-bit mode
#define LCD_1LINE_4BIT 0x20 // 1 line, 5x8 matrix, 4-bit mode
#define LCD_1ST_LINE 0x80 // send cursor to first line
#define LCD_2ND_LINE 0xC0 // send cursor to second line
#define LCD_CURSOR_LEFT 0x10 // shift cursor position to left
#define LCD_CURSOR_RIGHT 0x14// shift cursor position to right

#endif
