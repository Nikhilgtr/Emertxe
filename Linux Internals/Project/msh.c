#include "msh.h"

/*PROTOTYPES*/
void print_prompt();
void welcomeScreen();
int exec();
void single_system_commands();
void builtin_commands();

/*GLOBAL VARIABLES*/
char *c_list_built_in[6]={"exit","echo","mkdir","cd","pwd","rmdir"};
char PS1[]="Nikhil@hp";
char *h_dir="/media/sf_Ubuntu/linux_internal/Project";
int status_exit;
char *Buffer[SIZE];
int sigint_flag,sigstp_flag;
char *args[SIZE];

/*SIGNAL HANDLER*/
void sigint_handler(int signum)
{
	sigint_flag=1;
}

void sigstp_handler(int signum)
{
	sigstp_flag=1;
}

int main()
{/*SIGNAL HANDLING*/
	struct sigaction sigint,sigstp;
	memset(&sigint,0,sizeof(sigint));
	memset(&sigstp,0,sizeof(sigstp));

	sigint.sa_handler=sigint_handler;
	sigstp.sa_handler=sigstp_handler;

	sigaction(SIGINT,&sigint,NULL);
	sigaction(SIGTSTP,&sigstp,NULL);

	system("clear");
	welcomeScreen();
	sleep(2);
	system("clear");
	while(1)
    {

        print_prompt();

		switch(exec())
		{
			case 0:
			    single_system_commands();
				break;
			case 2:
			    builtin_commands();
			    break;
            case 1:
                break;
			default:
				printf("Command Not Found\n");
		}
	}
system("clear");
}

/*WELCOME SCREEN*/
void welcomeScreen()
{
    printf("\t\t\t\t\t\t%s*************************%s\n",RED,NONE);
    printf("\t\t\t\t\t\t%s         Welcome         %s\n",CYAN,NONE);
    printf("\t\t\t\t\t\t%s  Shell Script Project   %s\n",GREEN,NONE);
    printf("\t\t\t\t\t\t%s Made by: Nikhil Gautam  %s\n",BLUE,NONE);
    printf("\t\t\t\t\t\t%s*************************%s\n",RED,NONE);
}

/*PRINT PROMPT*/
void print_prompt()
{
    char* buf,*c_dir;
    int i=0,j=0;
    c_dir=(char*)get_current_dir_name();
	if((strcmp(h_dir,c_dir))==0)
		c_dir="~";

   printf("%s%s:%s%s%s%s%s ",GREEN,PS1,CYAN,c_dir,RED,"&",NONE);

    buf = readline("");
    add_history(buf);

    while( (Buffer[i] = strsep(&buf," ")) != NULL )
    {
        i++;
    }

}

/*COMMAND SELECTION FUNCTION*/
int exec()
{
	int i;
	/*Single Commands*/
	if(Buffer[3]==NULL && !((strcmp(Buffer[0],"exit"))==0) && !((strcmp(Buffer[0],"cd"))==0) &&
     !((strcmp(Buffer[0],"mkdir"))==0) && !((strcmp(Buffer[0],"rmdir"))==0) && !((strcmp(Buffer[0],"echo"))==0)
    && !((strcmp(Buffer[0],"pwd"))==0) )
            return 0;

    /*Built in commands*/
	for(i=0;i<7;i++)
	{
		if((strcmp(c_list_built_in[i],Buffer[0]))==0)
          	return 2;
	}

}

/*SINGLE SYSTEM COMMAND*/
void single_system_commands()
{
    // Forking a child
    int status;
    pid_t pid = fork();
     if (pid == -1)
    {
        printf("\nFailed forking child..");
        return;
    } else if (pid == 0)
     {

        if (execvp(Buffer[0], Buffer) < 0)
        {
            printf("\nCould not execute command..");
        }

        exit(0);
    }
    else
    {
        // waiting for child to terminate

		 if(sigint_flag==1)
		 {
		 kill(pid,SIGINT);
            sigint_flag=0;
		 }
		 if(sigstp_flag==1)
		 {
			kill(pid,SIGTSTP);
            sigstp_flag=0;
		 }


        waitpid(pid,&status,0);
        status_exit=WEXITSTATUS(status);
		if(status_exit==148)
        //printf("STOPPED CHILD!!!!  PID = %d\n",pid);
       return;
    }
}

/*BUILT IN COMMANDS*/
void builtin_commands()
{
    int no_of_cmds = 6 , i, opt = 0;
    char* list[no_of_cmds];

    list[0] = "exit";
    list[1] = "cd";
    list[2] = "mkdir";
    list[3] = "echo";
    list[4] = "rmdir";
    list[5] = "pwd";
    for (i = 0; i < no_of_cmds; i++)
    {
        if (strcmp(Buffer[0], list[i]) == 0)
        {
            opt = i + 1;
            break;
        }
    }

    switch (opt)
     {
    case 1://EXIT
         exit(0);
    case 2://CHANGE DIRECTORY
        chdir(Buffer[1]);
        return;
    case 3://MAKE DIRECTORY
        mkdir(Buffer[1],0777);
        return ;
    case 4://ECHO
            if((strcmp(Buffer[1],"$$"))==0)
				printf("%d\n",getpid());
			else if((strcmp(Buffer[1],"$SHELL"))==0)
				printf("%s\n",h_dir);
			else if((strcmp(Buffer[1],"$?"))==0)
				printf("%d",status_exit);
			else
                for(i=0;i<SIZE;i++)
                    {if(Buffer[i+1]!= NULL)
                    printf("%s",Buffer[i+1]);
                    }
                    printf("\n");
            return ;
    case 5://REMOVE DIRECTORY
        rmdir(Buffer[1]);
    return ;
    case 6://CURRENT DIRECTORY
         printf("%s\n",(char *)get_current_dir_name());
         break;
    default:
        break;
    }


}
