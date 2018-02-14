#include "slist.h"

void print_list(SLink *head)
{
	//take local reference to traverse through the link
	SLink *temp = head;
	
	//iterate and print 
	while(temp)
	{
		printf("%d ", temp -> data);
		temp = temp -> link;
	}
	printf("\n");
}
