#include "queue.h"

int dequeue(Queue *Q, data_t *data)
{
	//check for Queue empty
	if ( ( ((Q -> front) == -1) && ((Q -> rear) == -1) ) || ((Q -> front) > (Q -> rear)) )
	{
		return QEMPTY;
	}
	//get the data and return the value in data
	(*data) = Q -> Qarray[Q -> front];
	//increment the front pointer to valid queque front by incrementing by 1
	(Q -> front)++;

	return SUCCESS;
}
