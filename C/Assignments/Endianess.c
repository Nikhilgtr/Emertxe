/*  
 *  Q. Check for your Endianess of your processor
 *
 *  a. Check the memory assigning order of variables 
 *  for checking whether litte endian or big endian machine
 *
 *  Little Endian:
 *  --------------
 *
 *  int i = 10;
 *
 *  will be stored in memory as
 *
 *	1000
 *	1001
 *	1002
 *	1003
 *
 *  where 1000 contains LSB and 1003 contains MSB
 *
 *  char *ptr = &i;
 *
 *	ptr is now containg 1000
 *
 *  Big Endian:
 *  -----------
 *
 *  int i = 10;
 *
 *  will be stored in memory as
 *
 *	1000
 *	1001
 *	1002
 *	1003
 *
 *   where 1000 contains MSB and 1003 contains LSB
 *
 *  char *ptr = &i;
 *
 *	ptr is now containg 1000
 *
 *
 *  Fetch the values pointed by ptr for knowing whether
 *  they stored as little endian or big endian format.
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

union Endian
{
    int int_val;
    char byte[4];
};


int main()
{
    char value[3] = "AB";
    char *ptr = (char *)&value;
    
    union Endian e;
    
    /* METHOD 1*/
    /*
    printf ("%p has %c\n", ptr, *ptr);
    if (*ptr == 'A') {
         printf("Little Endian\n");
    }
    else
    {
        printf("Big Endian\n");
    }
    ptr = ptr+sizeof(char);
    printf ("%p has %c\n", ptr, *ptr);
    */
    /* METHOD 2*/
    
    e.int_val = 1;
    if (e.byte[0] == 1)
    {
        printf("Little Endian\n");
    }
    else
    {
        printf("Big Endian\n");
    }
    
    return 0;
}

