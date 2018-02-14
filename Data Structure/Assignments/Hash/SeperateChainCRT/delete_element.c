#include "hash.h"

int delete_element(Link **head, char *value)
{
	/* take a local reference of head */
	Link *temp, *temp2;
	temp = *head;

	

		/* If the element is in the head */
		if( strcmp(temp -> value, value) == 0 )
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
               			 if (strcmp((temp -> link) -> value, value) != 0 )
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
	//multi node
	
	return SUCCESS;
}
