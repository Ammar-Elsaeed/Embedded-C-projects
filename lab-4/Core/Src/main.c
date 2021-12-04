#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

int main(void) {
	unsigned char lookuptable[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66,0x6d, 0x7d, 0x07, 0x7f, 0x6f};
	GPIO_Init('B', 0 , OUTPUT, PUSH_PULL);
	int disp_number,pin_no,delay,data,pin_data;
	for(pin_no = 0;pin_no<7;++pin_no){
		  		GPIO_Init('B', pin_no , OUTPUT, PUSH_PULL);
		  			}
  while (1) {
	  for(disp_number = 0;disp_number<10;++disp_number){
	  		data = lookuptable[disp_number];
	  		for(pin_no = 0;pin_no<7;++pin_no){
	  			pin_data = (data & (1<<pin_no))>>pin_no;
	  			GPIO_WritePin('B', pin_no, pin_data);
	  		}
	  		for (delay = 0; delay < 500000; ++delay){}
	  }

  }
  return 0;
}
