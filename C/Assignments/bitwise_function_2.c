/*
 *  Q. Read int i, Read 0 <= a <= b <= 31. 
 *  Read an int n, put the (b-a+1)lsb's of n into i[b:a].
 *
 *  a. Read number n from user.
 *  b. Read number i from user.
 *  c. Read number a from user(0 < a < 31)
 *  d. Do error checking
 *      -> Check a is within limit or not.
 *  e. Read number b from user(a < b < 31)
 *  f. Do error checking
 *      -> Check b is within limit or not.
 *  g. Call set_nbits_from_pos function by passing i, 
 *  b - a + 1, b and n as arguments.
 *      -> set_nbits_from_pos(i, b - a + 1, b, n);
 *  h. Print the new value of i.
 *  i. Prompt for continue option.
 *
 *  Prerequisites:
 *  --------------
 *  Functional Concepts.
 *  Bitwise Operators.
 *  Modular Concepts.
 *
 *  Sample Execution
 *  ----------------
 *
 *  Enter number n: 5
 *  Enter number a: 2
 *  Enter number b: 6
 *  Enter number i: 15
 *
 *  15[6:2] = 7
 *
 */

#include <stdio.h>
#include "bitwise_lib.c"

#define MAXVAl 200000000
#define MINVAL -200000000

int main()
{
    int n, a, b, i, result;
    char option;
    
    do
    {
        /* Read number n from user */
        printf("Enter number n: ");
        scanf("%d", &n);
    
		/* Error Check for limit */
		if ((n <= MINVAL) || (n > MAXVAl))
		{
			printf("Error:n is Invalid Number. Retry\n");
			return 1;	
		} 
		
        /* Read number a from user(0 < a < 31) */
        printf("Enter number a: ");
        scanf("%d", &a);
    
        /* Do error checking */
        if ((a < 0) || (a > 31))
        {
            printf("Error: a is out of range\n ");
            return 1;
        }
    
        /* Read number b from user(0 < b < 31) */
        printf("Enter number b: ");
        scanf("%d", &b);
    
        /* Do error checking */
        if ((b < a) || (b > 31))
        {
            printf("Error: b is out of range\n ");
            return 1;
        }
    
        /* Read number i from user */
        printf("Enter number i: ");
        scanf("%d", &i);
    
		/* Error Check for limit */
		if ((i <= MINVAL) || (i > MAXVAl))
		{
			printf("Error:i is Invalid Number. Retry\n");
			return 1;	
		} 
		
        /* Call set_nbits_from_pos function by passing i,
        *  b - a + 1, b and n as arguments.
        */
        //printf("num=%d, n=%d, pos=%d, val = %d\n", i, (b - a + 1), b, n);
        
        result = set_nbits_from_pos(i, (b - a + 1), b, n);
    
        /* Print the new value of i */
        printf("%d[%d:%d] = %d\n", i, b, a, result);
    
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
