#include "EEPROM.h"
#include "EEPROM_private.h"
#include "../../../include/bitmanip.h"
#include "util/delay.h"

// void EEPROM_VidWrite(u16 address,u8 data)
// {
// 	//set up EEPROM address
// 	EEPROM_EEARL=(u8)address;
// 	EEPROM_EEARH=(u8)(address>>8);  //address is 10 bit
// 	//set up data register
// 	EEPROM_EEDR=data;
// 	//enable write operation
// 	SET_BIT(EEPROM_EECR,EEMWE);
// 	CLR_BIT(EEPROM_EECR,EEWE);
// 	//while(GET_BIT(EEPROM_EECR,EEMWE)==0); //hardware clear EEWE automatically
// 	_delay_ms(5);
// 	SET_BIT(EEPROM_EECR,EEWE);
// 	_delay_ms(9);
// }

// u8 EEPROM_U8Read(u16 address)
// {
// 	//set up EEPROM address
// 	EEPROM_EEARL=(u8)address;
// 	EEPROM_EEARH=(u8)(address>>8);  //address is 10 bit
// 	//enable read operation
// 	SET_BIT(EEPROM_EECR,EERE);
// 	return EEPROM_EEDR;
// }

// void EEPROM_WriteBlock(u16 u16addr, u8*u8data, u8 const size)
// {
// 	for(u8 i = 0; i < size; i++)
// 	{
// 		EEPROM_VidWrite(u16addr + i, u8data[i]);
// 		_delay_ms(10);
// 	}
// }


// EEPROM Functions
void EEPROM_VidWrite(u16 address,u8 data)
{
    // Wait for completion of previous write
    while (GET_BIT(EEPROM_EECR, EEWE));
    
    // Set up address and Data Registers
    EEPROM_EEARL = (u8)address;
    EEPROM_EEARH = (u8)(address >> 8);
    EEPROM_EEDR = data;
    
    // Write logical one to EEMWE
    SET_BIT(EEPROM_EECR, EEMWE);
    // Start EEPROM write by setting EEWE
    SET_BIT(EEPROM_EECR, EEWE);
}

u8 EEPROM_U8Read(u16 address)
{
    // Wait for completion of previous write
    while (GET_BIT(EEPROM_EECR, EEWE));
    
    // Set up address register
    EEPROM_EEARL = (u8)address;
    EEPROM_EEARH = (u8)(address >> 8);
    
    // Start EEPROM read by writing EERE
    SET_BIT(EEPROM_EECR, EERE);
    
    // Return data from Data Register
    return EEPROM_EEDR;
}

void EEPROM_WriteBlock(u16 u16addr, u8* u8data, u8 size)
{
    for(u8 i = 0; i < size; i++)
    {
        EEPROM_VidWrite(u16addr + i, u8data[i]);
    }
}