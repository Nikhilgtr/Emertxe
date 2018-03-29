#include "include.h"

int flag_p,flag_c;


void my_handler_parent(int signum)
{
	/*flag for parent*/
	flag_p=1;			
}

void my_handler_child(int signum)
{
	/*flag for child*/
	flag_c=1;			
}

int main()
{
	int pid;
	//sigaction structure 
	struct sigaction child, parent;

	//resetting all variable to zero
	memset(&child,0,sizeof(child));
	memset(&parent,0,sizeof(parent));
	
	//registering the handler
	child.sa_handler=my_handler_child;
	parent.sa_handler=my_handler_parent;
	//registration usong sigaction	
	sigaction(SIGUSR2,&child,NULL);
	sigaction(SIGUSR1,&parent,NULL);
	
	//forking making the child process	
	pid=fork();

	if(pid>0)
	{
		/*blocking the parent till signal received*/
		while(!flag_p);
		printf("SIGUSR1 signal is received from Child\n");
		sleep(1);
		/*sending the signal to the child*/
		printf("Sending SIGUSR2 to child\n");
		sleep(1);
		kill(pid,SIGUSR2);
		sleep(1);
		
		exit(0);
		
		/*NOTE: sigchild is the signal which informs for the child termination by signal*/
	}

	else if(pid==0)
	{
		//child process
		/*sending a signal to parent*/
		printf("Sending SIGUSR1 to parent\n");
		sleep(1);
		kill(getppid(),SIGUSR1);
		/*blocking the child till signal received*/
		while(!flag_c);
		printf("SIGUSR2 signal is received from parent\n");

		exit(0);
	}

	else
	{
		perror("fork");
			return 1;
	}

	return 0;
}
	




