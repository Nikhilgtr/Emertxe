#include "hash.h"

void hashTableDestroy(HashTable hash_table)
{
	int i;
	Link *element;
	Link *nextElement;

	//delete element by element in each table row
	for(i = 0; i <  INITIAL_SIZE; i++)
	{
		for(element = hash_table -> table[i]; element != 0; element = nextElement)
		{
			//update the element to next value
			nextElement = element -> link;
			
			//free the space
			free(element);
		}
	}
}

