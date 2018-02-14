/*
 * Read n and Print the greatest fibonacii no <= n
 */

#include <stdio.h>

int main()
{
	int givenNum;
    int fib1, fib2, temp;
	char option;
	
	do
	{
		fib1 = 0;
		fib2 = 1;
				
		printf("Enter a number:\n");
		scanf("%d", &givenNum);
		
		/* Negative number check */
		/* Check for out of range */
		
		if (givenNum < 0)
		{
			printf("Error: num entered is out of range\n");
			continue;
		}
		
		/* To get the greatest fibonacii number <= givenNum */
		printf("The greatest Fibonacii number <= %d is ", givenNum);
		/* generate the fibonacii numbers <= givenNum */
		while (fib1 <= givenNum)
		{
			/* take the first fib into temp */
			temp = fib1;
			/* fib1 will be sum of fib1 and fib2 */
			fib1 += fib2;
			/* fib2 will be the value of previous fib1 value */
			fib2 = temp;
		}
		printf("%d\n", fib2);
	
		/* ask the user whether to continue or not */
        printf("Continue(y/n): ");
        scanf("\n%s",&option);
        
        if (option == 'y')
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
