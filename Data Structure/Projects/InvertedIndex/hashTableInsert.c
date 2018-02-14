#include "invertedIndex.h"

int hashTableInsert(hash_table_t *HT, int index, char *word, int file_count, int total_word_count, SLink *file_word_array[])
{
	
	int i;

	//create newNode and update newnode data and link
	node_t *new = malloc(sizeof(node_t));

	//memory for the node
	if (NULL == new)
	{
		return FAILURE;
	}
	

	//create a node using the key and value
	strcpy(new -> word, word);
	new -> link = NULL;	
	new -> filetable = *file_word_array; 
	new -> f_count = file_count;
		
	//take local reference
	node_t *temp = HT -> table[index];
		
	//update the links and the pointer to the link in the table
	//when no elements are added yet	
	if(HT -> table[index] == NULL)
	{
		HT -> table[index] = new;
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

		

