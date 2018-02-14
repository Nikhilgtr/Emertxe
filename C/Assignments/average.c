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

#include <stdio.h>

#define MAXVAl 200000000
#define MINVAL -200000000

int main(int argc, char **argv)
{
    int n, number[15000], choice, i;
    char option;
    float average, sum;
    
    do
    {
        average = 0;
        sum = 0;
        
        printf("Enter the method:\n");
        printf("\t 1. Scan from keyboard.\n\t 2. Take command line args\n\t 3. Take environment variable args.\n");
        printf("Choice: ");
        scanf("%d", &choice);
               
        switch (choice)
        {
            case 1:
                /* Read number n from user. */
                printf("Enter the total number of integers\t: ");
                scanf("%d", &n);
                
				/* Error Check for limit */
				if ((n < 0) || (n > 20))
				{	
					printf("Error: n is Invalid Number. Retry\n");
					return 1;	
				} 
	   
                /* Read n numbers from user.*/
                for (i = 0; i < n; i++)
                {
                    printf("Enter the integer [%d]\t:", i);
                    scanf("%d", &number[i]);
					/* Error Check for limit */
					if ((number[i] <= MINVAL) || (number[i] > MAXVAl))
					{
						printf("Error: value is Invalid Number. Retry\n");
						return 1;	
					} 
	   
                }
               
                /*  Calculate average of entered numbers and print it on the screen */
                
                for (i = 0; i < n; i++) {
                    sum += number[i];
                }
                average = sum / n;
                printf("The average of entered numbers\t: %f \n", average);
                
                break;
                
            case 2:
                printf("Please run ./assignment20b <nos> \n");
                break;
                
            case 3:
                printf("From shell export a variable which contain numbers. export arr= 1 2 3 4. \nPlease run ./assignment20c \n");
                break;
                
            default:
                printf("Invalid choice \n");
                break;
        }
        
        /* Prompt for Continue option */
        printf("Continue (y/n): ");
        scanf("\n%c", &option);
    
        if ( option == 'y' )
        {
            continue;
        }
        else
        {
            break;
        }
    } while (1);
   	return 0;
}

