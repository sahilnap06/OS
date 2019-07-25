#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

#define MAX_SIZE 15

semaphore full,empty; 
pthread_mutex_t lock;
int buffer[MAX_SIZE];
int front = 0;rear = MAX_SIZE - 1;

void *producer(void *args){
	int thread_number = (int *)args;
	sem_wait(&empty);
}
