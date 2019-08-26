#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  char *str,*arg[15]; 
  int num[15],n,i,id;
 
  n=accept(num);
  printf("\nSORTING ARRAY\n\n");
  selectionSort(num,n);
  printf("\nARRAY SORTED\n\n");
  
  for (i = 0; i < n; i++)
    {  
        printf("%d",num[i]);  
        printf("\t"); 
        sprintf(str,"%d",num[i]);
        arg[i]=malloc(sizeof(str));
        strcpy(arg[i],str);
    }
    printf("\nPARENT ID::%d",getpid());
    printf("\nINVOKING FORK\n\n");
    id=fork();
    
    if(id==0)
    {
       printf("\n\nCHILD ID::%d",getpid());
       printf("\n\nENTERING CHILD PROCESS\n\n");
       execve("./assign2B2",arg,NULL);
       
    }
    else
    {
        printf("\n\nENTERING PARENT PROCESS\n\n"); 
        wait();
        printf("\n\nPARENT PROCESS COMPLETED......PARENT EXITING!!!\n\n");
    }  
}


int accept(int num[10])
{
   int i,n;
   printf("Enter the size of array::");
   scanf("%d",&n);
   
   printf("\n****ENTER THE NUMBERS****");
   for(i=0;i<n;i++)
   {
       printf("\nELEMENT[%d]",i+1);
       scanf("%d",&num[i]);
   }
   return n;
}
void swap(int *x, int *y)  
{  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
}  
  
void selectionSort(int num[], int n)  
{  
    int i, j, min_ind;  
  
     
    for (i = 0; i < n-1; i++)  
    {  
        
        min_ind = i;  
        for (j = i+1; j < n; j++)  
        if (num[j] < num[min_ind])  
            min_ind = j;  
                                           
        swap(&num[min_ind], &num[i]);  
    }  
}

