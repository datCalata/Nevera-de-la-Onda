#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <sqlite3.h>
#include "src/model/usuarios.h"
#include <string.h>
#include "src/controller/dbController.h"
#include "src/model/userlinkedlist.h"


#define GPIO_R1 29
#define GPIO_R2 31
#define GPIO_R3 33
#define GPIO_R4 37

#define GPIO_C1 32
#define GPIO_C2 36
#define GPIO_C3 38
#define GPIO_C4 40

#define MAX_PIN 4

int main() {

	int row_pin[] = {GPIO_R1,GPIO_R2,GPIO_R3,GPIO_R4};
	int col_pin[] = {GPIO_C1,GPIO_C2,GPIO_C3,GPIO_C4};
	char key[MAX_PIN][MAX_PIN];
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

	int i, j;

	wiringPiSetupPhys();

	for (i = 0; i < MAX_PIN; i++){
			pinMode(col_pin[i], INPUT);
			pullUpDnControl(col_pin[i], PUD_UP);
	}

	for (i = 0; i < MAX_PIN; i++){
			pinMode(row_pin[i], INPUT);
			pullUpDnControl(row_pin[i], PUD_OFF);
	}

	while (1){
			for (i = 0; i < MAX_PIN; i++){
				pinMode(row_pin[i], OUTPUT);
				digitalWrite(row_pin[i], LOW);

				for(j = 0; j <	MAX_PIN; j++){
					if (!digitalRead(col_pin[j])){
						printf("%c \n",key[i][j]);
						fflush(stdout);
						while(!digitalRead(col_pin[j])){
							delay(1);
						}
					}
				}

				pinMode(row_pin[i], INPUT);
				pullUpDnControl(row_pin[i], PUD_OFF);
			}
		}

}



