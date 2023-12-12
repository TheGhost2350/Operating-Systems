#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int id;
    id = fork();

    if (id < 0) {
        printf("Error\n");
        exit(0);
    } else if (id == 0) {
        execlp("/bin/ls", "ls", NULL);
    } else {
        wait(NULL);
        printf("Child completes\n");
    }

    return 0;
}

