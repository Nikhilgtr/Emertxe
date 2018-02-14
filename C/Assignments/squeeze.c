/*  
 *  Q. Write an alternative version of squeeze(s1, s2) 
 *  that deletes each character in s1 that matches any 
 *  character in the string s2
 *
 *  a. Read two strings s1 and s2 from user.
 *  b. Remove the characters in s1 that matches with s2.
 *
 *  Concepts to apply:
 *  ------------------
 *  Pointer Concepts
 *  String concepts
 *
 *  Sample Execution:
 *  -----------------
 *  Enter s1: Dennis Ritchie
 *  Enter s2: Linux
 *
 *  After squeeze s1: Des Ritche
 *
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
    char s2[MAXSTRINGLEN];
    
    do
    {
        printf("Enter s1: ");
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
        
        printf("Enter s2: ");
        fgets(s2, (sizeof(s2)+1), stdin);
        
        if (s2[strlen(s2)-1] != '\n')
        {
            printf("ERROR: String2 Out of range\n");
            /* clean all from stdin and set pointer to 0 */
            fflush(stdin);
            fseek(stdin, 0L, SEEK_SET);
            return -1;
        }
        
        /* print s1 after squuezing
         */
        printf("After squeeze s1: ");
        my_squeeze(s1, s2);
        printf("%s \n", s1);
        
        
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

