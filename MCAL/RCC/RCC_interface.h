/**********************************************************
 * Author:             Ahmed Seaid Abdalla
 * Creation Data:      1 May, 2023
 * Version:              v1.0
 * Compiler:           GNU GCC
 **********************************************************/
/**********************************************************
***********************************************************/




#ifndef 	RCC_INTERFACE_H
#define 	RCC_INTERFACE_H

void MRCC_voidInit(void);
void MRCC_voidEnablePeriphrealClock(u8 copy_u8peripheralBus ,u8 copy_u8peripheralID);
void MRCC_voidDisblePeriphrealClock(u8 copy_u8peripheralBus ,u8 copy_u8peripheralID);


#endif