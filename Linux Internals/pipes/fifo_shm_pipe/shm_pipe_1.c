#include "include.h"

#define SIZE 20
#define SMSIZE 30

void swap(char ,char );
int main()
{
	pid_t pid;
	key_t key;
	int pipefd[2],shmid,op,fd;
	char str[SIZE], conti='y';
	char *shm;
	/*path for temporary fifo*/
	char *path="/tmp/myfifo";
	/*key for shared memory*/
	char buff[SIZE];
	key='A';
	/*Creating Shared memory*/
	if((shmid=shmget(key,SMSIZE,IPC_CREAT|0666))==-1)
	{
		//error checking
		perror("shmget");
		return 1;
	}
	if((pipe(pipefd))==-1)
	{
		//error checking
		perror("pipe");
		return 1;
	}

	pid=fork();
printf("SHMID is %d\n",shmid);	
	if(pid>0)
	{

		//parent process
		
		int status;
		close(pipefd[0]);
		do
		{
			printf("Enter Your Choice\n");
			printf("\t1.Write\n\t2.Read\n");
			scanf("%d",&op);
			switch(op)
			{
				case 1:
				/*Input from user*/
				printf("Enter the string\n");
				scanf("%s",str);
			
				/*writing to the pipe*/
				write(pipefd[1],str,sizeof(str));
				/*waiting for child*/
				wait(&status);
				break;

				case 2:
				/*reading from fifo*/			
				fd=open(path,O_RDONLY);
				read(fd,buff,sizeof(buff));	
				
				printf("String is \"%s\"\n",buff);
				break;
			}
			printf("Are you want to continue\n");
			scanf("\n%c",&conti);
		}while(conti=='y'||conti=='Y');

	}	
	else if(pid==0)
	{
		//child process
		close(pipefd[1]);
		char buf[SIZE], temp[SIZE];
		int i,len;
		/*receiving form the parent*/
		read(pipefd[0],buf,sizeof(buf));
		/*reversing the string*/
		len=strlen(buf);
		for(i=0;i<len;i++)
		{
			temp[i]=buf[len-i-1];
			
		}
		temp[i]='\0';
	
		/*attaching to the shared memory*/
		shm=shmat(shmid,NULL,0);
			//shm=buf;
			/*NOTE : when using shared memory with the string always use string copy to copy
 			* data from buffer to shared memry ..... u cant use like shm=buff
			 * beacuse this fails in c to copy string*/
		strcpy(shm,temp);
		shmdt(shm);
	//	printf("str %s\n",buf);
	}
	else
	{
		perror("fork");
		return 1;
	}
	return 0;
}

