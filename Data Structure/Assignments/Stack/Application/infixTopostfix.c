#include "stack.h"

/* Algorithm:
 * 	Step1. Scan the Infix string from left to right.
 *	Step2. Initialize an empty stack.
 *	Step3. If the scanned character is an operand, add it to the Postfix string.
 *	Step4. If the scanned character is an operator and if the stack is empty push the character to stack.
 *	Step5. If the scanned character is an Operator and the stack is not empty, 
 *		compare the precedence of the character with the element on top of the stack.
 *	Step6. If top Stack has higher precedence over the scanned character pop the stack else push the scanned character to stack.
 *		Repeat this step until the stack is not empty and top Stack has precedence over the character.
 *	Step7. Repeat 4 and 5 steps till all the characters are scanned.
 *	Step8. After all characters are scanned, we have to add any character that the stack may have to the Postfix string.
 *	Step9. If stack is not empty add top Stack to Postfix string and Pop the stack.
 *	Step10. Repeat this step as long as stack is not empty.
 */

int infixTopostfix(char infixexp[STACKSIZE], char postfixexp[STACKSIZE])
{
	int infixexplen, i, j = 0;
	char data;

	//initialize the stack
	Stack operatorstackArray;
	operatorstackArray.top = -1;
	
	//get the legth of the infixexp
	infixexplen = strlen(infixexp);
	//printf("infixexplen: %d\n", infixexplen );
	
	//push the values into stack and pop to get postfix exp while traversing
	for(i = 0; i < infixexplen; i++)
	{
		//if the operator is '(' then push this onto stack
		if(infixexp[i] == '(')
		{
			push(&operatorstackArray, infixexp[i]);
		}
		else if(! isOperator(infixexp[i]))
		{	
			postfixexp[j] = infixexp[i];
			j++;
		}
		//if the operator is ')' 
		else if (infixexp[i] == ')')
		{
			//if there are no other inner brackets
			while (peek(operatorstackArray) != '(')
			{
				//get the operator from the top and save it onto postfix and increment the index
				pop(&operatorstackArray, &data);
				postfixexp[j] = data;
				j++;
			}
			//pop that operator out of the stack, as it is copied
			pop(&operatorstackArray, &data);				
		}
		//for any other operators 
		else
		{
			//pop out the operators and save in prefixexp till it becomes less than
			while ( checkPrecedence(peek(operatorstackArray)) >= checkPrecedence(infixexp[i]) )
			{
				pop(&operatorstackArray, &data);
				postfixexp[j] = data;
				j++;
			}
			//once the stack is cleared of that , push the new operator
			push(&operatorstackArray, infixexp[i]);
		}		

	}	

	//after the operator check, till stack becomes empty, pop the values and save in prefixexp and increment the index	
	while (operatorstackArray.top != -1)
	{
		pop(&operatorstackArray, &data);
		postfixexp[j] = data;
		j++;
	}

	//make prefixexp string
	postfixexp[j] = '\0';

	return SUCCESS;
}

