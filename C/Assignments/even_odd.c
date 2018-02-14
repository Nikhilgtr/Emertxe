/*
 * To check whether a given number is odd or even and
 * it's signedness using Nested if
 *
 * Eg: If input is -1, it should print -1 is negative odd number.
 *
 */

#include <stdio.h>

#define MAX 200000000
#define MIN -200000000

int main()
{
	int givenNum;
	char option;
	do
	{
		printf("Enter a number:\n");
		scanf("%d", &givenNum);

		/* Check for out of range */
		if ((givenNum < MIN) || (givenNum > MAX) )
		{
			printf("Error: num entered is out of range\n");
			continue;
		}
		
		/* To check for positive number */
		if( givenNum > 0 )
		{
			/* To check for positive even and odd number */
			if ( givenNum % 2 == 0 )
			{
				printf("%d is positive even number.\n", givenNum);
			}
			else
			{
				printf("%d is positive odd number.\n", givenNum);
			}
		}
		/* To check for negative number */
		else if( givenNum < 0 )
		{
			/* To check for negative even and odd number */
			if (givenNum % 2 == 0 )
			{
				printf("%d is negative even number.\n", givenNum);
			}
			else
			{
				printf("%d is negative odd number.\n", givenNum);
			}
		}
		/* To check for zero */
		else
		{
			printf("%d is zero.\n", givenNum);
		}
	
		/* ask the user whether to continue or not */
        printf("Continue(y/n): ");
        scanf("\n%s",&option);
        
        if (option == 'y')
        {
            continue;
        }
        else
        {
            break;
        }
        
    } while (1);
	return 0;
}	
