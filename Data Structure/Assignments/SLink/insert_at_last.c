#include "slist.h"

int insert_at_last(SLink **head, data_t data)
{
	/* take a local reference of head */
	SLink *temp;
	temp = *head;

	SLink *new = malloc(sizeof(SLink));

	if (NULL == new)
	{
		return FAILURE;
	}

	/* update the data and link */
	new -> data = data;
	new -> link = NULL;

	/* If empty list */
	if ( NULL == (*head) )
	{
		/* update head and tail */
		(*head) = new;
		return SUCCESS;
	} 
	else
	{
		//iterate till the last
		while(temp->link)
		{
			temp = temp -> link;
		}
		/* establish link between last + new Node and updte tail */
		(temp -> link) = new;
	}
	return SUCCESS;
}
