#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
    int id;
    printf("BEFORE FORK::\n");
    printf("MAIN PROCESS ID::%d\n",getpid());
    //printf("MAIN PROCESS PARENT'S ID::%d\n",getppid());
    
    printf("\nBEFORE FORK::\n");
    
    id=fork();
    printf("\nID=%d\n",id);
    
    if(id==0)
    {
       printf("\nCHILD PROCESS RUNNING::\n");
       printf("CHILD ID::%d\n",getpid());
       printf("CHILD'S PARENT::%d\n",getppid());
       printf("CHILD IS SLEEPING\n");
       sleep(50);
       printf("CHILD WAKE UP\n");
    }
    else
    {
       printf("\nPARENT PROCESS IS RUNNING::\n");
       printf("PARENT ID::%d\n",getpid());
       //printf("PARENT's PARENT ID::%d\n",getppid()); 
       printf("PARENT IS SLEEPING\n");
       sleep(50);
       printf("\nPARENT WAKE UP\n");
         
    }
    printf("\nAFTER FORK::\n");
    
}    
