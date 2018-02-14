#include "dlist.h"

int insert_after(DLink **head, data_t a_data, data_t n_data)
{
	/* take a local reference of head */
	DLink *temp;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		return EMPTYLIST;
	}

	//create newNode and update newnode data and link
	DLink *new = malloc(sizeof(DLink));
	new -> data = n_data;
	new -> next = NULL;
	new -> prev = NULL;

	/* check for if list has only one node */
	if ( ((*head) -> next) == NULL)
	{
		/* if the node is the given element after which we need to add newNode*/
		if (((*head) -> data) == a_data)
		{
			/* update first + newNode */
			((*head) -> next) = new;
			(new -> prev) = *head;	
			return SUCCESS;	
		}
		else
		{
			return NOELEMENT;
		}
	}
	/* check for multi node case */
	else
	{
		/* iterate through the list till you find the element after which new data has to be added */
		while(temp)
		{
			// check if node is given element 
			if ((temp-> data ) != a_data)
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
			/* update last + newNode */
			(temp -> next) = new;
			/* update prev of newNode */
			new -> prev = temp;
			return SUCCESS;	
		}
		else
		{
			/* update the newNode's next */
			new -> next = temp -> next;
			/* update the newNode's prev */
			new -> prev = temp;
			/* update current node + newNode*/			
			temp -> next = new;
			
			return SUCCESS;
		}
	}
	return FAILURE;
}
