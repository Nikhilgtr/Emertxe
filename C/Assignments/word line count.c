/*  
 *  Q. Write a program to count number of characters, 
 *  words and lines, entered through stdin.
 *
 *  a. Read characters from user till EOF.
 *  b. If EOF recieved, print the character count, 
 *      word count and line count.
 *
 *  Hint: Use getchar for taking input.
 *  Listen ' '  '\t'  '\n' characters for word and line count.
 *
 *  Prerequisites:
 *  --------------
 *  Understanding of getchar function.
 *
 *  Sample Execution
 *  ----------------
 *
 *  Hello World
 *  Dennis Ritchie
 *  Linux
 *
 *  Lines == 3, Words == 5, Characters == 33
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lines = 0, words = 0, characters = 0;
    int c;

    do
    {
        /* Read a character */
        c = getchar();
        /* Increment the character count */
        characters++;
        
        /* If newline increment the line count */
        if (c == '\n')
        {
            lines++;
        }
        
        /* If newline or space or tab increment the word count */
        if (c == ' ' || c == '\n' || c == '\t')
        {
            ++words;
            /* read next character */
            c = getchar();
            
            /* If next character is newline or space or tab decrement the word count */
            if (c == ' ' || c == '\n' || c == '\t')
            {
                words--;
                
            }
            /* unget the character from input stream */
            ungetc(c,stdin);
        }
    
        /* If EOF [ctrl+D] break the loop */
        else if (c == EOF)
        {
            ungetc(c,stdin);
            /* decrement one character count for EOF */
            characters--;
            break;
        }
        
    } while (1);
    
    /* print the character count, word count and line count.*/
    printf("\n");
    printf("Lines == %d, Words == %d, Characters == %d\n", lines, words, characters);
    
    return 0;
    
}
