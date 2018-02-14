/*
 *  Q. Define a macro SIZEOF(x), where x is a variable,
 *      without using sizeof operator.
 *
 *  a. Treat address of x and address of x + 1 as 
 *      characters address.
 *  b. Both addresses difference will be sizeof x
 *
 *  Concepts to apply:
 *  ------------------
 *
 *  Macro concepts
 *  Pointer type casting concepts
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZEOF(x) (char *)(&x+1) -  (char *)(&x)
int main()
{
    int x = 8;
    float fx = 8.9;
    char cx = 'y';
    double dx = 0.7;
    
    /* SIZEOF int values */
    printf("int SIZEOF --> x = %lu \n", SIZEOF(x));
    printf("\n");
    
    /* SIZEOF float values */
    printf("float SIZEOF --> fx = %lu \n", SIZEOF(fx));
    printf("\n");
    
    /* SIZEOF char values */
    printf("char SIZEOF --> cx = %lu \n", SIZEOF(cx));
    printf("\n");
    
    /* SIZEOF double values */
    printf("double SIZEOF --> dx = %lu \n", SIZEOF(dx));
    printf("\n");
    return 0;
}