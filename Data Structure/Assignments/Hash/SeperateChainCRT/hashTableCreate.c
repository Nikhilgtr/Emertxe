#include "hash.h"

HashTable hashTableCreate(void)
{
	
    	HashTable temptable;
	int i;

	//initialize the values for the table
	for( i = 0; i < INITIAL_SIZE; i++)
	{
		temptable -> table[i] = NULL;
	}

	return temptable;
}
