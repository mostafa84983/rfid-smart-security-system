#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "../../MCAL/DIO/DIO_interface.h"

#define PRESSEED 0
#define NOT_PRESSED 0xff

/*	keypad DIO	*/
#define KEYPAD_COL_PORT		Port_D
#define KEYPAD_ROW_PORT		Port_B


/*	KEYPAD PINS	*/
#define KEYPAD_COL_1		Pin2
#define KEYPAD_COL_2		Pin3
#define KEYPAD_COL_3		Pin4
#define KEYPAD_COL_4		Pin5

#define KEYPAD_ROW_1		Pin4
#define KEYPAD_ROW_2		Pin5
#define KEYPAD_ROW_3		Pin6
#define KEYPAD_ROW_4		Pin7


/*	KEYPAD SIZE	*/
#define KEYPAD_COL_NUM		4
#define KEYPAD_ROW_NUM		4


/*	KEYPAD VALUES	*/
#define KEYPAD_ARR_VAL_MATRIXMODE		{ {'1','2','3','-'},{'4','5','6','*'},{'7','8','9','/'},{'C','0','=','+'} }
#define KEYPAD_ARR_VAL_DirectMode		{ 'U','D','R','-' } // UP,DOWN,RESET,NULL



#endif
