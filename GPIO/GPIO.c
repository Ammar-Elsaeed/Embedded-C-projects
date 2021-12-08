/*
 * GPIO.C
 *
 *  Created on: Nov 24, 2021
 *      Author: ADVINTIC
 */
#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"
void GPIO_Init( char Port, unsigned int PIN_NO, unsigned int PIN_Dir, unsigned int Default_State)
{
	//enable clock of port
	switch (Port)
	{
		case('A'):
				RCC_AHB1ENR |= (0x01 <<0);
				//configure moder register for pin direction
				switch(PIN_Dir)
				{
					case (INPUT):
							GPIOA_MODER &= ~(0x03 << 2*PIN_NO);
					switch(Default_State){
					case(PULLUP):
						GPIOA_PUPDR &= ~(0x03<<2*PIN_NO);
						GPIOA_PUPDR |= (1<<2*PIN_NO);
					break;
					case(PULLDOWN):
						GPIOA_PUPDR &= ~(0x03<<2*PIN_NO);
						GPIOA_PUPDR |= (0x02<<2*PIN_NO);
						break;
								}
					break;
					case (OUTPUT):
							GPIOA_MODER |= (0x01 << 2*PIN_NO);
					switch(Default_State)
									{
										case(PUSH_PULL):
												GPIOA_OTYPER &= ~(0x01<<PIN_NO);
										break;
										case(OPEN_DRAIN):
												GPIOA_OTYPER |= (0x01<<PIN_NO);
										break;
									}//end switch
					break;
					case (ALTERNATE_FUN):
							GPIOA_MODER |= (0x02 << 2*PIN_NO);
					break;
					case (ANALOG):
							GPIOA_MODER |= (0x03 << 2*PIN_NO);
					break;
				}// end switch
				//configure default state

		break;
		case('B'):
				RCC_AHB1ENR |= (0x01 <<1);
				//configure moder register for pin direction
				switch(PIN_Dir)
				{
					case (INPUT):
							GPIOB_MODER &= ~(0x03 << 2*PIN_NO);
					switch(Default_State){
										case(PULLUP):
											GPIOB_PUPDR &= ~(0x03<<2*PIN_NO);
											GPIOB_PUPDR |= (1<<2*PIN_NO);
										break;
										case(PULLDOWN):
											GPIOB_PUPDR &= ~(0x03<<2*PIN_NO);
											GPIOB_PUPDR |= (0x02<<2*PIN_NO);
											break;
										}
					break;
					case (OUTPUT):
							GPIOB_MODER |= (0x01 << 2*PIN_NO);
					switch(Default_State)
									{
										case(PUSH_PULL):
												GPIOB_OTYPER &= ~(0x01<<PIN_NO);
										break;
										case(OPEN_DRAIN):
												GPIOB_OTYPER |= (0x01<<PIN_NO);
										break;
									}
					break;
					case (ALTERNATE_FUN):
							GPIOB_MODER |= (0x02 << 2*PIN_NO);
					break;
					case (ANALOG):
							GPIOB_MODER |= (0x03 << 2*PIN_NO);
					break;
				}// end switch
				//end switch
		break;
	}

}

unsigned char GPIO_WritePin(char Port, unsigned int PIN_NO, unsigned int Data)
{
	unsigned char result;
	switch(Port)
	{
		case('A'):
			if((GPIOA_MODER & (0x03 << 2*PIN_NO)) >> (2*PIN_NO) == 1)
			{
			     if(Data)
			     {
			    	 GPIOA_ODR |= (1<<PIN_NO);
			     }
			     else
			     {
			    	 GPIOA_ODR &= ~(1<<PIN_NO);
			     }
				result = OK;
			}
			else
			{
				result = NOK;
			}
		break;
		case('B'):
				if((GPIOB_MODER & (0x03 << 2*PIN_NO))>> (2*PIN_NO)  == 1)
				{
					 if(Data)
					 {
						 GPIOB_ODR |= (1<<PIN_NO);
					 }
					 else
					 {
						 GPIOB_ODR &= ~(1<<PIN_NO);
					 }
					result = OK;
				}
				else
				{
					result = NOK;
				}

		break;

	}// end switch

	return result;
}
unsigned char GPIO_ReadPin(char Port, unsigned int PIN_NO){
	unsigned char result;
	unsigned char read_data;
	switch(Port)
		{
	case("A"):
			if((GPIOA_MODER & (0x03 << 2*PIN_NO)) >> (2*PIN_NO) == 0){
				result = OK;
				read_data = GPIOA_IDR & (0x01<<PIN_NO);
			}
			else{
				result = NOK;
			}
	break;
	case("B"):
		if((GPIOB_MODER & (0x03 << 2*PIN_NO)) >> (2*PIN_NO) == 0){
						result = OK;
						read_data = GPIOB_IDR & (0x01<<PIN_NO);
					}
					else{
						result = NOK;
					}
	break;

		}
	return read_data;
}
