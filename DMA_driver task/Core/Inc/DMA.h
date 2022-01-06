
#ifndef DMA.h
#define DMA.h

void DMA_init(unsigned int PID);
void DMA_setparams(unsigned int PID,unsigned int trig,unsigned int * src_addr,unsigned int * dst_addr,
		unsigned int n_items, unsigned int item_size,unsigned int t_mode, unsigned int t_type, unsigned int fifo);
void DMA_start_transfer(unsigned int PID);
int DMA_transfer_complete(unsigned int PID);
void user_Deffunc();

#endif
