/*
 *  Q. Implement below mentioned bitwise functions.
 *
 *  int get_nbits(int num, int n);
 *  int set_nbits(int num, int n, int val);
 *  int get_nbits_from_pos(int num, int n, int pos);
 *  int set_nbits_from_pos(int num, int n, int pos, int val);
 *  int toggle_bits_from_pos(int num, int n, int pos);
 *  void print_nbits(unsigned int num, int n);
 *
 *  Implement a library named bitwise_lib.c which contain 
 *  all above mentioned functions.
 *
 *  Create a test program to check the library functions.
 *
 *  get_nbits
 *  ---------
 *
 *  a. Read number num from user
 *  b. Read number n from user
 *  c. Fetch n number of bits from num and return 
 *      it to the called function.
 *
 *  If num is 10 and n is 2,
 *      10 ->	0 0 0 0 1 0 1 0
 *                          ---
 *
 *  Take 2 bits from LSB end of 10 (1 0) and 
 *  return the corresponding decimal of that.
 *
 *  So get_nbits(10, 2) function should return 2
 *
 *  set_nbits
 *  ---------
 *
 *  a. Read number num from user.
 *  b. Read number n from user.
 *  c. Read number val from user
 *  d. Fetch n number of bits from LSB end of val and 
 *      replace in the last n bits of num.
 *  e. Return new value of num.
 *
 *  If num is 10 and n is 3 and val is 12
 *      10 -> 	0 0 0 0 1 0 1 0
 *                        -----
 *      12 ->	0 0 0 0 1 1 0 0
 *                        -----
 *
 *  The function should return 12 (1 1 0 0)
 *
 *  get_nbits_from_pos
 *  ------------------
 *
 *  a. Read number num from user.
 *  b. Read number n from user.
 *  c. Read number pos from user.
 *  d. Fetch n number of bits from pos positionth 
 *  bit(starting 0 from LSB) of num and return the 
 *  decimal value of it.
 *
 *  If num is 12, n is 3 and pos is 4
 *              7 6 5 4 3 2 1 0
 *              ---------------
 *        12 ->	0 0 0 0 1 1 0 0
 *                    -----
 *	The function should return 3 (0 1 1).
 *
 *  set_nbits_from_pos
 *  ------------------
 *
 *  a. Read number num from user.
 *  b. Read number n from user.
 *  c. Read number pos from user.
 *  d. Read number val from user.
 *  e. Fetch n number of bits from LSB of val.
 *  f. Place those fetched bits from pos positionth 
 *      bit of num and return new value of num.
 *
 *  If num is 12, n is 3, pos is 4 and val is 20
 *                      7 6 5 4 3 2 1 0
 *                      ---------------
 *              20 ->   0 0 0 1 0 1 0 0
 *                                -----
 *              12 ->	0 0 0 0 1 1 0 0
 *                            -----
 *
 *      return value->  0 0 0 1 0 0 0 0
 *
 *  So function should return 16 (1 0 0 0 0).
 *
 *  toggle_bits_from_pos
 *  --------------------
 *
 *  a. Read number num from user
 *  b. Read number n from user
 *  c. Read number pos from user
 *  d. Invert the n number of bits from pos positionth bit of num.
 *  e. Return the new value of num
 *
 *  If num is 10, n is 3, and pos is 5
 *                  7 6 5 4 3 2 1 0
 *                  ---------------
 *          10 ->   0 0 0 0 1 0 1 0
 *                      -----
 *
 *  return value->  0 0 1 1 0 0 1 0
 *
 *  So the function should return 50 (0 0 1 1 0 0 1 0)
 *
 *  print_bits
 *  ----------
 *
 *  a. Read number num from user.
 *  b. Read number n from user.
 *  c. Do error checking
 *      -> If n is greater than integer size, 
 *          assign n value as sizeof integer.
 *  d. Print n number of bits of num from LSB end.
 *
 *  If num is 10 and n is 12, then print last 12 bits 
 *      of binary representation of 10.
 *
 *
 *  The output should be -> 0 0 0 0 0 0 0 0 1 0 1 0
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
 *  Enter the choice
 *      1. get_nbits
 *      2. set_nbits
 *      3. get_nbits_from_pos
 *      4. set_nbits_from_pos
 *      5. toggle_bits_from_pos
 *      6. print_bits
 *
 *  Choice: 3
 *
 *  Enter num	: 12
 *  Enter n		: 3
 *  Enter pos	: 5
 *
 *  Value at 12[5:3] -> 1
 *
 *  Continue (y/n):
 *
 */

#include <stdio.h>
#include "bitwise_lib.c"

#define MAXVAl 200000000
#define MINVAL -200000000

int main()
{
    int choice, givenNum, n, pos, val;
    char option;
    
    do
    {
        /* Read the choice of bitwise manipulation */
        printf("Enter the choice\n\t1. get_nbits\n\t2. set_nbits\n\t3. get_nbits_from_pos\n\t4. set_nbits_from_pos\n\t5. toggle_bits_from_pos\n\t6. print_nbits\n");
        
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                
                /* Read number num from user */
                printf("Enter num\t: ");
                scanf("%d", &givenNum);
                
				/* Error Check for limit */
				if ((givenNum <= MINVAL) || (givenNum > MAXVAl))
				{
					printf("Error:givenNum is Invalid Number. Retry\n");
					return 1;	
				} 
				
                /* Read number n from user */
                printf("Enter n	\t: ");
                scanf("%d", &n);
                
				/* Error Check for n */
				if ((n < 0) || (n > 32))
				{
					printf("Error:n is Invalid Number. Retry\n");
					return 1;	
				}
				
                /* To test get_nbits(int num, int n) */
                printf("Value get_nbits(%d, %d) ->  %d \n", givenNum, n, get_nbits(givenNum, n));
                break;
                
            case 2:
                
                /* Read number num from user */
                printf("Enter num\t: ");
                scanf("%d", &givenNum);
                
				/* Error Check for limit */
				if ((givenNum <= MINVAL) || (givenNum > MAXVAl))
				{
					printf("Error:givenNum is Invalid Number. Retry\n");
					return 1;	
				} 
				
                /* Read number n from user */
                printf("Enter n	\t: ");
                scanf("%d", &n);
                
				/* Error Check for n */
				if ((n < 0) || (n > 32))
				{
					printf("Error:n is Invalid Number. Retry\n");
					return 1;	
				}
				
                /* Read number val from user */
                printf("Enter val \t: ");
                scanf("%d", &val);
                
				/* Error Check for limit */
				if ((val <= MINVAL) || (val > MAXVAl))
				{
					printf("Error:val is Invalid Number. Retry\n");
					return 1;	
				} 
				
                /* To test set_nbits(int num, int n, int val) */
                printf("Value set_nbits(%d, %d, %d) ->  %d \n", givenNum, n, val, set_nbits(givenNum, n, val));
                break;
            
            case 3:
                
                /* Read number num from user */
                printf("Enter num\t: ");
                scanf("%d", &givenNum);
                
				/* Error Check for limit */
				if ((givenNum <= MINVAL) || (givenNum > MAXVAl))
				{
					printf("Error:givenNum is Invalid Number. Retry\n");
					return 1;	
				} 
				
                /* Read number n from user */
                printf("Enter n	\t: ");
                scanf("%d", &n);
                
				/* Error Check for n */
				if ((n < 0) || (n > 32))
				{
					printf("Error:n is Invalid Number. Retry\n");
					return 1;	
				}
				
                /* Read number pos from user */
                printf("Enter pos \t: ");
                scanf("%d", &pos);
                
				/* Error Check for pos */
				if ((pos < 0) || (pos > 32))
				{
					printf("Error:pos is Invalid Number. Retry\n");
					return 1;	
				}
				
                /* To test get_nbits_from_pos(int num, int n, int pos) */
                printf("Value get_nbits_from_pos(%d, %d, %d) ->  %d \n", givenNum, n, pos, get_nbits_from_pos(givenNum, n, pos));
                break;
                
            case 4:
                
                /* Read number num from user */
                printf("Enter num\t: ");
                scanf("%d", &givenNum);
                
				/* Error Check for limit */
				if ((givenNum <= MINVAL) || (givenNum > MAXVAl))
				{
					printf("Error:givenNum is Invalid Number. Retry\n");
					return 1;	
				} 
				
                /* Read number n from user */
                printf("Enter n	\t: ");
                scanf("%d", &n);
                
				/* Error Check for n */
				if ((n < 0) || (n > 32))
				{
					printf("Error:n is Invalid Number. Retry\n");
					return 1;	
				}
				
                /* Read number pos from user */
                printf("Enter pos \t: ");
                scanf("%d", &pos);
                
				/* Error Check for pos */
				if ((pos < 0) || (pos > 32))
				{
					printf("Error:pos is Invalid Number. Retry\n");
					return 1;	
				}
				
                /* Read number val from user */
                printf("Enter val \t: ");
                scanf("%d", &val);
                
				/* Error Check for limit */
				if ((val <= MINVAL) || (val > MAXVAl))
				{
					printf("Error:val is Invalid Number. Retry\n");
					return 1;	
				} 
				
                /* To test int set_nbits_from_pos(int num, int n, int pos, int val) */
                printf("Value int set_nbits_from_pos(%d, %d, %d, %d) ->  %d \n", givenNum, n, pos, val, set_nbits_from_pos(givenNum, n, pos, val));
                break;
                
            case 5:
                
                /* Read number num from user */
                printf("Enter num\t: ");
                scanf("%d", &givenNum);
                
				/* Error Check for limit */
				if ((givenNum <= MINVAL) || (givenNum > MAXVAl))
				{
					printf("Error:givenNum is Invalid Number. Retry\n");
					return 1;	
				} 
				
                /* Read number n from user */
                printf("Enter n	\t: ");
                scanf("%d", &n);
                
				/* Error Check for n */
				if ((n < 0) || (n > 32))
				{
					printf("Error:n is Invalid Number. Retry\n");
					return 1;	
				}
				
                /* Read number pos from user */
                printf("Enter pos \t: ");
                scanf("%d", &pos);
                
                /* Error Check for pos */
				if ((pos < 0) || (pos > 32))
				{
					printf("Error:pos is Invalid Number. Retry\n");
					return 1;	
				}
				
                /* To test int toggle_bits_from_pos(int num, int n, int pos) */
                printf("Value int toggle_bits_from_pos(%d, %d, %d) ->  %d \n", givenNum, n, pos, toggle_bits_from_pos(givenNum, n, pos));
                break;
                
            case 6:
                
                /* Read number num from user */
                printf("Enter num\t: ");
                scanf("%d", &givenNum);
                
				/* Error Check for limit */
				if ((givenNum <= MINVAL) || (givenNum > MAXVAl))
				{
					printf("Error:givenNum is Invalid Number. Retry\n");
					return 1;	
				} 
				
                /* Read number n from user */
                printf("Enter n	\t: ");
                scanf("%d", &n);
                
                /* Error Check */
                /* If n is greater than integer size, n value is size of integer */
                
                if (n > 32)
                {
                    n = 32;
                }
                
                
                /* To test void print_bits(unsigned int num, int n) */
                printf("Value int print_nbits(%d, %d) ->\n", givenNum, n);
                print_nbits(givenNum, n);
                break;
                
            default: printf("Invalid Choice \n");
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
