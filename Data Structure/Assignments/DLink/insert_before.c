#include "dlist.h"

int insert_before(DLink **head, data_t b_data, data_t n_data)
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
		/* if the node is the given element before which we need to add newNode*/
		if (((*head) -> data) == b_data)
		{
			//establish link between newnode and first node
			new -> next = *head;
			(*head) -> prev = new;

			//update head
			(*head) = new;
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
		/* If the element is in the head */
		if( ((*head) -> data) == b_data)
		{
			//establish link between newnode and first node
			new -> next = *head;
			(*head) -> prev = new;

			//update head
			(*head) = new;
			return SUCCESS;	
		}
		/* If the element is in the middle or end */
		else
		{
			/* if list has multiple nodes then, iterate till tail node */
           		while(temp)
			{
				// check if node is given element 
				if ((temp-> data ) != b_data)
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

			/* update new Node's next to temp that contains b_data */
			new -> next = temp;
			/* update new Node's prev to temp->prev */
			new -> prev = temp -> prev;

			/* update previous Node's next to new Node*/
			(temp -> prev) -> next = new;
			/* update temp -> prev to new Node */
			temp -> prev = new;
			return SUCCESS;			
		}
	}
	return FAILURE;
}
