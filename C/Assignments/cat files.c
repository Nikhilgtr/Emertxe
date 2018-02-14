/*  
 * Q. Concatenate two files, as ./your_cat file1 file2 [filenew] 
 *  and like the command ’cat’
 *
 *  a. Recieve file names through command line.
 *  b. Do error checking.
 *      -> cmd line args
 *      -> fopen status
 *  c. if cmd line args are ./a.out, then print stdin 
 *      contents into stdout.
 *  d. if cmd line args are ./a.out file1 file2, 
 *      then print file1 and file2 contents to stdout.
 *  e. if cmd line args are ./a.out file1 file2 file3, 
 *      then print file1 file2 contents into file3.
 *  f. Use a common function for doing file copy.
 *
 *  Prerequisites:
 *  --------------
 *  Usage of file open, file read write functions.
 *
 */

#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *fp1, FILE *fp2);

int main(int argc, char **argv)
{
    int ch;
    
    /* file descriptors */
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    
    /* Do arg count check */
    /* Do error checking */
    if (argc == 1)
    {
        /* print stdin contents into stdout */
        /* calling function to do filecopy */
        filecopy(stdin, stdout);
    }
    else if (argc == 3)
    {
        /* check the fopen success or not */
        /* Open first file in read mode */
        fp1 = fopen(argv[1], "r");
        if (NULL == fp1)
        {
            perror("file1 fopen");
            return -1;
        }
        
        /* check the fopen success or not */
        /* Open second file in read mode */
        fp2 = fopen(argv[2], "r");
        if (NULL == fp2)
        {
            perror("file2 fopen");
            /* flush the buffer and close the file*/
            fclose(fp1); /* clean exit */
            return -1;
        }
        
        /* print file1 and file2 contents to stdout */
        /* calling function to do filecopy */
        filecopy(fp1, stdout);
        filecopy(fp2, stdout);
        
        /* flush the buffer and close the file*/
        fclose(fp1);
        fclose(fp2);
        
    }
    else if (argc == 4)
    {
        /* check the fopen success or not */
        /* Open first file in read mode */
        fp1 = fopen(argv[1], "r");
        if (NULL == fp1)
        {
            perror("file1 fopen");
            return -1;
        }
        
        /* check the fopen success or not */
        /* Open second file in read mode */
        fp2 = fopen(argv[2], "r");
        if (NULL == fp2)
        {
            perror("file2 fopen");
            /* flush the buffer and close the file*/
            fclose(fp1); /* clean exit */

            return -1;
        }
        
        /* check the fopen success or not */
        /* Open third file in write mode, file is created if it
         *  does not exist, otherwise it appends */
        fp3 = fopen(argv[3], "w+");
        if (NULL == fp3)
        {
            perror("file3 fopen");
            /* flush the buffer and close the file*/
            fclose(fp1);
            fclose(fp2);
            
            return -1;
        }
        
        /* To clear the data already present if the file exists */
        rewind(fp3);
        fflush(fp3);
        
        /* print file1 and file2 contents to file3 */
        /* calling function to do filecopy */
        filecopy(fp1, fp3);
        filecopy(fp2, fp3);
        
        /* flush the buffer and close the file*/
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
    }
    else
    {
        printf("Usage: ./assignment28 file1.txt file2.txt\n Or\n");
        printf("Usage: ./assignment28 file1.txt file2.txt file3.txt\n Or\n");
        printf("Usage: ./assignment28 \n");
        return -1;
    }
    
    return 0;
    
}

/* To copy from one file to another */
void filecopy(FILE *fp1, FILE *fp2)
{
    int c;
    while (!feof(fp1))
    {
        c = fgetc(fp1);
        fputc(c, fp2);
    }
}
