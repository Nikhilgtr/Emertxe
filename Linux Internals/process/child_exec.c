#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define SIZE 1024

int main(int argc, char *argv[])
{

	pid_t child_pid;
	int status,i;
	char *arr[SIZE];

	for(i=1;i<argc;i++)
	{
		arr[i-1]=argv[i];
	}
	arr[i]=NULL;
	
	if(argc<2)
	{
		printf("USAGE: ./exe_child <args>\n");
		return 1;
	}
		
	child_pid = fork();
        /* If its > 0 its parent process */ 	
	if (child_pid > 0)
	{
		//parent process
		wait(&status);
		sleep(2);
		if(WIFEXITED(status))
		printf("Child exited with code %d\n", WEXITSTATUS(status));
		else
		{
			printf("Child Terminated abnormally\n");
			printf("Child exited with code %d\n",WTERMSIG(status));
		}

	}
	/* If its zero then its child process */
	else if (child_pid == 0) 
	{
		printf("This is the CHILD process, with id %d\n",getpid());
		printf ("Child invoking %s ...\n\n",argv[1]);
		//execlp(argv[1],argv[1], NULL);
		execvp(argv[1],arr);
		exit(0);
	
	}
	else
	{
		perror("fork");
	}
	return 0;
}
