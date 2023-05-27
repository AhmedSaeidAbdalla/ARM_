/**********************************************************
 * Author:             Ahmed Seaid Abdalla
 * Creation Data:      1 May, 2023
 * Version:              v1.0
 * Compiler:           GNU GCC
 **********************************************************/
/**********************************************************
***********************************************************/



#ifndef 	RCC_PRIVATE_H
#define 	RCC_PRIVATE_H


 
 typedef strcut
 {
    volatile u32 CR;
    volatile u32 PLLCFGR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 AHB1RSTR;
    volatile u32 AHB2RSTR;
    volatile u32 Reserved1[2];
    volatile u32 APB1RSTR;
    volatile u32 APB2RSTR;
    volatile u32 Reserved2[2];
    volatile u32 AHB1ENR;
    volatile u32 AHB2ENR;
    volatile u32 Reserved3[2];
    volatile u32 APB1ENR;
    volatile u32 APB2ENR;
    volatile u32 Reserved4[2];
    volatile u32 AHB1LPENR;
    volatile u32 AHB2LPENR;
    volatile u32 Reserved5[2];
    volatile u32 APB1LPENR;
    volatile u32 APB2LPENR;
    volatile u32 Reserved6[2];
    volatile u32 BDCR;
    volatile u32 CSR;
    volatile u32 Reserved7[2];
    volatile u32 SSCGR;
    volatile u32 PLLI2SCFGR;
    volatile u32 Reserved8;
    volatile u32 DCKCFGR;
    
 }RCC_T;
  

#define RCC     (volatile RCC_T * ) 0x40023800



#define   RCC_BASE_ADDRESS  0x40023800
#define   RCC_CR    *((volatile u32 *)RCC_BASE_ADDRESS 0x00)


         //PRE SCALLER FOR APB1 AND APB2
#define APB1_2_DIVID_BY_2             0
#define APB1_2_DIVID_BY_4             1
#define APB1_2_DIVID_BY_8             2

         //PERSCALLER FOR AHB
         /* SUSCLOCK OPTIONS : HSI - HSE - PLL */
#define SYSCLOCK_DIVID_BY_1            
#define SYSCLOCK_DIVID_BY_2           8
#define SYSCLOCK_DIVID_BY_4           9
#define SYSCLOCK_DIVID_BY_8           10
#define SYSCLOCK_DIVID_BY_16          11

#endif