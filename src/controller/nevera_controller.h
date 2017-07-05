/*
 * nevera_controller.h
 *
 *  Created on: 5 jul. 2017
 *      Author: calata
 */

#ifndef SRC_CONTROLLER_NEVERA_CONTROLLER_H_
#define SRC_CONTROLLER_NEVERA_CONTROLLER_H_

#include "fsm.h"
#include "dbController.h"
#include "../model/userlinkedlist.h"
#include "../model/productlinkedlist.h"
#include "../view/display.h"

typedef enum fsm_state{
	//TODO: add estados
	START = 0,
	WAIT_FOR_USER = 1,
	WAIT_FOR_OPTION = 2,
	ADD_MONEY = 3,
	CHECK_MONEY = 4,
	BUY_SOMETHING = 5,
	ADD_PRODUCT = 6,
}fsm_state_t;

typedef struct nevera_fsm{
	fsm_t fsm;
	sqlite3* db;
	user_list_t lista_usuarios;
	product_list_t lista_productos;
	char intro[50];
	int option_accepted;
	int option_selected;
	int user_id_selected;
	int return_to_wait_for_user;
	int return_to_wait_for_option;
}nevera_fsm_t;

nevera_fsm_t* new_nevera_fsm(fsm_trans_t* nevera_transition_table);
int delete_nevera_fsm(nevera_fsm_t* nevera_fsm);


#endif /* SRC_CONTROLLER_NEVERA_CONTROLLER_H_ */
