#include<stdio.h>
#include<stdlib.h>

int main() {
    int ch;
    printf("\nEnter your choice (1/2/3):");
    scanf("%d", &ch);

    switch(ch) {
        case 1:
            printf("\nCPU type & model is:\n");
            system("awk 'NR==5{printf $5}' /proc/cpuinfo");
            printf("\nKernel version is:\n");
            system("cat /proc/sys/kernel/osrelease");
            printf("\nAmount of time the system was last booted:\n");
            system("awk 'NR==1{printf $1}' /proc/uptime");
            break;
        case 2:
            printf("\nTime CPU spent in user mode, system mode & when idle:\n");
            system("awk 'NR==1{printf $2 $4 $5}' /proc/stat");
            printf("\nNumber of accesses made to disk on the system:\n");
            system("awk 'NR==7{printf $2}' /proc/stat");
            printf("\nNumber of context switches kernel has performed:\n");
            system("awk 'NR==8{printf $2}' /proc/stat");
            printf("\nTime at which the system was last booted:\n");
            system("awk 'NR==9{printf $2}' /proc/stat");
            printf("\nNumber of processes created since the system was last booted:\n");
            system("awk 'NR==10{printf $2}' /proc/stat");
            break;
        case 3:
            printf("\nAmount of memory configured in the system:\n");
            system("awk 'NR==4{printf $0}' /proc/meminfo");
            printf("\nMemory currently in the system:\n");
            system("awk 'NR==5{printf $0}' /proc/meminfo");
            break;
        default:
            printf("\nInvalid choice.\n");
    }

    return 0;
}

