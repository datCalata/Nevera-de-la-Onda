/*
 * threads.h
 *
 *  Created on: 1 jul. 2017
 *      Author: jcala
 */

#ifndef SRC_THREADS_H_
#define SRC_THREADS_H_

#include <pthread.h>


pthread_mutex_t wait_key_mutex;
pthread_cond_t wait_key_threshold_cv;

int wait_button_press;
int wait_button_exit;
char* read_text;


#endif /* SRC_THREADS_H_ */
