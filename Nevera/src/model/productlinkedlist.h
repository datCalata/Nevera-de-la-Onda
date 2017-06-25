/*
 * productlinkedlist.h
 *
 *  Created on: 25 jun. 2017
 *      Author: jcala
 */

#ifndef SRC_MODEL_PRODUCTLINKEDLIST_H_
#define SRC_MODEL_PRODUCTLINKEDLIST_H_

#include "producto.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct product_list {
	product_t* product;
	struct product_list* next;
}product_list_t;

product_list_t* producto_list_init(void);
int producto_list_delete(product_list_t* producto_list);
int producto_list_push_element(product_list_t* producto_list,product_t* producto);
product_t* producto_list_search(product_list_t* producto_list,int id);
void producto_list_print(product_list_t* producto_list);
int producto_list_get_max_id(product_list_t* producto_list);

//Metodos de iteracion y acceso externo
int producto_list_has_next(product_list_t* producto_list);
product_list_t* producto_list_next(product_list_t* producto_list);

#endif /* SRC_MODEL_PRODUCTLINKEDLIST_H_ */
