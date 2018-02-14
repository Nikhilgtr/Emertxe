/*
 *  Q. Average of n numbers by taking input in 3 different ways.
 *
 *
 *  Ist method
 *  ----------
 *
 *  a. Read number n from user.
 *  b. Read n numbers from user.
 *  c. Calculate average of entered numbers and 
 *  print it on the screen.
 *
 *
 *  IInd method
 *  -----------
 *
 *  a. Pass the numbers (for which average to be calculated) 
 *      through command line.
 *  b. Collect them in main
 *  c. Calculate the average of them.
 *
 *  Hint: Use atoi function to convert string to integers.
 *
 *  IIIrd method
 *  ------------
 *
 *  a. Pass the numbers (for which average to be calculated) 
 *  through environment variables.
 *  b. Collect them in main
 *  c. Calculate the average of them.
 *
 *  Hint: use atoi function to convert string to integers.
 *  use strtok to split the strings.
 *
 *  From shell export a variable which contain numbers.
 *  export arr="1 2 3 4"
 *
 *  In main program recieve this by third argument of main. 
 *  Extract numbers from string and calculate their average.
 *
 *  Prerequisites:
 *  --------------
 *  Different prototypes of main.
 *  Array pointer concepts.
 *
 *  Sample Execution
 *  ----------------
 *
 *  Enter the method:
 *
 *	1. Scan from keyboard.
 *	2. Take command line args
 *	3. Take environment variable args.
 *
 *  Choice: 1
 *
 *  Enter the total number of integers	: 4
 *
 *  Enter the integer [0]			: 3
 *  Enter the integer [1]			: 5
 *  Enter the integer [2]			: 10
 *  Enter the integer [3]			: 7
 *
 *  The average of entered numbers 		: 6.25
 *
 *  Continue (y/n):
 *
 *
 */

/* IIIrd method */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 15000

int main(int argc, char *argv[], char *envp[])
{
    int count, i, number[MAXLEN];
    float average, sum;
    
    char *arr;
    const char str[2] = " ";
    char *token;
    
    average = 0;
    sum = 0;
    count = 0;
    
    printf("From shell export a variable which contain numbers. export arr= 1 2 3 4 \n");
    
    /* get the data from environment variable that was set */
    arr = getenv("ARR");
    
    printf ("Arr= %s.\n", arr);
  
    /* get the first token */
    token = strtok(arr, str);
    
    /* walk through other tokens */
    while( token != NULL )
    {
        count++;
        /* convert the string to integer */
        number[count] = atoi(token);
        /* sum of the numbers */
        sum += number[count];
        /* Actual Numbers */
        //printf( " %s\n", token );
        token = strtok(NULL, str);
    }
    //printf ("sum = %f \n", sum);
    /*  Calculate average of entered numbers and print it on the screen */
    average = sum / count;
 
    printf("The average of entered numbers\t: %f \n", average);
    
   	return 0;
}


