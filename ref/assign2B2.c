#include<stdio.h>

int main(int argc,char *argv[])
{
    int i,num,l=0,mid;
	int h=argc-l;
	int arr[20];
	for(i=0;i<argc;i++)
	{
		arr[i]=atoi(argv[i]); //string to int conversion (stack overflow ref)
		printf("%d\t",arr[i]);
	}
	printf("\n\nEnter number to be searched::");
	scanf("%d",&num);
	
	mid=(l+h)/2;
	
	while(l<h)
	{
		if(num>arr[mid])
		   l=mid+1;
		else if(num<arr[mid])
		   h=mid-1;
		else
		{
			printf("\n\nElement found at %d\n\n",mid+1);   
			break;
		}
		mid=(l+h)/2;
	}
	if(l>=h)
		printf("\n\nElement not found\n\n");		 
	
}
