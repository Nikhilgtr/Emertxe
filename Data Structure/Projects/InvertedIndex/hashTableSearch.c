#include "invertedIndex.h"

int hashTableSearch(hash_table_t *HT, char *value)
{

	//print hashtable
	//print_hashTable(HT);
	
	int key;
	
	//get the key value for the given value
	key = hash_function(value);	
	
	//printf("key :---> %d\n", key);
	
	//take local reference to Link
	node_t *temp;
	temp = HT -> table[key];
	
	//if no elements at all then do nothing	
	if(HT -> table[key] == NULL)
	{
		return NOELEMENT;
	}
	else
	{
		{
		/* if list has multiple nodes then, iterate till tail node */
         	while (temp)
         	{
			if(strcmp((temp -> word), value) == 0)
			{
				printf("%s :\t", temp -> word);
				//print values
				printf("%s ", temp -> filetable -> f_name);
				printf("%d ;\n", temp -> filetable -> data);
			}
			temp = temp -> link;
		}
		return SUCCESS;
		}
		
		return FAILURE;
		
	}
	
}
