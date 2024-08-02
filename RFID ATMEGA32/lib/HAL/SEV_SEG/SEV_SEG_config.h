#ifndef SEV_SEG_CONFIG
#define SEV_SEG_CONFIG

#include "../../MCAL/DIO/DIO_interface.h"

#define SEG_NUM_ZERO 0b01111110
#define SEG_NUM_ONE 0b00001100
#define SEG_NUM_TWO 0b10110110
#define SEG_NUM_THREE 0b10011110
#define SEG_NUM_FOUR 0b11001100
#define SEG_NUM_FIVE 0b11011010
#define SEG_NUM_SIX 0b11111010
#define SEG_NUM_SEVEN 0b10001110
#define SEG_NUM_EIGHT 0b11111110
#define SEG_NUM_NINE 0b11001110

#define SEGMENT_PORT Port_A

#define COMM_DDR Port_C
#define COMM_PORT Port_C
#define COMM_ONES Pin6
#define COMM_TENS Pin7

#define SEG_DELAY _delay_ms(40)

#endif
