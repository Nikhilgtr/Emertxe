#include "sort.h"


/* Swaps int */
void swap(int * aptr, int * bptr)
{
    int temp;
    
    temp = * aptr;
    * aptr = * bptr;
    * bptr = temp;
    
}
