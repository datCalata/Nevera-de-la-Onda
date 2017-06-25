#ifndef SRC_MODEL_USUARIOS_H_
#define SRC_MODEL_USUARIOS_H_



#define NAMESIZE 50;

typedef struct usuario{
	int id;
	char* nombre;
	float saldo;
}user_t;

//TODO reformat names

user_t* create_usuario(int id, char* nombre, float saldo);
void set_usuario_name(user_t* user, char* nombre);
void set_usuario_balance(user_t* user, float saldo);
void add_saldo(user_t* user, float cantidad);
void delete_usuario(user_t* user);
void print_usuario(user_t* user);
#endif // !USUARIOS_H_
