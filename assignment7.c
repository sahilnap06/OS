#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(void) {
    int pipefd[2];
    pid_t cpid;
    char buf[300];
    printf("Enter the Message : ");
    scanf("%s",buf);
    pipefd[0] = open("file1.txt",O_RDONLY|O_CREAT);
    pipefd[1] = open("file2.txt",O_WRONLY|O_CREAT);

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    cpid = fork();
    if (cpid == -1) {   //if fork is unsuccessful
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {        /* Child reads from pipe */
        close(pipefd[1]);          /* Close unused write end */
	printf("Child process has started");
        while (read(pipefd[0], &buf, strlen(buf)) > 0)
            write(STDOUT_FILENO, &buf, 1);
            write(STDOUT_FILENO, "\n", 1);
            close(pipefd[0]);
            exit(EXIT_SUCCESS);
    }
    else {            /* Parent writes argv[1] to pipe */
        close(pipefd[0]);          /* Close unused read end */
        write(pipefd[1], &buf, strlen(buf));
        close(pipefd[1]);          /* Reader will see EOF */
        wait(NULL);                /* Wait for child */
        exit(EXIT_SUCCESS);
    }
}
