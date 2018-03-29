#include "include.h"

#define SIZE 20
#define SMSIZE 30

int main()
{
	pid_t pid;
	key_t key;
	int pipefds[2],shmid;
	char *shm;

	/*key for shared memory*/
	key='A';
	/*Creating Shared memory*/
	if((shmid=shmget(key,SMSIZE,0666))==-1)
	{
		//error checking
		perror("shmget");
		return 1;
	}
	if((pipe(pipefds))==-1)
	{
		//error checking
		perror("pipe");
		return 1;
	}
	printf("SHMID is %d\n",shmid);
	pid=fork();
	
	if(pid>0)
	{

		//parent process
		
		int status,len,i;
		char buff[SIZE];
		close(pipefds[0]);
		/*attching to the shared memory*/
		shm=shmat(shmid,NULL,0);
		/*uppercase to the shared memory data*/	
		len=strlen(shm);	
			for(i=0;i<len;i++)
				{
					//printf("%c\n",shm[i]);
					if(shm[i]>='a'||shm[i]<='z')
					buff[i]=shm[i]-32;	
				}
			buff[i+1]='\0';
			/*pipe to the child*/
		write(pipefds[1],buff,sizeof(buff));
		shmdt(shm);
		wait(&status);

	}	
	else if(pid==0)
	{
		//child process
		close(pipefds[1]);
		char buf[SIZE];
		/*receiving form the parent*/
		read(pipefds[0],buf,sizeof(buf));
		/*attaching to the shared memory*/
		shm=shmat(shmid,NULL,0);
		/*NOTE : when using shared memory with the string always use string copy to copy
		 * data from buffer to shared memry ..... u cant use like shm=buff
		 * beacuse this fails in c to copy string*/
		strcpy(shm,buf);
		shmdt(shm);
	}
	else
	{
		perror("fork");
		return 1;
	}
	return 0;
}

