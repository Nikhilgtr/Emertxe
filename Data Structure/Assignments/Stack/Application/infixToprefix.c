#include "stack.h"

/*
 *	Step 1. Push “)” onto STACK, and add “(“ to end of the A
 *	Step 2. Scan A from right to left and repeat step 3 to 6 for each element of A until the STACK is empty
 * 	Step 3. If an operand is encountered add it to B
 *	Step 4. If a right parenthesis is encountered push it onto STACK
 *	Step 5. If an operator is encountered then:
 *		 a. Repeatedly pop from STACK and add to B each operator
 *			 (on the top of STACK) which has same or higher precedence than the operator.
 *	         b. Add operator to STACK
 *	Step 6. If left parenthesis is encontered then
 * 		 a. Repeatedly pop from the STACK and add to B (each operator on top of stack until a left parenthesis is encounterd)
 *		 b. Remove the left parenthesis
 *	Step 7. Exit
 *
 */

int infixToprefix(char infixexp[STACKSIZE], char prefixexp[STACKSIZE])
{
	int infixexplen, i, j = 0;
	char data;

	//initialize the stack
	Stack operatorstackArray;
	operatorstackArray.top = -1;

	//reverse the infix
	reverseString(infixexp);
		
	//get the legth of the infixexp
	infixexplen = strlen(infixexp);
	//printf("infixexplen: %d\n", infixexplen );
	
	//push the values into stack and pop to get prefix exp while traversing from back
	for(i = 0; i < infixexplen; i++)
	{
		//if it is not any operator, copy to prefixexp and increment the index			
		if(! isOperator(infixexp[i]))
		{	
			prefixexp[j] = infixexp[i];
			j++;
		}
		//else, if it is an operator
		else 
		{
			//if the operator is ')' then push this onto stack
			if(infixexp[i] == ')')
			{
				push(&operatorstackArray, infixexp[i]);
			}
			//if the operator is '(' 
			else if (infixexp[i] == '(')
			{
				
				//if there are no other inner brackets
				while (peek(operatorstackArray) != ')')
				{
					//get the operator from the top and save it onto prefix and increment the index
					pop(&operatorstackArray, &data);
					prefixexp[j] = data;
					j++;
				}
				//pop that operator out of the stack, as it is copied
				pop(&operatorstackArray, &data);				
			}
			//for any other operators 
			else
			{
				//check for precedency rule, if the top of the stack operator is less then push then push new operator
				if ( checkPrecedence(peek(operatorstackArray)) <= checkPrecedence(infixexp[i]) )
				{
					push(&operatorstackArray, infixexp[i]);
				}
				//else, 
				else
				{
					//pop out the operators and save in prefixexp till it becomes less than
					while ( checkPrecedence(peek(operatorstackArray)) >= checkPrecedence(infixexp[i]) )
					{
						pop(&operatorstackArray, &data);
						prefixexp[j] = data;
						j++;
					}
					//once the stack is cleared of that , push the new operator
					push(&operatorstackArray, infixexp[i]);
				}
			}	
		}
		

	}	

	//after the operator check, till stack becomes empty, pop the values and save in prefixexp and increment the index	
	while (operatorstackArray.top != -1)
	{
		pop(&operatorstackArray, &data);
		prefixexp[j] = data;
		j++;
	}

	//make prefixexp string
	prefixexp[j] = '\0';

	//reverse the prefixexp to get the actual exp
	reverseString(prefixexp);	
	return SUCCESS;
}

