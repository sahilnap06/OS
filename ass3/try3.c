#include <stdlib.h>
#include<stdio.h>
#include<pthread.h>

int mat1[10][10],mat2[10][10],mat3[10][10];
int r1,r2,c1,c2;

void *matrixMult(void *args){
	int sum = 0,*rcArgs,row,col,k;
	rcArgs = (int *)args;
	row = rcArgs[0];
	col = rcArgs[1];
	k = rcArgs[2];
<<<<<<< HEAD
	print("Thread for %d-%");
	for(int i = 0; i<l; i++ ){
		sum += mat1[row][i] * mat2[i][col];

=======
<<<<<<< HEAD
	print("Thread for %d-%");
	for(int i = 0; i<l; i++ ){
		sum += mat1[row][i] * mat2[i][col];
=======
	while(k--){
		sum += mat1[row][k] * mat2[k][col];
>>>>>>> f15935e0a61bbb79b8965847e23bbdb1e43262b7
		
>>>>>>> 69eac82e0a4985ffea2a7d19f504e970f83e8a85
	}
	mat3[row][col] = sum;
	printf("sum = %d\n",sum);
}


int main(){
	pthread_t threads[10][10];
	int i,j;
	int rcArgs[3];
	printf("Enter the rows of matrix 1 :");
	scanf("%d",&r1);
<<<<<<< HEAD

	printf("Enter the columns of matrix 1 :");
	scanf("%d",&c1);

	printf("Enter the rows of matrix 2 : ");
	scanf("%d",&r2);

=======
	
	printf("Enter the columns of matrix 1 :");
	scanf("%d",&c1);
	
	printf("Enter the rows of matrix 2 : ");
	scanf("%d",&r2);
	
>>>>>>> 69eac82e0a4985ffea2a7d19f504e970f83e8a85
	if(c1 != r2){
		printf("Matrix multiplication is not possible!!\n");
		exit(0);
	}
<<<<<<< HEAD

	printf("Enter the columns of matrix 2 : ");
	scanf("%d",&c2);

=======
	
	printf("Enter the columns of matrix 2 : ");
	scanf("%d",&c2);
	
>>>>>>> 69eac82e0a4985ffea2a7d19f504e970f83e8a85
	printf("Enter matrix 1	::\n");
	for(int i = 0; i < r1;i++){
		for(int j = 0; j < c1;j++){
			printf("Enter element matrix1[%d][%d] :: ",i+1,j+1);
			scanf("%d",&mat1[i][j]);
		}
	}
<<<<<<< HEAD

=======
	
>>>>>>> 69eac82e0a4985ffea2a7d19f504e970f83e8a85
	printf("Enter matrix 2	::\n");
	for(int i = 0; i < r2;i++){
		for(int j = 0; j < c2;j++){
			printf("Enter element matrix2[%d][%d] :: ",i+1,j+1);
			scanf("%d",&mat2[i][j]);
		}
	}
<<<<<<< HEAD

=======
	
>>>>>>> 69eac82e0a4985ffea2a7d19f504e970f83e8a85
	for(int i = 0; i < r1;i++){
		for(int j = 0; j < c2;j++){
			mat3[i][j] = 0;
		}
	}
	i = j =0;
	for(;i<r1;i++){
		for(;j<c2;j++){
			rcArgs[0] = i;
			rcArgs[1] = j;
			rcArgs[2] = c1;
			pthread_create(&threads[i][j], NULL, matrixMult,rcArgs);
		}
	}
<<<<<<< HEAD

	printf("The multiplied matrix is :: \n");

=======
	
	printf("The multiplied matrix is :: \n");
	
>>>>>>> 69eac82e0a4985ffea2a7d19f504e970f83e8a85
	for(int i = 0; i < r1;i++){
		for(int j = 0; j < c2;j++){
			printf("%d\t",mat3[i][j]);
		}
		printf("\n");
	}
		return 0;
}
<<<<<<< HEAD
=======

>>>>>>> 69eac82e0a4985ffea2a7d19f504e970f83e8a85
