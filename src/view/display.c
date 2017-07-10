/*
 * display.c
 *
 *  Created on: 29 jun. 2017
 *      Author: jcala
 */

#include "display.h"

void write_display(char* ln1, char* ln2, char* ln3, char* ln4);

void display_init() {
	lcd_init();
}

void write_display(char* ln1, char* ln2, char* ln3, char* ln4) {
	display_clear();
	if (ln1 != NULL) {
		lcdLoc(LINE1);
		typeln(ln1);
	}
	if (ln2 != NULL) {
		lcdLoc(LINE2);
		typeln(ln2);
	}
	if (ln3 != NULL) {
		lcdLoc(LINE3);
		typeln(ln3);
	}
	if (ln3 != NULL) {
		lcdLoc(LINE3);
		typeln(ln3);
	}
}

void display_user_menu() {
	display_clear();
	lcdLoc(LINE1);
	typeln("Introduzca su numero de usuario");
}

void display_options_menu() {
	char* ln1 = "1) METER DINERO";
	char* ln2 = "2) VER DINERO";
	char* ln3 = "3) COMPRAR";
	char* ln4 = "4) SALIR";
	write_display(ln1,ln2,ln3,ln4);
}

void display_add_money_menu(int total) {

}

void display_check_money_menu(user_t* usuario) {
	display_clear();
	char* ln1 = (char*) malloc(21 * sizeof(char));
	char* ln2 = (char*) malloc(21 * sizeof(char));
	snprintf(ln1, 21, FORMAT_CHECK_MONEY_1, usuario->nombre);
	snprintf(ln2, 21, FORMAT_CHECK_MONEY_2, usuario->saldo);
	write_display(ln1,ln2,NULL,NULL);
	free(ln1);
	free(ln2);
}

void display_buy_menu(void *t, int current_id) {
	char* displn = (char*) malloc(21 * sizeof(char));
	int num = 0;
	ClrLcd();
	product_list_t* list = (product_list_t*) t;
	product_t* p_tmp = NULL;
	lcdLoc(LINE1);
	p_tmp = producto_list_search(list, current_id);
	if (p_tmp == NULL) {
		return;
	}
	snprintf(displn, 21, FORMAT_BUY, p_tmp->id, p_tmp->nombre);
	typeln(displn);
	lcdLoc(LINE2);
	p_tmp = producto_list_search(list, current_id + 1);
	if (p_tmp == NULL) {
		return;
	}
	snprintf(displn, 21, FORMAT_BUY, p_tmp->id, p_tmp->nombre);
	typeln(displn);
	lcdLoc(LINE3);
	p_tmp = producto_list_search(list, current_id + 2);
	if (p_tmp == NULL) {
		return;
	}
	snprintf(displn, 21, FORMAT_BUY, p_tmp->id, p_tmp->nombre);
	typeln(displn);
	free(displn);
}

void display_write_last(char* line) {
	lcdLoc(LINE4);
	typeln(line);
}

void display_clear() {
	lcdLoc(LINE1);
	typeln("");
	lcdLoc(LINE2);
	typeln("");
	lcdLoc(LINE3);
	typeln("");
	lcdLoc(LINE4);
	typeln("");
	delay(50);
}
