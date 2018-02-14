#include "hash.h"

int main()
{
	
	int choice, i = 0;
	char option;

	HashTable people;
	
	//initialize the table 
	people = hashTableCreate();
	char name[NAMELENGTH];
	int key;

	do
	{
	
	printf("Enter the option:\n");
	printf("1. Insert into HashTable\n");	
	printf("2. Search HashTable\n");	
	printf("3. Delete particular element in HashTable\n");	
	printf("4. Destroy HashTable\n");
	
	printf("Choice: ");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
			printf("Enter the name of the person: \n");
			scanf("%s", name);
			//get the key to map to hashtable
			key = hash_function(name);			
			//printf("key : %d :: value : %s\n", key, name);

			// to insert the value
			hashTableInsert(people, key, name);
			
			//print hash table			
			print_hashTable(people);
			break;
		case 2:
			printf("Enter the name of the person that needs to be searched for: \n");
			scanf("%s", name);

			//to search that element
			if(hashTableSearch(people, name) == SUCCESS)
			{
				printf("SUCCESS: element found\n");
			}
			else
			{
				printf("FAILURE: no element found\n");
			}
			printf("\n");
			break;
		case 3: 
			printf("Enter the name of the person that needs to be deleted: \n");
			scanf("%s", name);

			//to delete that element
			hashTableDelete(people, name);			
			//print hash table			
			print_hashTable(people);
			printf("\n");	
			break;
		case 4: 
			hashTableDestroy(people);
		
			//print hash table			
			print_hashTable(people);
			break;
		
		default:
			printf("Invalid entry.\n");
			break;
	}

	/* check for continue */
        printf("Continue (y/n): ");
        scanf("\n%c", &option);
        
        if ( option == 'y' )
        {
            continue;
        } else
        {
            break;
        }
        
    } while (1);
		
    return 0;
}
