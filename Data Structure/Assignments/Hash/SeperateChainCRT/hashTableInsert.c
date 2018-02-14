#include "hash.h"

int hashTableInsert(HashTable hash_table, int key, char *value)
{
	
	//create newNode and update newnode data and link
	Link *new = malloc(sizeof(Link));

	//memory for the node
	if (NULL == new)
	{
		return FAILURE;
	}

	//create a node using the key and value
	new -> key = key;
	strcpy(new -> value, value);
	new -> link = NULL;
	
	//take local reference
	Link *temp = hash_table -> table[key];
	
	//update the links and the pointer to the link in the table
	//when no elements are added yet	
	if(hash_table -> table[key] == NULL)
	{
		hash_table -> table[key] = new;
		return SUCCESS;
	}
	else
	{
		//go till the last node
		while(temp -> link)
		{
			temp = temp -> link;
		}
		//update the last node with new 
		temp -> link = new;
 		return SUCCESS;	
	}
	return FAILURE;
}

