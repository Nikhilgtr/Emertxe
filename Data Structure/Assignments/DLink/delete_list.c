#include "dlist.h"

int delete_list(DLink **head)
{
	/* take a local reference of head */
	DLink *temp;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		return EMPTYLIST;
	}
	/* iterate through the list and delete from the head till the tail */
	else
	{
		
		while(temp -> next)
		{
			/*
			// update the iterator to the next node 	
			temp = temp -> next;
			// unlink the previous node 
			(temp -> prev) -> next  = NULL;
			// free the previous node 
			free((temp -> prev));
			*/
			delete_first(&temp);
		}
		// update the linked list as empty list 
		(*head) = NULL;	
		
			
		return SUCCESS;	
	}	
	return FAILURE;
	
}
