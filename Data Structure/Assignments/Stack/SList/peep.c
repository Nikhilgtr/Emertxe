#include "stack.h"

int peep(Stack S)
{
	
	//if stack is empty, return stackempty
	if ( S.top == NULL )
	{
		return STACKEMPTY;
	}
	else
	{
		//take a local reference to traverse along the stack
		SLink *temp = S.top;
	
		//iterate till the last of the list and print what ever is there in the list
		while(temp)
		{
			printf("%d ", temp -> data);
			temp = temp -> link;
		}
		printf("\n");
		return SUCCESS;
	}
	return FAILURE;	
}

