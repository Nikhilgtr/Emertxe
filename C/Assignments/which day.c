/*
 *  Q. Given a number between 1-365 (incl), find which day is it
 *
 *
 */

#include <stdio.h>

int main()
{
    
    int dayNumber;
	int startDay;
	char option;
	
	/* days */
	char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	
	do
	{
		
		/* Enter the starting day of the year */
		printf("Enter the starting day of the year: \n");
		printf("1. Monday \n2. Tuesday \n3.Wednesdday \n4. Thursdday \n5. Friday \n6. Saturday \n7. Sunday\n \n ");
		printf("StartDay: ");
		scanf("%d", &startDay);
		
		/* Enter the number */
		printf("Enter the number between 1-365 (incl): ");
		scanf("%d", &dayNumber);
		
		/* Print the day accordingly */
		switch (startDay)
		{
			case 1: dayNumber%=7; /* Print the day accordingly for start day being Monday */
					printf("Day is : %s\n", *(days+dayNumber));
					break;
			case 2: dayNumber = (dayNumber+1) % 7;
					printf("Day is : %s\n", *(days+dayNumber));
					break;
			case 3: dayNumber = (dayNumber+2) % 7;
					printf("Day is : %s\n", *(days+dayNumber));
					break;
			case 4: dayNumber = (dayNumber+3) % 7;
					printf("Day is : %s\n", *(days+dayNumber));
					break;
			case 5: dayNumber = (dayNumber+4) % 7;
					printf("Day is : %s\n", *(days+dayNumber));
					break;
			case 6: dayNumber = (dayNumber+5) % 7;
					printf("Day is : %s\n", *(days+dayNumber));
					break;
			case 7: dayNumber = (dayNumber+6) % 7;
					printf("Day is : %s\n", *(days+dayNumber));
					break;
			default: printf("Invalid Option \n");
					break;
		}
		
		/* check for continue */
        printf("Continue (y/n): ");
        scanf("\n%c", &option);
        
        if ( option == 'y' )
        {
            continue;
        } else
        {
            break;
        }
        
    } while (1);
	
    return 0;
}	
