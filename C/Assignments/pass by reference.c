/*
 *  Q. Write a C program to swap two variables by using pass by reference method.
 *
 *  a. Read number a from user.
 *  b. Read number b from user.
 *  c. Call a swap function by passing address of both a & b.
 *  d. After swap function, a and b values should get swapped.
 *  e. Prompt for continue option.
 *
 *  Prerequisites:
 *  --------------
 *  Function Concepts.
 *  Pointer Concepts.
 *
 *  Sample Execution
 *  ----------------
 *
 *  Enter a: 10
 *  Enter b: 20
 *
 *  After swapping,
 *
 *  a === 20
 *  b === 10
 *
 *  Continue (y/n):
 *
 *
 */

#include <stdio.h>

#define MAXVAl 200000000
#define MINVAL -200000000

/* Function prototype */
void swap_generic(void * aptr, void * bptr, int size);

int main()
{
    int a, b;
    char option;
    
    do
    {
        /* Read number a from user */
        printf("Enter a: ");
        scanf("%d", &a);
        
		/* Error Check for limit */
		if ((a <= MINVAL) || (a > MAXVAl))
		{
			printf("Error: a is Invalid Number. Retry\n");
			return 1;	
		} 
	   
	   
		/* Read number b from user */
        printf("Enter b: ");
        scanf("%d", &b);
		
		
		/* Error Check for limit */
		if ((b <= MINVAL) || (b > MAXVAl))
		{
			printf("Error: b is Invalid Number. Retry\n");
			return 1;	
		} 
		
        /* Call a swap function by passing address of both a & b */
        swap_generic(&a, &b, sizeof(a));
        
        /* print values after swap */
        printf("After swap a: %d\n", a);
        printf("After swap b: %d\n", b);
        
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

void swap_generic(void * aptr, void * bptr, int size)
{
    int i;
    char temp;
    
    for ( i = 0; i < size; i++ ) 
	{
        temp = * (char *) aptr;
        * (char *) aptr++ = * (char *) bptr;
        * (char *) bptr++ = temp;
    }
}
