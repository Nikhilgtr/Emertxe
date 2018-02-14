/*
 * Q. Read n and check for its perfectness.
 *
 * a. Read n from user.
 * b. Do error checking.
 *	-> if number is less than zero.
 * c. Check the number is perfect number or not and print it.
 * d. After printing, ask the user whether to continue or not.
 *	-> if yes, continue with step a.
 *	-> else exit.
 *
 * Pre-requestites:
 * ----------------
 * Looping concepts.
 *
 * Sample Execution
 * ----------------
 * Enter the number: 28
 *
 * The number 28 is a perfect number.
 *
 * Continue(y/n): y
 *
 * Enter the number:
 *
 */

#include <stdio.h>

int main()
{
	int givenNum, i, sum = 0, flag = 0;
    char option;
    
    do
    {
        /* Read n from user */
        printf("Enter a number: ");
        scanf("%d", &givenNum);

        /* Error check for negative numbers and zero also for out of range values */
        if (givenNum <= 0)
        {
            printf("Error: Invaid number. Give only Positive numbers < 2000000000. \n");
            return 1;
        }
    
        /* Check the number is perfect number or not and print it */
        for (i = 1; i <= givenNum; i++)
        {
            if ((givenNum % i) == 0 )
            {
                sum += i;
            }
        }
        
        if ( (sum - givenNum) == givenNum )
        {
            printf("The number %d is a perfect number\n", givenNum);
        }
        else
        {
            printf("The number %d is not a perfect number\n", givenNum);
        }
        
        /* ask the user whether to continue or not */
        printf("Continue(y/n): ");
        scanf("\n%s",&option);
        
        if (option == 'y')
        {
            sum = 0;
            flag = 0;
            continue;
        }
        else
        {
            break;
        }
        
    } while (1);
    
    printf("\n");
    return 0;
}	
