/*  
 *  Q. Fibonacci with using its recursive relation
 *
 *  a. Pass a number (for which fibonacci need to be generated)
 *      through command line.
 *  b. Collect it in main
 *  c. Do error checking
 *      -> Check if I passed zero numbers in command line.
 *      -> If so return by printing a message
 *  d. Call a function fibonacci which will take this number 
 *  and call same function again by passing appropriate values.
 *
 *
 *  Sample Execution
 *  ----------------
 *
 *  [shell ]$ ./a.out 15
 *
 *  0 1 1 2 3 5 8 13
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 200000000
#define MINVAL -200000000

/* function prototype */
void fibonacci(int givenNum);

int main(int argc, char **argv)
{
    int num;
    
    /* Do error checking for arg count */
    if (argc != 2)
    {
        printf("Invalid entry: ./assignment23 <no>\n");
        exit(1);
    }
    else
    {
        num = atoi(argv[1]);
		
		/* Error Check for limit */
		if ((num < 0) || (num > MAXVAL))
		{
			printf("Error: num is Invalid Number. Retry\n");
			return 1;	
		} 
		
        fibonacci(num);
    }
    
    printf("\n");
    return 0;
    
}

/* Recursive fibonacii function */
/* generate the fibonacii numbers <= givenNum */
void fibonacci(int givenNum)
{
    /* initial values */
    static long int fib1=0, fib2=1, temp;
    
    while (fib1 <= givenNum)
    {
        printf("%ld ", fib1);
        /* take the first fib into temp */
        temp = fib1;
        /* fib1 will be sum of fib1 and fib2 */
        fib1 += fib2;
        /* fib2 will be the value of previous fib1 value */
        fib2 = temp;
        /* recursively call the fibonacii function */
        fibonacci( givenNum - 1 );
    }
    
}

