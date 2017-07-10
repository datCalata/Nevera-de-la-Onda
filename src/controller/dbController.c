#include "dbController.h"

//Internal Functions
void charge_db(sqlite3* db,user_list_t* user_list,product_list_t* product_list);

//CALLBACKS
static int charge_user_db_callback(void *ptr, int argc, char **argv, char** azColName);
static int charge_product_db_callback(void *ptr, int argc, char **argv, char** azColName);
static int insert_user_callback(void *NotUsed, int argc, char **argv, char **azColName);

sqlite3* load_db(user_list_t* user_list,product_list_t* product_list){
	sqlite3* db;
	int rc;

	if((rc = sqlite3_open("onda.db",&db))){
		fprintf(stderr,"No se puede abrir la base de datos %s \n",sqlite3_errmsg(db));
		return NULL;
	}
	fprintf(stdout,"Base de datos abierta \n");
	charge_db(db,user_list,product_list);

	return db;
}

int insert_db_user(sqlite3* db,user_t* user){
	char sql [150] = "";
	char* z_err_msg = NULL;

	sprintf(sql,"INSERT OR REPLACE INTO usuarios (id, nombre, saldo) VALUES (%d,\"%s\",%f) ;",user->id,user->nombre,user->saldo);

	if(sqlite3_exec(db,sql,insert_user_callback, NULL,&z_err_msg)!=SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", z_err_msg);
		sqlite3_free(z_err_msg);
		return 1;
	}
	printf("Introduccion correcta \n");
	return 0;
}

int delete_db_user(sqlite3* db,user_t* user){
	char sql[150] = "";
	char* z_err_msg = NULL;

	sprintf(sql,"DELETE FROM usuarios WHERE id = %d ;",user->id);

	if(sqlite3_exec(db,sql,insert_user_callback, NULL,&z_err_msg) != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", z_err_msg);
		sqlite3_free(z_err_msg);
		return 1;
	}
	printf("Borrado correcto \n");
	return 0;
}

void close_db(sqlite3* db){
	sqlite3_close(db);
}

int commit_db(sqlite3* db, user_list_t* lista_usuarios, product_list_t* lista_productos){
	write_user_list_db(db,lista_usuarios);
	return 1;
}

int write_user_list_db(sqlite3* db,user_list_t* list){
	//aux apunta al segundo elemento porque el primero es la cabecera de la lista
	user_list_t* aux = list->next;
	while(usuario_list_has_next(aux)){
		if(insert_db_user(db,aux->user)){
			fprintf(stderr,"Error volcando lista en la base de datos");
			return 1;
		}
		aux = usuario_list_next(aux);
	}
	return 0;
}



//TODO: escribir en la base de datos de productos

int write_productos_list_db(sqlite3* db,product_list_t* list){
	product_list_t* aux = list->next;
	while(producto_list_has_next(aux)){

	}
}

//In file Functions

void charge_db(sqlite3* db, user_list_t* user_list,product_list_t* product_list){
	char* sql = "SELECT * FROM usuarios";
	char* z_err_msg = NULL;

	if(sqlite3_exec(db,sql,charge_user_db_callback,user_list,&z_err_msg) != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", z_err_msg);
		sqlite3_free(z_err_msg);
		return;
	}

	sql = "SELECT * FROM productos";

	if(sqlite3_exec(db,sql,charge_product_db_callback,product_list,&z_err_msg) != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", z_err_msg);
		sqlite3_free(z_err_msg);
		return;
	}

	printf("Base de datos volcada \n");
}

//CALLBACK FUNTIONS

static int charge_user_db_callback(void *ptr, int argc, char **argv, char** azColName){
	int i;
	int id;
	char* nombre;
	double saldo;
	user_list_t* lista = (user_list_t*) ptr;


	for (i = 0; i < argc; i++) {
		//printf("%s = %s\n", azColName[i], argv[i]);
		if (i == 0) {
			id = atoi(argv[i]);
		} else if (i == 1) {
			nombre = argv[i];
		} else if (i == 2) {
			saldo = atof(argv[i]);
			user_t* user = create_usuario(id, nombre, saldo);
			usuario_list_push_element(lista, user);
		}
	}
	printf("\n");
	return 0;
}

static int charge_product_db_callback(void *ptr, int argc, char **argv, char** azColName){
	int i;
	int id;
	char* nombre;
	float precio;
	int stock;
	product_list_t* lista = (product_list_t*) ptr;


	for (i = 0; i < argc; i++) {
		//printf("%s = %s\n", azColName[i], argv[i]);
		if (i == 0) {
			id = atoi(argv[i]);
		} else if (i == 1) {
			nombre = argv[i];
		} else if (i == 2) {
			precio = atof(argv[i]);
		} else if(i == 3){
			stock = atoi(argv[i]);
			product_t* product = create_producto(id, nombre,precio, stock);
			producto_list_push_element(lista,product);
		}
	}
	printf("\n");
	return 0;
}

static int insert_user_callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      //printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
