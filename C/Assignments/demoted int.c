/*
 *  Q. Read a float. 
 *     Print the demoted integer value without assigning to int
 *
 *
 */

 union _FLOATNUM
 {
	float FLOATNUM;
	
	struct _FLOATRANGE
	{
		unsigned int MANTESSA :23;
		unsigned int EXPONENT :8;
		unsigned char SIGN :1;
		
		 
	} floatRange;
	
 } floatNum;

#include <stdio.h>

int main()
{
  
    int exp, mask;
    
    /* Swap int values */
    printf("Enter a float value: ");
    scanf("%f", &floatNum.FLOATNUM );
    
	
    //printf("sign = %#x\n", floatNum.floatRange.SIGN);
    //printf("exponent: %d \n", floatNum.floatRange.EXPONENT);
    //printf("mantissa: %#x \n", floatNum.floatRange.MANTESSA);
    //printf("float = %f\n", floatNum.FLOATNUM);
    
    
    if (floatNum.floatRange.EXPONENT >= 127)
    {
        exp = floatNum.floatRange.EXPONENT - 127;
       // printf("exp = %d\n", exp);
        
        mask = (~((1 << (23 - exp)) - 1));
        //printf("mask = %#x\n", mask);
        
        floatNum.floatRange.MANTESSA &= mask;
        //printf("mantissa: %#x \n", floatNum.floatRange.MANTESSA);
        
        printf("demoted int value: %f \n",  floatNum.FLOATNUM);
        
    }
    else
    {
        exp = 127 - floatNum.floatRange.EXPONENT;
        floatNum.floatRange.SIGN &= 0;
        floatNum.floatRange.EXPONENT &= 0;
        floatNum.floatRange.MANTESSA &= 0;
        printf("demoted int value: %f \n",  floatNum.FLOATNUM);
    }
   
    return 0;
}