#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() 
{
	int id;
	id = fork();
	if(id == 0) 
	{
		int a1 = getpid();
		int b1 = getppid();

		printf("Child Process..%c", '\n');
		printf("Parent id is: %d %c", a1, '\n');
		printf("Child id is: %d %c", b1, '\n');
	}
	else
	{
		int a2 = getpid();
		int b2 = getppid();
	
		printf("Parent Process..%c", '\n');
		printf("Parent id is: %d %c", a2, '\n');
		printf("Child id is: %d %c", b2, '\n');
	}
	return 0;
}
