#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>
void *reader(int *ar);
void *writer(int *ar);
sem_t wrt;
pthread_mutex_t work_mutex;
int i,a[5]={0},in=0,inr=0;
int read1=0;
#define WORK_SIZE 2048
int main() 
{
   int w,r,j,res=0;
   pthread_t wth[4];
   pthread_t rth[4];
   printf("\nEnter no of readers");
   scanf("%d",&r);
   printf("\nEnter no of writers");
   scanf("%d",&w);
   res=sem_init(&wrt,0,1);
   if (res != 0) 
  {
       perror("WRT Semaphore initialization failed");
       exit(EXIT_FAILURE);
  }
  res=pthread_mutex_init(&work_mutex,NULL);
  if (res != 0) 
  {
      perror("MUTEX Semaphore initialization failed");
      exit(EXIT_FAILURE);
  }
  for(j=0;j<w;j++) 
  {
      res = pthread_create(&(wth[j]), NULL, writer,(int*)j);
     //sleep(rand()%4);
      if (res != 0) 
      {
          perror("Thread creation failed");
          exit(EXIT_FAILURE);
      }
  }
  for(j=0;j<r;j++) 
 {
      res = pthread_create(&(rth[j]), NULL, reader,(int*)j);
      // sleep(rand()%4);
      if (res != 0) 
   {
       perror("Thread creation failed");
       exit(EXIT_FAILURE);
   }
 }
 printf("\nWaiting for thread to finish...\n");
  for(j=0;j<w;j++)
 {
     res = pthread_join(wth[j], NULL);
     if (res != 0) 
   {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
   }
 }
 for(j=0;j<r;j++)
 {
    res = pthread_join(rth[j], NULL);
	if (res != 0) 
	{
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
 }
 exit(EXIT_SUCCESS);
 return 0;
}

void *reader(int *ar)
{
    int k=0,r;
    //int thread_numb=*(int*)ar;
    while(1)
    {
       printf("\n\nReader %d wants to read\n ",ar);
       pthread_mutex_lock(&work_mutex);
       read1++;
       if(read1==1)
        sem_wait(&wrt);
       pthread_mutex_unlock(&work_mutex);
       //in = (in++)%5;
       printf("\nReader %d is reading item %d\n",ar,a[k]);
       //in++;
       pthread_mutex_lock(&work_mutex);
       read1--;
       printf("\n\n Reader's Queue is:\n ");
     //sleep(rand()%10);
       for(r=0;r<5;r++)
       {
          //if(a[r]!=0)
       		printf(" %d ",a[r]);

       }
       sleep(10);
       if(read1==0)
       sem_post(&wrt);
       pthread_mutex_unlock(&work_mutex);
       printf("\nReader %d has read successfully ",ar);
      k++;
      
    }
pthread_exit(NULL);
}

void *writer(int *ar)
{
int k,r=0;
    while(1)
    {
       printf("\n\nWriter %d wants to write \n",ar);
      //sleep(1);
       sem_wait(&wrt);
       a[in]=rand()%10;
       printf("\nWriter %d is writing %d th item\n",ar,a[in]);
       in++;
         //r=a[k];
        // a[r]=0;
        printf("\n\n Writer's Queue is:\n ");
       for(r=0;r<5;r++)
       {
          //if(a[r]!=0)
       		printf(" %d ",a[r]);
       }
       printf("\n");
       sem_post(&wrt);
       printf("\nWriter %d has written successfully\n",ar);
       //sleep(rand()%10);
     
    }
    pthread_exit(NULL);
}
