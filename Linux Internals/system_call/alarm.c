
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int flag;

void handler(int arg)
{
    flag = 1;
}

int main(int argc, char *argv[])
{
    //Declaration of variables
    int choice, delay, sec = 0;
    struct tm time_i, *time_ptr;
    time_t time_curr, givn_time;

    //argument validation
    if (argc < 2 || argc > 3)
    {
	printf("Error: pass proper arguments\n");
	printf("Pass: ./a.out <hh:mm:ss> <dd:mm:yyyy>\n");
	exit(1);
    }

    //to convert min, hour, day, mon, year to sec
    time_curr = time(NULL);
    printf("curr time : %ld\n", time_curr);

    //if only time is provided
    if (argc == 2)
    {
	//TO copy present day's date, month, year into structure
	time_ptr = localtime(&time_curr);

	//initializing structure
	memset(&time_i, 0,sizeof(struct tm));

	//TO get time( hour, minutes, sec) into structure
	strptime(argv[1], "%T", &time_i);

	time_i.tm_mday = time_ptr -> tm_mday;
	time_i.tm_mon = time_ptr -> tm_mon;
	time_i.tm_year = time_ptr -> tm_year;
    }

    //if both date and time is passed
    if (argc == 3)
    {
	//initializing structure
	memset(&time_i, 0,sizeof(struct tm));
	strptime(argv[1], "%T", &time_i);
	strptime(argv[2], "%d:%m:%Y", &time_i);
    }

    givn_time = mktime(&time_i);
    printf("given time : %ld\n", givn_time);
    if  ((sec = givn_time - time_curr) < 0)
    {
	printf("Error! Invalid time\n");
	exit(2);
    }

    printf("\nALARM IN %d SECONDS\n\n", sec);

    signal(SIGALRM, handler);
    alarm(sec);
    while (1)
    {
	if (flag)
	{
	    printf("***TIME UP.... WAKE UP***\n");
	    printf("\nSelect\n1. Snooze \n2. Quit\n");
	    scanf("%d", &choice);
	    if (1 == choice)
	    {
		printf("Enter Snooze time :");
		scanf("%d", &delay);
		alarm(delay);
		flag = 0;
	    }
	    else if (2 == choice)
	    {
		exit(1);
	    }
	}
    }
}
