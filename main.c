/*#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <sqlite3.h>
#include "src/model/usuarios.h"
#include <string.h>
#include "src/controller/dbController.h"
#include "src/model/userlinkedlist.h"
#include "src/controller/keypad.h"
#include "src/view/display.h"
#include "src/view/lcd.h"
*/


// PIN de LED: el PIN 0 de wiringPi es BCM_GPIO 17.
// hemos tenido que usar la numeración de BCM al inicializar con wiringPiSetupSys
// cuando elige un número PIN diferente, use la numeración de BCM, también
// en Páginas de propiedades, seleccione Eventos de compilación > Evento remoto posterior a la compilación y actualice el comando.
// que utiliza la exportación de gpio para la configuración de wiringPiSetupSys
#define	LED	4

#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

#include "src/view/lcd.h"
#include "src/model/productlinkedlist.h"
#include "src/model/userlinkedlist.h"
#include "src/controller/dbController.h"
#include "src/controller/keypad.h"
#include "src/view/display.h"


void tmp_test(product_list_t* productos_lista,user_list_t* usuarios_lista,sqlite3* db);
void setup(product_list_t* productos_lista,user_list_t* usuarios_lista,sqlite3* db);
void kill(product_list_t* productos_lista,user_list_t* usuarios_lista,sqlite3* db);

/*int main() {
	int i = 0;
	char c;
	char* intro;
	product_list_t* productos_lista = NULL;
	user_list_t* usuarios_lista = NULL;
	sqlite3* db = NULL;



	if (wiringPiSetupPhys() == -1) exit(1);

	fd = wiringPiI2CSetup(I2C_ADDR);

	//printf("fd = %d ", fd);

	lcd_init(); // setup LCD
	set_up_keypad();

	productos_lista = producto_list_init();
	usuarios_lista = usuario_list_init();
	db = load_db(usuarios_lista, productos_lista);


	c = scan_key();

	printf("%c \n",c);

	for(i = 1; i < producto_list_get_max_id(productos_lista);i += 3){
		display_buy_menu(productos_lista,i);
		intro = scan_chain_stop(10);
		if(strcmp(intro,"*") != 0){
			break;
		}
	}



	close_db(db);
	usuario_list_delete(usuarios_lista);
	producto_list_delete(productos_lista);

	return 0;

}*/




int main() {

	product_list_t* productos_lista = NULL;
	user_list_t* usuarios_lista = NULL;
	sqlite3* db = NULL;

	wiringPiSetupPhys();

	set_up_keypad();


	fd = wiringPiI2CSetup(I2C_ADDR);

	lcd_init();

	productos_lista = producto_list_init();
	usuarios_lista = usuario_list_init();
	db = load_db(usuarios_lista, productos_lista);
	printf("setUp done");
	fflush(stdout);

	int i = 0;
	char* intro;

	for(i = 1; ;i += 3){
		if(i >= producto_list_get_max_id(productos_lista)){
			i = 1;
		}
		display_buy_menu(productos_lista,i);
		intro = scan_chain_stop(10);
		if(strcmp(intro,"*") != 0){
			break;
		}
	}

	close_db(db);
	usuario_list_delete(usuarios_lista);
	producto_list_delete(productos_lista);

	printf("recursos liberados");
	fflush(stdout);

	return EXIT_SUCCESS;
}

void setup(product_list_t* productos_lista,user_list_t* usuarios_lista,sqlite3* db){
	wiringPiSetupPhys();
	fd = wiringPiI2CSetup(I2C_ADDR);

	set_up_keypad();
	lcd_init();


	productos_lista = producto_list_init();
	usuarios_lista = usuario_list_init();
	db = load_db(usuarios_lista, productos_lista);
	printf("setUp done");
	fflush(stdout);
}

void kill(product_list_t* productos_lista,user_list_t* usuarios_lista,sqlite3* db){
	close_db(db);
	usuario_list_delete(usuarios_lista);
	producto_list_delete(productos_lista);
}

void tmp_test(product_list_t* productos_lista,user_list_t* usuarios_lista,sqlite3* db){

	int i = 0;
	char* intro;

	for(i = 1; i < producto_list_get_max_id(productos_lista);i += 3){
		display_buy_menu(productos_lista,i);
		intro = scan_chain_stop(10);
		if(strcmp(intro,"*") != 0){
			break;
		}
	}
}

