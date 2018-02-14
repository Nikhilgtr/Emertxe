/*
 *  Q. Write a bitwise program to check a number is even or odd.
 *
 *  a. Read number n from user.
 *  b. Check the zeroth bit(on LSB end) of the number.
 *      -> if last bit is 1, number is odd.
 *      -> if last bit is zero, number is even.
 *  c. Prompt for continue option.
 *
 *  Prerequisites:
 *  --------------
 *  if else concepts.
 *  Bitwise operators.
 *
 *  Sample Execution
 *  ----------------
 *
 *  Enter the number: 11
 *
 *  Entered number 11 is odd.
 *
 *  Continue (y/n):
 *
 */

#include <stdio.h>
#define MAXVAL 200000000
#define MINVAL -200000000

int main()
{
    int givenNum;
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
		else
		{
			/* Check the zeroth bit(on LSB end) of the number */
			if (givenNum & 0x01) {
				/* if last bit is 1, number is odd */
				printf ("Entered number %d is odd.\n", givenNum);
			}
			/* if last bit is zero, number is even */
			else if(givenNum != 0)
			{
				printf ("Entered number %d is even.\n", givenNum);
			}
			else 
			{
				printf ("Entered number %d is zero.\n", givenNum);
			}
		}	
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
