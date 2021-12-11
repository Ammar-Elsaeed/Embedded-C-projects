/*
 * Author : Abdullah Drwesh
 * Date   : 8/12/2021
 * Version: 1.0.0
 */

#ifndef KEYPAD_H
#define KEYPAD_H

void keypad_init(void);
void keypad_manage(void);
char keypad_getkey(void);
void keypadCallouts_KeyPressNotification(void);

#endif /* KEYPAD_H */
