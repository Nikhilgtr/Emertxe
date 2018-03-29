#include "include.h"

int main()
{
	pid_t pid;

	pid=vfork();

	if(pid==0)
	{
		//child process
		
			printf("Child is running\n");
			sleep(5);
			exit(0);
	}
	else
	{
		//parent process

		printf("Parent is exited\n");
		sleep(1);
	exit(0);	
	}
	return 0;

}


