/*  
 * Q. Implement atoi(const char *s)
 *
 *  a. The function will recieve a string and covert the 
 *  number stored in the string into exact integer number.
 *  b. And return the number.
 *
 *
 *  Sample Execution
 *  ----------------
 *
 *  Enter the string: 1986
 *
 *  You entered the number 1986
 *
 *  Continue(y/n): y
 *
 *  Enter the string: I am 20
 *
 *  You entered the number 0
 *
 *  Continue(y/n): y
 *
 *  Enter the string: 1986 July 10
 *
 *  You entered the number 1986
 *
 *  Continue(y/n):
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "ntype_lib.c"

#define MAXLEN 256
#define MAXVAL 200000000
#define MINVAL -200000000


int main()
{
    char myInput[MAXLEN];
    char option;
    
    do
    {
        /* Enter the string and store */
        printf("Enter the string: ");
        fgets (myInput, MAXLEN, stdin);
        
        /* Call my_atoi and print the output*/
        printf("You entered the number %d\n", my_atoi(myInput));
        
        /* Prompt for Continue option */
        printf("Continue (y/n): ");
        scanf("\n%c", &option);
        
        if ( option == 'y' )
        {
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
