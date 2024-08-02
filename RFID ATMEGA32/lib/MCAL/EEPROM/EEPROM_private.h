#ifndef EEPROM_PRIVATE_H_
#define EEPROM_PRIVATE_H_

#include "../../../include/std_types.h"

//Addresses of registers
#define EEPROM_EECR *((volatile u8*)0x3C)
#define EEPROM_EEDR *((volatile u8*)0x3D)
#define EEPROM_EEARH *((volatile u8*)0x3F)
#define EEPROM_EEARL *((volatile u8*)0x3E)

#endif
