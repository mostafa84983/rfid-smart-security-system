#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

// ADCMUX REFERANCE SELECTION BIT
#define ADMUX_REFS1     7
#define ADMUX_REFS0     6
#define ADMUX_ADLAR     5 //ADC LEFT ADJUSTMENT

// ADC CONTROL AND STATUS REGISTER
#define ADCSRA_ADEN     7 //ADC ENABLE
#define ADCSRA_ADSC     6 //ADC START CONVERSION
#define ADCSRA_ADTE     5 //ADC AUTO TRIGGER INTERRUPT
#define ADCSRA_ADIF     4 //ADC INTERRUPT FLAG
#define ADCSRA_ADIE     3 //ADC INTERRUPT ENABLE
#define ADCSRA_ADPS2    2 //CLOCK PRESCALAR
#define ADCSRA_ADPS1    1 //CLOCK PRESCALAR
#define ADCSRA_ADPS0    0 //CLOCK PRESCALAR

// Define ADC channel macros
#define ADC_CHANNEL_0   0x00
#define ADC_CHANNEL_1   0x01
#define ADC_CHANNEL_2   0x02
#define ADC_CHANNEL_3   0x03
#define ADC_CHANNEL_4   0x04
#define ADC_CHANNEL_5   0x05
#define ADC_CHANNEL_6   0x06
#define ADC_CHANNEL_7   0x07

// Define ADC reference voltage macros
#define ADC_REF_EXTERNAL    0x00
#define ADC_REF_AVCC        0x40
#define ADC_REF_INTERNAL    0xC0

// ADC PRESCALAR VALUES
#define ADC_CLOCK_DIV_2     0x01
#define ADC_CLOCK_DIV_4     0x02
#define ADC_CLOCK_DIV_8     0x03
#define ADC_CLOCK_DIV_16    0x04
#define ADC_CLOCK_DIV_32    0x05
#define ADC_CLOCK_DIV_64    0x06
#define ADC_CLOCK_DIV_128   0x07


#endif
