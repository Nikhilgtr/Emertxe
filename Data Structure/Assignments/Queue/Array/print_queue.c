#include "queue.h"

void print_queue(Queue Q)
{
	int i;
	//print the values present from front till rear in the queue
	for(i = Q.front; i <= Q.rear; i++)
	{
		printf("%d ", Q.Qarray[i]);
		
	}
	printf("\n");
}
