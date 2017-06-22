#ifndef USUARIOS_H_
#define USUARIOS_H_



#define NAMESIZE 50;

typedef struct usuario{
	int id;
	char* nombre;
	float saldo;
}user_t;

user_t* createUsuario(int id, char* nombre, float saldo);
void setUsuarioName(user_t* user, char* nombre);
void setUsuarioMoney(user_t* user, float saldo);
void addSaldo(user_t* user, float cantidad);
void deleteUsuario(user_t* user);
void printUsuario(user_t* user);
#endif // !USUARIOS_H_
