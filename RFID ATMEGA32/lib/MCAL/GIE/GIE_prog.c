#include "GIE_interface.h"
#include "GIE_private.h"

#include "../../../include/bitmanip.h"

// GLOBAL INTERRUPT ENABLE
void GIE_VidEnable(void){
    SET_BIT(SREG,SREG_I);
}

// GLOBAL INTERRUPT DISABLE
void GIE_VidDisnable(void){
    CLR_BIT(SREG,SREG_I);
}