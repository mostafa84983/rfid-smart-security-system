#ifndef EX_INT_PRIVATE_H_
#define EX_INT_PRIVATE_H_

#include "../../include/std_types.h"

/*  GICR BITS ENABLE INTERRUPT INTI->Bit7, INTO->Bit6, INT2-->Bit5    */
#define GICR *((volatile u8*)0x5B)

/*  MCUCR BITS INTERRUPT PIN INTI OR INTO   */
#define GIFR *((volatile u8*)0x5A)

/*  MCU CONTROL REGISTER */
#define MCUCR *((volatile u8*)0x55)

/*  MCUCSR BITS INTERRUPT PIN INT2 Bit6-->1SC2  */
#define MCUCSR *((volatile u8*)0x54)

#endif