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
#include "../model/usuarios.h"
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
	fsm_t* fsm;
	sqlite3* db;
	user_list_t* lista_usuarios;
	product_list_t* lista_productos;
	user_t* user_selected;
	char* intro;
	int option_selected;
}nevera_fsm_t;

nevera_fsm_t* new_nevera_fsm(fsm_trans_t* nevera_transition_table);
int delete_nevera_fsm(nevera_fsm_t* nevera_fsm);


#endif /* SRC_CONTROLLER_NEVERA_CONTROLLER_H_ */
