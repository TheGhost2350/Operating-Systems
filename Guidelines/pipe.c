#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#define buffersize 25
#define readend 0
#define writeend 1

int main(void) {
    char writemsg[buffersize] = "greetings";
    char readmsg[buffersize];
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        fprintf(stderr, "pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "fork failed");
        return 1;
    }

    if (pid > 0) {
        printf("Parent is writing %s \n", writemsg);
        close(fd[readend]);
        write(fd[writeend], writemsg, strlen(writemsg) + 1);
        close(fd[writeend]);
    } else {
        close(fd[writeend]);
        read(fd[readend], readmsg, buffersize);
        printf("Child has read %s", readmsg);
        close(fd[readend]);
    }

    return 0;
}

