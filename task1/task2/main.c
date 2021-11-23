#include "stm32f401cc_interface.h"

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
  GPIOB_OTYPER &= ~(0x07<<5) // clear 5,6,7 so the output type is push-pull

  //set bin 3 to pull up
  GPIOB_PUPDR = &= ~(0x03<<2*3);
  GPIOB_PUPDR |= (1<<2*3);
  short int checkbit3=0;
  short int color =8;
  while(1){
        checkbit3 = (GPIOB_IDR & (1<<3)) >>3;
       if (checkbit3 == 0x00){
       for(int i=0; i<50000;i++){}} //50 ms delay
        checkbit3 = (GPIOB_IDR & (1<<3)) >>3;
       if (checkbit3 == 0x00){
            color = color+1;
           switch (color)
​{
    case 0:
        GPIOx_ODR = 0;
      break;

    case 1:
        GPIOx_ODR = 1<<5;
      break;
   case 2:
         GPIOx_ODR = 1<<6;
      break;
      case 3:
         GPIOx_ODR = 1<<7;
      break;
      case 4:
        GPIOx_ODR = 0x03<<5;
      break;
      case 5:
        GPIOx_ODR = 0x05<<5;
      break;
      case 6:
        GPIOx_ODR = 0x06<<5;
      break;
      case 7:
        GPIOx_ODR = 0x07<<5;
      break;
      case 8:
        color=0;
      break;
    default:
      GPIOB_ODR = 0;
}

       }



  }

  return 0;
}
