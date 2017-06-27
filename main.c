#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <sqlite3.h>
#include "src/model/usuarios.h"
#include <string.h>
#include "src/controller/dbController.h"
#include "src/model/userlinkedlist.h"
#include "src/controller/keypad.h"
#include "src/view/lcd.h"

int main() {

	if (wiringPiSetup() == -1) exit(1);

	fd = wiringPiI2CSetup(I2C_ADDR);

	//printf("fd = %d ", fd);

	lcd_init(); // setup LCD

	char array1[] = "Hello world!";

	while (1) {
		lcdLoc(LINE3);
		typeln("Hola");
		delay(4000);
		lcdLoc(LINE1);
		typeln("Using wiringPi");
		lcdLoc(LINE2);
		typeln("Geany editor.");

		delay(2000);
		ClrLcd();
		lcdLoc(LINE1);
		typeln("I2c  Programmed");
		lcdLoc(LINE2);
		typeln("in C not Python.");

		delay(2000);
		ClrLcd();
		lcdLoc(LINE1);
		typeln("Arduino like");
		lcdLoc(LINE2);
		typeln("fast and easy.");

		delay(2000);
		ClrLcd();
		lcdLoc(LINE1);
		typeln(array1);

		delay(2000);
		ClrLcd(); // defaults LINE1
		typeln("Int  ");
		int value = 20125;
		typeInt(value);

		delay(2000);
		lcdLoc(LINE2);
		typeln("Float ");
		float FloatVal = 10045.25989;
		typeFloat(FloatVal);
		delay(2000);
	}


	return EXIT_SUCCESS;
}



