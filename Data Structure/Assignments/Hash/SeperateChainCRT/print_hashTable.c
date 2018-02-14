#include "hash.h"

int print_hashTable(HashTable hash_table)
{
	int i;	
	
	//take local reference to Link
	Link *element;
	
	//iterate through each link in each table row
	for(i = 0; i < INITIAL_SIZE; i++)
	{
		for(element = hash_table -> table[i]; element != NULL; element = element -> link)
		{
			//print values
			printf("%s ", element -> value);
					
		}
		printf("; ");	
	}
	printf("\n");	
}
