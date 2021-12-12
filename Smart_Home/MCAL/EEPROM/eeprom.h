/*
 * eeprom.h
 *
 * Created: 12/11/2021 7:24:53 PM
 *  Author: hp
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "Std_Types.h"

void eeprom_writeByte(uint16 u16Address, uint8 u8Data);
uint8 eeprom_readByte(uint16 u16Address);



#endif /* EEPROM_H_ */
