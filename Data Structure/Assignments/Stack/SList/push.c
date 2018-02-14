#include "stack.h"

int push(Stack *S, data_t data)
{

	//create a new Node
	SLink *new = malloc(sizeof(SLink));

	//check if stack is full if s return stack is full
	// If malloc fails, stack is full 
	if (NULL == new)
	{
		return STACKFULL;
	}
		
	//update the newNode, link and data
	new -> data = data;
	new -> link = NULL;

	//check if stack was empty initailly
	if ( (S -> top) == NULL)
	{
		//update the stack with newNode	
		(S -> top) = new;
		return SUCCESS;
	}
	
	
	//establish link between existing stack and newNode
	new -> link = (S -> top);
	//update the top value to current pushed value
	S -> top = new;

	return SUCCESS;

}

