/**********************************************************
 * Author:             Ahmed Seaid Abdalla
 * Creation Data:      21 May, 2023
 * Version:              v1.0
 * Compiler:           ARM GNU GCC
 * processor            STM32F401CCU6 (32-BIT Architeture)
 **********************************************************/
/*********************************************************/

#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_configer.h"




void MNVIC_voidInit(void)
{
    /* set the groub and sub priorites distrubtion */
    SCB_AIRCR |=(AIRCR_PRIVKEY << 16) | (MNVIC_GPR_SUB_DISTRUBTION << 8);

}

void MNVIC_voidEnablePreipheralInterrupt( u8 copy_u8peripheralID)
{
  u8 Local_u8ISRIndex;
  Local_u8ISRIndex = copy_u8peripheralID /32;
  MNVIC ->ISER[Local_u8ISRIndex] =(1 << (copy_u8peripheralID % 32));
}
void MNVIC_voidDisablePreipheralInterrupt( u8 copy_u8peripheralID)
{
    u8 Local_u8ISRIndex;
  Local_u8ISRIndex = copy_u8peripheralID /32;
  MNVIC ->ICER[Local_u8ISRIndex] =(1 << (copy_u8peripheralID % 32));

}
void MNVIC_voidSetPendingFlag(u8 copy_u8peripgheralID)
{
  u8 Local_u8ISRIndex;
  Local_u8ISRIndex = copy_u8peripgheralID /32;
  MNVIC ->ISPR[Local_u8ISRIndex] =(1 << (copy_u8peripgheralID % 32));
}

u8 MNVIC_u8GetSetFlag( u8 copy_u8peripheralID)
{
  u8 Local_u8ISRIndex;
  Local_u8ISRIndex = copy_u8peripheralID /32;
  MNVIC ->ISPR[Local_u8ISRIndex] =(1 << (copy_u8peripheralID % 32));
}

u8 MNVIC_u8GetClearFlag( u8 copy_u8peripheralID)
{

}

