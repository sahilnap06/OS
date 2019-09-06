#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (phil_num + 4)%5
#define RIGHT (phil_num + 1)%5

int state[N];
int phil[] = {0,1,2,3,4};
int times_eaten[] = {0,0,0,0,0};

sem_t mutex;
sem_t S[N];

void test(int phil_num){
    if(state[phil_num]== HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING){
        state[phil_num] = EATING;
        sleep(2);
        printf("(|) Philosopher %d takes fork %d and fork %d.\n",phil_num+1,LEFT+1,RIGHT);
        times_eaten[phil_num]++;
        printf("Philosopher %d is eating.\n",phil_num+1);
        printf("Starvation :::: \n+============================================================+\n");
        for(int i  = 0; i< N;i++){
            printf("%d\t",i+1);
        }
        printf("\n");
        for(int i =0 ;i<N;i++){
            printf("%d\t",times_eaten[i]);
        }
        printf("\n+============================================================+\n");
        
        sem_post(&S[phil_num]);
    }
    
}

void take_fork(int phil_num){
    sem_wait(&mutex);

    state[phil_num] = HUNGRY;
    printf("Philosopher number %d is hungry.\n",phil_num+1);
    test(phil_num);
    sem_post(&mutex);
    sleep(1); 
}

void put_fork(int phil_num){
    sem_wait(&mutex);
    state[phil_num] = THINKING;
    printf("(X) Philosopher %d put the fork %d and fork %d down.\n",phil_num+1,LEFT+1,RIGHT);
    printf("Philosopher %d is thinking.\n",phil_num+1);
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}

void *philosopher(void *num){
    while(1){
        int *phil_num = num;
        sleep(1);
        take_fork(*phil_num);
        sleep(1);
        put_fork(*phil_num);
    }
}

int main(){
    pthread_t philosophers[N];
    int i;
    sem_init(&mutex,0,1);
    for(i = 0 ; i< N;i++){
        sem_init(&S[i],0,0);
    }
    for(i = 0; i < N;i++){
        pthread_create(&philosophers[i],NULL,philosopher,&phil[i]);
        printf("Philosopher %d is thinking\n",i+1);     
    }    
    for(i =  0 ; i < N;i++){
        pthread_join(philosophers[i],NULL);
    }
    printf("Starvation:::: ");
    for(i = 0 ; i < N;i++){
        printf("%d\t",times_eaten[i]);
    }
    return 0;
}