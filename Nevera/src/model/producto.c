#include "producto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

product_t* create_producto(int id, char* nombre, int stock){
	product_t* product = (product_t*)malloc(sizeof(product_t));
	char* name = (char*)malloc(50*sizeof(char));
	if (product == NULL) {
		perror("Error al reservar memoria");
		return NULL;
	}
	strcpy(name,nombre);
	product->id = id;
	product->nombre = name;
	product->stock = stock;
	return product;
}

void set_prducto_name(product_t* product, char* nombre){
	if (product == NULL) {
		perror("El producto no ha sido creado");
	}
	free(product->nombre);
	char* name = (char*)malloc(50*sizeof(char));
	strcpy(name,nombre);
	product->nombre =  name;
}

void set_producto_stock(product_t* product, int stock){
	if (product == NULL) {
		perror("El producto no ha sido creado");
	}
	product->stock = stock;
}
void add_stock(product_t* product, int stock){
	if (product == NULL) {
		perror("El producto no ha sido creado");
	}
	product->stock += stock;

}
void delete_producto(product_t* product){
	free(product->nombre);
	free(product);
}
void print_producto(product_t* product){
	printf("%d %s %d \n",product->id,product->nombre,product->stock);
}
