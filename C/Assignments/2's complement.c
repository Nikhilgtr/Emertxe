/*
 *  Q. Print bits of signed & unsigned types and 
 *  check for 2’s complement.
 *
 *  a. Read number n from user.
 *  b. Print the 32 bit binary representation of n and -n.
 *  c. And compare both.
 *  d. Prompt for continue option.
 *
 *  Prerequisites:
 *  --------------
 *  Bitwise Operators.
 *  2's Complement concept.
 *
 *  Sample Execution
 *  ----------------
 *
 *  Enter the number: 12
 *
 *  +12 -> 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0
 *
 *  -12 -> 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 0 0
 *
 *  Continue (y/n):
 *
 */

#include <stdio.h>
#define MAXVAL 200000000
#define MINVAL -200000000

int main()
{
    int givenNum, i, mask, bit;
    char option;
    
    do
    {
        /* Read number n from user */
        printf("Enter the number: ");
        scanf("%d", &givenNum);
    
		/* Error Check for each number */
        if ((givenNum <= MINVAL) || (givenNum > MAXVAL))
        {
			printf("Error: Invalid Number. Retry\n");
			continue;	
        }     
    
	
        /* To print the + for positive n */
        (givenNum > 0) ? printf("+%d -> ", givenNum) : printf("%d -> ", (givenNum));
        
        /* Print the 32 bit binary representation of n and -n */
        for ( i = 31; i >= 0; i-- )
        {
            mask = 1 << i; /* masking */
            bit = mask & givenNum; /* to get the MSB */
            bit == 0 ? printf("0"): printf("1"); /* print bits */
        }
        printf("\n");
        
        /* To print the + for positive n */
        (givenNum > 0) ? printf("%d -> ", (givenNum * -1)) : printf("+%d -> ", (givenNum * -1));
        
        /* Print the 32 bit binary representation of n and -n */
        for ( i = 31; i >= 0; i-- )
        {
            mask = 1 << i; /* masking */
            bit = mask & (givenNum * -1); /* to get the MSB */
            bit == 0 ? printf("0"): printf("1");  /* print bits */
        }
        printf("\n");
        
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
