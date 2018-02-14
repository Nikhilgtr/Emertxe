#include "hash.h"

int hashTableSearch(HashTable hash_table, char *value)
{
	
	int key;
	
	//get the key value for the given value
	key = hash_function(value);	
		
	//take local reference to traverse through the list
	Link *temp;
	temp = hash_table -> table[key];

	
	//if no elements at all then do nothing	
	if(hash_table -> table[key] == NULL)
	{
		return NOELEMENT;
	}
	else
	{
		/* if list has multiple nodes then, iterate till tail node */
         	while (temp)
         	{
			if(strcmp(temp -> value, value) == 0)
			{
				return SUCCESS;
			}
			temp = temp -> link;
		}
		return FAILURE;
	}
	
}

