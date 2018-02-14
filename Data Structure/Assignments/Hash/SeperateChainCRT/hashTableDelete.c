#include "hash.h"

void hashTableDelete(HashTable hash_table, char *value)
{
	
	int key;
	
	//get the key value for the given value
	key = hash_function(value);	
		
	//take local reference to traverse through the list
	Link *temp, *temp2;
	temp = hash_table -> table[key];

	
	//if no elements at all then do nothing	
	if(hash_table -> table[key] == NULL)
	{
		return;
	}
	else
	{
		if (temp -> link == NULL)
		{
			if(strcmp(temp -> value, value) == 0)
			{
				free(temp);
				hash_table -> table[key] = NULL;
				return;
			}			
		}
		else
		{
			delete_element( &hash_table -> table[key], value);
			
		}
		return;
	}
	
}

