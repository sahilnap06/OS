#include <pthread.h>
#include <stdio.h>

void *tfunction(void *args)	{
	printf("The ID of the kid is %d !!!\n",getpid());
	printf("The thread is sleeping for 5 seconds!!\n");
	sleep(5);
	printf("The thread woke up!!\n");
}

int main(int argc,char *argv[])	{
	pthread_t thread1;	
	printf("Before thread creation!!!\n");
	pthread_create(&thread1,NULL,tfunction,NULL);
	printf("The thread is created!!\n");
	//printf("Main thread going to sleep\n");
	//sleep(1);
	printf("The ID of this process is %d\n",getpid());
	pthread_join(thread1,NULL);
	printf("Kid has died\n");
	return 0;
}
