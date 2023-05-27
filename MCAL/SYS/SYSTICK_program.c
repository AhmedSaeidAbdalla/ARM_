    /**********************************************************
 * Author:             Ahmed Seaid Abdalla
 * Creation Data:      6 May, 2023
 * Version:              v1.0
 * Compiler:           ARM GNU
 **********************************************************/
/**********************************************************
***********************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_configer.h"


void Systick_voidInitiate(void)
{

SET_BIT(STK_CTRL,PIN0);        //ENABLE THE CTRL.

/* Chose The Clock Source*/
#if (CLKSOURCE == AHB)

    SET_BIT(STK_CTRL,PIN2);

#elif (CLKSOURCE == AHB_BY_8)

    CLR_BIT(STK_CTRL,PIN2);
#endif

#if SYSTICK_INTERIPET == ENABLE
SET_BIT(STK_CTRL,PIN1);

#elif SYSTICK_INTERIPET == ENABLE
CLR_BIT(STK_CTRL,PIN1);
#endif

#if SYSTICK_ENABLE == ENABLE
SET_BIT(STK_CTRL , PIN0);
#elif SYSTICK_ENABLE == DISABLE
CLR_BIT(STK_CTRL,PIN0);

#endif


}
void Systick_voidBusyWait(u32 copy_u32TimeWait)
{

  STK_LOAD = copy_u32TimeWait;
    u32 RegisterValue = GET_BIT(STK_CTRL,PIN16);
  while (RegisterValue == 0 )
  {
   // do nothing.
  }


}
/*void Systick_voidInernalSignal(u32 Copy_PreloadValue)
{
   //Load Reload Value
	STK_LOAD = Copy_PreloadValue - 1;
	//Clear Val Register
	STK_VAL  = 0 ;
	//Enable Systick
	SET_BIT( STK_CTRL , 0 );
}  */ 
void Systick_voidInernalPeriodic(void)
{

} 
u32 Systick_u32GetElapsed()     // THE TIME THAT DONE
{

u32 LOCAL_U32ElapsedTime;
LOCAL_U32ElapsedTime = STK_LOAD - STK_VAL;
return LOCAL_U32ElapsedTime;

}
u32 Systick_u32GetRemingTime() // the remain time that timer has finshed or not 
{

u32 local_RemaingTime;
local_RemaingTime = STK_VAL;
return local_RemaingTime;

}



/* ISR FOR */

