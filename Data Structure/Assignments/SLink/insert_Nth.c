#include "slist.h"

int insert_Nth(SLink **head, int index, data_t data)
{
	int i;
	
	//local reference to traverse through the link
	SLink *temp;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		if (index == 0)
		{
			insert_at_first(head, data);
			return SUCCESS; 
		}
		else
		{
			return NOELEMENT;
		}
	}
	else
	{
		// if single node
		if ( ((*head) -> link) == NULL)
		{
			if (index == 0)
			{
				insert_at_first(head, data);
				return SUCCESS;  
			}
			else
			{
				return NOELEMENT;
			}
		}
		//for multi node case
		else
		{
			//iterate through the link to till the index value
			for(i = 0; i < index; i++)
			{
				temp = temp -> link;
				if(temp == NULL)
				{
					return NOELEMENT;
				}
			}
			//temp will be at the index value and so insert before this value
			insert_before(head, temp -> data, data);	
		
			return SUCCESS;	
		}		
	}	
	return FAILURE;		
}
