#include "slist.h"

/* Inserts data in sorted order*/

int sorted_insert(SLink **head, data_t data)
{
	/* take a local reference of head */
	SLink *temp;
	temp = *head;

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

	//case for single node
	if ((*head) -> link == NULL)
	{
		if ( ((*head) -> data) >= data )
		{
			new -> link = *head;
			(*head) = new;
			return SUCCESS;
		}
		else
		{
			(*head) -> link = new;
			return SUCCESS;
		}
	}
	//multi node	
	else	
	{
		//traverse through the list
		while(temp)
		{
			//if list data is greater than the given data, then add before this node
			if ( (temp -> data) >= data )
			{
				insert_before(head, temp -> data, data);
				return SUCCESS;
			}
			//if the list data is less than given data that needs to be inserted
			else if ( (temp -> data) < data )
			{
				/* if no element is found at all then return */
                    		if ((temp->link) == NULL)
				{
					//if last node is reached, then add the new node in the end
					temp -> link = new;
					return SUCCESS;
				}
			}
			//update the link	
			temp = temp -> link;
		}

	}
	return FAILURE;
}
