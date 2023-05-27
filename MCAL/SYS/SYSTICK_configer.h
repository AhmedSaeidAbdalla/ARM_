/**********************************************************
 * Author:             Ahmed Seaid Abdalla
 * Creation Data:      6 May, 2023
 * Version:              v1.0
 * Compiler:           ARM GNU
 **********************************************************/
/**********************************************************
***********************************************************/

#ifdef  SYSTICK_CONFIGER_H
#define SYSTICK_CONFIGER_H


/*Option AHB - AHB_BY_8*/      // AHB the processor clock

#define  CLKSOURCE    AHB_BY_8


/*OPTIONS  ENABLE - DISABLE */

#define SYSTICK_INTERIPET     ENABLE 
#define SYSTICK_ENABLE        ENABLE


#endif