/*
 * producto.h
 *
 *  Created on: 25 jun. 2017
 *      Author: jcala
 */

#ifndef SRC_MODEL_PRODUCTO_H_
#define SRC_MODEL_PRODUCTO_H_

#include "producto.h"

typedef struct producto{
	int id;
	char* nombre;
	int stock;
}product_t;

product_t* create_producto(int id, char* nombre, int stock);
void set_prducto_name(product_t* product, char* nombre);
void set_producto_stock(product_t* product, int stock);
void add_stock(product_t* product, int stock);
void delete_producto(product_t* product);
void print_producto(product_t* product);


#endif /* SRC_MODEL_PRODUCTO_H_ */
