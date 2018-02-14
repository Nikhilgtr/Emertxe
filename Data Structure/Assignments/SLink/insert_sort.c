#include "slist.h"

/* list is made in sorted order*/

int insert_sort(SLink **head)
{
	/* take a local reference of list, a node to save next node in the list and a list to hold the sorted list */
	SLink *temp; 
	SLink *result = NULL;
	temp = *head;

	if (NULL == (temp))
	{
		return EMPTYLIST;
	}
	else
	{
		while (temp) 
		{
			
			//insert this data into result in sorted way
			sorted_insert(&result, temp -> data);
			temp = temp -> link;
			
		}
		
		//replace the head with result
		*head = result;

		return SUCCESS;
	}
	
	return FAILURE;
}

