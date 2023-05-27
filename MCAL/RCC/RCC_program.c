/**********************************************************
 * Author:             Ahmed Seaid Abdalla
 * Creation Data:      1 May, 2023
 * Version:              v1.0
 * Compiler:           GNU GCC
 **********************************************************/
/**********************************************************
***********************************************************/



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_config.h"
#include "RCC_private.h"





void MRCC_voidInit(void)
{
 #if     CPU_CLK_SOURCE == HSI
        SET_BIT((RCC->CR), 0);
        CLR_BIT((RCC->CFGR), 0);
        CLR_BIT((RCC->CFGR), 1);
    #elif   CPU_CLK_SOURCE == HSE
        SET_BIT((RCC->CR), 16);
        SET_BIT((RCC->CFGR), 0);
        CLR_BIT((RCC->CFGR), 1);
    #elif   CPU_CLK_SOURCE == PPL
        #if PPL_SOURCE == HSI
            SET_BIT((RCC->CR), 0);
        #elif   PPL_SOURCE == HSE
            SET_BIT((RCC->CR), 16);
        #else
            #error "RCC PPL_SOURCE Configuration Error"
        #endif
    #else
        #error "RCC CPU_CLK_SOURCE Configuration Error"
    #endif

    #if AHB_PRESCALLER == SYSCLOCK_DIVID_BY_2
    RCC -> CFGR &=0xFFFFFF0F;
    RCC -> CFGR |= (AHB_PRESCALLER <<4);
}



/* TO ENABLE AND DISABEL THE CLOCK*/

void MRCC_voidEnablePeriphrealClock(u8 copy_u8peripheralBus ,u8 copy_u8peripheralID)
{
 switch (copy_u8peripheralBus)
    {
        case RCC_AHP1:
            SET_BIT((RCC->AHB1ENR), Copy_u8PeripheralID);
        break;
        case RCC_AHP2:
            SET_BIT((RCC->AHB2ENR), Copy_u8PeripheralID);
        break;
        case RCC_APB1:
            SET_BIT((RCC->APB1ENR), Copy_u8PeripheralID);
        break;
        case RCC_APB2:
            SET_BIT((RCC->APB2ENR), Copy_u8PeripheralID);
        break;
        default:

        break;
    }
}
void MRCC_voidDisblePeriphrealClock(u8 copy_u8peripheralBus ,u8 copy_u8peripheralID)

{
switch (copy_u8peripheralBus)
    {
        case RCC_AHP1:
            CLR_BIT((RCC->AHB1ENR), Copy_u8PeripheralID);
        break;
        case RCC_AHP2:
            CLR_BIT((RCC->AHB2ENR), Copy_u8PeripheralID);
        break;
        case RCC_APB1:
            CLR_BIT((RCC->APB1ENR), Copy_u8PeripheralID);
        break;
        case RCC_APB2:
            CLR_BIT((RCC->APB2ENR), Copy_u8PeripheralID);
        break;
        default:
        break;
    }
}

