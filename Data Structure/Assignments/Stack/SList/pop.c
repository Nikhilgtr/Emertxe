#include "stack.h"

int pop(Stack *S, data_t *data)
{
	//if stack is empty, return stackempty
	if ( S -> top == NULL )
	{
		return STACKEMPTY;
	}
	else
	{
		//take a local reference to traverse along the stack
		SLink *temp = S -> top;
	
		//check if only one node is there
		if(temp -> link == NULL)
		{
			//retrive the data from stack at top and save in data and free
			(*data) = S -> top->data;
			S -> top = NULL;
			free(S -> top);
			
		}
		else
		{
			//retrive the data from stack at top and save in data and free
			(*data) = S -> top->data;

			/* if list has multiple nodes then, update top and free the topmost node */
			S -> top = (S -> top -> link);
			free(temp);
			
		}
		return SUCCESS;
	}
	return FAILURE;
}

	 
