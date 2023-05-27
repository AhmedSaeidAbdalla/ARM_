/**********************************************************
 * Author:             Ahmed Seaid Abdalla
 * Creation Data:      21 May, 2023
 * Version:              v1.0
 * Compiler:           ARM GNU GCC
 * processor            STM32F401CCU6 (32-BIT Architeture)
 **********************************************************/
/*********************************************************
 * Version 
*/
/*********************************************************/


#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

typedef struct 
{
    volatile u32 ISER[8];
    volatile u32 Reserved0[24];
    volatile u32 ICER[8];
    volatile u32 Reserved1[24];
    volatile u32 ISPR[8];
    volatile u32 Reserved2[24];
    volatile u32 ICPR[8];
    volatile u32 Reserved3[24];
    volatile u32 IABR[8];
    volatile u32 Reserved4[24];
    volatile u32 IPR[240];
    volatile u32 Reserved0[580];
    volatile u32 STIR;

}NVIC_T;

#define SCB_AIRCR (( volatile u32 *) 0XE000ED0C)

#define MNVIC   *((volatile NVIC_T * )0xE000E100)
#define AIRCR_PRIVKEY  

#define GRP_4_SUB_4_BITS     0b000
#define GRP_3_SUB_3_BITS     0b100
#define GRP_2_SUB_2_BITS     0b101
#define GRP_1_SUB_1_BITS     0b110
#define GRP_0_SUB_4_BITS     0b111



#endif