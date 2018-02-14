#include "slist.h"

int delete_last(SLink **head)
{
	/* take a local reference of head */
	SLink *temp, *temp2;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		return EMPTYLIST;
	}
	
	/* check for if list has only one node */
	if ((*head) -> link == NULL)
	{
		/* free the tail node, and update tail and head with null */
		free(temp);
		(*head) = NULL;
		return SUCCESS;
	}
	else
	{
		/* if list has multiple nodes then, iterate till tail-1 node */
		while((temp->link) ->link)
		{
			temp = temp -> link;
		}

		/* update that last-1 node i.e its link to null, free the last node */
		temp2 = temp -> link;		
		free(temp2);
		(temp -> link) = NULL;
		return SUCCESS;
	}
	
	return FAILURE;
}
