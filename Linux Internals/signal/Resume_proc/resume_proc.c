#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>	
#include<sys/wait.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>

int flag;

void handler(int signum,siginfo_t *info,void *dummy)
{
	flag=1;
	printf("in handler\n");
	signal(SIGTSTP,SIG_DFL);
}

int main(int argc,char *argv[])
{
	char *args[argc],*input;
	int i;
	for(i=0;i<argc;i++)
		args[i]=argv[i+1];
	args[i]=NULL;
	pid_t child_pid;
	/* declaring handler */
	struct sigaction proc_handler;
	sigset_t blk_sig;
	/* clearing handler */
	memset(&proc_handler,0,sizeof(proc_handler));
	/* creating a duplicate child process */
	child_pid=fork();
	switch(child_pid)
	{
		/* failure */
		case -1:
			perror("fork");
			return 1;
		/* child */ 
		case 0:
			execvp(args[0],args);
						break;
		default:
		/* parent */	
			proc_handler.sa_sigaction=handler;
			sigaction(SIGTSTP,&proc_handler,NULL);
			while(!flag);
			  printf("paused!!");
			break;
	}
	return 0;
}
