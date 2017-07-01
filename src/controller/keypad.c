/*
 * keypad.c
 *
 *  Created on: 27 jun. 2017
 *      Author: jcala
 */

#include "keypad.h"

void debounce_delay(int debounce,int pin);

void debounce_delay(int debounce, int pin){
	while (!digitalRead(col_pin[pin])) {
		delay(debounce);
	}
}

char* scan_key() {
	int i = 0;
		int j = 0;
		char result;
		char* result_str = (char*)malloc(2*sizeof(char));

		while (j != -1) {
			for (i = 0; i < MAX_PIN && j != -1; i++) {
				pinMode(row_pin[i], OUTPUT);
				digitalWrite(row_pin[i], LOW);
				for (j = 0; j < MAX_PIN; j++) {
					if (!digitalRead(col_pin[j])) {
						result = key[i][j];
						printf("%c \n", result);
						fflush(stdout);
						debounce_delay(1, j);
						j = -1;
						break;
					}
				}
				pinMode(row_pin[i], INPUT);
				pullUpDnControl(row_pin[i], PUD_OFF);
			}
		}

		result_str[0] = result;
		result_str[1] = '\0';
		return result_str;

}

char* scan_chain(int max_length) {
	char* chain = (char*)malloc(max_length*sizeof(char));
	strcpy(chain,"");
	char* tmp;
	while (strcmp((tmp = scan_key()), "A") != 0 && strlen(chain) < max_length) {
		strcat(chain, tmp);
		printf("Lleva presionado %s \n",chain);
		free(tmp);
	}
	return chain;
}

char* scan_chain_stop(int max_length) {
	char* chain = (char*)malloc(max_length*sizeof(char));
	char* tmp;
	char* displn;
	int cmp;

	strcpy(chain,"");

	while (strcmp((tmp = scan_key()), "A") != 0 && strlen(chain) < max_length){
		cmp =strcmp(tmp,"*");
		if(cmp == 0){
			free(chain);
			printf("salgo de pantalla \n");
			fflush(stdout);
			return tmp;
		}
		strcat(chain, tmp);
		printf("Lleva presionado %s \n",chain);
		sprintf(displn,"Ha elegido: %s",chain);
		display_write_last(displn);
		fflush(stdout);
		free(tmp);
	}
	return chain;
}

void set_up_keypad() {

	int i;

	row_pin[0] = GPIO_R1;
	row_pin[1] = GPIO_R2;
	row_pin[2] = GPIO_R3;
	row_pin[3] = GPIO_R4;

	col_pin[0] = GPIO_C1;
	col_pin[1] = GPIO_C2;
	col_pin[2] = GPIO_C3;
	col_pin[3] = GPIO_C4;

	for (i = 0; i < MAX_PIN; i++) {
		pinMode(col_pin[i], INPUT);
		pullUpDnControl(col_pin[i], PUD_UP);
	}

	for (i = 0; i < MAX_PIN; i++) {
		pinMode(row_pin[i], INPUT);
		pullUpDnControl(row_pin[i], PUD_OFF);
	}


	key[0][0] = '1';
	key[0][1] = '2';
	key[0][2] = '3';
	key[0][3] = 'A';
	key[1][0] = '4';
	key[1][1] = '5';
	key[1][2] = '6';
	key[1][3] = 'B';
	key[2][0] = '7';
	key[2][1] = '8';
	key[2][2] = '9';
	key[2][3] = 'C';
	key[3][0] = '*';
	key[3][1] = '0';
	key[3][2] = '#';
	key[3][3] = 'D';


}
