/*
 * main.c
 *
 *  Created on: 19 jun. 2017
 *      Author: jcala
 */
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <sqlite3.h>
#include "src/model/usuarios.h"
#include <string.h>
#include "src/controller/dbController.h"
#include "src/model/userlinkedlist.h"
int n = 0;



int main() {
	user_list_t* lista;
	sqlite3* db;
	user_t* user;

	lista = usuario_list_init();
	db = load_db(lista);
	usuario_list_print(lista);

	user = create_usuario(usuario_list_get_max_id(lista)+1,"Prueba",100);
	usuario_list_push_element(lista, user);
	usuario_list_print(lista);
	write_user_list_db(db,lista);
	usuario_list_delete(lista);
	close_db(db);
	return 0;
}

