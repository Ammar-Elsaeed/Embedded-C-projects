/*
 * Author : Abdullah Drwesh
 * Date   : 8/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
#include "Keypad.h"
char key_value;
char valuesarr[4][3] ={{1,2,3},{4,5,6}, {7,8,9},{'*',0,'#'}};
void keypad_init(void){
	GPIO_EnableClock('B');

	for (int input_pin =0; input_pin<=3;input_pin++){
	GPIO_Init('B',input_pin,INPUT,PULL_UP);

	}

	for (int output_pin =5; output_pin<=7; output_pin++){
		GPIO_Init('B',output_pin,OUTPUT,PUSH_PULL);
		GPIO_WritePin('B',output_pin,1);
	}
}

void keypad_manage(void)
{
	int input, output;

		for (output = 5; output <= 7; output++)
		{
			GPIO_WritePin('B', output,0);
			for (input = 0; input <= 3; input++)
			{
			  if(GPIO_ReadPin('B', input)==0)
			  {
				  for(int wait=0;wait<30000;wait++);// check for valid button press only (debouncing)
				  if(GPIO_ReadPin('B', input)==0)
				  {
					  key_value = valuesarr[input][output-5];
					  keypadCallouts_KeyPressNotification();
					  while(GPIO_ReadPin('B', input)==0);
				  }
			  }
			}
			GPIO_WritePin('B', output,1);
			key_value =127;
		}

}
char keypad_getkey(void){
	return key_value;
}
void keypadCallouts_KeyPressNotification(void){
		unsigned char i;
	  unsigned char sevenSegHex[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
	                                   0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	  GPIO_EnableClock('A');
	  for (i = 0; i < 7; i++) {
	    GPIO_Init('A', i, OUTPUT, PUSH_PULL);
	  }
	  if (key_value != 127){
	  for (i = 0; i < 7; i++) {
	              GPIO_WritePin('A', i, (sevenSegHex[key_value] & (1 << i)) >> i);
	            }
	  }
}
