#include "GPIO.h"

int main(void) {
	GPIO_Init(0,0,OUTPUT,PUSH_PULL);
  while (1) {
	  GPIO_WritePin(0,0,1);
	  for(int i=0; i<10000;i++){}

	  GPIO_WritePin(0,0,0);
	  for(int i=0; i<10000;i++){}
  }
  return 0;
}
