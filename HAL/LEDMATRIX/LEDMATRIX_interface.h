/**********************************************************
 * Author:             Ahmed Seaid Abdalla
 * Creation Data:      14 May, 2023
 * Version:              v1.0
 * Compiler:           ARM GNU GCC
 * processor            STM32F401CCU6 (32-BIT Architeture)
 **********************************************************/
/*********************************************************/

#ifndef LED_MATRIX_INTERFACE_H
#define LED_MATRIX_INTERFACE_H

void HLEDMAT_VoidInit(void);
void HLEDMAT_VoidDisplay(u8 * copy_pu8data);
static void voidDisableAllColume(void);

#endif