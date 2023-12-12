#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t childId = fork();

    if (childId == 0) {
        printf("Child: Process ID - %d\n", getpid());
        printf("Child: Task execution complete\n");
    } else {
        printf("Parent: Process ID - %d\n", getpid());
        wait(NULL);
        printf("Parent: Child's task completed, now terminating\n");
    }

    return 0;
}

