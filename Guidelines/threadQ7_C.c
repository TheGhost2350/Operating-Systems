#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int fact;

void *runner(void *param);

int main(int argc, char *argv[]) {
    pthread_t tid;
    pthread_attr_t attr;

    if (argc != 2) {
        fprintf(stderr, "usage: a.out <integer value>\n");
        return -1;
    }

    if (atoi(argv[1]) < 0) {
        fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
        return -1;
    }

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);
    pthread_join(tid, NULL);

    return 0;
}

void *runner(void *param) {
    int i, upper = atoi(param);
    int n, first = 0, second = 1, next;

    for (i = 0; i < upper; i++) {
        if (i <= 1)
            next = i;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d\n", next);
    }

    pthread_exit(0);
}

