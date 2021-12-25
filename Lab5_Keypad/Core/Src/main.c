/*
 * Author : Abdullah Drwesh
 * Date   : 7/12/2021
 * Version: 1.0.0
 */
#include "GPIO.h"
#include "Keypad.h"

int main(void) {
	keypad_init();

  while (1) {
	  	  keypad_manage();
  }

  return 0;
}
