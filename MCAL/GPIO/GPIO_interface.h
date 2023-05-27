/*
**************************************
Author          Ahmed Saeid Abdall
Data            5 MAY,2023
Compiler        GNU ARM-GCC
Controller      stm32f401ccu6 (32-bit Architiecture)
layer           MCAL
**************************************
*/



#ifndef MGPIO_INTERFACE_H
#define MGPIO_INTERFACE_H

/* PORT NAME  */

#define MGPIO_PORTA   0
#define MGPIO_PORTB   0
#define MGPIO_PORTC   0
#define MGPIO_PORTD   0

// PIN NUMBER

#define MGPIO_PIN0     0  
#define MGPIO_PIN1     1  
#define MGPIO_PIN2     2  
#define MGPIO_PIN3     3  
#define MGPIO_PIN4     4  
#define MGPIO_PIN5     5  
#define MGPIO_PIN6     6  
#define MGPIO_PIN7     7  
#define MGPIO_PIN8     8  
#define MGPIO_PIN9     9  
#define MGPIO_PIN10    10 
#define MGPIO_PIN11    11 
#define MGPIO_PIN12    12 
#define MGPIO_PIN13    13 
#define MGPIO_PIN14    14 
#define MGPIO_PIN15    15 

#define INPUT                        0
#define OUTPUT                       1
#define MGPIO_AF                     2
#define ANALOG                       3


// MACRO FOR PIN OUTPUT
#define MGPIO_OUTPUT_OD                  0
#define MGPIO_OUTPUT_PP                  1
//OUTPUT SPEED      
#define MGPIO_LOW_SPEED                  0
#define MGPIO_MEDIUM_SPEED               1
#define MGPIO_HIGH_SPEED                 2
#define MGPIO_VERY_HIGH_SPEED            3

// PULL UP AND PULL DOWN RESISTOER

#define MGPIO_FLOAT                     0
#define MGPIO_PULLUP                    1
#define MGPIO_PULLDOWN                  2


//OUTPUT PIN STATE 
#define MGPIO_OUTPUT_LOW                 0
#define MGPIO_OUTPUT_HIGH                1

/********************************** API PROTOTYPES *****************************************/
 
// pointer to object.
 void MGPIO_voidConfiguerPin(MGPIO_pin_t * GPIO_pin);

 
 /*
 copy_u8portname  : Chose from GPIO_PORTA...
 copy_u8pinnumber : Chose from MGPIO_PIN0...
 copy_u8pinmode   : Chose from OUTPUT,INPUT,AF,ANALOG
 */

void MGPIO_voidSetPinMode(u8 copy_u8portname,u8 copy_u8pinnumber, u8 copy_u8pinmode);
 /*
 copy_u8portname  : Chose from GPIO_PORTA...
 copy_u8pinnumber : Chose from MGPIO_PIN0...
 copy_u8pinmode   : Chose from MGPIOOUTPUT_OD,MGPIOOUTPUT_PP.
 */
void MGPIO_voidPinOutputType(u8 copy_u8portname,u8 copy_u8pinnumber, u8 copy_u8pinmode);

/*
            copy_u8portname  : Chose from GPIO_PORTA,...
            copy_u8pinnumber : Chose from MGPIO_PIN0,...
 *          copy_u8pinspeed  : Chose from Speed MGPIO_LOW_SPEED,....
*/

void MGPIO_voidSetPinSpeed(u8 copy_u8portname,u8 copy_u8pinnumber,u8 copy_u8pinspeed);

/*
       
    copy_u8portname         : Chose from GPIO_PORTA,...
    copy_u8pinnumber        : Chose from MGPIO_PIN0,...
    copy_u8pullupdownstate  : MGPIO_FLOAT,.....
*/

void MGPIO_voidSetPinPullUpDown(u8 copy_u8portname,u8 copy_u8pinnumber,u8 copy_u8pullupdownstate);

/*
    copy_u8portname         : Chose from GPIO_PORTA,...
    copy_u8pinnumber        : Chose from MGPIO_PIN0,...

*/
void MGPIO_voidSetPinValue(u8 copy_u8portname, u8 copy_u8pinnumber,u8 copy_u8pinvalue);

/*
        copy_u8portname         : Chose from GPIO_PORTA,...
        Copy_u32PortModeValue   : mode value to be set for a port ,value in range 0:6553 

*/
void MGPIO_voidSetPortSpecificMode(u8 copy_u8portname,u32 Copy_u32PortModeValue );


/*
copy_u8portname         : Chose from GPIO_PORTA,...
Copy_u32PortModeValue   : output value to be set for a port ,value in range 0:6553 

*/
void MGPIO_voidSetPortSpecificValue(u8 copy_u8portname,u32 Copy_u32PortValue );




u8 MGPIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber);


#endif








