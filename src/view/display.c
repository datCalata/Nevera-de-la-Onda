/*
 * display.c
 *
 *  Created on: 29 jun. 2017
 *      Author: jcala
 */


#include "display.h"

void display_init(){
	lcd_init();
}

void display_user_menu(){
	display_clear();
	lcdLoc(LINE1);
	typeln("Introduzca su numero de usuario");
}

void display_options_menu(){

}

void display_add_money_menu(int total){

}

void display_buy_menu(void *t,int current_id){
	char* displn = (char*)malloc(21*sizeof(char));
	int num = 0;
	ClrLcd();
	product_list_t* list = (product_list_t*)t;
	product_t* p_tmp = NULL;
	lcdLoc(LINE1);
	p_tmp = producto_list_search(list, current_id);
	if(p_tmp == NULL){
		return;
	}
	snprintf(displn,21,FORMAT_BUY,p_tmp->id,p_tmp->nombre);
	typeln(displn);
	lcdLoc(LINE2);
	p_tmp = producto_list_search(list, current_id+1);
	if(p_tmp == NULL){
			return;
		}
	snprintf(displn,21,FORMAT_BUY,p_tmp->id,p_tmp->nombre);
	typeln(displn);	lcdLoc(LINE3);
	p_tmp = producto_list_search(list, current_id+2);
	if(p_tmp == NULL){
			return;
		}
	snprintf(displn,21,FORMAT_BUY,p_tmp->id,p_tmp->nombre);
	typeln(displn);
	free(displn);
}

void display_write_last(char* line){
	lcdLoc(LINE4);
	typeln(line);
}

void display_clear(){
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
