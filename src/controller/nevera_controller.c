/*
 * nevera_controller.c
 *
 *  Created on: 5 jul. 2017
 *      Author: calata
 */

#include "nevera_controller.h"

int buy_stuff(nevera_fsm_t* nevera,int id);

///////FSM TABLE FUNCTIONS//////
//CONDITION FUNCTIONS
//TODO: HACER FUNCIONES DE CONDICION
static int input_condition_func_start(fsm_t* fsm);
static int input_condition_func_wait_for_option(fsm_t* fsm);
static int input_condition_func_add_money(fsm_t* fsm);
static int input_condition_func_check_money(fsm_t* fsm);
static int input_condition_func_buy_something(fsm_t* fsm);
static int input_condition_func_add_product(fsm_t* fsm);
static int input_condition_func_return_wait_for_user(fsm_t* fsm);

//OUTPUT FUNCTIONS
//TODO Declaración de funciones OUTPUT de la máquina de estados. Se ejecutan cuando se alcanza el estado.
static void output_func_wait_for_user(fsm_t* fsm);
static void output_func_wait_for_option(fsm_t* fsm);
static void output_func_add_money(fsm_t* fsm);
static void output_func_check_money(fsm_t* fsm);
static void output_func_buy_something(fsm_t* fsm);
static void output_func_add_product(fsm_t* fsm);

fsm_trans_t nevera_transition_table[] = {
		{START, input_condition_func_start,WAIT_FOR_USER,output_func_wait_for_user},
		{WAIT_FOR_USER,input_condition_func_wait_for_option,WAIT_FOR_OPTION,output_func_wait_for_option},
		{WAIT_FOR_OPTION,input_condition_func_add_money,ADD_MONEY,output_func_add_money},
		{WAIT_FOR_OPTION,input_condition_func_check_money,CHECK_MONEY,output_func_check_money},
		{WAIT_FOR_OPTION,input_condition_func_buy_something,BUY_SOMETHING,output_func_buy_something},
		{WAIT_FOR_OPTION,input_condition_func_add_product,ADD_PRODUCT,output_func_add_product},
		{WAIT_FOR_OPTION,input_condition_func_return_wait_for_user,WAIT_FOR_USER,output_func_wait_for_user},
		{CHECK_MONEY,input_condition_func_return_wait_for_user,WAIT_FOR_OPTION,output_func_wait_for_option},
		{BUY_SOMETHING,input_condition_func_return_wait_for_user,WAIT_FOR_OPTION,output_func_wait_for_option},
		{ADD_PRODUCT,input_condition_func_return_wait_for_user,WAIT_FOR_OPTION,output_func_wait_for_option},
		{ADD_MONEY,input_condition_func_return_wait_for_user,WAIT_FOR_OPTION,output_func_wait_for_option},
		{-1, NULL, -1, NULL },
};

nevera_fsm_t* new_nevera_fsm(fsm_trans_t* nevera_transition_table){
	nevera_fsm_t* nevera_fsm = (nevera_fsm_t*)malloc(sizeof(nevera_fsm_t));
	nevera_fsm->fsm.tt = nevera_transition_table;
	nevera_fsm->fsm.current_state = START;
	nevera_fsm->lista_usuarios = usuario_list_init();
	nevera_fsm->lista_productos  = producto_list_init();
	nevera_fsm->db = load_db(nevera_fsm->lista_usuarios,nevera_fsm->lista_productos);
	return nevera_fsm;
}

int delete_nevera_fsm(nevera_fsm_t* nevera_fsm){
	commit_db(nevera_fsm->db,nevera_fsm->lista_usuarios,nevera_fsm->lista_productos);
	close_db(nevera_fsm->db);
	usuario_list_delete(nevera_fsm->lista_usuarios);
	producto_list_delete(nevera_fsm->lista_productos);
	free(nevera_fsm);
	return 0;
}

static int input_condition_func_start(fsm_t* fsm){
	return 1;
}
static int input_condition_func_wait_for_option(fsm_t* fsm){
	nevera_fsm_t* nevera = (nevera_fsm_t*)fsm;
	if(nevera->option_selected == -1)
		return 1;
	return 0;
}
static int input_condition_func_add_money(fsm_t* fsm){
	nevera_fsm_t* nevera = (nevera_fsm_t*)fsm;
	if(nevera->option_selected == 1)
		return 1;
	return 0;
}
static int input_condition_func_check_money(fsm_t* fsm){
	nevera_fsm_t* nevera = (nevera_fsm_t*) fsm;
	if (nevera->option_selected == 2)
		return 1;
	return 0;
}
static int input_condition_func_buy_something(fsm_t* fsm){
	nevera_fsm_t* nevera = (nevera_fsm_t*) fsm;
	if (nevera->option_selected == 3)
		return 1;
	return 0;
}
static int input_condition_func_add_product(fsm_t* fsm){
	nevera_fsm_t* nevera = (nevera_fsm_t*) fsm;
	if (nevera->option_selected == -1)
		return 1;
	return 0;
}
static int input_condition_func_return_wait_for_user(fsm_t* fsm){
	nevera_fsm_t* nevera = (nevera_fsm_t*) fsm;
	if (nevera->option_selected == 4)
		nevera->user_selected = NULL;
		return 1;
	return 0;
}

//OUTPUT FUNCTIONS
//TODO Declaración de funciones OUTPUT de la máquina de estados. Se ejecutan cuando se alcanza el estado.
static void output_func_wait_for_user(fsm_t* fsm){
		nevera_fsm_t* nevera = (nevera_fsm_t*) fsm;
		display_user_menu();
		nevera->intro = scan_chain(10);
		nevera->user_selected = usuario_list_search(nevera->lista_usuarios,atoi(nevera->intro));
		nevera->option_selected = -1;
		nevera->intro = "";
}

static void output_func_wait_for_option(fsm_t* fsm){
	int option = -1;
	nevera_fsm_t* nevera = (nevera_fsm_t*) fsm;
	display_options_menu();
	while(1){
		option = scan_num();
		if(option > 0 && option < 5)
			break;
	}

	nevera->option_selected = option;
}

static void output_func_add_money(fsm_t* fsm){
	nevera_fsm_t* nevera = (nevera_fsm_t*) fsm;
	add_saldo(nevera->user_selected,scan_float());
	nevera->option_selected = -1;
}
static void output_func_check_money(fsm_t* fsm){
	nevera_fsm_t* nevera = (nevera_fsm_t*) fsm;
	display_check_money_menu(nevera->user_selected);
	scan_key();
	nevera->option_selected = -1;
}

static void output_func_buy_something(fsm_t* fsm){
	nevera_fsm_t* nevera = (nevera_fsm_t*) fsm;
	int i = 0;
	char* intro = (char*)malloc(10*sizeof(char));
	int max = producto_list_get_max_id(nevera->lista_productos);

	intro = "";
	display_clear();


	for(i = 1;  ;i += 3){
			if(i > max)
				i = 1;
			display_buy_menu(nevera->lista_productos,i);
			intro = scan_chain_stop(10);
			if(strcmp(intro,"*") != 0){
				break;
			}
		}
		if(buy_stuff(nevera,atoi(intro)))
			nevera->option_selected = -1;

	free(intro);

}
static void output_func_add_product(fsm_t* fsm){

}

//Extra
int buy_stuff(nevera_fsm_t* nevera,int id){
	product_t* comprado = producto_list_search(nevera->lista_productos,id);
	if(comprado != NULL){
		add_saldo(nevera->user_selected,-producto_get_precio(comprado));
		return 1;
	}
	printf("ID de producto erroneo");
	return 0;
}

