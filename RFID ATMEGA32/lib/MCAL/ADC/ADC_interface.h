#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_config.h"

#include "../../../include/std_types.h"

void ADC_VidInit(u8 Copy_u8RefVoltage, u8 Copy_u8PreScalar);
void ADC_VidEnableInterrupt(u8 Copy_u8Channel);
u8 ADC_u8ReadChannel(u8 Copy_u8Channel);
u16 ADC_u16ReadChannel(u8 Copy_u8Channel);

#endif