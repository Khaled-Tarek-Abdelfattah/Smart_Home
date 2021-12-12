/*
 * eeprom.c
 *
 * Created: 12/11/2021 7:24:35 PM
 *  Author: hp
 */ 

#include "ATMEGA32A_Config.h"
#include "eeprom.h"
#include "Macros.h"


void eeprom_writeByte(uint16 u16Address, uint8 u8Data)
{
	// wait for completion for previous write
	while (*EEPROM_CTRL_REG & (1 << 1));       // EEWE (EEPROM Write Enable)
	
	// put address in address register
	*EEPROM_ADDRESS_REG_HIGH_BYTE = u16Address >> 8;
	*EEPROM_ADDRESS_REG_LOW_BYTE = u16Address;
	
	// put data in data register
	*EEPROM_DATA_REG = u8Data;
	
	// Preparing write operation by setting logical one to EEMWE bit (EEPROM Master Write Enable)
	SET_BIT(*EEPROM_CTRL_REG, 2);
	
	// starting write operation
	SET_BIT(*EEPROM_CTRL_REG, 1);   
}


uint8 eeprom_readByte(uint16 u16Address)
{
	// Wait for completion of previous write
	while(*EEPROM_CTRL_REG & (1 << 1));      // EEWE bit ( EEPROM Write Enable)
	
	
	/*
	   Store Program Memory Control Register (SPMCR) :
	   The Store Program Memory Control Register contains the control bits needed to control the Boot
	   Loader operations
	*/
	while(*STORE_PROGRAM_MEM_CTRL_REG & (1 << 1));        // SPMEN bit (Store Programming Memory Enable)
	
	// Put address of data to be read in register
	*EEPROM_ADDRESS_REG_HIGH_BYTE = u16Address >> 8;
	*EEPROM_ADDRESS_REG_LOW_BYTE = u16Address;
	
	// Start EEPROM read by writing EEMWE
	SET_BIT(*EEPROM_CTRL_REG, 0);                 // EERE (EEPROM Read Enable bit (bit 0))
	
	// Return data from  data register
	return *EEPROM_DATA_REG;
}
