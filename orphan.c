#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
    int id;
   printf("BEFORE FORK::\n");
    printf("MAIN PROCESS ID::%d\n",getpid());
    //printf("MAIN PROCESS PARENT'S ID::%d\n",getppid());
    
    printf("BEFORE FORK::\n");
    id=fork();
    
    if(id==0)
    {
       printf("\nCHILD PROCESS RUNNING::\n");
       printf("CHILD ID::%d\n",getpid());
       printf("CHILD'S PARENT::%d\n",getppid());
       printf("CHILD IS SLEEPING::\n");
       sleep(20);
       printf("\nCHILD WAKE UP::\n");
       printf("CHILD ID::%d\n",getpid());
       printf("CHILD'S PARENT::%d\n",getppid());
       //exit(0);
    }
    else
    {
       printf("\nPARENT PROCESS IS RUNNING::\n");
       printf("PARENT ID::%d\n",getpid());
       //printf("PARENT's PARENT ID::%d\n",getppid()); 
       printf("PARENT IS SLEEPING::\n");
       sleep(5);
       printf("\nPARENT EXITING\n");
       exit(-1);
         
    }    
}    
