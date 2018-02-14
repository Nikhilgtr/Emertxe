/*  
 *  Q. Read input till eof and print no of words read.
 *
 *  a. Take an existing filename from user through command line.
 *  b. Do error checking.
 *      -> If user passed any filename through command line or not.
 *      -> If passed, check the fopen success or not.
 *  c. Read characters from file till EOF.
 *  d. If EOF reached, print the word count.
 *
 *  Prerequisites:
 *  --------------
 *  Usage of file open functions.
 *  Usage of fgetc function.
 *
 *  Sample Execution
 *  ----------------
 *  ./a.out my_file.txt
 *
 *  Word Count in my_file.txt === 12
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int c;
    int words = 0;
    
    FILE *fp;
    
    /* Do arg count check */
    if (argc == 1)
    {
        printf("Usage: ./assignment26 <filename>\n");
        return -1;
    }
    else
    {
        /*  check the fopen success or not */
        fp = fopen(argv[1], "r");
        if (NULL == fp)
        {
            perror("fopen");
            return -1;
        }
    }
    
    /* Read a character till EOF is recieved */
    while ((c = fgetc(fp)) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            ++words;
            /* read next character */
            c = fgetc(fp);
            /* If next character is newline or space or tab decrement the word count */
            if (c == ' ' || c == '\n' || c == '\t')
            {
                words--;
            }
            /* unget the character from file stream as we did read character twice. Not necessary as no character count is considered */
            //ungetc(c,fp);
            
        }
    }
    /* flush the buffer and close the file*/
    fclose(fp);
    
    printf("Word Count in %s === %d\n", argv[1], words);
    
    return 0;
    
}
