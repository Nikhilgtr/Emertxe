#include "stack.h"

/* Algorithm:
 * 	Suppose P is an arithmetic expression in prefix notation. We will evaluate it using a stack to hold the operands.
 * 
 *    Start with an empty stack. We reverse the prefix expressionand  We scan P from left to right.
 *
 *    While (we have not reached the end of P)
 *       If an operand is found
 *          push it onto the stack
 *       End-If
 *       If an operator is found
 *          Pop the stack and call the value A
 *          Pop the stack and call the value B
 *          Evaluate B op A using the operator just found.
 *          Push the resulting value onto the stack
 *       End-If
 *    End-While
 *    Pop the stack (this is the final value)
 */

int prefixEval(char prefixexp[STACKSIZE])
{
	int prefixexplen, i, j = 0;
	char data, char_result[STACKSIZE];
	
	int int_valueA, int_valueB, int_result;
	
	//initialize the stack for evaluation
	Stack evaluationStackArray;
	evaluationStackArray.top = -1;

	//reverse the prefix exp
	reverseString(prefixexp);
	
	//get the length of the postfixexp
	prefixexplen = strlen(prefixexp);
	
	//push the values into stack and pop to get values from postfix exp while traversing to evaluate appropriately
	for(i = 0; i < prefixexplen; i++)
	{
		//if it is not any operator, push postfixexp into evaluationStackArray	
		if(! isOperator(prefixexp[i]))
		{	
			push(&evaluationStackArray, prefixexp[i]);
		}
		//else, if it is an operator
		else 
		{
			//printf("peek value A: %d\n", peek(evaluationStackArray));
			int_valueA = peek(evaluationStackArray);
			// Pop the stack and call the value A
			pop(&evaluationStackArray, &data);
			
			//printf("peek value B: %d\n", peek(evaluationStackArray));
			int_valueB = peek(evaluationStackArray);
			// Pop the stack and call the value B
			pop(&evaluationStackArray, &data);

			//Evaluate B op A using the operator just found.
			int_result = expressionEvaluation(int_valueA, int_valueB, prefixexp[i]);
			my_itoa (int_result, char_result);
			
			//printf("%d %c %d: %s = %d\n", int_valueA,  prefixexp[i], int_valueB, char_result, atoi(char_result) );	
			
			//Push the resulting value onto the stack
			push(&evaluationStackArray, int_result);
			//printf("peek value res: %d\n", peek(evaluationStackArray));
			
		}
		
	}	

	//Pop the stack (this is the final value)
	pop(&evaluationStackArray, &data);
	
	if( ( data >= '0' && data <= '9' ))
   	{
        	return ((data - '0') );
    	}
	else
	{
		return (data);
	}
	
}

/*  a. Convert integer n into a string and store the string in s.
 *  b. Return the length of string from the function.
 */
int my_itoa(int n, char *s)
{
    int count = 0, temp, i;
    
    /* Check for buf size */
    if(s == NULL)
    {
        return 0;
    }
    
    /* if number is 0 then just give zero */
    if(n == 0)
    {
        *s = '0';
        return 1;
    }
    
    /* if num is negative int */
    if(n < 0)
    {
        n *= (-1); /* make the num positive for next evaluation */
        *s++ = '-'; /* store the '-' in s[0] and */
        count++; /* increment count for string length */
    }
    
    /* to acess s buf from s[n-1] where n is the number of digits and also to add null at nth place */
    for(temp = n; temp > 0; temp /= 10, s++);
    *s = '\0';
    
    /* fill the ASCII value of each digit by getting from lsb into s[n-1] --> s[0] place */
    for(temp = n; temp > 0; temp /= 10)
    {
        
        *--s = temp % 10 + '0';
        count++; /* increment the str len */
    }
    
    
    /* returns the string len */
    rewind(stdin);
    return count;
    
}

