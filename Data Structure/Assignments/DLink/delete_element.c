#include "dlist.h"

int delete_element(DLink **head, data_t data)
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
		/* check if the element is the one that needs to be deleted */
		if (((*head) -> data) == data)
		{
			/* free the node, and head with null */
			free(temp);
			(*head) = NULL;
			return SUCCESS;
		}
		else
		{
			return NOELEMENT;
		}
	}
	/* if list has multiple nodes */
	else
	{
		/* If the element is in the head then check for next values */
		if( ((*head) -> data) == data)
		{
			//update the head to next value
			(*head) = (*head) -> next;
			//unlink the previous node and free 
			((*head) -> prev) -> next = NULL;
			free((*head) -> prev);
			//update the prev of head to null
			(*head) -> prev = NULL;
		}
		/* iterate till last node */
		else
		{
			while(temp)
			{
				// check if node is given element 
				if ((temp-> data ) != data)
                		{
					// if no element is found at all then return
					if (temp -> next == NULL)
                    			{
                        			return NOELEMENT;
                    			}
				}
				else
				{
					// if element is present break 
					break;
				}
				temp = temp -> next;		
			}
			//check for end node
			if (temp -> next == NULL )
			{
				// unlink the node
				(temp -> prev) -> next = NULL;
				free(temp);
			}
			else
			{
				/* update that node's link, free the node that contains element */
				(temp -> prev) -> next = temp -> next;
				(temp -> next) -> prev = temp -> prev;

				/* unlink the node that has element */
				temp -> prev = NULL;
				temp -> next = NULL;
				free(temp);
			}
		}
		
		return SUCCESS;
	}
	return FAILURE;
}


