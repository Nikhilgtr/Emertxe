#include "stack.h"

/* Algorithm:
 * 	Suppose P is an arithmetic expression in postfix notation. We will evaluate it using a stack to hold the operands.
 *
 *    Start with an empty stack.  We scan P from left to right.
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

int postfixEval(char postfixexp[STACKSIZE])
{
	int postfixexplen, i, j = 0;
	char data;
	
	char int_valueA, int_valueB, int_result;

	//initialize the stack
	Stack evaluationStackArray;
	evaluationStackArray.top = -1;

	//get the length of the postfixexp
	postfixexplen = strlen(postfixexp);
	
	//push the values into stack and pop to get values from postfix exp while traversing to evaluate appropriately
	for(i = 0; i < postfixexplen; i++)
	{
		//if it is not any operator, push postfixexp into evaluationStackArray	
		if(! isOperator(postfixexp[i]))
		{	
			push(&evaluationStackArray, postfixexp[i]);
		}
		//else, if it is an operator
		 
		if(isOperator(postfixexp[i]))
		{
			// Pop the stack and call the value B
			pop(&evaluationStackArray, &data);
			int_valueB = data;
			
			// Pop the stack and call the value A
			pop(&evaluationStackArray, &data);
			int_valueA = data;	

			//Evaluate B op A using the operator just found.
			int_result = expressionEvaluation(int_valueA, int_valueB, postfixexp[i]);
			
			//change this int to ascii equivalent
			int_result += '0';				
			//printf("%d and %d: %d\n", int_valueA, int_valueB, int_result);	
			
			//Push the resulting value onto the stack
			push(&evaluationStackArray, int_result);
			//printf("peek value: %d\n", peek(evaluationStackArray));
				
		}
		
	}	

	//Pop the stack (this is the final value)
	pop(&evaluationStackArray, &data);
	return (data - '0');
}

