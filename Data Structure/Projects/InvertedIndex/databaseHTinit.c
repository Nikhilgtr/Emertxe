#include "invertedIndex.h"

void databaseHTinit(hash_table_t *HT)
{
	int i;
	for(i = 0; i < SIZE; i++)
	{
		HT -> table[i] = NULL;
	}	
}
