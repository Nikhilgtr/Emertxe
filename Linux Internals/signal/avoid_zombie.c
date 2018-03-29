#include "include.h"

int flag,status;
void my_handler(int signum, siginfo_t* info, void *dummy)
{
	wait(&status);
	if(WIFEXITED(status))
	{
		printf("child process terminate with exit code %d\n",WEXITSTATUS(status));
	}	
	flag =1;	/*when child is terminatied then the flag
				 *will become 1
				 */
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
	
	action.sa_flags=SA_SIGINFO; //for accessing the siginfo_t structure the mask must be used

	sigaction(SIGCHLD,&action,NULL);
	
	//forking making the child process	
	pid=fork();

	if(pid>0)
	{
		//parent process
		while(!flag);

		/*NOTE: sigchild is the signal which informs for the child termination by signal*/
	}

	else if(pid==0)
	{
		//child process
		sleep(5);
	}

	else
	{
		perror("fork");
			return 1;
	}

	return 0;
}
	




