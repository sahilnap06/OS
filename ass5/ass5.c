#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t wrt,
FILE *readFromOther,*writeToOther;	//for writers
FILE *reading;	//for readers
int byteNum = 0;
int bytesForReader[15] = {0};

void *writer(void *args){
	int threadno = (int*) args;
	int BytesToRead;
	char buffer[10] = '\0';
	printf("Writer thread %d joined\n",threadno);
	//critical section started....  add the mutexes and semaphores
	while(1){
	
		readFromOther = fopen("article.txt","r");	//opened the article file in read mode
		writeToOther = fopen("common.txt","a");		//opens the common file to write the data to
		
		fseek(readFromOther,byteNum,SEEK_SET);	//moves the read pointer to the starting position to read
		BytesToRead = rand()%10;
		byteNum += BytesToRead;	//store the next position to read from
		printf("Writer thread writing %d bytes\n",BytesToRead);	
		fgets(buffer,BytesToRead,readFromOther); //reads from article
		fputs(buffer,writeToOther);	//write to the file
	fclose(readFromOther);
	fclose(writeToOther);
	}
	//critical section ended... release the semaphores and mutexes

}

void *reader(void *args){
	int threadno = (int *)args;
	int byteNum1 = bytesForReader[threadno];	//gets the last position of the reader
	char buffer[10] = '\0';
	int bytesToRead = rand()%10;	//to read a random number of bytes
	bytesForReader[threadno] += bytesToRead;	//update the position
	printf("Reader thread no. %d joined and reading %d bytes\n",threadno,bytesToRead);
	//critical section started
	while (1)	{
		reading = fopen("common.txt","r");
		fseek(reading,byteNum1,SEEK_SET);
		fgets(buffer,bytesToRead,reading);
		printf("Reader %d read %s\n",buffer);
		fclose(reading);
	}
	//critical section ended
}

int main()
{
	int w,r;
	pthread_t writers[15];
	pthread_t readers[15];
	printf("Enter the number of writers :: ");
	scanf("%d",&w);
	printf("Enter the number of readers :: ");
	scanf("%d",&r);
	for(int i = 0; i< w;i++){
		pthread_create(writers[i],NULL,writer,(void*)i);
		sleep(rand()%4);
	}
	for(int j = 0; j < r;j++){
		pthread_create(readers[j],NULL,reader,(void*)j);
		sleep(rand()%4);
	}
	return 0;
}
