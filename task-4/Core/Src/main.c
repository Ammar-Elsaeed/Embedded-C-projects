#include "GPIO.h"
#define RCC_APB2ENR *(unsigned int*)(0x40023800 + 0x44)
#define SYSCFG_EXTICR1 *(unsigned int*)(0x40013800 + 0x08)
#define EXTI_IMR *(unsigned int*)(0x40013C00 + 0x00)
#define EXTI_RTSR *(unsigned int*)(0x40013C00 + 0x08)
#define EXTI_FTSR *(unsigned int*)(0x40013C00 + 0x0C)
#define EXTI_PR *(unsigned int*)(0x40013C00 + 0x14)
#define NVIC_ISER *(unsigned int*)(0xE000E000 + 0x100)
#define NVIC_ICER *(unsigned int*)(0xE000E000 + 0x180)

unsigned int key_value = 3;
// seven segment display
unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,0x6D, 0x7D, 0x07, 0x7F, 0x6F};

int main(){
	GPIO_EnableClock('B');
	GPIO_EnableClock('A');
	// 2 active low buttons
	GPIO_Init('A',0,INPUT,PULL_UP);
	GPIO_Init('A',1,INPUT,PULL_UP);
	// enable 2 interrupts
	RCC_APB2ENR |= (1<<14);
	SYSCFG_EXTICR1 &= (0x00<<4 * 0);
	EXTI_IMR |= (1<<0);
//	EXTI_RTSR &= 0;
	EXTI_FTSR |= 1;
	NVIC_ISER|= (1<<6);

	EXTI_IMR |= (1<<1);
	EXTI_RTSR &= 0<<1;
	EXTI_FTSR |= (1<<1);
	NVIC_ISER|= (1<<7);

	for (int i = 0; i < 7; i++) {
		GPIO_Init('B', i, OUTPUT, PUSH_PULL);
					  }

	while (1){
		for (int i = 0; i < 7; i++) {
		    GPIO_WritePin('B', i, (sevenSegHex[key_value] & (1 << i)) >> i);
		}
		}
//	while (1){
//		GPIO_Init('B', 4, OUTPUT, PUSH_PULL);
//		GPIO_WritePin('B', 4, 1);
//	}

		 return 0;
}

void increment_7seg(){
	NVIC_ICER |= (0x01 << 7);
	EXTI_PR |= (0x01 << 0);
	if (key_value<9){
	key_value = key_value +1;

}
	NVIC_ISER |= (0x01 << 7);
}

void decrement_7seg(){
	NVIC_ICER |= (0x01 << 6);
	EXTI_PR |= (0x01 << 1);
	if (key_value>0){
	key_value = key_value-1;
}
	NVIC_ISER |= (0x01 << 6);
}
