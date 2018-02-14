#include "queue.h"

int dequeue(Queue *Q, data_t *data)
{

	/* take a local reference of head */
	SLink *temp = Q -> rear;
	
	//check for Queue empty
	if ( ( ((Q -> front) == NULL) && ((Q -> rear) == NULL) ) || ((Q -> front) > (Q -> rear)) )
	{
		return QEMPTY;
	}
	//get the data and return the value in data
	(*data) = (Q -> front) -> data;

	/* check for if list has only one node */
	if ((Q -> front) == (Q -> rear))
	{
		/* free the tail node, and update tail and head with null */
		free(temp);
		Q -> front = NULL;
		Q -> rear = NULL;
		return SUCCESS;
	}
	else
	{
		printf("hereh rear= %d\n", (Q -> front) -> data );
		/* if list has multiple nodes then, iterate till front-1 node */
		while((temp->link) != (Q -> front))
		{
			temp = temp -> link;
		}

		/* update that last-1 node i.e its link to null, update the front */
		temp -> link = NULL;
		(Q -> front) = temp; 
		return SUCCESS;
	}

	
	return FAILURE;
}
