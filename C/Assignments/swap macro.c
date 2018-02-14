/*
 *  Q. Define a macro swap(t,x,y) that interchanges 
 *      two arguments of type t.
 *
 *  a. Implement swap concept with the help of macro.
 *  b. The type of arguments to swap will be passed as t
 *  c. swap(int, x, y) where x and y are of types int.
 *
 *  Concepts to apply:
 *  ------------------
 *  Macro concepts
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define SWAPG(t, x, y)  \
{                       \
t temp = x;          \
x = y;                  \
y = temp;               \
}

int main()
{
    int x = 8, y = 9;
    float fx = 8.9, fy = 9.4;
    
    /* Swap int values */
    printf("Before SWAPG --> x = %d, y = %d \n", x, y);
    SWAPG(int, x, y)
    printf("After SWAPG --> x = %d, y = %d \n", x, y);
    printf("\n");
    
    /* Swap float values */
    printf("Before SWAPG --> fx = %f, fy = %f \n", fx, fy);
    SWAPG(float, fx, fy)
    printf("After SWAPG --> fx = %f, fy = %f \n", fx, fy);
    
    return 0;
}