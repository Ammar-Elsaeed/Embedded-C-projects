#include "stm32f401cc_interface.h"
#define button_state ((GPIOB_IDR & (1<<3)) >>3)

int main(void) {

  RCC_AHB1ENR |= (1<<1);//supply clock to port B (enable)
  GPIOB_MODER &= ~(0x03<<2*3); //set bin 3 as input
  //reset bins 5,6,7 . then set them to output
  GPIOB_MODER &= ~(0x03<<2*5);
  GPIOB_MODER &= ~(0x03<<2*6);
  GPIOB_MODER &= ~(0x03<<2*7);

  GPIOB_MODER |= (1<<2*5);
  GPIOB_MODER |= (1<<2*6);
  GPIOB_MODER |= (1<<2*7);
  //set the output type to push pull
  GPIOB_OTYPER &= ~(0x07<<5); // clear 5,6,7 so the output type is push-pull

  //set bin 3 to pull up
  GPIOB_PUPDR  &= ~(0x03<<2*3);
  GPIOB_PUPDR |= (1<<2*3);
  short int checkbit3=button_state;
  unsigned char color =0;
  unsigned char colorbit0=0;
  unsigned char colorbit1=0;
  unsigned char colorbit2=0;
  unsigned char stillpressed=0;
//  GPIOB_ODR = 1<<5;

  while(1){

	for(int i=0; i<500000;i++){
		checkbit3 = button_state;
		if (checkbit3==1){break;}
	} //delay, the button must be pressed for at least the same period as this delay so it counts as a press.

	if (checkbit3 == 0x00){
	color = color+1;}

	colorbit0 = (color & 0x01);
	if (colorbit0 ==0){
		GPIOB_ODR &= ~(1<<5);}
	else{
		GPIOB_ODR |=(1<<5);}

	colorbit1 = (color & 0x02);
	if (colorbit1 ==0){
		GPIOB_ODR &= ~(1<<6);}
	else{
		GPIOB_ODR |=(1<<6);}

	colorbit2 = (color & 0x04);
	if (colorbit2 ==0){
		GPIOB_ODR &= ~(1<<7);}
	else{
		GPIOB_ODR |=(1<<7);}

	while(checkbit3==0){//rising edge detection, this won't exit until we unpress the button. which brings logic level to 1.
		checkbit3 = button_state;
	}
  }

  return 0;
}
