/*
 * GPIO.C
 *
 *  Created on: Nov 24, 2021
 *      Author: ADVINTIC
 */
#include "GPIO.h"
//#include "stm32f401xc.h"
//#include "stm32f401cc_interface.h"

unsigned int *lookup[2][6] = {{GPIOA_ENR,GPIOA_MODER,GPIOA_PUPDR,GPIOA_OTYPER,GPIOA_IDR,GPIOA_ODR},
                            	{GPIOB_ENR,GPIOB_MODER,GPIOB_PUPDR,GPIOB_OTYPER,GPIOB_IDR,GPIOB_ODR}};

void GPIO_Init( unsigned int Port, unsigned int PIN_NO, unsigned int PIN_Dir, unsigned int Default_State)
{	//enable clock
	*lookup[Port][0] |= (0x01 << Port);

	// mode register
	*lookup[Port][1] &= ~(0x03 << 2 * PIN_NO); //CLR
	*lookup[Port][1] |= (PIN_Dir << 2 * PIN_NO); //write direction

	//pull up down register
	*lookup[Port][2] &= ~(0x03 << 2 * PIN_NO);
	*lookup[Port][2] |= Default_State << (2 * PIN_NO);

	//output type register
	*lookup[Port][3] &= ~(1<<PIN_NO); //CLR
	*lookup[Port][3] |= (Default_State<<PIN_NO);

}

unsigned char GPIO_WritePin(unsigned int Port, unsigned int PIN_NO, unsigned int Data)
{
	unsigned char result;
	if ( ((*lookup[Port][1] & (0x03 << 2 * PIN_NO)) >> (2 * PIN_NO)) == 1) {
	if (Data)
		*lookup[Port][5] |= 1<<PIN_NO;
	else
		*lookup[Port][5] &= 0<<PIN_NO;
	result = OK;
	}
	else
		result = NOK;
	return result;
}
unsigned char GPIO_ReadPin(unsigned int Port, unsigned int PIN_NO){
	unsigned char result;
	unsigned char read_data;
	if((*lookup[Port][1] & (0x03 << 2*PIN_NO)) >> (2*PIN_NO) == 0){
		result = OK;
		read_data = *lookup[Port][4] & (0x01<<PIN_NO);
	}
	else
		result = NOK;

	return read_data;
}
