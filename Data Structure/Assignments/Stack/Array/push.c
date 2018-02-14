#include "stack.h"

int push(Stack *S, data_t data)
{
	//check if stack is full if s return stack is full
	if ( (S -> top) == (STACKSIZE - 1) )
	{
		return STACKFULL;
	}
	//else, increment the top by 1
	(S -> top)++;
	//save the data at that place in the array
	S -> Sarray[S -> top] = data;
	//return success
	return SUCCESS;

}

