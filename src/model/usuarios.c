#include "usuarios.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


user_t* create_usuario(int id, char* nombre, float saldo) {
	user_t* user = (user_t*)malloc(sizeof(user_t));
	char* name = (char*)malloc(50*sizeof(char));
	if (user == NULL) {
		perror("Error al reservar memoria");
		return NULL;
	}
	strcpy(name,nombre);
	user->id = id;
	user->nombre = name;
	user->saldo = saldo;
	return user;
}

void set_usuario_name(user_t* user, char* nombre) {
	if (user == NULL) {
		perror("El usuario no ha sido creado");
	}
	free(user->nombre);
	char* name = (char*)malloc(50*sizeof(char));
	strcpy(name,nombre);
	user->nombre =  nombre;
}

void set_usuario_balance(user_t* user, float saldo) {
	if (user == NULL) {
		perror("El usuario no ha sido creado");
	}
	user->saldo = saldo;
}

void add_saldo(user_t* user, float cantidad) {
	if (user == NULL) {
		perror("El usuario no ha sido creado");
	}
	user->saldo += cantidad;
}

void delete_usuario(user_t* user) {
	free(user->nombre);
	free(user);
}
void print_usuario(user_t* user){
	printf("%d %s %f \n",user->id,user->nombre,user->saldo);
}
