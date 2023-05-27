/**********************************************************
 * Author:             Ahmed Seaid Abdalla
 * Creation Data:      6 May, 2023
 * Version:              v1.0
 * Compiler:           ARM GNU
 **********************************************************/
/**********************************************************
***********************************************************/

#ifndef  SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H


#define STK_CTRL     0
#define STK_LOAD     1
#define STK_VAL      2
#define STK_CALIB    3

#define PIN0         0
#define PIN1         1
#define PIN2         2
#define PIN3         3
#define PIN4         4
#define PIN5         5
#define PIN6         6
#define PIN7         7
#define PIN8         8
#define PIN9         9
#define PIN10       10
#define PIN11       11
#define PIN12       12
#define PIN13       13
#define PIN14       14
#define PIN15       15
#define PIN16       16
#define PIN17       17
#define PIN18       18
#define PIN19       19
#define PIN20       20
#define PIN21       21
#define PIN22       22
#define PIN23       23


#define SYSTICK_INTERIPET 0
#define ENABLE            1
#define DISABLE           2
#define SYSTICK_ENABLE    3


void Systick_voidInitiate(void);
void Systick_voidBusyWait(u32 copy_u32TimeWait);
//void Systick_voidInernalSignal(void);            // Enable Interupet PIE
void Systick_voidInernalPeriodic(void);          // Enabled Interupte PIE
u32 Systick_u32GetElapsed();
u32 Systick_u32GetRemingTime();
/*void Systick_voidInernalSignal(u32 Copy_PreloadValue);*/


#endif