/*
 * Q. Generate AP, GP, HP
 *
 *	Read 3 numbers a, r, n. Generate AP, GP, HP
 *  ----------------------------------
 *  Hint:
 *  What is AP, GP, HP ?
 *
 *  1. AP :-
 *      In mathematics, an arithmetic progression (AP) or 
 *  arithmetic sequence is a sequence of numbers such that 
 *  the difference between the consecutive terms is constant.
 *	For instance, the sequence 5, 7, 9, 11, 13, 15 ... 
 *  is an arithmetic progression with common difference of 2.
 *
 *  2. GP :-
 *      In mathematics, a geometric progression, also known 
 *  as a geometric sequence, is a sequence of numbers where 
 *  each term after the first is found by multiplying the previous
 *	one by a fixed, non-zero number called the common ratio.
 *	For example, the sequence 2, 6, 18, 54, ... 
 *  is a geometric progression with common ratio 3.
 *	Similarly 10, 5, 2.5, 1.25, ... 
 *  is a geometric sequence with common ratio 1/2.
 *
 *  3. HP :-
 *      In mathematics, a harmonic progression (or harmonic 
 *  sequence) is a progression formed by taking the 
 *  reciprocals of an arithmetic progression.
 *  ------------------------------------------------
 *
 *  Pre-requisites :
 *      1. Loops
 *      2. Arthmetic operators
 *      3. Data types
 *  --------------------------------
 *
 *  Sample run:
 *  Run-1
 *      Input 	a = 2 r = 3n = 5
 *      Output 	AP = 2, 5, 8, 11, 14
 *              GP = 2, 6, 18, 54, 162
 *              HP = 0.5, 0.2, 0.125, 0.0909091, 0.0714285
 *
 *  Run-2
 *      Input 	Negative number
 *      Output  Not valid number
 *
 *  Run-3
 *      Input 	Big number
 *      Output  Out of range
 *
 */

#include <stdio.h>
#include <math.h>

#define LIMIT 20 /* Maximum limit on numbers 'n' */
#define MAXVAL 200000000
#define MINVAL -200000000

int main()
{
    int AP, GP, HP, a, r, n;
    int i, j;
    char option;
	
	do
	{
	
		/* Read a, r, n */
		printf("Read the values: \n");
		printf("a = ");
		scanf("%d", &a);
			printf("r = ");
		scanf("%d", &r);
		/* More than LIMIT is invalid */
		if (a > MAXVAL)
			{
			printf("a is Not valid number\n");
			return 1;
		}
			if (a < MINVAL) 
			{
			printf("a is Not valid number\n");
			return 1;
		}
			
		
		/* More than LIMIT is invalid */
		if ((r > 20000) || (r < -20000))
		{
			printf("r is Not valid number\n");
			return 1;
		}
			
		printf("n = ");
		scanf("%d", &n);
		
		/* Check Errors */
			/* Negative numbers are invalid */
		if ( n < 0 ) 
			{
			printf("n is Not valid number\n");
			return 1;
		}
		
		/* More than LIMIT is invalid */
		if (n > LIMIT)
			{
			printf("n is  Not valid number\n");
			return 1;
		}
		
		
		/* Arithmetic Progression */
		printf("AP = ");
		for ( i = 0; i < n; i++ ) {
			printf("%d, ", a+i*r);
		}
		printf("\n");
		
		/* Geometric Progression */
		printf("GP = ");
		for ( i = 0; i < n; i++ ) {
			printf("%d, ", (int) (a * pow(r,i)));
		}
		printf("\n");
		
		/* Harmonic Progression */
		printf("HP = ");
		for ( i = 0; i < n; i++ ) {
			printf("%f, ", (double)1/(a+i*r));
		}
		printf("\n");
		
		/* check for continue */
        printf("Continue (y/n): ");
        scanf("\n%c", &option);
        
        if ( option == 'y' )
        {
            continue;
        } else
        {
            break;
        }
        
    } while (1);
		
    return 0;
}	
