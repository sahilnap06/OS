#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define SIZE 10

int number;
long int factorial = 1;
int t=1;


void *calcFact(void *arg) 
{
	int i,min,mod, *rcArgs, z;
	long int return_val=1;  
	int max;
	
	rcArgs = (int *) arg;
	min = rcArgs[0]*10;
	mod = rcArgs[1];
	if(mod == 0) {mod = 10;}
	max = min+mod;
	
	printf("\nThread No %d joined",t);
	for(i=min+1;i<=max;i++)
	{
		
		printf("\n%d - Thread No %d - Calculated %ld x %d = %ld ----> %ld",t,i%10,return_val,i,return_val*i,return_val);
		return_val *= i;
		z=rand()%10;
		printf("\n%d - Thread No %d - Paused........Sleeping for %d units",t,i%10,z);
		sleep(z);
		printf("\n%d - Thread No %d - .......Resumed",t,i%10);
		t++;
	}
	//return ((void *) return_val);
	printf("\n...........Thread No %d .......exits",(i%10)-1);
	pthread_exit((void *) return_val);
}

int main() {
	int rcArgs[2];
	int i,*status;
	pthread_t P[SIZE];
	int mod,mul;
	
	printf("Enter the number to calculate factorial of :: ");
	scanf("%d",&number);
	
	mod = number % 10;
	mul = number / 10;
	
	for(i = 0; i < mul;i++){
		if(mod == 0){
			rcArgs[0] = i;
			rcArgs[1] = mod;
		}
		else {
			if(i == mul){
				rcArgs[0] = i;
				rcArgs[1] = mod;
			}
			else{
				rcArgs[0] = i;
				rcArgs[1] = 0;
			}
		}
		if(pthread_create(&P[i],NULL,calcFact,rcArgs) != 0){
			printf("Cannot create the thread\n");
		} 
		else{
			printf("Thread number %d is created\n",i+1);
			sleep(2);
		}
	}
	
	for(i=0;i<=mul;i++) {
		if(pthread_join(P[i],(void **) &status) != 0) perror("\nThread join failed.\n");
		else factorial *= (long int)status;
	}
	
	printf("\nThe factorial is :: \n");
	printf("%ld",factorial);
	printf("\n");
	printf("\n----------------------------\n\n");
	exit(EXIT_SUCCESS);
}
