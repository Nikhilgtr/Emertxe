#include "stack.h"

int pop(Stack *S, data_t *data)
{
	//check if the stack is already empty
	if ( (S -> top) == -1)
	{
		//if so return Stackempty
		return STACKEMPTY;
	}
	//else, retrive the data from stack at top and save in data
	(*data) = S -> Sarray[S -> top];
	//decrement the top by 1
	(S -> top)--;
	//return Success
	return SUCCESS;
}

	 
