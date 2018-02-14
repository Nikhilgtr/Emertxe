#include "dlist.h"

int insert_at_last(DLink **head, data_t data)
{
	DLink *new = malloc(sizeof(DLink));

	if (NULL == new)
	{
		return FAILURE;
	}

	/* take a local reference of head */
	DLink *temp;
	temp = (*head);

	//update newnode data and links
	new -> data = data;
	new -> prev = NULL;
	new -> next = NULL;

	//if list is empty
	if ( NULL == (*head))
	{
		(*head) = new;
		return SUCCESS;
	}
	else 
	{
		//if non empty list
		//iterate till the last node
		while (temp -> next)
		{
			temp = temp -> next;
		}
		temp -> next = new;
		new -> prev = temp;
	
		return SUCCESS;
	}
	
	return FAILURE;
}	


