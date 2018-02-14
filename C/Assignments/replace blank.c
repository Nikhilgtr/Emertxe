/*  
 *  Q. Write a program to copy its input to its output, 
 *   replacing each string of one or more blanks by a single blank.
 *
 *  a. Read characters from user.
 *  b. Replace multiple spaces by a single space and 
 *      print them to the screen.
 *  c. Continue this till EOF is recieved.
 *
 *  Prerequisites:
 *  --------------
 *  Usage of getchar function.
 *
 *  Sample Execution
 *  ----------------
 *
 *  Hello World
 *  Hello World
 *  Dennis   Ritchie
 *  Dennis Ritchie
 *  Linux            vs            Windows
 *  Linux vs Windows
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, lastcharacter;
    
    /* initially let the last character be non space value */
    lastcharacter = 'a';
    
    /* Read a character till EOF is recieved */
    while ((c = getchar()) != EOF)
    {
        /* if the character is space */
        if (c == ' ')
        {
            /* check if last character was not space */
            if (lastcharacter != ' ')
            {
                /* if so then print */
                putchar(c);
            }
        }
         /* if the character is not space then print */
        else
        {
            putchar(c);
        }
        /* update the lastcharacter with curent c */
        lastcharacter = c;
    }
    
    return 0;
    
}
