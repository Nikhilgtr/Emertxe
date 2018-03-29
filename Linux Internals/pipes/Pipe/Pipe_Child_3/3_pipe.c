#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char *argv[])
{

	int pipe_fd[2];
	int pipe_fd1[2];
	int pipe_fd2[2];
	int newfd,fd;
	pid_t pid_child1,pid_child2,pid_child3;
	int i=1,argc_1=0,argc_2=0,argc_3=0,argc_4=0,j=0;
	/* check for argument validity */
	if(argc<8)
	{
		printf("Insufficient arguments passed!\n");
		printf("Usage : ./pipe <command 1> '|' <command 2> '|' <command 3> | <command 4>\n");
		return 1;
	}
	/* get command 1 from cli */
	while(strcmp(argv[i++],"|")!=0)
		argc_1++; 
	char *arg_1[argc_1+1];
	for(i=1;i<argc_1+1;i++)
	{
		arg_1[i-1]=argv[i];
	}
	arg_1[i-1]=NULL;

	/* get command 2 from cli */
	i=argc_1+2;
	while(strcmp(argv[i++],"|")!=0)
		argc_2++;
	char *arg_2[argc_2+1];
	for(i=argc_1+2;strcmp(argv[i],"|")!=0;i++)
	{
		arg_2[j]=argv[i];
		j++;
	}
	arg_2[j]=NULL;
	j=0;

	/* get command 3 from cli */
	i=argc_1+argc_2+3;
	while(strcmp(argv[i++],"|")!=0)
		argc_3++;
	char *arg_3[argc_3+1];
	for(i=argc_1+argc_2+3;strcmp(argv[i],"|")!=0;i++)
	{
		arg_3[j]=argv[i];
		j++;
	}
	arg_3[j]=NULL;
	j=0;

	/* get command 4 from cli */
	i=argc_1+argc_2+argc_3+4;
	while(argv[i++]!=NULL)
		argc_4++;
	char *arg_4[argc_4+1];
	j=0;
	for(i=argc_1+argc_2+argc_3+4;i<argc;i++)
	{
		arg_4[j]=argv[i];
		j++;
	}
	arg_4[j]=NULL;

	/* create a pipe to communicate between related processes */
	pipe(pipe_fd);
	pipe(pipe_fd1);
	pipe(pipe_fd2);

	/* creating child 1 */
	pid_child1=fork();
	{
		switch(pid_child1)
		{
			/* failure */
			case -1:
				perror("fork");
				return 1;
				break;

				/* child 1 (command 1) */
			case 0:
				/* close pipe ends that are not required */
				close(pipe_fd1[0]);
				close(pipe_fd1[1]);	
				close(pipe_fd2[0]);
				close(pipe_fd2[1]);
				close(pipe_fd[0]);
				/* closing stdout */
				close(1);
				/* duplicating fd to redirect stdout */
				newfd=dup(pipe_fd[1]);
				/* execute command 1*/
				execvp(arg_1[0],arg_1);
				perror("exec fail");
				return 1;

			default:
				wait(NULL);
				/* creating child 2 */
				pid_child2=fork();

				switch(pid_child2)
				{
					/* failure */
					case -1:
						perror("fork");
						return 1;

						/* child 2 (command 2) */
					case 0:
						/* close pipe ends that are not required */
						close(pipe_fd[1]);
						close(pipe_fd2[0]);
						close(pipe_fd2[1]);
						close(pipe_fd1[0]);
						/* close stdin */
						close(0);
						/* duplicate fd to redirect stdin */
						newfd=dup(pipe_fd[0]);
						/* close stdout */
						close(1);
						/* duplicate fd to redirect stdout */
						newfd=dup(pipe_fd1[1]);
						/* execute command 2 */
						execvp(arg_2[0],arg_2);
						perror("exec fail");
						return 1;
						break;

						/* parent */
					default :
						close(pipe_fd[1]);
						wait(NULL);
						/* creating child 3 */
						pid_child3=fork();

						switch (pid_child3)
						{   
							/* failure */
							case -1:
								perror("fork");
								return 1;

								/* child 3 (command 3) */	
							case 0:
								/* close pipe ends that are not required */
								close(pipe_fd1[1]);
								close(pipe_fd2[0]);
								close(pipe_fd[0]);
								close(0);
								/* duplicate fd to redirect stdin */
								newfd=dup(pipe_fd1[0]);
								close(1);
								/* duplicate fd to redirect stdout */
								newfd=dup(pipe_fd2[1]);
								execvp(arg_3[0],arg_3);
								perror("exec fail");
								return 1;
								break;
								/* parent (command 4)*/
							default:
								close(pipe_fd[0]);
								close(pipe_fd1[0]);
								close(pipe_fd1[1]);
								close(pipe_fd2[1]);
								wait(NULL);
								close(0);
								/* duplicate fd to redirect stdin */
								newfd=dup(pipe_fd2[0]);
								execvp(arg_4[0],arg_4);
								perror("exec fail");
								return 1;
						}
				}
		}
	}
}
