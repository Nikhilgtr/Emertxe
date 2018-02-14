/*  
 *  Q. Variance calculation with dynamic arrays
 *
 *  a. Create a dynamic array to store n integers.
 *      -> Get the integer count through command line.
 *  b. Read n integers from user.
 *  c. Output the variance of entered numbers.
 *
 *
 *  Hints:
 *  -> Use the following steps to calculate variance.
 *
 *  a. Determine a set of numbers.
 *      For example, 1, 2, 3, 4 and 5.
 *  b. Subtract each of the numbers in the set by the mean number,
 *  which is the number that's value is in the middle of the set.
 *  The mean number in the example set is 3.
 *
 *  1 - 3 = -2
 *
 *  2 - 3 = -1
 *
 *  3 - 3 = 0
 *
 *  4 - 3 = 1
 *
 *  5 - 3 = 2
 *
 *  c. Square all the numbers that you obtained from
 *  subtracting each set number by the mean:
 *
 *  -2 squared = 4
 *
 *  -1 squared = 1
 *
 *   0 squared = 0
 *
 *   1 squared = 1
 *
 *   2 squared = 4
 *
 *	d. Add the results: 4 + 1 + 0 + 1 + 4 = 10
 *	e. Divide the sum of the numbers by the number of numbers
 *      in the set: 10 / 5 = 2
 *	f. The variance for the example set of numbers is 2.
 *
 *
 *  Sample Execution
 *  ----------------
 *
 *  ./a.out 5
 *
 *  Enter 5 numbers:
 *
 *  [0] -> 1
 *  [1] -> 2
 *  [2] -> 3
 *  [3] -> 4
 *  [4] -> 5
 *
 *  The variance of entered numbers is 2
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXLEN 256
#define MAXVAL 20000000
#define MINVAL -20000000

int main(int argc, char **argv)
{
    int intCount, i;
    int *intArray;
    int variance, mean, sum;
    
    /* Do arg count check */
    if (argc != 2)
    {
        printf("Invalid entry: ./assignment36 <size> \n");
        exit(1);
    }
    else
    {
        /* Error Check for limit */
        if (((atoi(argv[1])) < 0) || ((atoi(argv[1])) > MAXLEN))
        {
            printf("Error: value is Invalid Number size. Retry\n");
            return 1;
        }
        intCount = (atoi(argv[1]));
    }

    int * const ptr = (int *)malloc(intCount * sizeof(int));
    
    if (NULL == ptr)
    {
        printf("Error: Malloc allocation failure.\n");
        return -1;
    }
    intArray = ptr;
    
    printf("Enter 5 numbers: \n");
    for (i = 0; i < intCount; i++)
    {
        printf("[%d] -> ", i);
        scanf("%d", &intArray[i]);
        
        /* Error Check for limit */
        if (((intArray[i]) < MINVAL) || ((intArray[i]) > MAXVAL))
        {
            printf("Error: Out of range. Retry\n");
            return 1;
        }
        
    }
    
    /*  Compute the mean of all elements */
    for (i = 0; i < intCount; i++)
    {
        sum += intArray[i];
    }
    mean = sum / intCount;
    sum = 0;
    
    /*  Compute  variance */
    for (i = 0; i < intCount; i++)
    {
        sum = sum + pow((intArray[i] - mean), 2);
    }
    variance = sum / intCount;
    
    printf("The variance of entered numbers is %d\n", variance );

    free(ptr);
    intArray = NULL;
    
    return 0;
}
