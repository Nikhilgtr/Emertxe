#include "include.h"

int main()
{
	/*PROTOTYPE FOR WAIT3:
	
 	pid_t wait3(int *status, int options,struct rusage *rusage);

	*/
	pid_t pid;

	pid=fork();

	if(pid==0)
	{
		//child process
		printf("Child is running\n");
		sleep(2);
		exit(0);
	}
	else
	{
		//parent process
		int status;
		pid_t wpid;
		int option;
		struct rusage x;

		wpid = wait3(&status,option, &x);
			sleep(1);
			printf("************RESOURCE DATA************\n");
			printf("Integral shared memory size = %lu\n",x.ru_ixrss);
			printf("Maximum resident set size = %lu\n",x.ru_maxrss);
			printf("Integral unshared data size = %lu\n",x.ru_idrss);
			printf("Integral unshared stack size = %lu\n",x.ru_isrss);
			printf("Page reclaims = %lu\n",x.ru_minflt);
			printf("Page faults = %lu\n",x.ru_majflt);
			printf("Swaps = %lu\n",x.ru_nswap);
			printf("Block input operations = %lu\n",x.ru_inblock);
			printf("Block output operations = %lu\n",x.ru_oublock);
			printf("IPC message sent = %lu\n",x.ru_msgsnd);
			printf("IPC message received = %lu\n",x.ru_msgrcv);
			printf("Signal received = %lu\n",x.ru_nsignals);
			printf("Voluntary context switches = %lu\n",x.ru_nvcsw);
			printf("Involuntary context switches  = %lu\n",x.ru_nivcsw);

		sleep(1);
		exit(0);
			


	}
	return 0;
}

		

