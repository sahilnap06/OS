#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 69eac82e0a4985ffea2a7d19f504e970f83e8a85
>>>>>>> eb3dd7c3ca0efea0a7c47ace4b6754a5c0e67273
#define MAX_SIZE 5

typedef struct	{
	sem_t full,empty; 
	pthread_mutex_t lock;
	int buffer[MAX_SIZE];
	int in,out;
}BUFFER;

BUFFER b1;

void init(){
	b1.in = b1.out = 0;
	for(int i = 0 ; i < 15;i++){
		b1.buffer[i] = 0;
	}
	pthread_mutex_init(&b1.lock,NULL);
	sem_init(&b1.empty,0,MAX_SIZE);
	sem_init(&b1.full,0,0);
}

void *producer(void *args){
	int z,rand_sleep;
	int thread_number = (int *)args;
	while(1){
		sem_wait(&b1.empty);	//locks empty semaphore if not zero
		pthread_mutex_lock(&b1.lock);	//locks the mutex
		
		z = rand() % 15;
		printf("The producer thread number %d -->> produced %d\n (|)",thread_number,z);

		b1.buffer[(b1.in++)%MAX_SIZE] = z;

		printf("The buffer is :: ");	
		for(int i = 0; i < MAX_SIZE;i++){
			printf("%d\t",b1.buffer[i]);
		} 	
		printf("\n");
		
		pthread_mutex_unlock(&b1.lock);
		sem_post(&b1.full);	

		rand_sleep = rand()%6; 
		//printf("The producer number %d -->> sleeping for %d units.\n ",thread_number,rand_sleep);
		sleep(rand_sleep);
		
			
	}//end while
}

void *consumer(void *args){
	int thread_number,rand_sleep;
	int consumed;
	thread_number = (int *)args;

	while (1)	{
		sem_wait(&b1.full);
		pthread_mutex_lock(&b1.lock);

		consumed = b1.buffer[(b1.out++)%MAX_SIZE];
		printf("The consumer thread number %d -->> consumed %d\n (X)",thread_number,consumed);


		pthread_mutex_unlock(&b1.lock);
		sem_post(&b1.empty);	

		rand_sleep = rand()%6;
		printf("The consumer number %d is sleeping for %d units\n",thread_number,rand_sleep);
		sleep(rand_sleep);	
	}
}	

main() {
	int cno,pno;
	pthread_t pid[10],cid[10];
	printf("Enter the number of producers :: ");
	scanf("%d",&pno);
	printf("Enter the number of consumers :: ");
	scanf("%d",&cno);

	init();

	for(int i = 0;i<pno;i++){
		pthread_create(&pid[i],NULL,*producer,i+1);
		printf("Thread for producer %d created\n",i+1);
	}

	for(int j = 0;j<cno;j++){
		pthread_create(&cid[j],NULL,*consumer,j+1);
		printf("Thread for consumer %d created\n",j+1);
	}

	for(int i = 0;i<pno;i++){
		pthread_join(pid[i],NULL);
	}
	
	for(int i = 0;i<cno;i++){
		pthread_join(cid[i],NULL);
	}
	return 0;
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
=======
#define MAX_SIZE 15

semaphore full,empty; 
pthread_mutex_t lock;
int buffer[MAX_SIZE];
int front = 0;rear = MAX_SIZE - 1;

void *producer(void *args){
	int thread_number = (int *)args;
	sem_wait(&empty);
>>>>>>> f15935e0a61bbb79b8965847e23bbdb1e43262b7
>>>>>>> 69eac82e0a4985ffea2a7d19f504e970f83e8a85
>>>>>>> eb3dd7c3ca0efea0a7c47ace4b6754a5c0e67273
}
