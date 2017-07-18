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
// hemos tenido que usar la numeraci�n de BCM al inicializar con wiringPiSetupSys
// cuando elige un n�mero PIN diferente, use la numeraci�n de BCM, tambi�n
// en P�ginas de propiedades, seleccione Eventos de compilaci�n > Evento remoto posterior a la compilaci�n y actualice el comando.
// que utiliza la exportaci�n de gpio para la configuraci�n de wiringPiSetupSys
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
#include "src/controller/nevera_controller.h"

void tmp_test(product_list_t* productos_lista,user_list_t* usuarios_lista,sqlite3* db);
void setup();
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


extern fsm_trans_t nevera_transition_table[];


int main() {

	/*product_list_t* productos_lista = NULL;
	user_list_t* usuarios_lista = NULL;
	sqlite3* db = NULL;*/

	setup();

	fsm_t* fsm = (fsm_t*) new_nevera_fsm(nevera_transition_table);


	while(1){
		fsm_fire(fsm);
	}

	/*setup(&productos_lista,&usuarios_lista,&db);
	printf("setUp done");
	fflush(stdout);

	tmp_test(productos_lista,usuarios_lista,db);

	kill(productos_lista,usuarios_lista,db);

	printf("recursos liberados");
	fflush(stdout);*/

	return EXIT_SUCCESS;
}

void setup(){
	wiringPiSetupPhys();
	fd = wiringPiI2CSetup(I2C_ADDR);

	set_up_keypad();
	lcd_init();

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
	int max = producto_list_get_max_id(productos_lista);

	for(i = 1;  ;i += 3){
		if(i > max)
			i = 1;

		display_buy_menu(productos_lista,i);
		intro = scan_chain_stop(10);
		if(strcmp(intro,"*") != 0)
			break;

	}
}

