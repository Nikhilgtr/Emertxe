#include "slist.h"

int countKey(SLink *head, data_t data)
{
	//take local reference to traverse through the link
	SLink *temp;
	temp = head;
	
	//take variable for count
	int count = 0;

	//to check for empty
	if(head == NULL)
	{
		return EMPTYLIST;
	}
	else
	{
		//iterate to the last of a list and copy this into alist
		while(temp)
		{
			if(temp -> data == data)
			{
				count++;
			}
			temp = temp -> link; 
		}
	
		return count;
	}

	return FAILURE;
}
