#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>




int main()
{
	int id,a1,b1;
	id = fork();


	if(id == 0)
	{
		a1 = getpid();
		b1 = getppid();
		printf("Child ID: %d\n" , a1);
		printf("Child's Parent ID: %d\n" , b1);
	}
	else{
		a1 = getpid();
		b1 = getppid();
		printf("Parent ID: %d\n" , a1);
		printf("Parent's Parent ID: %d\n" , b1);
	}
	return 0;
} 


