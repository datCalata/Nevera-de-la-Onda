/*
 * keypad.h
 *
 *  Created on: 27 jun. 2017
 *      Author: jcala
 */

#ifndef SRC_VIEW_KEYPAD_H_
#define SRC_VIEW_KEYPAD_H_

#include <wiringPi.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../view/display.h"
#include "../threads.h"


#define MAX_PIN 4

#define GPIO_R1 29
#define GPIO_R2 31
#define GPIO_R3 33
#define GPIO_R4 37

#define GPIO_C1 32
#define GPIO_C2 36
#define GPIO_C3 38
#define GPIO_C4 40

char key[MAX_PIN][MAX_PIN];
int row_pin[MAX_PIN];
int col_pin[MAX_PIN];


char* scan_key();
char* scan_chain(int max_length);
char* scan_chain_stop(int max_length);
void set_up_keypad();
void* scan_key_thread();
int scan_num();
float scan_float();

#endif /* SRC_VIEW_KEYPAD_H_ */
