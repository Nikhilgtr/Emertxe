/*
 * Q. Print all ascii characters.
 *
 * a. Print the Decimal numbers from 0 to 127 in Octal, 
 * Hexadecimal and in ASCII representation.
 * b. Display as 'Non Printable' for non-printable characters.
 *
 * Pre-requesites:
 * ---------------
 * Looping Concepts.
 *
 * Sample Execution
 * ----------------
 *
 * Dec		Oct		Hex		Ascii
 * ---		---		---		-----
 * 0		000		00		Non Printable
 * 1		001		01		Non Printable
 *
 */

#include <stdio.h>

int main()
{
    int i;
    
    /* Print all ASCII characters*/
    printf(" Dec\t Oct\t Hex\t Ascii\n");
    printf(" ---\t ---\t ---\t -----\n");
    
    /* Check the number is perfect number or not and print it */
    for (i = 0; i <= 127; i++)
    {
        if ( (i < 32) || (i == 127) )
        {
            printf(" %d\t %.3o\t %.2x\t Non Printable\n", i, i, i);
        }
        else
        {
            printf(" %d\t %.3o\t %.2x\t %c\n", i, i, i, i);
        }
    }
   
    return 0;
}	
