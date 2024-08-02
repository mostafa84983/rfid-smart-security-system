#include "ADC_interface.h"
#include "ADC_private.h"

#include "../../../include/bitmanip.h"


void ADC_VidInit(u8 Copy_u8RefVoltage, u8 Copy_u8PreScalar){
   // SET REFERENCE VOLTAGE
   ADMUX &= 0b00111111;
   ADMUX |= Copy_u8RefVoltage;
   // SET CLOCK DIVISION FACTOR
   ADCSRA &= 0b11111000;
   ADCSRA |= Copy_u8PreScalar;
   // ACTIVATE LEFT ADJUSTMENT
   SET_BIT(ADMUX, ADMUX_ADLAR);
   // ENABLE ADC
   SET_BIT(ADCSRA, ADCSRA_ADEN);
}

u8 ADC_u8ReadChannel(u8 Copy_u8Channel){
   // SET ADC CHANNEL
   ADMUX &= 0b11110000;
   ADMUX |= Copy_u8Channel;
   // START ADC CONVERSION
   SET_BIT(ADCSRA, ADCSRA_ADSC);
   // POLL UNTIL CONVERSION IS COMPLETE
   while (GET_BIT(ADCSRA, ADCSRA_ADSC))
      ;
   // RETURN ADC
   return ADC_H;
}

u16 ADC_u16ReadChannel(u8 Copy_u8Channel){
   // SET ADC CHANNEL
   ADMUX &= 0b11110000;
   ADMUX |= Copy_u8Channel;
   // START ADC CONVERSION
   SET_BIT(ADCSRA, ADCSRA_ADSC);
   // POLL UNTIL CONVERSION IS COMPLETE
   while (GET_BIT(ADCSRA, ADCSRA_ADSC))
      ;
   // RETURN ADC
   return ADC;
}

void ADC_VidEnableInterrupt(u8 Copy_u8Channel){
   // SET ADC CHANNEL
   ADMUX &= 0xF0;
   ADMUX |= Copy_u8Channel;

   // ENABLE ADC INTERRUPT
   SET_BIT(ADCSRA, ADCSRA_ADIE);
   
   // START ADC CONVERSION
   SET_BIT(ADCSRA, ADCSRA_ADSC);
   
}