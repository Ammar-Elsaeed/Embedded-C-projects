#include "GPIO.h"
#include "DMA.h"
#include "stm32f401cc_interface.h"

unsigned int src_arr[100];
unsigned int dst_arr[100];
void user_Deffunc(){

		GPIO_WritePin('A',0,1);

}

int main(){

	src_arr[0] =100;
	dst_arr[0]=0;
	for (int i =1;i<=100;i++) {
		src_arr[i] =100+src_arr[i-1];
		dst_arr[i] =0;
	}

	GPIO_EnableClock('A');
	GPIO_Init('A',0,OUTPUT,PUSH_PULL);

	DMA_init(0);
	DMA_setparams(0,0,src_arr,dst_arr,0x64,0x02,0x02,0x00,0x03);
	DMA_start_transfer(0);
	int flag = DMA_transfer_complete(0);
	while (1){

	}
	return 0;
}
