
#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>

int main()
{
	int pid = fork();
	if(pid<0)
	{
		fprintf(stderr, "Fork is failed");
	}
	else if(pid == 0)
	{
		execlp("/home/file1.out", "file1.out", NULL);
	}
	else
	{
	wait(NULL);
	printf("The Fork Process is Completed!");
	}
	return 0;
}
