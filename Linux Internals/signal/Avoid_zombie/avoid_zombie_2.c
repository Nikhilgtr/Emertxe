#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
/* handler for SIGCHILD */
void handler(int signum,siginfo_t *info,void *ptr)
{
	wait(NULL);
	printf("Child %d exited with exit status %d\n",info->si_pid,info->si_status);
//    exit(0);
}

int main()
{
	int status,exit_status;
	pid_t child_pid;
	struct sigaction action;
	action.sa_sigaction=handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags=SA_SIGINFO;
	status=sigaction(SIGCHLD,&action,NULL);

	if(status==-1)
	{
		perror("sigaction");
		return 1;
	}

	child_pid=fork();

	switch(child_pid)
	{
		case -1:
			perror("fork");
			return 1;
			break;
		case 0:
			printf("This is a child process %d\n",getpid());
			exit_status=4;
			break;
		default:
			printf("This is the parent process\n");
			sleep(2);
			exit_status=0;
			break;
	}
	exit(exit_status);
}


    
	
