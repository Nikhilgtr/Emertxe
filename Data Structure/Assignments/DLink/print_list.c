#include "dlist.h"

void print_list(DLink *head)
{
	DLink *temp = head;

	while(temp)
	{
		printf("%d ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
} 
