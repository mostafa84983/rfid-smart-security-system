#include "EX_INT_interface.h"
#include "EX_INT_private.h"

#include "../../../include/bitmanip.h"

void EXTINT_VidInit(u8 source, u8 sense){
    if (INT0 == source){
        switch(sense){
            case LOW_LEVEL:
                CLR_BIT(MCUCR,MCUCR_ISC00);
                CLR_BIT(MCUCR,MCUCR_ISC01);
                break;
            case LOGICAL_CHANGE:
                SET_BIT(MCUCR,MCUCR_ISC00);
                CLR_BIT(MCUCR,MCUCR_ISC01);
                break;
            case FALLING_EDGE:
                CLR_BIT(MCUCR,MCUCR_ISC00);
                SET_BIT(MCUCR,MCUCR_ISC01);
                break;
            case RISING_EDGE:
                SET_BIT(MCUCR,MCUCR_ISC00);
                SET_BIT(MCUCR,MCUCR_ISC01);
                break;
            default: //FALLING EDGE
                CLR_BIT(MCUCR,MCUCR_ISC00);
                SET_BIT(MCUCR,MCUCR_ISC01);
                break;
        }
        SET_BIT(GICR,GICR_INT0);
    }
    else if (INT1 == source){
        switch(sense){
            case LOW_LEVEL:
                CLR_BIT(MCUCR,MCUCR_ISC10);
                CLR_BIT(MCUCR,MCUCR_ISC11);
                break;
            case LOGICAL_CHANGE:
                SET_BIT(MCUCR,MCUCR_ISC10);
                CLR_BIT(MCUCR,MCUCR_ISC11);
                break;
            case FALLING_EDGE:
                CLR_BIT(MCUCR,MCUCR_ISC10);
                SET_BIT(MCUCR,MCUCR_ISC11);
                break;
            case RISING_EDGE:
                SET_BIT(MCUCR,MCUCR_ISC10);
                SET_BIT(MCUCR,MCUCR_ISC11);
                break;
            default: //FALLING EDGE
                CLR_BIT(MCUCR,MCUCR_ISC10);
                SET_BIT(MCUCR,MCUCR_ISC11);
                break;
        }
        SET_BIT(GICR,GICR_INT1);
    }
    else if (INT2 == source){
        CLR_BIT(GICR,GICR_INT2); //AVOID UNWANTED INTERRUPT
        switch (sense){
        case FALLING_EDGE:
            CLR_BIT(MCUCSR,MCUCSR_ISC2);
            break;
        case RISING_EDGE:
            SET_BIT(MCUCSR,MCUCSR_ISC2);
            break;
        default://FALLING EDGE
            CLR_BIT(MCUCSR,MCUCSR_ISC2);
            break;
        }
        SET_BIT(GIFR,GIFR_INTF2); //AVOID UNWANTED INTERRUPT
        SET_BIT(GICR,GICR_INT2);
    }
}