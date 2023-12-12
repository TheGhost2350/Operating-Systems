#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int id, a = 10;
    id = fork();
    if (id != 0) {
        a = a + 5;
    } else {
        printf("value of a is %d\n", a);
    }
    return 0;
}

