#ifndef DBCONTROLLER_H_
#define DBCONTROLLER_H_

#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../model/userlinkedlist.h"
#include "../model/usuarios.h"
#include "../model/productlinkedlist.h"
#include "../model/producto.h"

sqlite3* load_db(user_list_t* list,product_list_t* product_list);
void close_db(sqlite3* db);
int insert_db_user(sqlite3* db,user_t* user);
int delete_db_user(sqlite3* db,user_t* user);
int insert_db_product(sqlite3* db);
int delete_db_product(sqlite3* db);
int write_user_list_db(sqlite3* db,user_list_t* list);

//TODO: hacerla
int commit_db(sqlite3* db, user_list_t* lista_usuarios, product_list_t* lista_productos);

#endif
