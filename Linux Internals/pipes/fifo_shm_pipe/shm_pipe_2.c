#include "include.h"

#define SIZE 20
#define SMSIZE 30

int main()
{
	pid_t pid;
	key_t key;
	int pipefds[2],shmid,read_count;
	char *shm;
	/*path for tmeporary named fifo*/
	char *path="/tmp/myfifo";
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
			buff[i]='\0';
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
		int fd;
		/*receiving form the parent*/
		read_count=read(pipefds[0],buf,sizeof(buf));
		/*attaching to the shared memory*/
		if((mkfifo(path,0666))==-1)
		{
			perror("myfifo");
			return 1;
		}
		/*opening the fifo*/
		fd=open(path,O_WRONLY);
		/*writing to fifo*/
		write(fd,buf,sizeof(buf));
		
	}
	else
	{
		perror("fork");
		return 1;
	}
	return 0;
}

