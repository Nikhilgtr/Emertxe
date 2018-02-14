#include "slist.h"

int getNth(SLink *head, int index)
{
	//take local reference to traverse through the link
	SLink *temp = head;

	int i;

	/* check for if list is empty */
	if (NULL == (temp))
	{
		return EMPTYLIST;
	}
	else
	{
		//iterate through the link to till the index value
		for(i = 0; i < index; i++)
		{
			temp = temp -> link;
			if(temp == NULL)
			{
				return NOELEMENT;
			}
		}
		
		//temp will be at the index value so return the data if the index is within the list length
		return temp -> data;
	}
	return FAILURE;		
}
