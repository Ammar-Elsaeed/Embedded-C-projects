#include "stm32f401cc_interface.h"
#include "DMA.h"
unsigned int *registers[2][7]={{DMA2_S0CR,DMA2_S0NDTR,DMA2_S0FCR,DMA2_S0PAR,DMA2_S0M0AR,DMA2_LIFCR,DMA2_LISR},
							 {DMA_S0CR,DMA_S0NDTR,DMA_S0FCR,DMA_S0PAR,DMA_S0M0AR,DMA_LIFCR,DMA_LISR}};

void DMA_init(unsigned int PID){

	RCC_AHB1ENR |= 1<<22; //enable clock
	*registers[PID][0] &= ~(1<<0); //disable stream 0 until configured
	while (((*registers[PID][0]) & 1)==1){}
	// interrupt work flow
	*registers[PID][0] |= 1<<4; // transfer complete interrupt enable
	switch(PID){//11 and 56
	case 0:
		*NVIC_ISER1 |= 1<<24;
		break;
	case 1:
		*NVIC_ISER0 |= 1<<11;
		break;


	}

}

void DMA_setparams(unsigned int PID,unsigned int trig,unsigned int * src_arr,unsigned int * dst_arr,
		unsigned int n_items, unsigned int item_size,unsigned int t_mode, unsigned int t_type, unsigned int fifo){

	*registers[PID][0] |= t_type<<21; // transfer type for memory and peripheral (single or burst)
	*registers[PID][0] &= ~(3<<6);
	*registers[PID][0] |= t_mode<<6; // select Memory to memory mode
	*registers[PID][1] = n_items; // number of items to transfer = 100
	*registers[PID][0] |= 1<<9; //  Peripheral increment mode
	*registers[PID][0] |= 1<<10; //  Memory increment mode
	*registers[PID][2] &= ~(fifo); // 1/4 FIFO
	*registers[PID][0] &= ~(0x03<<11);
	*registers[PID][0] &= ~(0x03<<13);
	*registers[PID][0] |= item_size<<13; // MSIZE word size
	*registers[PID][0] |= item_size<<11;// PSIZE word size
	*registers[PID][3] = (unsigned int) src_arr; // set source address (head of the source array)
	*registers[PID][4] = (unsigned int) dst_arr; // set destination address (head of the destination array)



}

void DMA_start_transfer(unsigned int PID){
	//clear interrupts
//	*registers[PID][5] |= (1<<0);
//	*registers[PID][5] |= (0x0F<<2);
	*registers[PID][0] |= (1<<0); //enable stream 0
}

int DMA_transfer_complete(unsigned int PID){// read and return the transfer complete flag for stream 0;
	int flag_val =  (*registers[PID][6] & (1 << 5)) >> 5;
	return flag_val;

}


void DMA2_Stream0_IRQHandler(){
	user_Deffunc();
	*registers[0][5] |= 1<<5;
}
void DMA1_Stream0_IRQHandler(){
	user_Deffunc();
	*registers[1][5] |= 1<<5;
}

