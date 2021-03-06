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
#define FORMAT_CHECK_MONEY_1 "%s tiene:"
#define FORMAT_CHECK_MONEY_2 "%2.2f Euros"

void display_init();
void display_user_menu();
void display_options_menu();
void display_user_menu();
void display_add_money_menu();
void display_options_menu();
void display_options_error();
void display_user_error();
void display_user_selected(char* user);
void display_total_money(float saldo);
void display_buy_menu(void *t,int current_id);
void display_write_last(char* line);
void display_clear();

#endif /* SRC_VIEW_DISPLAY_H_ */
