#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(void){
    char pathname[200],buffer[2000],input[2000]; //pathname to be taken from the user, path_to_open will be the same, just copied from the pipe
    char* buffer1[2000];
    pid_t cpid;
    int pipefd1[2],pipefd2[2]; //fd1 is used for transfer of pathname
                                //fd2 is used for data transfer
    FILE *fptr;
    printf("Enter the path of the file to read : ");
    scanf("%s",pathname);

    if(pipe(pipefd1)){
        perror("Pipe 1 not created\n");
    }
    if(pipe(pipefd2)){
        perror("Pipe 2 not created\n");
    }

    cpid = fork();

    if(cpid == -1){
        perror("Fork causing error\n");
        exit(EXIT_FAILURE);
    }

    if(cpid > 0){   //parent process started
        //step 1. close the unused read end of the pipe 1
        close(pipefd1[0]);
        
        //step 2. Send the data throught the write end of the pipe
        printf("Parent process is sending the data to the child process\n");
        write(pipefd1[1],&pathname,strlen(pathname));
        printf("The parent process has sent the filename %s throught pipe 1\n",pathname);
        
        //step 3. Close the write end of the pipe
        close(pipefd1[1]);  
        wait(NULL);

        //after the child sends the data
        close(pipefd2[1]);
        read(pipefd2[0],&input,sizeof(input));
        close(pipefd2[0]);

    	fptr = fopen(pathname,"r");
    	fscanf(fptr,"%s",buffer1);

        printf("The file content is %s\n",&buffer1);
        exit(EXIT_SUCCESS);
    }
    else {  
        //child process started
        printf("Into the child process\n");
        
        //step 1. close the unused write end of pipe 1 
        close(pipefd1[1]);

        //step 2. Read the pathname from the pipe
        printf("Child is reading from the pipe\n");
        read(pipefd1[0],pathname,strlen(pathname)+1);
        close(pipefd1[0]);

        //opening the file
        fptr = fopen(pathname,"a");

        //accept the data from user
        printf("Enter the data to be written : ");
        scanf("%s",input);

       // printf("Input data is '%s'\n",input);

        fprintf(fptr,input);
        fclose(fptr);
        close(pipefd2[0]);
        write(pipefd2[1],&buffer,sizeof(input));
        close(pipefd2[1]);

    }

    return 0;

}
