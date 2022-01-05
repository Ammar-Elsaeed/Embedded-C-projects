/*
 * GPIO.h
 *
 *  Created on: Nov 24, 2021
 *      Author: ADVINTIC
 */

#ifndef GPIO
#define GPIO

//#include "stm32f401xc.h"

#define GPIO_REG(PORT_ID,REG_ID) ((unsigned int*)(PORT_ID + REG_ID))

#define GPIOA_MODER (GPIO_REG(0x40020000,0x00))
#define GPIOB_MODER (GPIO_REG(0x40020400,0x00))

#define GPIOA_OTYPER (GPIO_REG(0x40020000,0x04))
#define GPIOB_OTYPER (GPIO_REG(0x40020400,0x04))

#define GPIOA_PUPDR (GPIO_REG(0x40020000,0x0C))
#define GPIOB_PUPDR (GPIO_REG(0x40020400,0x0C))

#define GPIOA_IDR (GPIO_REG(0x40020000,0x10))
#define GPIOB_IDR (GPIO_REG(0x40020400,0x10))

#define GPIOA_ODR (GPIO_REG(0x40020000,0x14))
#define GPIOB_ODR (GPIO_REG(0x40020400,0x14))

#define GPIOA_ENR (GPIO_REG(0x40023800,0x30))
#define GPIOB_ENR (GPIO_REG(0x40023800,0x30))

//write result
#define OK  ((unsigned char)0)
#define NOK ((unsigned char)1)

//mode types
#define INPUT ((unsigned int)0x00)
#define OUTPUT ((unsigned int)0x01)
#define ALTERNATE_FUN ((unsigned int)0x02)
#define ANALOG ((unsigned int)0x03)

//output modes
#define PUSH_PULL ((unsigned int)0x00)
#define OPEN_DRAIN ((unsigned int)0x01)
#define PULLUP ((unsigned int)0x01)
#define PULLDOWN ((unsigned int)0x02)

void GPIO_Init( unsigned int Port, unsigned int PIN_NO, unsigned int PIN_Dir, unsigned int Default_State);
unsigned char GPIO_WritePin(unsigned int Port, unsigned int PIN_NO, unsigned int Data);
unsigned char GPIO_ReadPin(unsigned int Port, unsigned int PIN_NO);

#endif
