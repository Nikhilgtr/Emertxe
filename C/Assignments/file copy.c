/*  
 *  Q. Copy one file into another
 *
 *  a. Take two file names through command line.
 *  b. Do error checking.
 *      -> check cmd line args
 *      -> check fopen status.
 *  c. Open first file in read mode.
 *  d. Open second file in write mode.
 *  e. Copy first file contents into second file.
 *
 *  Prerequisites:
 *  --------------
 *  Usage of fopen functions.
 *  Usage of fgetc functions.
 *
 *  Sample Execution
 *  ----------------
 *
 *  ./a.out my_file.txt write_file.txt
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int c;
    int words = 0;
    
    /* file descriptors */
    FILE *fp1;
    FILE *fp2;
    
    /* Do arg count check */
    if (argc != 3)
    {
        printf("Usage: ./assignment27 read_file.txt write_file.txt\n");
        return -1;
    }
    else
    {
        /* check the fopen success or not */
        /* Open first file in read only mode */
        fp1 = fopen(argv[1], "r");
        if (NULL == fp1)
        {
            perror("fopen");
            return -1;
        }
        
        /* check the fopen success or not */
        /* Open second file in write only mode */
        fp2 = fopen(argv[2], "w");
        if (NULL == fp2)
        {
            perror("fopen");
            fclose(fp1); /* clean exit */
            return -1;
        }
    }
    
    /* Read a character from read_file.txt till EOF is recieved 
     *  and copy it to write_file.txt */
    while (!feof(fp1))
    {
        c = fgetc(fp1);
        fputc(c, fp2);
    }
    
    /* flush the buffer and close the file*/
    fclose(fp1);
    fclose(fp2);
    
    return 0;
    
}
