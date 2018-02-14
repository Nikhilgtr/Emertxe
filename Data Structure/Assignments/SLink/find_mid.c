#include "slist.h"

int find_mid(SLink *head)
{
	//take local reference to traverse through the link
	SLink *temp = head;

	int i, index = 0;

	/* check for if list is empty */
	if (NULL == (temp))
	{
		return EMPTYLIST;
	}
	else
	{
		//iterate to get index value as mid 
		while(temp)
		{
			index++;
			temp = temp -> link;
		}

		//check for single node
		
		if(index == 1)
		{
			return head -> data;
		
		}
		else
		{	
			index = index/2;	
			return getNth(head, index);
		}		
		
		
	}
	return FAILURE;		
}
