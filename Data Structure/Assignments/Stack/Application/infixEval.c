#include "stack.h"

int infixEval(char infixexp[STACKSIZE])
{
	
	char prefixexp[STACKSIZE];

	//change this infixexp tp prefix
	infixToprefix(infixexp, prefixexp);

	//evaluate prefix expression and return
	return prefixEval(prefixexp);
}

/*
int infixEval(char infixexp[STACKSIZE])
{
	int infixexplen, i, j = 0;
	char data;
	
	char int_valueA, int_valueB, int_result;

	//initialize the stack for evaluation
	Stack evaluationStackArray;
	evaluationStackArray.top = -1;

	//initialize the stack for operators
	Stack operatorStackArray;
	operatorStackArray.top = -1;
	
	//get the length of the postfixexp
	infixexplen = strlen(infixexp);
	
	//push the values into stack and pop to get values from postfix exp while traversing to evaluate appropriately
	for(i = 0; i < infixexplen; i++)
	{
		//if it is not any operator, push postfixexp into evaluationStackArray	
		if(! isOperator(infixexp[i]))
		{	
			push(&evaluationStackArray, infixexp[i]);
		}
		//else, if it is an operator
		else 
		{
			while(checkPrecedence(peek(operatorStackArray)) < checkPrecedence(infixexp[i]) )
			{
				//check for precedency rule, if the top of the stack operator is less then push then push new operator
				if  ( checkPrecedence(peek(operatorStackArray)) >= checkPrecedence(infixexp[i]) )
				{
					// Pop the stack and call the value A
					pop(&evaluationStackArray, &data);
					int_valueB = data;
				
					// Pop the stack and call the value B
					pop(&evaluationStackArray, &data);
					int_valueA = data;
			
					//pop out the operator from operator stack, as it is used
					pop(&operatorStackArray, &data);
	
					//Evaluate B op A using the operator just found.
					int_result = expressionEvaluation(int_valueA, int_valueB, data);
					//printf("%d and %d: %d\n", int_valueA, int_valueB, int_result);
		
					//Push the resulting value onto the stack
					push(&evaluationStackArray, int_result);
					//printf("peek value: %d\n", peek(evaluationStackArray));
				}
				else
				{
					break;
				}	
			}
			push(&operatorStackArray, infixexp[i]);
			
		}	
	}
	
	
	while (peep(operatorStackArray) != STACKEMPTY)
	{	
		// Pop the stack and call the value A
		pop(&evaluationStackArray, &data);
		int_valueB = data;
			
		// Pop the stack and call the value B
		pop(&evaluationStackArray, &data);
		int_valueA = data;

		//pop out the operator from operator stack, as it is used
		pop(&operatorStackArray, &data);

		//Evaluate B op A using the operator just found.
		int_result = expressionEvaluation(int_valueA, int_valueB, data);
		//printf("%d and %d: %d\n", int_valueA, int_valueB, int_result);
	
		//Push the resulting value onto the stack
		push(&evaluationStackArray, int_result);
		//printf("peek value: %d\n", peek(evaluationStackArray));
	
	}

	//Pop the stack (this is the final value)
	pop(&evaluationStackArray, &data);
	return data;
}
*/
