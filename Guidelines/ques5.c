#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat fs;

    if (argc != 2) {
        printf("Pass filenames as a command-line argument.\n");
        exit(1);
    }

    stat(argv[1], &fs);

    printf("\nUser id is %ld\n", (long)fs.st_uid);
    printf("Group id is %ld\n", (long)fs.st_gid);
    printf("Access permissions are %lo\n", (unsigned long)fs.st_mode);
    printf("Access time is %s\n", ctime(&fs.st_atime));

    exit(0);
}

