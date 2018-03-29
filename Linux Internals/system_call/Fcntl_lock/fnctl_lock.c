#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int fd;
	struct flock lock;	
	char buff_1[]="Parent process got lock\n";
	char buff_2[]="Child process got lock\n";
	pid_t child_pid;

	/* check for file passed as command line argument */
	if(argc==1)
	{
		printf("INFO : Please Provide file name as command line argument!\n");
		return 1;
	}

	fd=open(argv[1],O_WRONLY|O_CREAT,0666);
		/* initiate duplication */
	child_pid=fork();

	/* child process */
	if(child_pid == 0)
	{
		/* open file */

		/* check for failure in opening of file */
		if(fd==-1)
		{
			printf("FILE : %s\n",argv[1]);
			perror("File open");
			return 1;
		}
		else
			printf("INFO : Opening %s\n",argv[1]);

		/* set lock parameters */
		lock.l_type=F_WRLCK;
		lock.l_whence=SEEK_SET;
		lock.l_start=0;
		lock.l_len=0;

		if(fcntl(fd,F_GETLK,&lock)==-1)
			perror("fcntl");
		else
			printf("INFO : Lock status acquired!!\n");

//		printf("lock type %d\n",lock.l_type);
		/* check if lock already set */
		if(lock.l_type==F_UNLCK)
		{
			printf("INFO : File locked by child process!!\n");
			/* set lock */
			lock.l_type=F_WRLCK;

			if(fcntl(fd,F_SETLK,&lock)==-1)
			{
				perror("lock");
				close(fd);
				return 1;
			}
			else
				printf("INFO : Lock set for child process!!\n");
		}
		/* lock not set */
		else
		{
			/* set lock */
			lock.l_type=F_WRLCK;
			if(fcntl(fd,F_SETLKW,&lock)==-1)
			{
				perror("lock");
				close(fd);
				return 1;
			}
			else
				printf("INFO : Lock set for child process!!\n");
		}

		/* write into file */
		if(write(fd,buff_2,sizeof(buff_2)-1)==-1)
		{
			printf("FILE : %s\n",argv[1]);
			perror("File write");
			return 1;
		}
		else
			printf("INFO : Write Successfull in child process!!\n");
		
//		sleep(5);
		/* reset lock to unclock mode */
		lock.l_type=F_UNLCK;

		/* set unlock */
		if(fcntl(fd,F_SETLK,&lock)==-1)
			perror("fcntl");
		else
			printf("INFO : Lock released by child process!!\n");

	return 0;
	}

	/* parent process */
	else if(child_pid>0)
	{
		/* check for failure in opening file */
//		sleep(2);
		if(fd==-1)
		{
			printf("FILE : %s\n",argv[1]);
			perror("File open");
			return 1;
		}
		printf("INFO : Opening %s\n",argv[1]);/* set lock parameters */
		lock.l_type=F_WRLCK;
		lock.l_whence=SEEK_SET;
		lock.l_start=0;
		lock.l_len=sizeof(buff_1)-1;

		/* set lock on file */
		if(fcntl(fd,F_SETLK,&lock)==-1)
			perror("fcntl");
		else
			printf("INFO : Lock set in parent process!!\n");

		/* write into file */
		if(write(fd,buff_1,sizeof(buff_1)-1)==-1)
		{
			printf("FILE : %s\n",argv[1]);
			perror("File write");
			return 1;
		}
		else
			printf("INFO : Writing into file in parent process...\n");
			
		printf("INFO : Writing into file in parent process complete...\n");
		sleep(5);

		/* reset lock to unclock mode */
		lock.l_type=F_UNLCK;

		/* set unlock */
		if(fcntl(fd,F_SETLK,&lock)==-1)
			perror("fcntl");
		else
			printf("INFO : Lock released by parent process!!\n");
		return 0;
	}

	else
	{
		perror("fork");
		return 1;
	}
}
