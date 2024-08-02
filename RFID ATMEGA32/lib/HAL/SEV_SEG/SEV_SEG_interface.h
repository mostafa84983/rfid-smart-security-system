#ifndef SEV_SEG_INTERFACE
#define SEV_SEG_INTERFACE

#include "SEV_SEG_config.h"

#include "../../../include/std_types.h"

void SEV_SEG_VidInit();
void SEV_SEG_VidDisplayNumber(u8 Local_u8Number, et_Status SEG_Activator);
void SEV_SEG_VidDisplayOnes(u8 Local_u8Ones);
void SEV_SEG_VidDisplayTens(u8 Local_u8Tens);
void SEV_SEG_VidSpinner();

#endif