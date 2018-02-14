/*
 *  Q. Read integer num & n. 
 *  Circular right & left shift the num by n.
 *
 *  a. Read a number num from user.
 *  b. Read a number n from user.
 *  c. Select the option among
 *      -> Circular right shift
 *      -> Circular left shift
 *  d. Pass num and n to the corresponding functions.
 *  e. Shift num, n times 
 *      (either left or right, depends on function).
 *  f. While shifting the shifted bits should get 
 *      replaced at the alternate end.
 *      -> For right shifting, the shifted bits should 
 *      come at left most side.
 *      -> For left shifting, the shifted bits should 
 *      come at right most side.
 *  g. Return the new number from the function.
 *  h. Print the new number.
 *
 *  Note:	Use print_bits function from bitwise_lib.c 
 *  for making this program more readable.
 *
 *  If num is 12, and n is 3, in circular_right_shift fuction
 *
 *  12 		-> 
 *  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0
 *
 *  new number 	-> 
 *  1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
 *
 *
 *  Prerequisites:
 *  --------------
 *  Function Concepts.
 *  Bitwise Operators.
 *  Modular Concepts.
 *
 *  Sample Execution
 *  ----------------
 *
 *  Enter num: 12
 *  Enter n  : 3
 *
 *  Enter Choice
 *      1. circular_right_shift
 *      2. circular_left_shift
 *
 *  Choice: 1
 *
 *
 */

#include <stdio.h>
#include "bitwise_lib.c"

#define MAXVAl 200000000
#define MINVAL -200000000

/* Function prototypes */
int circular_right_shift(int num, int n);
int circular_left_shift(int num, int n);
void print_bits(unsigned int num);

int main()
{
    int num, n, result;
    int choice;
    char option;
	
	do 
	{
		/* Read a number num from user */
		printf("Enter num: ");
		scanf("%d", &num);
			
		/* Read a number n from user */
		printf("Enter n  : ");
		scanf("%d", &n);
		
		/* Error Check for limit */
		if ((num <= MINVAL) || (num > MAXVAl))
		{
			printf("Error: num is Invalid Number. Retry\n");
			return 1;	
		} 
		
		/* Do error checking */
		if ((n < 0) || (n > 31))
		{
			printf("Error: n is out of range\n ");
			return 1;
		}
			
		/* Select the option among
		*      -> Circular right shift
		*      -> Circular left shift
		*/
		printf("Enter Choice \n \t1. circular_right_shift \n \t2. circular_left_shift\n");
		printf("Choice: ");
		scanf("%d", &choice);
		
		switch (choice)
		{
			case 1:
				printf("circular_right_shift \n");
				/* Circular right shift */
				printf("%d \t\t-> ", num);
				print_bits(num);
				result = circular_right_shift(num, n);
				/* Print the new number */
				printf("new number \t-> ");
				print_bits(result);
				break;
				
			case 2:
				printf("circular_left_shift \n");
				/* Circular left shift */
				printf("%d \t\t-> ", num);
				print_bits(num);
				result = circular_left_shift(num, n);
				/* Print the new number */
				printf("new number \t-> ");
				print_bits(result);
				break;
				
			default:
				printf("Invalid Choice \n");
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
