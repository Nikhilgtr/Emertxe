#include "queue.h"

int enqueue(Queue *Q, data_t data)
{
	//check if Queue is full
	if((Q -> rear) == (QSIZE - 1 ))
	{
		return QFULL;
	}
	//check if queue is empty
	if((Q -> front) == -1 )
	{
		(Q -> front)++;
	}
	//update the rear to valid position by incrementing by 1
	(Q -> rear)++;
	//save the data in the valid place in Qarray pointed ny Q -> rear
	Q -> Qarray[Q -> rear] = data;
	return SUCCESS;
}

