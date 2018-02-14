#include "invertedIndex.h"

int hash_function(char *value)
{
	int key;
	int i;	
	

	//takes mod of 26 for the first character of the value
	//a/A = 0.... z/Z =25
	
	//to ignore case-senstitivity
	if (*value >= 'A' && *value <= 'Z') 
	{
		key = *value - 'A';
	}
	else if (*value >= 'a' && *value <= 'z') 
	{
		key = *value - 'a';
	}

	//key value to map to the hashtable
	key = key % SIZE;	
    	return key;
}
