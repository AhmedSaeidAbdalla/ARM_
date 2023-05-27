/**********************************************************
 * Author:             Ahmed Seaid Abdalla
 * Creation Data:      14 May, 2023
 * Version:              v1.0
 * Compiler:           ARM GNU GCC
 * processor            STM32F401CCU6 (32-BIT Architeture)
 **********************************************************/
/*********************************************************/


 /*  */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "LEDMATRIX_interface.h"
#include "LEDMATRIX_configer.h"
#include "LEDMATRIX_private.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/SYS/SYSTICK_interface.h"


void HLEDMAT_VoidInit(void)
{

// INITATE ROWS AND COKUMES PINS TO BE OUTPUT PINS 

MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT,HLEDMAT_R0_PIN,OUTPUT);
MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT,HLEDMAT_R1_PIN,OUTPUT);
MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT,HLEDMAT_R2_PIN,OUTPUT);
MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT,HLEDMAT_R3_PIN,OUTPUT);
MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT,HLEDMAT_R4_PIN,OUTPUT);
MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT,HLEDMAT_R5_PIN,OUTPUT);
MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT,HLEDMAT_R6_PIN,OUTPUT);
MGPIO_voidSetPinMode(HLEDMAT_ROWS_PORT,HLEDMAT_R7_PIN,OUTPUT);

// initate coulume pins to be output pins
MGPIO_voidSetPinMode(HLED_COLUMES_PORT,HLEDMAT_R0_PIN,OUTPUT);
MGPIO_voidSetPinMode(HLED_COLUMES_PORT,HLEDMAT_R1_PIN,OUTPUT);
MGPIO_voidSetPinMode(HLED_COLUMES_PORT,HLEDMAT_R2_PIN,OUTPUT);
MGPIO_voidSetPinMode(HLED_COLUMES_PORT,HLEDMAT_R3_PIN,OUTPUT);
MGPIO_voidSetPinMode(HLED_COLUMES_PORT,HLEDMAT_R4_PIN,OUTPUT);
MGPIO_voidSetPinMode(HLED_COLUMES_PORT,HLEDMAT_R5_PIN,OUTPUT);
MGPIO_voidSetPinMode(HLED_COLUMES_PORT,HLEDMAT_R6_PIN,OUTPUT);
MGPIO_voidSetPinMode(HLED_COLUMES_PORT,HLEDMAT_R7_PIN,OUTPUT);
voidDisableAllColume();

}

void HLEDMAT_VoidDisplay(u8 * copy_pu8data)
{

u8 local_u8ColumeIndex = 0;
u8 local_u8RowIndex = 0;
u8 local_u8bit=0;
u8 RowArry[8] = {

HLEDMAT_R0_PIN,
HLEDMAT_R1_PIN,
HLEDMAT_R2_PIN,
HLEDMAT_R3_PIN,
HLEDMAT_R4_PIN,
HLEDMAT_R5_PIN,
HLEDMAT_R6_PIN,
HLEDMAT_R7_PIN

};
u8 columeArry[8] = {

HLEDMAT_C0_PIN,
HLEDMAT_C1_PIN,
HLEDMAT_C2_PIN,
HLEDMAT_C3_PIN,
HLEDMAT_C4_PIN,
HLEDMAT_C5_PIN,
HLEDMAT_C6_PIN,
HLEDMAT_C7_PIN

};

for(local_u8ColumeIndex =0;local_u8ColumeIndex < 8 ;local_u8ColumeIndex++)
{
    voidDisableAllColume();
    for(local_u8RowIndex =0;local_u8RowIndex < 8 ;local_u8RowIndex++)
    {
        local_u8bit =GET_BIT(copy_pu8data [local_u8ColumeIndex],local_u8RowIndex)
        MGPIO_voidSetPinValue(HLEDMAT_ROWS_PORT,RowArry[local_u8RowIndex],local_u8bit);
    }
    MGPIO_voidSetPinValue(HLED_COLUMES_PORT,columeArry[local_u8ColumeIndex],MGPIO_OUTPUT_LOW);
    Systick_voidBusyWait(2500);

}

}

static void voidDisableAllColume(void)
{

    MGPIO_voidSetPinValue(HLEDMAT_C0_PIN,MGPIO_OUTPUT_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_C1_PIN,MGPIO_OUTPUT_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_C2_PIN,MGPIO_OUTPUT_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_C3_PIN,MGPIO_OUTPUT_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_C4_PIN,MGPIO_OUTPUT_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_C5_PIN,MGPIO_OUTPUT_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_C6_PIN,MGPIO_OUTPUT_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_C7_PIN,MGPIO_OUTPUT_HIGH);

}

