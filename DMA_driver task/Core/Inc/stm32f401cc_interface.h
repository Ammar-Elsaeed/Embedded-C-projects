
#ifndef STM32F401CC_INTERFACE_H
#define STM32F401CC_INTERFACE_H

#include "stm32f401xc.h"

#define RCC_CR             (RCC->CR)
#define RCC_PLLCFGR        (RCC->PLLCFGR)
#define RCC_CFGR           (RCC->RCC_CFGR)
#define RCC_CIR            (RCC->CIR)
#define RCC_AHB1RSTR       (RCC->AHB1RSTR)
#define RCC_AHB2RSTR       (RCC->AHB2RSTR)
#define RCC_APB1RSTR       (RCC->APB1RSTR)
#define RCC_APB2RSTR       (RCC->APB2RSTR)
#define RCC_AHB1ENR        (RCC->AHB1ENR)
#define RCC_AHB2ENR        (RCC->AHB2ENR)

#define GPIOA_MODER        (GPIOA->MODER)
#define GPIOA_OTYPER       (GPIOA->OTYPER)
#define GPIOA_OSPEEDR      (GPIOA->OSPEEDR)
#define GPIOA_PUPDR        (GPIOA->PUPDR)
#define GPIOA_IDR          (GPIOA->IDR)
#define GPIOA_ODR          (GPIOA->ODR)
#define GPIOA_BSRR         (GPIOA->BSRR)
#define GPIOA_LCKR         (GPIOA->LCKR)
#define GPIOA_AFRL         (GPIOA->AFRL)
#define GPIOA_AFRH         (GPIOA->AFRH)


#define GPIOB_MODER        (GPIOB->MODER)
#define GPIOB_OTYPER       (GPIOB->OTYPER)
#define GPIOB_OSPEEDR      (GPIOB->OSPEEDR)
#define GPIOB_PUPDR        (GPIOB->PUPDR)
#define GPIOB_IDR          (GPIOB->IDR)
#define GPIOB_ODR          (GPIOB->ODR)
#define GPIOB_BSRR         (GPIOB->BSRR)
#define GPIOB_LCKR         (GPIOB->LCKR)
#define GPIOB_AFRL         (GPIOB->AFRL)
#define GPIOB_AFRH         (GPIOB->AFRH)


#define GPIOC_MODER        (GPIOC->MODER)
#define GPIOC_OTYPER       (GPIOC->OTYPER)
#define GPIOC_OSPEEDR      (GPIOC->OSPEEDR)
#define GPIOC_PUPDR        (GPIOC->PUPDR)
#define GPIOC_IDR          (GPIOC->IDR)
#define GPIOC_ODR          (GPIOC->ODR)
#define GPIOC_BSRR         (GPIOC->BSRR)
#define GPIOC_LCKR         (GPIOC->LCKR)
#define GPIOC_AFRL         (GPIOC->AFRL)
#define GPIOC_AFRH         (GPIOC->AFRH)


#define GPIOD_MODER        (GPIOD->MODER)
#define GPIOD_OTYPER       (GPIOD->OTYPER)
#define GPIOD_OSPEEDR      (GPIOD->OSPEEDR)
#define GPIOD_PUPDR        (GPIOD->PUPDR)
#define GPIOD_IDR          (GPIOD->IDR)
#define GPIOD_ODR          (GPIOD->ODR)
#define GPIOD_BSRR         (GPIOD->BSRR)
#define GPIOD_LCKR         (GPIOD->LCKR)
#define GPIOD_AFRL         (GPIOD->AFRL)
#define GPIOD_AFRH         (GPIOD->AFRH)

#define RCC_APB2ENR *(unsigned int*)(0x40023800 + 0x44)
#define SYSCFG_EXTICR1 *(unsigned int*)(0x40013800 + 0x08)
#define EXTI_IMR *(unsigned int*)(0x40013C00 + 0x00)
#define EXTI_RTSR *(unsigned int*)(0x40013C00 + 0x08)
#define EXTI_FTSR *(unsigned int*)(0x40013C00 + 0x0C)
#define EXTI_PR *(unsigned int*)(0x40013C00 + 0x14)
#define NVIC_ISER1 (unsigned int*)(0xE000E100 + 0x04)
//#define NVIC_ICER1 *(unsigned int*)(0xE000E000 + 0x180)
#define NVIC_ISER0 (unsigned int*)(0xE000E100)
//#define NVIC_ICER1 *(unsigned int*)(0xE000E000 + 0x180)

#define DMA2_S0M0AR (unsigned int*)(0x40026400+0x1C)
#define DMA2_S0M1AR (unsigned int*)(0x40026400+0x20)
#define DMA2_S0CR (unsigned int*)(0x40026400+0x10)
#define DMA2_S0NDTR (unsigned int*)(0x40026400+0x14)
#define DMA2_S0PAR (unsigned int*)(0x40026400+0x18)
#define DMA2_S0FCR (unsigned int*)(0x40026400+0x24)
#define DMA2_LISR (unsigned int*)(0x40026400+0x00)
#define DMA2_HISR (unsigned int*)(0x40026400+0x04)
#define DMA2_LIFCR (unsigned int*)(0x40026400+0x08)
#define DMA2_HIFCR (unsigned int*)(0x40026400+0x0C)

#define DMA_S0M0AR (unsigned int*)(0x40026000+0x1C)
#define DMA_S0M1AR (unsigned int*)(0x40026000+0x20)
#define DMA_S0CR (unsigned int*)(0x40026000+0x10)
#define DMA_S0NDTR (unsigned int*)(0x40026000+0x14)
#define DMA_S0PAR (unsigned int*)(0x40026000+0x18)
#define DMA_S0FCR (unsigned int*)(0x40026000+0x24)
#define DMA_LISR (unsigned int*)(0x40026000+0x00)
#define DMA_HISR (unsigned int*)(0x40026000+0x04)
#define DMA_LIFCR (unsigned int*)(0x40026000+0x08)
#define DMA_HIFCR (unsigned int*)(0x40026000+0x0C)


#endif /* STM32F401CC_INTERFACE_H */
