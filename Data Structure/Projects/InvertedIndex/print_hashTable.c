#include "invertedIndex.h"

int print_hashTable(hash_table_t *HT)
{
	int i;	
	
	//take local reference to Link
	node_t *element;
	
	//iterate through each link in each table row
	for(i = 0; i < SIZE; i++)
	{
		printf("%d ", i);
		for(element = HT -> table[i]; element != NULL; element = element -> link)
		{
			//print values
			printf("%s: ", element -> word);
			printf("%s ", element -> filetable -> f_name);
			printf("%d ;\t", element -> filetable -> data);		
		}
		printf("\n ");	
	}
	printf("\n");	
}
