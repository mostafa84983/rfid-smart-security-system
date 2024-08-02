#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_

#include "GIE_config.h"

void GIE_VidEnable(void);
void GIE_VidDisnable(void);

// GENERIC VECTOR DEFINITION
#ifndef _VECTOR
#define _VECTOR(N) __vector_ ## N
#endif

// ISR DEFINITION (PULLED FROM <avr/interrupts.h>)
#define __INTR_ATTRS used, externally_visible
#define ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)
    
#endif