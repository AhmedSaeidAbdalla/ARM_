/**********************************************************
 * Author:             Ahmed Seaid Abdalla
 * Creation Data:      6 May, 2023
 * Version:              v1.0
 * Compiler:           ARM GNU
 **********************************************************/
/**********************************************************
***********************************************************/


#ifdef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

#define STK_CTRL  ((volatile u32 *)  0xE000E010)  //SysTick control and status register
#define STK_LOAD  ((volatile u32 *)  0xE000E018)  //do not forget the offset.   //LOAD REGISTER 
#define STK_VAL   ((volatile u32 *)  0xE000E030)  //do not forget the offset.   // VALUE REGISTER
#define STK_CALIB ((volatile u32 *)  0xE000E01C)  //do not forget the offset.


#endif
