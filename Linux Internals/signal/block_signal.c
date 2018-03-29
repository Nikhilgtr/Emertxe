#include"include.h"

int flag;
/*handler*/
void my_handler(int signum)
{	
	flag=1;
	/*printing the pid*/
	printf("PID IS %d\n",getpid());
	printf("SIGINT INITIATED\n");
	/*using loop to retain inn the handler and to check
	 *the signal handling*/
	while(1)
	{
		printf("In Handler\n");
		sleep(2);
	}
}



int main()
{
	sigset_t t;  //datatype sigset_t is used for masking
	/*structure for sigaction*/
	struct sigaction action;
	/*adding siganls in sigset*/
	sigaddset(&t,SIGUSR1);
	sigaddset(&t,SIGABRT);
	sigaddset(&t,SIGUSR2);
	sigaddset(&t,SIGSEGV);

	/*clearing the memory and reset it to zero*/
	memset(&action,0,sizeof(action));
	/*registering the handler*/
	action.sa_handler=my_handler;
	action.sa_mask=t;
	sigaction(SIGINT,&action,NULL);
	/*blocking the parent*/
	while(!flag);

	exit(0);
}
	

