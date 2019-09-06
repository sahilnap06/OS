#include <stdlib.h>
#include<stdio.h>
//#include<pthreads.h>

int mat1[10][10],mat2[10][10],mat3[10][10];
void matrixMult(int,int,int);
int r1,r2,c1,c2;

int main(){
	printf("Enter the rows of matrix 1 :");
	scanf("%d",&r1);
	
	printf("Enter the columns of matrix 1 :");
	scanf("%d",&c1);
	
	printf("Enter the rows of matrix 2 : ");
	scanf("%d",&r2);
	
	if(c1 != r2){
		printf("Matrix multiplication is not possible!!\n");
		exit(0);
	}
	
	printf("Enter the columns of matrix 2 : ");
	scanf("%d",&c2);
	
	printf("Enter matrix 1	::\n");
	for(int i = 0; i < r1;i++){
		for(int j = 0; j < c1;j++){
			printf("Enter element matrix1[%d][%d] :: ",i+1,j+1);
			scanf("%d",&mat1[i][j]);
		}
	}
	
	printf("Enter matrix 2	::\n");
	for(int i = 0; i < r2;i++){
		for(int j = 0; j < c2;j++){
			printf("Enter element matrix2[%d][%d] :: ",i+1,j+1);
			scanf("%d",&mat2[i][j]);
		}
	}
	
	for(int i = 0; i < r1;i++){
		for(int j = 0; j < c2;j++){
			mat3[i][j] = 0;
		}
	}
	
	matrixMult(r1,c1,c2);
	
	printf("The multiplied matrix is :: \n");
	
	for(int i = 0; i < r1;i++){
		for(int j = 0; j < c2;j++){
			printf("%d\t",mat3[i][j]);
		}
		printf("\n");
	}
		return 0;
}

void matrixMult(int r1,int c1,int c2){
	int sum = 0;
	for(int i = 0; i < r1;i++){
		for(int j = 0; j < c2;j++){
			for(int k = 0; k<c1;k++){
				sum += mat1[i][k] * mat2[k][j];
				printf("%d",sum);
			}
			mat3[i][j] = sum;
			sum = 0;
		}
	}
	
}
