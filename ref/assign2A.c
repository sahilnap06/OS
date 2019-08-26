#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
    int id,n,n1,num[10],num1[10];
    printf("\n***PARENT ARRAY***\n\n");    
     n=accept(num);
     
     printf("\n***CHILD ARRAY***\n\n");
     n1=accept(num1);
    printf("BEFORE FORK::\n");
    id=fork();
    
    if(id==0)
    { 
       printf("CHILD PROCESS RUNNING::\n");
       printf("CHILD ID::%d\n",getpid());
      
       printf("CHILD'S PARENT::%d\n",getppid());
       
       printf("\nSORTING USING INSERTION SORT\n");
       printf("\n***SORTED CHILD ARRAY***\n");
       insertionSort(num1,n1);
       display(num1,n1);
             
       printf("\nCHILD IS EXITING\n");
       exit(-1);
       
    }
    else
    {
       printf("PARENT PROCESS IS RUNNING::\n\n");
       printf("PARENT ID::%d\n",getpid());   
       printf("PARENT's PARENT ID::%d\n",getppid());
       
       printf("\nSORTING USING SELECTION SORT\n");
       printf("\n***SORTED PARENT ARRAY***\n");
       selectionSort(num,n);
       display(num,n);
       
       wait(NULL);
            
       printf("\nPARENT IS EXITING\n\n");    
       exit(0);
         
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
void insertionSort(int num[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = num[i];  
        j = i - 1;  
  
       
        while (j >= 0 && num[j] > key) 
        {  
            num[j + 1] = num[j];  
            j = j - 1;  
        }  
        num[j + 1] = key;  
    }  
}         
void display(int num[], int n)  
{  
    int i;
      
    for (i = 0; i < n; i++)
    {  
        printf("%d",num[i]);  
      printf("\t"); 
    }  
    printf("\n");
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
   
   
   
