#include "include.h"

int flag_1,flag_2,flag_3,count_1=1,count_2=1,count_3=1;

void my_handler(int signum, siginfo_t* info, void *dummy)
{
	/*flags for individual signals*/
	if(signum==SIGUSR2)
		flag_1=1;			
	if(signum==SIGUSR1)
		flag_2=1;
	if(signum==SIGINT)
		flag_3=1;
}

int main()
{
	int pid;
	//sigaction structure 
	struct sigaction action;

	//resetting all variable to zero
	memset(&action,0,sizeof(action));
	
	//registering the handler
	action.sa_sigaction=my_handler;
	
	
	//forking making the child process	
	pid=fork();
	if(pid>0)
	{
	//registering the signals	
		sigaction(SIGINT,&action,NULL);
		sigaction(SIGUSR1,&action,NULL);
		sigaction(SIGUSR2,&action,NULL);
	/*blocking the parent till all three signal is received*/
		while(!(flag_3&&flag_2&&flag_1))
		{
			if(flag_1&&count_1)
			{
				printf("SIGUSR2 is Received\n");
				count_1=0;
			}
			if(flag_2&&count_2)
			{
				printf("SIGUSR1 is Received\n");
				count_2=0;
			}
			if(flag_3&&count_3)
			{
				printf("SIGINT is Received\n");
				count_3=0;
			}
		}
		sleep(1);
		printf("Parent is unblocked pid is %d\n",getpid());	
		
		exit(0);
		
		/*NOTE: sigchild is the signal which informs for the child termination by signal*/
	}

	else if(pid==0)
	{
		//child process
		kill(getppid(),SIGUSR2);
		sleep(1);
		kill(getppid(),SIGUSR1);
		sleep(1);
		kill(getppid(),SIGINT);
		sleep(1);

		exit(0);
	}

	else
	{
		perror("fork");
			return 1;
	}

	return 0;
}
	




