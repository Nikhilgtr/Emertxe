/*  
 *  Q. Implement int my_itoa(int n, char *s)
 *
 *  a. Convert integer n into a string and store the string in s.
 *  b. Return the length of string from the function.
 *
 *  Note: Call the function as
 *      -> itoa(n, arr);
 *  After this function, arr should contain n as string.
 *
 *  Sample Execution
 *  ----------------
 *
 *  Enter the number: 100
 *
 *  You entered 100
 *
 *  Continue(y/n):
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "ntype_lib.c"

int main()
{
    char strBuf[MAXLEN];
    char option;
    int number = 0;
    
    do
    {
        
        /* Enter the string and store */
        printf("Enter the number: ");
        /* check if only int values are considered */
        if(! scanf("%d", &number))
        {
            printf("Error: Invalid number\n");
            break;
        }
       
        /* Error Check for limit */
        if ((number < MINVAL) || (number > MAXVAL))
        {
            printf("Error: Invalid Number. Retry\n");
            return 1;
        }
        
        //printf("length of the string: %d", my_itoa(number, strBuf));
        my_itoa(number, strBuf);
        
        /* Call getword and print the output*/
        printf("\nYou entered %s\n", strBuf);
        
        /* Prompt for Continue option */
        printf("Continue (y/n): ");
        scanf("\n%c", &option);
        
        if ( option == 'y' )
        {
            *strBuf = '\0';
            getchar();
            continue;
        }
        else
        {
            break;
        }

    } while(1);
    return 0;
}

