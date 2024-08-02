#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#include "../../../include/std_types.h"

#define ADMUX    *((volatile u8*)0x27) //ADC MULTIPLEXER SELECTION REGISTER
#define ADCSRA   *((volatile u8*)0x26) //ADC CONTROL & STATUS REGISTER A
#define ADC_H    *((volatile u8*)0x25) //ADC HIGH
#define ADC_L    *((volatile u8*)0x24) //ADC LOW
#define ADC      *((volatile u16*)0x24) //ADC HIGH + LOW

#endif