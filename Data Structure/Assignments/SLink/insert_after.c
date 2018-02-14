#include "slist.h"

int insert_after(SLink **head, data_t a_data, data_t n_data)
{
	/* take a local reference of head */
	SLink *temp;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		return EMPTYLIST;
	}

	//create newNode and update newnode data and link
	SLink *new = malloc(sizeof(SLink));

	if (NULL == new)
	{
		return FAILURE;
	}

	new -> data = n_data;
	new -> link = NULL;

	/* check for if list has only one node */
	if ( ((*head) -> link) == NULL)
	{
		/* if the node is the given element after which we need to add newNode*/
		if (((*head) -> data) == a_data)
		{
			/* update first + newNode */
			((*head) -> link) = new;
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
				if (temp -> link == NULL)
                    		{
                       			return NOELEMENT;
                    		}
			}
			else
			{
				// if element is present break 
				break;
			}
			temp = temp -> link;
		}
		//check for end node
		if (temp -> link == NULL )
		{
			/* update last + newNode */
			(temp -> link) = new;
			return SUCCESS;	
		}
		else
		{
			/* update the newNode's link */
			new -> link = temp -> link;
			/* update current node + newNode*/			
			temp -> link = new;
			return SUCCESS;
		}
	}
	return FAILURE;
}
