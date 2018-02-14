#include "slist.h"

int split_alternatively(SLink *head, SLink **ahead, SLink **bhead)
{
	//take local reference to traverse through the link
	SLink *temp;
	temp = head;
	
	//check if list is empty
	if (temp == NULL)
	{
		return EMPTYLIST;
	}
	
	//if head has only one element,
	if(head -> link == NULL)
	{
		*ahead = head;
		*bhead = NULL;
		return SUCCESS;
	}		
	//if multinode
	else
	{
		//iterate to the mid of a list and copy this into alist
		while(temp)
		{
			insert_at_last(ahead, temp -> data); 
			temp = temp -> link;
			if(temp != NULL)
			{
				insert_at_last(bhead, temp -> data);
				temp = temp -> link; 
			}
		}
			
		return SUCCESS;
	}
	
	return FAILURE;

}


