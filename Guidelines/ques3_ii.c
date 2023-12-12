#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t childId = fork();

    if (childId == 0) {
        printf("Child: Process ID - %d\n", getpid());
        printf("Child: Different code execution in the child process\n");
    } else {
        // Parent process
        printf("Parent: Process ID - %d\n", getpid());
        printf("Parent: Different code execution in the parent process\n");
    }

    return 0;
}

