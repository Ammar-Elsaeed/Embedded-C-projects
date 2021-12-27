#include "GPIO.h"
#include "stm32f401cc_interface.h"


int main(void) {
	GPIO_Init('A',0,INPUT,PULLUP);
	GPIO_Init('A',1,OUTPUT,PUSH_PULL);
	// interrupt work flow
	RCC_APB2ENR |= (1<<14);
	SYSCFG_EXTICR1 &= (0x00<<4 * 0);
	EXTI_IMR |= (1<<0);
	EXTI_RTSR &= 0;
	EXTI_FTSR |= 1;
	NVIC_ISER|= (1<<6);
	while (1){}
  return 0;
}

void toggle_led(){

	EXTI_PR |= 1;
	GPIOA_ODR ^= (1<<1);

}
