#include "slist.h"

int reverse(SLink **head)
{
	//take local reference to traverse through the link
	SLink *temp, *nextNode, *result = NULL;
	temp = *head;
	
	//to check for empty
	if((*head) == NULL)
	{
		return EMPTYLIST;
	}
	else
	{
		//iterate to the last of a list and copy this into result in reverse order
		while(temp)
		{
			//get the next node
			nextNode = temp -> link;
			// move the node onto the result
			temp -> link = result; 
			result = temp;
			//update the temp node for iteration
			temp = nextNode;
		}
		(*head) = result;
	
		return SUCCESS;
	}
	return FAILURE;
}
