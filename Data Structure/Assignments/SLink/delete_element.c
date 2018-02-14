#include "slist.h"

int delete_element(SLink **head, data_t data)
{
	/* take a local reference of head */
	SLink *temp, *temp2;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		return EMPTYLIST;
	}
	
	/* check for if list has only one node */
	if ( ((*head) -> link ) == NULL)
	{
		if (((*head) -> data) == data)
		{
			/* free the node, and update tail and head with null */
			free(temp);
			(*head) = NULL;
			return SUCCESS;
		}
		else
		{
			return NOELEMENT;
		}
	}
	//multi node
	else
	{
		/* If the element is in the head */
		if( ((*head) -> data) == data)
		{
			temp2 = (*head);
			(*head) = (*head) -> link;
			
			temp2 -> link = NULL;
			free(temp2);
		}
		else
		{
            		/* if list has multiple nodes then, iterate till tail node */
           		 while (temp -> link)
            		 {
                		/* check if next node is given element */
               			 if (((temp->link)-> data ) != data)
                		 {
                  			/* if no element is found at all then return */
                    			if (((temp->link)-> link ) == NULL)
					{
						return NOELEMENT;
					}
                    			temp = temp -> link;
                		}
                		else
                		{
                    			/* if element is present break */
                    			break;
                		}
                
            		}
	
			/* take a local reference to the element node */
			temp2 = temp -> link;

			/* update that node's link, free the next node that contains element */
			(temp -> link) = temp2 -> link;
			free(temp2);
		}
		return SUCCESS; 
	}
	printf("not entering any cond\n");	
	return FAILURE;
}
