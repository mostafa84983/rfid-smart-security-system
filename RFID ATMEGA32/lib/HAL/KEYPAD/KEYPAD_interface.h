#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "KEYPAD_config.h"
#include "../../../include/std_types.h"

void KEYPAD_VidInitMatrixMode(void);
void KEYPAD_VidInitDirectMode(void);
void WaitForKey(u8 *PtrKeyPressed);
u8 KEYPAD_u8CheckPress(void);

#endif
