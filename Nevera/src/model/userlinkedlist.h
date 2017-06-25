#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "usuarios.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct usuario_list {
	user_t* user;
	struct usuario_list* next;
}user_list_t;

user_list_t* usuario_list_init(void);
int usuario_list_delete(user_list_t* usuario_list);
int usuario_list_push_element(user_list_t* usuario_list,user_t* user);
user_t* usuario_list_search(user_list_t* usuario_list,int id);
void usuario_list_print(user_list_t* usuario_list);
int usuario_list_get_max_id(user_list_t* usuario_list);

//Metodos de iteracion y acceso externo
int usuario_list_has_next(user_list_t* usuario_list);
user_list_t* usuario_list_next(user_list_t* usuario_list);


#endif // !USUARIOS_H_
