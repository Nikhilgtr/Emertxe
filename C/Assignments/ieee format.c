/*  
 * Q. Print bits of float & double. Check IEEE std.
 *
 *  a. Read the choice from user.
 *      -> float or double
 *  b. Read the fractional number from user.
 *  c. Print the bits of the entered number.
 *
 *  Concepts to apply
 *  -----------------
 *  IEEE standard
 *  floating point numbers
 *  Bitwise Operators.
 *
 *  Sample Execution
 *  ----------------
 *
 *  Enter the Choice:
 *      1. float
 *      2. double
 *
 *  Choice: 1
 *
 *  Enter the float value: 2.3
 *
 *  Sign    Mantissa                        Exponent
 *  ---------------------------------------------------------
 *   0     10000000   0 0 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1
 *
 *  Continue(y/n):
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "bitwise_lib.c"

int main()
{
  
    unsigned int ival, mantissa, exponent, sign;
    unsigned long int ilval, lmantissa;
    
    int choice;
    char option;
    
    float actualnum;
    double actualdoublenum;
    
    do
    {
        printf("Enter the Choice:\n \t1. float \t2. double\n");
    
        printf("Choice: ");
        scanf("%d", &choice);
        
        /* For Sign Bit:
         * If the number is positive, sign bit is 0 
         * else 1
         */
        
        /*
         * To calculate Mantessa
         */
        
        switch (choice) {
            case 1:
                printf("Enter the float value: ");
                scanf("%f", &actualnum);
                
                printf("Float Mantessa and Exponent\n");
                
                /* actual number */
                ival = *((unsigned int *)&actualnum);
                
                /* and with mask to get only 23 mantissa bits */
                mantissa = ( ival & 0x7FFFFF);
                
                /* remove the 23 mantessa bits by shift right */
                ival = ival >> 23;
                
                /* and with mask to get only 8 exponent bits */
                exponent = ( ival  & 0xFF );
                
                /* remove the 8 exponent bits by shift right */
                ival = ival >> 8;
                
                /* and with mask = 0x01 to get only 1 sign bits */
                sign = ( ival & 0x01 );
                
                /* print the values */
                printf("sign = \n%x\n", sign);
                printf("exponent = ");
                print_nbits(exponent,8);
                printf("mantissa = ");
                print_nbits(mantissa,23);
                
                break;
            
            case 2:
                printf("Enter the double value: ");
                scanf("%lf", &actualdoublenum);
                
                printf("Double Mantessa and Exponent\n");
                
                /* actual number */
                ilval = *((unsigned long int *)&actualdoublenum);
                
                /* and with mask to get only 52 mantissa bits */
                lmantissa = ( ilval & 0xFFFFFFFFFFFFF);
                
                /* remove the 52 mantessa bits by shift right */
                ilval = ilval >> 52;
                
                /* and with mask to get only 11 exponent bits */
                exponent = ( ilval  & 0x7FF );
                
                /* remove the 11 exponent bits by shift right */
                ilval = ilval >> 11;
               
                /* and with mask = 0x01 to get only 1 sign bits */
                sign = ( ilval & 0x01 );
                
                printf("sign = \n%x\n", sign);
                printf("exponent = ");
                print_nbits(exponent,11);
                printf("mantissa = ");
                ilval = lmantissa;
                
                /* as print_nbits can handle only 32 bits at a time 
                 * shift the lmantissa 31 bits and then 
                 *  print the next 21 bits
                 */
                ilval = ilval >> 31;
                print_nbits(ilval,21); /* print in order */
                print_nbits(lmantissa,31);
                
                break;
            
            default:
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
