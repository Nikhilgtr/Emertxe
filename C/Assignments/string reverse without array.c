/*  
 *  Q. Read a string and print it in reverse order without storing
 *  in an array.(try recursive and non-recursive methods)
 *
 *  a. Read a string from user.
 *  b. Without modifying that string, print it in reverse order.
 *  c. Implement in both recursive and non-recursive methods.
 *
 *  Concepts to apply:
 *  ------------------
 *  Pointer concepts
 *  String concepts
 *
 *  Sample Execution:
 *  -----------------
 *
 *  Enter string: Hello World
 *
 *  Reverse: dlroW olleH
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stype_lib.c"

#define MAXSTRINGLEN 255

int main()
{
    char option;
    char s1[MAXSTRINGLEN];
    
    do
    {
        printf("Enter string: ");
        fgets(s1, (sizeof(s1)+1), stdin);
        /* Error check for out os range */
        
        if (s1[strlen(s1)-1] != '\n')
        {
            printf("ERROR: String1 Out of range\n");
            /* clean all from stdin and set pointer to 0 */
            fflush(stdin);
            fseek(stdin, 0L, SEEK_SET);
            return -1;
        }
        
        /* print it in reverse order without storing in an array 
         * Non-recursively
         */
        printf("Reverse NON-recursively: ");
        print_reverseStringNonRec(s1);
        printf("\n");
        
        
        /* print it in reverse order without storing in an array
         * Recursively
         */
        printf("Reverse Recursively: ");
        print_reverseStringRec(s1);
        printf("\n");
        
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

