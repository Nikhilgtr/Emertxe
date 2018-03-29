#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
	int cpid=fork();
	if(cpid <0)
	{
		//error handling for fork
		perror("fork");
		return 1;
	}
	else if(cpid==0)
	{
		//child process will work here
		printf("Child process id is %d\n",getpid());
		exit(0);
	}
	else
	{
			//parent process will work here
		int cpid2=fork();
	if(cpid2 <0)
	{
		perror("fork");
		return 1;
	}
	else if(cpid2 == 0)
	{
		//child process will wok here
		printf("Child process id is %d\n",getpid());
		exit(0);
	}
	else
	{
		//parent process wil work here
		 int cpid3=fork();
		if(cpid3<0)
		{
			perror("fork");
			return 1;
		}
		else if(cpid3==0)
		{
			//child process will work here
			printf("Child process id is %d\n",getpid());
		exit(0);
		}
		else
		{
			//parent function to printing the values of the child id and exitstatus
			int status;
			int wpid;
			int i;
			sleep(2);
			for(i=0;i<3;i++)
			{
				wpid=wait(&status);
				if(WEXITSTATUS(wpid))
				{
					printf("Child process %d is ended with the status %d\n",wpid,WEXITSTATUS(status));
				}
			}
		}
		
	}
	
	}
return 0;
}
