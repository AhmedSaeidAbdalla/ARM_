/*
**************************************
Author          Ahmed Saeid Abdall
Data            5 MAY,2023
Compiler        GNU ARM-GCC
Controller      stm32f401ccu6 (32-bit Architiecture)
layer           MCAL
**************************************
*/

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_configer.h"

void MGPIO_voidConfiguerPin(MGPIO_pin_t * GPIO_pin)
{
// checking the portname
switch (GPIO_pin -> portname)
{
    case MGPIO_PORTA:
    // CHEACKING FOR PIN MODE
    switch (GPIO_pin -> mode)
    {
    case INPUT:
    // set the pin to be input pin
        GPIOA -> MODER |= (0b00 << (GPIO_pin -> pinnumber * PIN_BITS_OFFSET));
        //cheaking for the pull up and pull down resistoer
        switch (GPIO_pin -> pullupdown)
        {
        case MGPIO_FLOAT:
        // disable the pull up and down resistoer 
            GPIOA -> PUPDR |= (0b00 << (GPIO_pin -> pinnumber * PIN_BITS_OFFSET));
            break;
            case MGPIO_PULLUP:
            // enable the pull up resistoer
            break;
            GPIOA ->PUPDR |= (0b01 << (GPIO_pin ->pinnumber * PIN_BITS_OFFSET));
            break;
            case MGPIO_PULLDOWN :
            //ENABEL THE PULL DOWN RESISTOER 
            GPIOA ->PUPDR |= (0b10 <<(GPIO_pin->pinnumber * PIN_BITS_OFFSET));
            break;

        }
        break;
        case OUTPUT:
        // set the pin to be output pin
        GPIOA -> MODER |= (0b01 << (GPIO_pin ->pinnumber * PIN_BITS_OFFSET));
        // cheaking for the output type 
        switch (GPIO_pin -> outouttype)
        {
        case MGPIO_OUTPUT_OD:
            // ser the pin output type to be open drain pin
            SET_BIT(GPIOA ->OTYPER,GPIO_pin->pinnumber);
            break;
            case MGPIO_OUTPUT_PP:
        // ser the pin output type to be pushpull pin
        CLR_BIT(GPIOA ->OTYPER,GPIO_pin->pinnumber);
        break;

    }
           switch (GPIO_Pin->OutputSpeed)
            {
            case MGPIO_LOW_SPEED:
                //Set the speed of the pin to low speed
                GPIOA->OSPEEDR |= (0b00 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_MEDIUM_SPEED:
                //Set the speed of the pin to medium speed
                GPIOA->OSPEEDR |= (0b01 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_HIGH_SPEED:
                //Set the speed of the pin to high speed
                GPIOA->OSPEEDR |= (0b10 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_VHIGH_SPEED:
                //Set the speed of the pin to very high speed
                GPIOA->OSPEEDR |= (0b11 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
    }

            //Check For The Pin Initial Value
            switch (GPIO_Pin->InitialState)
            {
            case MGPIO_OUTPUT_LOW:
                //Set Pin Low, Atomic Reset
                GPIOA->BSRR = 1 << (GPIO_Pin->PinNumber + BSRR_PIN_OFFSET);
                break;
            case MGPIO_OUTPUT_HIGH:
                //Set Pin High, Atomic Set
                GPIOA->BSRR = 1 << (GPIO_Pin->PinNumber);
                break;
            }
            break;
        case MGPIO_AF:
            //Set The Pin To Be Alternative Function Pin
            GPIOA->MODER |= (0b10 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_ANALOG:
            //Set The Pin To Be Analog Pin
            GPIOA->MODER |= (0b11 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;

         case MGPIO_PORTB:
         // CHEACKING FOR PIN MODE
        switch (GPIO_pin -> mode)
             {
         case INPUT:
         // set the pin to be input pin
        GPIOB -> MODER |= (0b00 << (GPIO_pin -> pinnumber * PIN_BITS_OFFSET));
        //cheaking for the pull up and pull down resistoer
        switch (GPIO_pin -> pullupdown)
        {
        case MGPIO_FLOAT:
        // disable the pull up and down resistoer 
            GPIOB -> PUPDR |= (0b00 << (GPIO_pin -> pinnumber * PIN_BITS_OFFSET));
            break;
            case MGPIO_PULLUP:
            // enable the pull up resistoer
            break;
            GPIOB ->PUPDR |= (0b01 << (GPIO_pin ->pinnumber * PIN_BITS_OFFSET));
            break;
            case MGPIO_PULLDOWN :
            //ENABEL THE PULL DOWN RESISTOER 
            GPIOB ->PUPDR |= (0b10 <<(GPIO_pin->pinnumber * PIN_BITS_OFFSET));
            break;

        }
        break;
         case OUTPUT:
             // set the pin to be output pin
             GPIOB -> MODER |= (0b01 << (GPIO_pin ->pinnumber * PIN_BITS_OFFSET));
            // cheaking for the output type 
         switch (GPIO_pin -> outouttype)
         {
             case MGPIO_OUTPUT_OD:
            // ser the pin output type to be open drain pin
            SET_BIT(GPIOB ->OTYPER,GPIO_pin->pinnumber);
            break;
            case MGPIO_OUTPUT_PP:
            // ser the pin output type to be pushpull pin
            CLR_BIT(GPIOB ->OTYPER,GPIO_pin->pinnumber);
                break;

    }
             switch (GPIO_Pin->OutputSpeed)
            {
            case MGPIO_LOW_SPEED:
                //Set the speed of the pin to low speed
                GPIOB->OSPEEDR |= (0b00 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_MEDIUM_SPEED:
                //Set the speed of the pin to medium speed
                GPIOB->OSPEEDR |= (0b01 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_HIGH_SPEED:
                //Set the speed of the pin to high speed
                GPIOB->OSPEEDR |= (0b10 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_VHIGH_SPEED:
                //Set the speed of the pin to very high speed
                GPIOB->OSPEEDR |= (0b11 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
    }

            //Check For The Pin Initial Value
            switch (GPIO_Pin->InitialState)
            {
            case MGPIO_OUTPUT_LOW:
                //Set Pin Low, Atomic Reset
                GPIOB->BSRR = 1 << (GPIO_Pin->PinNumber + BSRR_PIN_OFFSET);
                break;
            case MGPIO_OUTPUT_HIGH:
                //Set Pin High, Atomic Set
                GPIOB->BSRR = 1 << (GPIO_Pin->PinNumber);
                break;
            }
            break;
        case MGPIO_AF:
            //Set The Pin To Be Alternative Function Pin
            GPIOB->MODER |= (0b10 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_ANALOG:
            //Set The Pin To Be Analog Pin
            GPIOB->MODER |= (0b11 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;
        case MGPIO_PORTC:
        // CHEACKING FOR PIN MODE
        switch (GPIO_pin -> mode)
             {
         case INPUT:
         // set the pin to be input pin
        GPIOC -> MODER |= (0b00 << (GPIO_pin -> pinnumber * PIN_BITS_OFFSET));
        //cheaking for the pull up and pull down resistoer
        switch (GPIO_pin -> pullupdown)
        {
        case MGPIO_FLOAT:
        // disable the pull up and down resistoer 
            GPIOC -> PUPDR |= (0b00 << (GPIO_pin -> pinnumber * PIN_BITS_OFFSET));
            break;
            case MGPIO_PULLUP:
            // enable the pull up resistoer
            break;
            GPIOC ->PUPDR |= (0b01 << (GPIO_pin ->pinnumber * PIN_BITS_OFFSET));
            break;
            case MGPIO_PULLDOWN :
            //ENABEL THE PULL DOWN RESISTOER 
            GPIOC ->PUPDR |= (0b10 <<(GPIO_pin->pinnumber * PIN_BITS_OFFSET));
            break;

        }
        break;
         case OUTPUT:
             // set the pin to be output pin
             GPIOC -> MODER |= (0b01 << (GPIO_pin ->pinnumber * PIN_BITS_OFFSET));
            // cheaking for the output type 
         switch (GPIO_pin -> outouttype)
         {
             case MGPIO_OUTPUT_OD:
            // ser the pin output type to be open drain pin
            SET_BIT(GPIOC ->OTYPER,GPIO_pin->pinnumber);
            break;
            case MGPIO_OUTPUT_PP:
            // ser the pin output type to be pushpull pin
            CLR_BIT(GPIOC ->OTYPER,GPIO_pin->pinnumber);
                break;

    }
             switch (GPIO_Pin->OutputSpeed)
            {
            case MGPIO_LOW_SPEED:
                //Set the speed of the pin to low speed
                GPIOC->OSPEEDR |= (0b00 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_MEDIUM_SPEED:
                //Set the speed of the pin to medium speed
                GPIOC->OSPEEDR |= (0b01 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_HIGH_SPEED:
                //Set the speed of the pin to high speed
                GPIOC->OSPEEDR |= (0b10 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_VHIGH_SPEED:
                //Set the speed of the pin to very high speed
                GPIOC->OSPEEDR |= (0b11 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
    }

            //Check For The Pin Initial Value
            switch (GPIO_Pin->InitialState)
            {
            case MGPIO_OUTPUT_LOW:
                //Set Pin Low, Atomic Reset
                GPIOC->BSRR = 1 << (GPIO_Pin->PinNumber + BSRR_PIN_OFFSET);
                break;
            case MGPIO_OUTPUT_HIGH:
                //Set Pin High, Atomic Set
                GPIOC->BSRR = 1 << (GPIO_Pin->PinNumber);
                break;
            }
            break;
        case MGPIO_AF:
            //Set The Pin To Be Alternative Function Pin
            GPIOC->MODER |= (0b10 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_ANALOG:
            //Set The Pin To Be Analog Pin
            GPIOC->MODER |= (0b11 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;
        case MGPIO_PORTD:
         // CHEACKING FOR PIN MODE
        switch (GPIO_pin -> mode)
             {
         case INPUT:
         // set the pin to be input pin
        GPIOD -> MODER |= (0b00 << (GPIO_pin -> pinnumber * PIN_BITS_OFFSET));
        //cheaking for the pull up and pull down resistoer
        switch (GPIO_pin -> pullupdown)
        {
        case MGPIO_FLOAT:
        // disable the pull up and down resistoer 
            GPIOD -> PUPDR |= (0b00 << (GPIO_pin -> pinnumber * PIN_BITS_OFFSET));
            break;
            case MGPIO_PULLUP:
            // enable the pull up resistoer
            break;
            GPIOD ->PUPDR |= (0b01 << (GPIO_pin ->pinnumber * PIN_BITS_OFFSET));
            break;
            case MGPIO_PULLDOWN :
            //ENABEL THE PULL DOWN RESISTOER 
            GPIOD ->PUPDR |= (0b10 <<(GPIO_pin->pinnumber * PIN_BITS_OFFSET));
            break;

        }
        break;
         case OUTPUT:
             // set the pin to be output pin
             GPIOD -> MODER |= (0b01 << (GPIO_pin ->pinnumber * PIN_BITS_OFFSET));
            // cheaking for the output type 
         switch (GPIO_pin -> outouttype)
         {
             case MGPIO_OUTPUT_OD:
            // ser the pin output type to be open drain pin
            SET_BIT(GPIOD ->OTYPER,GPIO_pin->pinnumber);
            break;
            case MGPIO_OUTPUT_PP:
            // ser the pin output type to be pushpull pin
            CLR_BIT(GPIOD ->OTYPER,GPIO_pin->pinnumber);
                break;

    }
             switch (GPIO_Pin->OutputSpeed)
            {
            case MGPIO_LOW_SPEED:
                //Set the speed of the pin to low speed
                GPIOD->OSPEEDR |= (0b00 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_MEDIUM_SPEED:
                //Set the speed of the pin to medium speed
                GPIOD->OSPEEDR |= (0b01 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_HIGH_SPEED:
                //Set the speed of the pin to high speed
                GPIOD->OSPEEDR |= (0b10 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
            case MGPIO_VHIGH_SPEED:
                //Set the speed of the pin to very high speed
                GPIOD->OSPEEDR |= (0b11 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
                break;
    }

            //Check For The Pin Initial Value
            switch (GPIO_Pin->InitialState)
            {
            case MGPIO_OUTPUT_LOW:
                //Set Pin Low, Atomic Reset
                GPIOD->BSRR = 1 << (GPIO_Pin->PinNumber + BSRR_PIN_OFFSET);
                break;
            case MGPIO_OUTPUT_HIGH:
                //Set Pin High, Atomic Set
                GPIOD->BSRR = 1 << (GPIO_Pin->PinNumber);
                break;
            }
            break;
        case MGPIO_AF:
            //Set The Pin To Be Alternative Function Pin
            GPIOD->MODER |= (0b10 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_ANALOG:
            //Set The Pin To Be Analog Pin
            GPIOD->MODER |= (0b11 << (GPIO_Pin->PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;


 } 


}

void MGPIO_voidSetPinMode(u8 copy_u8portname,u8 copy_u8pinnumber, u8 copy_u8pinmode)
{

   //Checking The PortName
    switch (Copy_u8PortName)
    {
    case MGPIO_PORTA:
        //Checking For Pin Mode
        switch (Copy_u8PinMode)
        {
        case MGPIO_INPUT:
            //Set The Pin To Be Input Pin
            GPIOA->MODER |= (0b00 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_OUTPUT:
            //Set The Pin To Be Output Pin
            GPIOA->MODER |= (0b01 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_AF:
            //Set The Pin To Be Alternative Function Pin
            GPIOA->MODER |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_ANALOG:
            //Set The Pin To Be Analog Pin
            GPIOA->MODER |= (0b11 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;

    case MGPIO_PORTB:
        //Checking For Pin Mode
        switch (Copy_u8PinMode)
        {
        case MGPIO_INPUT:
            //Set The Pin To Be Input Pin
            GPIOB->MODER |= (0b00 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_OUTPUT:
            //Set The Pin To Be Output Pin
            GPIOB->MODER |= (0b01 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_AF:
            //Set The Pin To Be Alternative Function Pin
            GPIOB->MODER |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_ANALOG:
            //Set The Pin To Be Analog Pin
            GPIOB->MODER |= (0b11 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;

    case MGPIO_PORTC:
        //Checking For Pin Mode
        switch (Copy_u8PinMode)
        {
        case MGPIO_INPUT:
            //Set The Pin To Be Input Pin
            GPIOC->MODER |= (0b00 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_OUTPUT:
            //Set The Pin To Be Output Pin
            GPIOC->MODER |= (0b01 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_AF:
            //Set The Pin To Be Alternative Function Pin
            GPIOC->MODER |= (0b10 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_ANALOG:
            //Set The Pin To Be Analog Pin
            GPIOC->MODER |= (0b11 << (Copy_u8PinNumber * PIN_BITS_OFFSET));
            break;
        }
        break;
    }
}
void MGPIO_voidPinOutputType(u8 copy_u8portname,u8 copy_u8pinnumber, u8 Copy_u8OutputType)

{
    switch (copy_u8portname)
    {
    case MGPIO_PORTA:
        switch (Copy_u8OutputType)
        {
        case MGPIO_OUTPUT_OD:
            //Set The Pin Output Type To Be Open Drain Pin
            SET_BIT(GPIOA->OTYPER, copy_u8pinnumber);
            break;
        case MGPIO_OUTPUT_PP:
            //Set The Pin Output Type To Be PushPull Pin
            CLR_BIT(GPIOA->OTYPER, copy_u8pinnumber);
            break;
        }
        break;
        case MGPIO_PORTB: 
        switch (Copy_u8OutputType)
        {
        case MGPIO_OUTPUT_OD:
            //Set The Pin Output Type To Be Open Drain Pin
            SET_BIT(GPIOB->OTYPER, copy_u8pinnumber);
            break;
        case MGPIO_OUTPUT_PP:
            //Set The Pin Output Type To Be PushPull Pin
            CLR_BIT(GPIOB->OTYPER, copy_u8pinnumber);
            break;
        }
        break;
        case MGPIO_PORTC: 
        switch (Copy_u8OutputType)
        {
        case MGPIO_OUTPUT_OD:
            //Set The Pin Output Type To Be Open Drain Pin
            SET_BIT(GPIOC->OTYPER, copy_u8pinnumber);
            break;
        case MGPIO_OUTPUT_PP:
            //Set The Pin Output Type To Be PushPull Pin
            CLR_BIT(GPIOC->OTYPER, copy_u8pinnumber);
            break;
        }
        break;
    }
}

void MGPIO_voidSetPinSpeed(u8 copy_u8portname,u8 copy_u8pinnumber,u8 copy_u8pinspeed)
{

switch (copy_u8portname)
    {
    case MGPIO_PORTA:
        switch (copy_u8pinspeed)
        {
        case MGPIO_LOW_SPEED:
            GPIOA->OSPEEDR |= (0b00 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_MEDIUM_SPEED:
            GPIOA->OSPEEDR |= (0b01 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_HIGH_SPEED:
            GPIOA->OSPEEDR |= (0b10 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_VERY_HIGH_SPEED:
            GPIOA->OSPEEDR |= (0b11 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        }
        break;

    case MGPIO_PORTB:
        switch (copy_u8pinspeed)
        {
        case MGPIO_LOW_SPEED:
            GPIOB->OSPEEDR |= (0b00 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_MEDIUM_SPEED:
            GPIOB->OSPEEDR |= (0b01 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_HIGH_SPEED:
            GPIOB->OSPEEDR |= (0b10 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_VERY_HIGH_SPEED:
            GPIOB->OSPEEDR |= (0b11 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        }
        break;

    case MGPIO_PORTC:
        switch (copy_u8pinspeed)
        {
        case MGPIO_LOW_SPEED:
            GPIOC->OSPEEDR |= (0b00 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_MEDIUM_SPEED:
            GPIOC->OSPEEDR |= (0b01 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_HIGH_SPEED:
            GPIOC->OSPEEDR |= (0b10 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_VERY_HIGH_SPEED:
            GPIOC->OSPEEDR |= (0b11 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        }
        break;
    }
}


void MGPIO_voidSetPinPullUpDown(u8 copy_u8portname,u8 copy_u8pinnumber,u8 copy_u8pullupdownstate)
{
 switch (copy_u8portname)
    {
    case MGPIO_PORTA:
        //Check For The State Of Pull Up/Down Resistor
        switch (copy_u8pullupdownstate)
        {
        case MGPIO_FLOAT:
            //Set The Input Pin To Be Float Pin
            GPIOA->PUPDR |= (0b00 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_PULLUP:
            //Set The Input Pin To Be Pulled Up Pin
            GPIOA->PUPDR |= (0b01 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_PULLDOWN:
            //Set The Input Pin To Be Pulled Down Pin
            GPIOA->PUPDR |= (0b10 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        }
        break;

    case MGPIO_PORTB:
        switch (copy_u8pullupdownstate)
        {
        //Check For The State Of Pull Up/Down Resistor
        case MGPIO_FLOAT:
            //Set The Input Pin To Be Float Pin
            GPIOB->PUPDR |= (0b00 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_PULLUP:
            //Set The Input Pin To Be Pulled Up Pin
            GPIOB->PUPDR |= (0b01 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_PULLDOWN:
            //Set The Input Pin To Be Pulled Down Pin
            GPIOB->PUPDR |= (0b10 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        }
        break;
    case MGPIO_PORTC:
        //Check For The State Of Pull Up/Down Resistor
        switch (copy_u8pullupdownstate)
        {
        case MGPIO_FLOAT:
            //Set The Input Pin To Be Float Pin
            GPIOC->PUPDR |= (0b00 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_PULLUP:
            //Set The Input Pin To Be Pulled Up Pin
            GPIOC->PUPDR |= (0b01 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        case MGPIO_PULLDOWN:
            //Set The Input Pin To Be Pulled Down Pin
            GPIOC->PUPDR |= (0b10 << (copy_u8pinnumber * PIN_BITS_OFFSET));
            break;
        }
        break;
    }
}

void MGPIO_voidSetPinValue(u8 copy_u8portname, u8 copy_u8pinnumber,u8 copy_u8pinvalue)
{
switch (copy_u8portname)
    {
    case MGPIO_PORTA:
        //Check For The Value Of The Pin
        switch (copy_u8pinvalue)
        {
        case MGPIO_OUTPUT_LOW:
            //Set The Output Pin To Be Low, Atomic Reset
            GPIOA->BSRR = 1 << (copy_u8pinnumber + 16);
            break;
        case MGPIO_OUTPUT_HIGH:
            //Set The Output Pin To Be High, Atomic Set
            GPIOA->BSRR = 1 << (copy_u8pinnumber);
            break;
        }
        break;

    case MGPIO_PORTB:
        //Check For The Value Of The Pin
        switch (copy_u8pinvalue)
        {
        case MGPIO_OUTPUT_LOW:
            //Set The Output Pin To Be Low, Atomic Reset
            GPIOB->BSRR = 1 << (copy_u8pinnumber + 16);
            break;
        case MGPIO_OUTPUT_HIGH:
            //Set The Output Pin To Be High, Atomic Set
            GPIOB->BSRR = 1 << (copy_u8pinnumber);
            break;
        }
        break;

    case MGPIO_PORTC:
        //Check For The Value Of The Pin
        switch (copy_u8pinvalue)
        {
        case MGPIO_OUTPUT_LOW:
            //Set The Output Pin To Be Low, Atomic Reset
            GPIOC->BSRR = 1 << (copy_u8pinnumber + 16);
            break;
        case MGPIO_OUTPUT_HIGH:
            //Set The Output Pin To Be High, Atomic Set
            GPIOC->BSRR = 1 << (copy_u8pinnumber);
            break;
        }
        break;
    }
}

void MGPIO_voidSetPortSpecificMode(u8 copy_u8portname,u32 Copy_u32PortModeValue )
{
switch (copy_u8portname)
    {
    case MGPIO_PORTA:
        //Set The Specific Mode Value To MODE Register
        GPIOA->MODER = Copy_u32PortModeValue;
        break;

    case MGPIO_PORTB:
        //Set The Specific Mode Value To MODE Register
        GPIOB->MODER = Copy_u32PortModeValue;
        break;

    case MGPIO_PORTC:
        //Set The Specific Mode Value To MODE Register
        GPIOC->MODER = Copy_u32PortModeValue;
        break;
    }

}


void MGPIO_voidSetPortSpecificValue(u8 copy_u8portname,u32 Copy_u32PortValue )
{
switch(copy_u8portname)
    {
        case MGPIO_PORTA:
        //Set The Specific Value To ODR Register
            GPIOA->ODR=Copy_u32PortValue;
        break;

        case MGPIO_PORTB:
        //Set The Specific Value To ODR Register
            GPIOB->ODR=Copy_u32PortValue;
        break;

        case MGPIO_PORTC:
        //Set The Specific Value To ODR Register
            GPIOC->ODR=Copy_u32PortValue;
        break;
    }

}


u8 MGPIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
    u8 Local_u8PinValue;
    //Check For The Port Name
    switch (Copy_u8PortName)
    {
    case MGPIO_PORTA:
        //Assign The Pin Value For The Local_u8PinValue Variable
        Local_u8PinValue = GET_BIT(GPIOA->IDR, Copy_u8PinNumber);
        break;

    case MGPIO_PORTB:
        //Assign The Pin Value For The Local_u8PinValue Variable
        Local_u8PinValue = GET_BIT(GPIOB->IDR, Copy_u8PinNumber);
        break;

    case MGPIO_PORTC:
        //Assign The Pin Value For The Local_u8PinValue Variable
        Local_u8PinValue = GET_BIT(GPIOC->IDR, Copy_u8PinNumber);
        break;
    }
    return Local_u8PinValue;
}