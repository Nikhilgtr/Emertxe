/*
 * Q. Read n and n nos. of ints and print the median of those.
 *
 *  a. Read a positive number n from user.
 *  b. Do error checking.
 *      -> if n is negative number or zero, repeat step a.
 *  c. Read n number of integers from user.
 *  d. Sort the numbers in ascending order.
 *  e. Check n is odd or even.
 *      -> if n is odd, median is the middle number.
 *      -> if n is even, take the 2 middle numbers ((n / 2) 
 *     and (n / 2) - 1 elements) and median will be average of them.
 *  f. Print the median on the screen.
 *  g. Prompt for continue option.
 *
 *  Prerequisites:
 *  --------------
 *  Looping Concepts.
 *  Array Concepts.
 *
 *  Sample Execution
 *  ----------------
 *
 *  Enter a positive number: 7
 *
 *  Enter [0] number : 2
 *  Enter [1] number : 3
 *  Enter [2] number : 8
 *  Enter [3] number : 9
 *  Enter [4] number : 13
 *  Enter [5] number : 5
 *  Enter [6] number : 3
 *
 *  Median of Entered 7 numbers is 5.00
 *
 */

#include <stdio.h>
#define LIMIT 15000 /* Limit for array */
#define MAXVAL 200000000

int main()
{
    int n, i, j, temp;
    signed int numberArray[LIMIT];
    float median;
    char option;
    do
    {
        
        
        /* Read a positive number n from user */
        printf("Enter a positive number: ");
        scanf("%d", &n);
      
        /* Error Check for each number */
        /* if n is negative number or zero, repeat */
		if ((n <= 0) || (n > MAXVAL))
        {
			printf("Error: Invalid Number. Retry\n");
			continue;	
        }     
    
        /* Read n number of integers from user */
        for ( i = 0; i < n; i++)
        {
            printf("Enter [%d] number : ", i);
            scanf("%d", &numberArray[i]);
        }
    
        /* Sort the numbers in ascending order */
        for ( i = 0; i < n; i++)
        {
            for ( j = i; j < n; j++)
            {
                if (numberArray[j] < numberArray[i])
                {
                    temp = numberArray[i];
                    numberArray[i] = numberArray[j];
                    numberArray[j] = temp;
                }
            }
        }

        /* To get the median */
        /* if n is odd, median is the middle number in sorted array */
        if ( ( n % 2) != 0)
        {
            median = numberArray[n/2];
        }
        /* if n is even, take the 2 middle numbers ((n / 2) and (n / 2) - 1 elements) and median will be average of them. */
        else
        {
            median = ((numberArray[n/2] + numberArray[(n/2)-1])/2);
        }
    
        /* Print the median on the screen */
        printf("Median of Entered %d numbers is %f \n", n, median);
    
        /* Prompt for Continue option */
        printf("Continue (y/n): ");
        scanf("\n%c", &option);
    
        if ( option == 'y' )
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
