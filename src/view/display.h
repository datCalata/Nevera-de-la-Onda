/*
 * display.h
 *
 *  Created on: 29 jun. 2017
 *      Author: jcala
 */

#ifndef SRC_VIEW_DISPLAY_H_
#define SRC_VIEW_DISPLAY_H_

#include "lcd.h"
#include "../model/productlinkedlist.h"
#include "../model/producto.h"
#include "../model/userlinkedlist.h"
#include "../model/usuarios.h"
#include <wiringPi.h>
#include <pthread.h>
#include "../threads.h"
#include "../controller/keypad.h"

#define FORMAT_BUY "%d) %s"

void display_init();
void display_user_menu();
void display_options_menu();
void display_user_menu();
void display_add_money_menu(int total);
void display_buy_menu(void *t,int current_id);
void display_write_last(char* line);
void display_clear();

#endif /* SRC_VIEW_DISPLAY_H_ */
