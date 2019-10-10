#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define SIZE 10

int A[SIZE][SIZE], B[SIZE][SIZE];
long int C[SIZE][SIZE];
int t=1;


void *mul_thread(void *arg) 
{
	int i, k, row, col, *rcArgs, z;
	long int return_val=0; 
	rcArgs = (int *) arg;
	row = rcArgs[0];
	col = rcArgs[1];
<<<<<<< HEAD
	k = rcArgs[2];
=======
<<<<<<< HEAD
	k = rcArgs[2];
=======
<<<<<<< HEAD
	k = rcArgs[2];
=======
	k	= rcArgs[2];
>>>>>>> f15935e0a61bbb79b8965847e23bbdb1e43262b7
>>>>>>> 69eac82e0a4985ffea2a7d19f504e970f83e8a85
>>>>>>> eb3dd7c3ca0efea0a7c47ace4b6754a5c0e67273
	printf("\n\tThread No %d-%d joined",row+1,col+1);
	for(i=0;i<k;i++)
	{
		return_val = return_val + A[row][i] * B[i][col];
		printf("\n%d - Thread No %d-%d - Calculated %d x %d = %d --> %ld",t,row+1,col+1,A[row][i],B[i][col],A[row][i]*B[i][col],return_val);
		z=rand()%10;
		printf("\n%d - Thread No %d-%d Paused -- Sleeping for %d units",t, row+1,col+1,z);
		sleep(z);
		printf("\n%d - Thread No %d-%d .......Resumed",t, row+1,col+1);
		t++;
	}
	printf("\n...........Thread No %d-%d ............................exits", row+1,col+1);
	pthread_exit((void *) return_val);
}

void accept_matrix(int M[SIZE][SIZE], int rows, int cols) {
	int i, j;
	printf("\n");
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++) 
		{
			printf("Value at [%d][%d]: ",i+1,j+1);
			scanf("%d",&M[i][j]);
		}
	}
}

void display_matrix(int M[SIZE][SIZE], int rows, int cols) 
{
	int i, j;
	printf("\n");	
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			printf("%d  ",M[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int rows_A, cols_A, rows_B, cols_B;
	int rcArgs[3];
	int i, j, k, *status;
	pthread_t P[SIZE][SIZE];
	
	printf("\nEnter no. of rows in matrix A: ");
	scanf("%d",&rows_A);
	printf("Enter no. of columns in matrix A: ");
	scanf("%d",&cols_A);


        printf("\nEnter no. of rows in matrix B: ");
	scanf("%d",&rows_B);
	printf("Enter no. of columns in matrix B: ");
	scanf("%d",&cols_B);

        
	if(cols_A != rows_B) {
		
		printf("\n Matrix multiplication not possible.");
                printf("\nEnter no. of rows in matrix A: ");
		scanf("%d",&rows_A);
		printf("Enter no. of columns in matrix A: ");
		scanf("%d",&cols_A);


        	printf("\nEnter no. of rows in matrix B: ");
		scanf("%d",&rows_B);
		printf("Enter no. of columns in matrix B: ");
		scanf("%d",&cols_B);
	}
       

	accept_matrix(A, rows_A, cols_A);
	accept_matrix(B, rows_B, cols_B);
	
	 
		for(i=0;i<rows_A;i++) 
		{
			for(j=0;j<cols_B;j++) 
			{
				rcArgs[0] = i;
				rcArgs[1] = j;
				rcArgs[2] = cols_A;
					
				if(pthread_create(&P[i][j], NULL, mul_thread, rcArgs) != 0)
					printf("\n\tCannot create thread.\n");
				else
				{
					printf("\n\tThread No %d-%d Created",i+1,j+1);
					sleep(2);
				}
				
			}
		}
	
		
	printf("\n\nMatrix A : \n");
	display_matrix(A, rows_A, cols_A);
	printf("\nMatrix B : \n");
	display_matrix(B, rows_B, cols_B);
	
	for(i=0;i<rows_A;i++) {
		for(j=0;j<cols_B;j++) {
                        {
				if(pthread_join(P[i][j],(void **) &status) != 0)
					perror("\nThread join failed.\n");
				C[i][j] = (long int)status;
			}
		}
	}
	
	printf("\n\nResultant Matrix:\n");
	for(i=0;i<rows_A;i++){
		for(j=0;j<cols_B;j++){
			printf("%ld  ",C[i][j]);
		}
		printf("\n");
	}
	printf("\n------------------------------------------------------\n\n");
	exit(EXIT_SUCCESS);
}
