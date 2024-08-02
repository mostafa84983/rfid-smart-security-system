#ifndef EEPROM_H_
#define EEPROM_H_

#include "../../../include/std_types.h"

//Pins
#define EEMWE 2
#define EEWE  1
#define EERE  0

//Functions
void EEPROM_VidWrite(u16 address,u8 data);
u8 EEPROM_U8Read(u16 address);
void EEPROM_WriteBlock(u16 u16addr, u8*u8data, u8 const size);

#endif
