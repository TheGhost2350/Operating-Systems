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
    } else {
        printf("Fork successful\n");

        if (id == 0) {
            printf("Child\n");
            exit(0);
        } else {
            printf("Parent\n");
            wait(NULL);
            exit(0);
        }
    }

    return 0;
}

