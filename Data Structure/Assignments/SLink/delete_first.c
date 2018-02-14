#include "slist.h"

int delete_first(SLink **head)
{
	/* take a local reference of head */
	SLink *temp;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		return EMPTYLIST;
	}
	
	/* check for if list has only one node */
	if ((*head) -> link == NULL)
	{
		/* free the node, and update tail and head with null */
		free(temp);
		(*head) = NULL;
		return SUCCESS;
	}
	else
	{
		/* if list has multiple nodes then, update head and free the first node */
		(*head) = ((*head) -> link);
		free(temp);
		return SUCCESS;
	}
	
	return FAILURE;
}
