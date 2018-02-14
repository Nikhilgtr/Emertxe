#include "slist.h"

int delete_list(SLink **head)
{
	/* take a local reference of head */
	SLink *temp, *temp2;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		return EMPTYLIST;
	}
	
	/* iterate through the list and delete from the head till the tail */
	else
	{
		while(temp)
		{
			/* take the reference to delete the node */
			temp2 = temp;
			/* update the iterator to the next node */	
			temp = temp -> link;
			/* delete the node */
			free(temp2);
		}
		/* update the linked list as empty list */
		(*head) = NULL;
	
		return SUCCESS;	
	}	
	return FAILURE;
}
