#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

int main()
{
	int cpid;
	int status;

	cpid =fork();

	if(cpid < 0)
	{
		printf("Error: fork() failed");
		return 1;
	}
	else if (cpid == 0)
	{
		//child process
		//exit child process
		sleep(5);
		exit(0);
		
	}
	else
	{
		//parent process
		int wpid;
		do
		{
			// check if child is exited or terminated
			wpid = waitpid(cpid, &status, WNOHANG);
			if(wpid == 0)
			{
				printf("parent is running...\n");
			}
			sleep(1);
			
		}while(wpid == 0);	

		//check exit status of child
		if(WIFEXITED(status))
		{
			printf("Child %d terminated normally with exit status %d \n", cpid, WEXITSTATUS(status));
		}
		exit(1);
	}
	return 0;
}
