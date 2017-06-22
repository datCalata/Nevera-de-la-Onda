#include "usuarios.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




user_t* createUsuario(int id, char* nombre, float saldo) {
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

void setUsuarioName(user_t* user, char* nombre) {
	if (user == NULL) {
		perror("El usuario no ha sido creado");
	}
	user->nombre =  nombre;
}

void setUsuarioMoney(user_t* user, float saldo) {
	if (user == NULL) {
		perror("El usuario no ha sido creado");
	}
	user->saldo = saldo;
}

void addSaldo(user_t* user, float cantidad) {
	if (user == NULL) {
		perror("El usuario no ha sido creado");
	}
	user->saldo += cantidad;
}

void deleteUsuario(user_t* user) {
	free(user->nombre);
	free(user);
}
void printUsuario(user_t* user){
	printf("%d %s %f \n",user->id,user->nombre,user->saldo);
}
