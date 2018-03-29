#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <time.h>	
#include <stdio_ext.h>
#include <string.h>
#include <sys/wait.h>
int main()
{
	int fl,i,jj,a,z;
	pid_t pid,pid1;
	char buff[2],buff1[30];
	pid=fork();
	switch(pid)
	{
		case -1:
			perror("fork");
			return 2;
			break;
		case 0:
			sleep(2);
			break;
		default:
			printf(" child process ppid=%d\n",getpid());
			sprintf(buff1,"/proc/%d/status", pid);
			fl=open(buff1, O_RDONLY);
			if(fl!=-1)
			{
				a=1; z=0;
				while(a!=0 && z<3)
				{
					//puts("hi");
					a=read(fl,buff,1);
					write(1,buff,a);
					if(buff[0]=='\n')
						z++;
				}
			}puts("");	
			sleep(4);
			sprintf(buff1,"/proc/%d/status",pid);
			fl=open(buff1,O_RDONLY);
			if(fl!=-1)
			{
				a=1; z=0;
				while(a!=0 && z<3)
				{
					a=read(fl,buff,1);
					write(1,buff,a);
					if(buff[0]=='\n')
						z++;
				}
			}
			i=getpid();
			pid1=fork();
			if(pid1==-1)
			{
				perror("fork");
				return 2;
			}
			else if(pid1==0)
			{
				sleep(6);
				sprintf(buff1,"/proc/%d/status/",i);
				fl=open(buff1,O_RDONLY);
				if(fl==-1)
				{
					printf("Process %d cleared by init\n",i);
					return 3;
				}

				break;
			}
			else if(pid1>0)
			{
			}
			break;
	}
}
