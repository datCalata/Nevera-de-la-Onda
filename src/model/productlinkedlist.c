#include "productlinkedlist.h"
#define MAX_ID 1000


product_list_t* producto_list_init(void){
	product_list_t* cola =  (product_list_t*)malloc(sizeof(product_list_t));
	product_list_t* lista =  (product_list_t*)malloc(sizeof(product_list_t));
	lista->product = create_producto(0, "CABECERA",0.0, 0);
	lista->next = cola;
	cola->product = create_producto(MAX_ID,"COLA",0.0,0);
	cola->next = NULL;
	return lista;
}
int producto_list_delete(product_list_t* producto_list){
	product_list_t* aux;
	while (producto_list->next != NULL) {
		aux = producto_list->next;
		producto_list->next = aux->next;
		delete_producto(aux->product);
		free(aux);
	}
	free(producto_list);
	return 1;

}
int producto_list_push_element(product_list_t* producto_list,product_t* producto){
	if(producto->id >= MAX_ID)
		perror("Indice Maximo sobrepasado");

	product_list_t* entry = (product_list_t*)malloc(sizeof(product_list_t));
	product_list_t* actual = producto_list;
	product_list_t* siguiente = producto_list->next;

	while (producto->id > siguiente->product->id) {
	    actual = siguiente;
		siguiente = actual->next;
		printf(siguiente->product->nombre);
		printf(actual->product->nombre);
	}
	entry->product = producto;
	entry->next = siguiente;
	actual->next = entry;
	return 0;
}
product_t* producto_list_search(product_list_t* producto_list,int id){
	product_list_t* actual = producto_list;
	product_list_t* siguiente = producto_list->next;
	while (siguiente->product->id != id) {
		siguiente = siguiente->next;
		actual = siguiente;
		if (siguiente->product->id == MAX_ID) {
			perror("No se ha encontrado al usuario");
			return NULL;
		}
	}
	return siguiente->product;
}
void producto_list_print(product_list_t* producto_list){
	product_list_t* aux = producto_list;
	while(aux != NULL){
		print_producto(aux->product);
		aux = aux->next;
	}
}
int producto_list_get_max_id(product_list_t* producto_list){
	product_list_t* aux = producto_list;
	while(aux->next->product->id != MAX_ID){
		aux = aux->next;
	}
	return aux->product->id;
}

//Metodos de iteracion y acceso externo
int producto_list_has_next(product_list_t* producto_list){
	return !(producto_list->next == NULL);
}
product_list_t* producto_list_next(product_list_t* producto_list){
	return producto_list->next;
}
