#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int id;

    id = fork();

    if (id < 0) {
        printf("Error\n");
        exit(0);
    } else if (id == 0) {
        printf("Fork is successful\n");
        printf("Child's PID is %d\n", getpid());
        exit(1);
    }

    return 0;
}

