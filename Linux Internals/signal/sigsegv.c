#include "include.h"

void my_handler(int signum, siginfo_t* info, void *dummy)
{
	printf("SEGMENTATION FAULT!!\n");
	printf("Address %p caused error!\n",info->si_addr);
	exit(0);
}


int main()
{

	//sigaction structure 
	struct sigaction action;

	//resetting all variable to zero
	memset(&action,0,sizeof(action));
	
	//registering the handler
	action.sa_sigaction=my_handler;
	
	action.sa_flags=SA_SIGINFO; //for accessing the siginfo_t structure the mask must be used

	sigaction(SIGSEGV,&action,NULL);
	//accessing the non exited address to create the segmentation fault
		

		int *ptr=(int*)0x12;  /*prints 0x12 int the address in handler 
							   *because u r accessing the adress which is not existed
							   *in the 32 bit machine
							   */
		*ptr	=12;		//defrecncing the invalid address

//	*((char*)NULL)='s';   //prints nill in the address because u are accessing nil address

	return 0;
}
	




