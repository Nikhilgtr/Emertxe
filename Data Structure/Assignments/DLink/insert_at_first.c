#include "dlist.h"

int insert_at_first(DLink **head, data_t data)
{
	DLink *new = malloc(sizeof(DLink));

	DLink *temp;
	temp = (*head);

	if (NULL == new)
	{
		return FAILURE;
	}

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
	
	//if non empty list
	temp -> prev = new;
	new -> next = temp;
	(*head) = new;

	return SUCCESS;
}	


