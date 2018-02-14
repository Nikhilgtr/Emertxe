#include "stack.h"

int peek(Stack S)
{
	//if no elements are there in the stack, return stack is empty
	if ( S.top == -1 )
	{
		return STACKEMPTY;
	}
	
	//else return the element present at the top most in the stack
	return S.Sarray[S.top];
}
