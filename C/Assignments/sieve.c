/*
 * Q. Sieve of Eratosthenes
 *
 *  a. Read a number num from user.
 *  b. Do error checking.
 *	-> Check number is greater than 2 or not.
 *	-> If not, exit.
 *  c. Arrange the numbers from 2 to num in sequential way.
 *  d. Remove the multiples of 2, from 2 to num, except 2.
 *  e. Remove the multiples of 3, from 3 to num, except 3.
 *  f. Continue this process till sqrt of num.
 *  g. Remaining elements will be the prime numbers within the range of 2 to num.
 *  h. Print all those numbers.
 *
 *  Prerequisites:
 *  --------------
 *  Looping Concepts
 *  Array Concepts
 *
 *  Sample Execution
 *  ----------------
 *
 *  Enter the number: 100
 *
 *  After Sieve of Eretosthenes, Prime Numbers within 2 to 100 are
 *  --->
 *
 *  2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 
 *  61 67 71 73 79 83 89 97
 *
 *  Continue (y/n):
 *
 *
 */

#include <stdio.h>
#include <math.h>

#define LIMIT 200000

int main()
{
    int num, i, j;
    int numArray[LIMIT];
    char option;
    
    do
    {
		num = 0;
        numArray[0] = 0;
        numArray[1] = 0;
    
        /* Read a number num from user. */
        printf("Enter a number: ");
        scanf("%d", &num);
    
        /* Error Check */
        if (num < 2 || num > 200)
        {
            printf("Error: Enter only positive numbers > 2 less than 200 \n");
            return 1;
        }
    
        /* Arrange the numbers from 2 to num in sequential way */
        for ( i = 2; i <= num ; i++ )
        {
            numArray[i] = i;
        }
    
        /* Remove multiples of i to get prime numbers */
        for ( i = 2; i <= num; i++)
        {
            for ( j = i; j <= num; j++ )
            {
                /* mark the multiples as 0 in numArray */
                numArray[(i*j)] = 0;
            }
        }
    
        /* To print prime Numbers */
        printf("After Sieve of Eretosthenes, Prime Numbers within 2 to %d are ---> \n", num);
  
        for ( i = 2; i <= num ; i++ )
        {
            /* all non-zero values in numArray are prime */
            if (numArray[i] != 0)
            {
                printf("%d ", numArray[i]);
            }
        }
        printf("\n");
        
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
