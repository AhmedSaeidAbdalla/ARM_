/*
**************************************
Author          Ahmed Saeid Abdall
Data            5 MAY,2023
Compiler        GNU ARM-GCC
Controller      stm32f401ccu6 (32-bit Architiecture)
layer           MCAL
**************************************
*/


#ifndef MGPIO_PRIVATE_H
#define MGPIO_PRIVATE_H

typedef struct
{
    volatile u32 MODER;
    volatile u32 OTYPER;
    volatile u32 OSPEEDR;
    volatile u32 PUPDR;
    volatile u32 IDR;
    volatile u32 ODR;
    volatile u32 BSRR;
    volatile u32 LCKR;
    volatile u32 AFRL;
    volatile u32 AFRH;

} GPIO_t;


#define GPIOA ((volatile GPIO_t *)0x40020000)       // Base Address For GPIOA
#define GPIOB ((volatile GPIO_t *)0x40020400)       // Base Address For GPIOB
#define GPIOC ((volatile GPIO_t *)0x40020800)       // Base Address For GPIOC
#define GPIOD ((volatile GPIO_t *)0x40020800)       // Base Address For GPIOD


#define PIN_BITS_OFFSET 2
#define BSRR_PIN_OFFSET 16


#endif