#include "slist.h"

int insert_at_first(SLink **head, data_t data)
{
	SLink *new = malloc(sizeof(SLink));

	if (NULL == new)
	{
		return FAILURE;
	}

	//update newnode data and link
	new -> data = data;
	new -> link = NULL;

	//if empty link
	if (NULL == (*head))
	{
		(*head) = new;
		return SUCCESS;
	}
	else
	{
		//establish link between newnode and first node
		new -> link = *head;
	
		//update head
		(*head) = new;
		return SUCCESS;
	}

	return FAILURE;
}
