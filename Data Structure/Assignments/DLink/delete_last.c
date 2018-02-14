#include "dlist.h"

int delete_last(DLink **head)
{
	/* take a local reference of head */
	DLink *temp;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		return EMPTYLIST;
	}

	/* check for if list has only one node */
	if ( ((*head) -> next) == NULL)
	{
		/* free the node, and update head with null */
		free(temp);
		(*head) = NULL;
		return SUCCESS;
	}
	else
	{
		/* if list has multiple nodes then, update last -1 node and free the last node */

		/* iterate till last node */
		while((temp -> next))
		{
			temp = temp -> next;
		}

		// update last - 1's next link to null
		(temp -> prev) -> next = NULL;
 
		//free the last element
		free(temp);
		return SUCCESS;
	}
	
	return FAILURE;
}
