#include "userlinkedlist.h"
#define MAX_ID 1000

user_list_t* usuario_list_init(void){
	user_list_t* cola = (user_list_t*)malloc(sizeof(user_list_t));
	user_list_t* lista = (user_list_t*)malloc(sizeof(user_list_t));
	lista->user = create_usuario(0,"CABECERA",0);
	lista->next = cola;
	cola->user = create_usuario(MAX_ID, "COLA", 0);
	cola->next = NULL;
	return lista;
}

int usuario_list_delete(user_list_t * usuario_list){
	user_list_t* aux;
	while (usuario_list->next != NULL) {
		aux = usuario_list->next;
		usuario_list->next = aux->next;
		delete_usuario(aux->user);
		free(aux);
	}
	free(usuario_list);
	return 1;
}

int usuario_list_push_element(user_list_t* usuario_list, user_t * user){
	if(user->id >= MAX_ID){
		perror("Indice Maximo sobrepasado");

	}
	user_list_t* entry = (user_list_t*)malloc(sizeof(user_list_t));
	user_list_t* actual = usuario_list;
	user_list_t* siguiente = usuario_list->next;

	while (user->id > siguiente->user->id) {
	    actual = siguiente;
		siguiente = actual->next;
		printf(siguiente->user->nombre);
		printf(actual->user->nombre);
	}
	entry->user = user;
	entry->next = siguiente;
	actual->next = entry;
	return 0;
}

user_t* usuario_list_search(user_list_t* usuario_list, int id){
	user_list_t* actual = usuario_list;
	user_list_t* siguiente = usuario_list->next;
	while (siguiente->user->id != id) {
		siguiente = siguiente->next;
		actual = siguiente;
		if (siguiente->user->id == MAX_ID) {
			perror("No se ha encontrado al usuario");
			return NULL;
		}
	}
	return siguiente->user;
}

void usuario_list_print(user_list_t* usuario_list){
	user_list_t* aux = usuario_list;
	while(aux != NULL){
		print_usuario(aux->user);
		aux = aux->next;
	}
}

int usuario_list_get_max_id(user_list_t* usuario_list){
	user_list_t* aux = usuario_list;
	while(aux->next->user->id != MAX_ID){
		aux = aux->next;
	}
	return aux->user->id;
}

int usuario_list_has_next(user_list_t* usuario_list){
	return !(usuario_list->next == NULL);
}

user_list_t* usuario_list_next(user_list_t* usuario_list){
	return usuario_list->next;
}
