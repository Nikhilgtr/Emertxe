#include "include.h"

void my_handler(int signum, siginfo_t* info, void *dummy)
{
	printf("Inside SIGINT handler\n");
	
	
//	exit(0); 
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

	sigaction(SIGINT,&action,NULL);
	
	//forking making the child process	
	pid=fork();


	if(pid>0)
	{
		//parent process
		printf("Parent is waiting for the signal\n");
		pause();  //wait for any signal
		/*NOTE: pause wait for any signal and wait(&status) is wait for child to exit */
	
	
	}

	else if(pid==0)
	{
		//child process
		sleep(5);
		printf("Child is sending the signal\n");
		/*child is sending the signal to the parent*/
		kill(getppid(),SIGINT);
		printf("Child sent signal\n");
	}
	else
	{
		perror("fork");
			return 1;
	}

	return 0;
}
	




