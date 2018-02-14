#include "stack.h"

int peep(Stack S)
{
	//take a local reference to traverse along the stack
	int temp = S.top;

	do
	{
		//if stack is empty, return stackempty
		if ( (temp) == -1 )
		{
			return STACKEMPTY;
		}
		//print the value present at that place
		printf("%d ", S.Sarray[temp]);
		//decrement the temp by one and repeat till all elements are printed
		(temp)--;
	} while(temp != -1);

	printf("\n");
	return SUCCESS;

}

