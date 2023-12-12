#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t childId = fork();

    if (childId == 0) {
        printf("Child: Process ID - %d\n", getpid());
    } else {
        printf("Parent: Process ID - %d\n", getpid());
    }

    return 0;
}

