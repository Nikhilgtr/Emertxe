#include "invertedIndex.h"

int delete_list(SLink **head);

void hashTableDestroy(hash_table_t *HT)
{
	int i;
	//take local reference to Link
	node_t *element;
	node_t *nextElement;


	//delete element by element in each table row
	//iterate through each link in each table row
	for(i = 0; i < SIZE; i++)
	{
				
		for(element = HT -> table[i]; element != NULL; element = nextElement)
		{
			
			printf("%d:", i);
			////update the element to next value
			nextElement = element -> link;	
			
			//delete the file_word_count list array
			//delete_list(&element -> filetable);

			while (element)
			{ // set curr to head, stop if list empty.
    				element -> filetable = element -> filetable->link;    // advance head to next element.
    				delete_list(&element -> filetable);                // delete saved pointer.
			}
		
			//free the space
			free(element);
		}
			
	}

}

int delete_list(SLink **head)
{
	printf("here");
	/* take a local reference of head */
	SLink *temp, *temp2;
	temp = *head;


	/* check for if list is empty */
	if (NULL == (*head))
	{
		return EMPTYLIST;
	}
	
	/* iterate through the list and delete from the head till the tail */
	else
	{
		while(temp)
		{
			/* take the reference to delete the node */
			temp2 = temp;
			/* update the iterator to the next node */	
			temp = temp -> link;
			/* delete the node */
			free(temp2);
		}
		/* update the linked list as empty list */
		(*head) = NULL;
	
		return SUCCESS;	
	}	
	return FAILURE;
}
