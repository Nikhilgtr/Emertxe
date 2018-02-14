/*
 * Q. Verify type promotion table using sizeof.
 *
 *  a. Compare return value of sizeof with signed values.
 *
 *  Prerequisites:
 *  --------------
 *  Type promotion Concepts.
 *
 *  I. Integral Promotion
 *
 *  Original type       -->Type after promotion
 *  ------------------------------------------
 *  unsigned char       -->unsigned int
 *  signed char         -->int
 *  unsigned short int	-->unsigned int
 *  short int           -->int
 *
 * II. Functional Promotion
 *
 * Original type       -->Type after promotion
 *  ------------------------------------------
 *  float              -->double
 *
 *  III. Arithmetic conversions
 *
 *  If the evaluation of an expression involves values of 
 *  different types various conversions are applied to one (or both)
 *  of the values to give two values of the same type as binary 
 *  arithmetic operations are only defined when applied to two 
 *  values of same type. 
 *
 *  RULE1: If either operand has type long double , 
 *  the other operand is converted to long double .
 *
 *  RULE2: If either operand has type double ,
 *  the other operand is converted to double .
 *
 *  RULE3: If either operand has type float ,
 *  the other operand is converted to type float .
 *
 *  RULE4: The integral promotions are first applied to both
 *  operands and then the following rules are applied.
 *       -->1. If either operand has type unsigned long int,
 *          the other operand is converted to unsigned long int.
 *
 *  RULE5:  If one operand has type long int and the other
 *  has type unsigned int, 
 *       -->1. If a long int can represent all values of an
 *          unsigned int, the operand of type unsigned int
 *          is converted to long int;
 *       -->2. If a long int cannot represent all the values 
 *          of an unsigned int, both operands are converted to
 *          unssigned long int
 *
 *  RULE6:  If either operand has type long int, 
 *  the other operand is converted to long int.
 *
 *  RULE7: If either operand has type unsigned int, 
 *  the other operand is converted to unsigned int.
 *
 */

#include <stdio.h>

int main()
{
    long double ldvalue = 10;
    double dvalue = 10;
    float fvalue = 10;
    int ivalue = 10;
    char cvalue = 10;
    
    unsigned char	ucvalue = 10;
    signed char	scvalue = 10;
    unsigned short int	usivalue = 10;
    short int sivalue = 10;
    
    /* Before Applying Binary Arithmetic Operation */
    printf("Before Applying Binary Arithmetic Operation: \n");
    printf("long double = %lu \n", sizeof(ldvalue));
    printf("double = %lu \n", sizeof(dvalue));
    printf("int = %lu \n", sizeof(ivalue));
    
    printf("float = %lu \n", sizeof(fvalue));
    printf("char = %lu \n", sizeof(cvalue));
    printf("unsigned char = %lu \n", sizeof(ucvalue));
    printf("signed char = %lu \n", sizeof(scvalue));
    printf("unsigned short int = %lu \n", sizeof(usivalue));
    printf("short int = %lu \n", sizeof(sivalue));
    
    
    /* After Applying Binary Arithmetic Operation */
    printf("\nAfter Applying Binary Arithmetic Operation: \n");
    printf("long double = %lu \n", sizeof(ldvalue+1));
    printf("double = %lu \n", sizeof(dvalue+1));
    printf("int = %lu \n", sizeof(ivalue+1));
    
    printf("The promotions in arithmetic contexts: \n");
    printf("float = %lu \n", sizeof(fvalue+1.7));
    printf("char = %lu \n", sizeof(cvalue+1));
    printf("unsigned char = %lu \n", sizeof(ucvalue+1));
    printf("signed char = %lu \n", sizeof(scvalue+1));
    printf("unsigned short int = %lu \n", sizeof(usivalue+1));
    printf("short int = %lu \n", sizeof(sivalue+1));
    
	return 0;
}
