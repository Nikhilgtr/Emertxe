#include "slist.h"

/* Inserts data in sorted order*/

int remove_duplicate(SLink **head)
{
	
	//to keep track of next next link for duplicate cases
	SLink *nextNext, *result;
	
	//if empty link
	if (NULL == (*head))
	{
		return EMPTYLIST;
	}

	//sort the given list
	insert_sort(head);
	
	/* take a local reference of head */
	SLink *temp;
	temp = *head;

	//if single node
	if((*head) -> link == NULL)
	{
		return SUCCESS;
	}

	{
	/* if list has multiple nodes then, iterate till tail node */
       	while (temp -> link)
      	{
		if (temp -> data != (temp -> link) -> data)
		{
			/* if no element is found at all then return */
               		if (((temp->link)-> link ) == NULL)
			{
				return SUCCESS;
			}
               		temp = temp -> link;
		}	
		else
		{
			nextNext = temp -> link;
			delete_element(head, temp -> data);
			temp = nextNext;
		}
	}
		return SUCCESS;
	}	
	return FAILURE;
}
