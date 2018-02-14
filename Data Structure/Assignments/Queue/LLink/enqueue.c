#include "queue.h"

int enqueue(Queue *Q, data_t data)
{

	//create a new Node
	SLink *new = malloc(sizeof(SLink));

	//check if queue is full if yes return queue is full
	// If malloc fails, queue is full 
	if (NULL == new)
	{
		return QFULL;
	}
	
	//update the newNode, link and data
	new -> data = data;
	new -> link = NULL;
	
	//check if queue is empty
	if((Q -> front) == NULL )
	{
		(Q -> front) = new;
		(Q -> rear) = new;
		return SUCCESS;
	}
	else
	{
		//establish link between newnode and rear end node
		new -> link = (Q -> rear);
		
		//update head
		(Q -> rear) = new;
		return SUCCESS;
	}
	
	return FAILURE;	
}



