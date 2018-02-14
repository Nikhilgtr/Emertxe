#include "invertedIndex.h"

int main(int argc, char **argv)
{
	int choice, i;
	char option;
	
	hash_table_t inverted_HT;
	int file_count = 0;

	char searchWord[NAMELENGTH];	

	//check for argc
	if(argc < 2)
	{
		printf("Invalid arguments.\n");
		printf("Usage: ./a.out <file> [FILES..] \n");
		return -1;
	}

	do
	{
		printf("Enter the option:\n");
		printf("1. initialization\n");
		printf("2. Search for a word\n");	
		printf("3. Save the database\n");	
		printf("4. Update to existing database\n");	
		printf("5. Destroy HashTable\n");
		printf("6. Print Database\n");
				
		printf("Choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				//initialize the database
				databaseHTinit(&inverted_HT);
				file_count = argc - 1;
				
				//create database for given files
				for(i = 1; i < argc; i++)
				{
				createDatabase(&inverted_HT, argv[i], file_count);				
				}				
				//createDatabase(&inverted_HT, argv[2], file_count);

				//print wat is there in current database
				print_hashTable(&inverted_HT);
				break;

			case 2:
				printf("Enter the word that needs to be searched in the database: ");
				scanf("%s", searchWord);

				//print_hashTable(&inverted_HT);

				//search in inverted hashtable
				if(hashTableSearch(&inverted_HT, searchWord) == SUCCESS)
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
				save_to_database(&inverted_HT);
				printf("Saved in file 'backup_database.txt'\n");
				break;
			case 4:
				printf("DATABASE Updated\n");
break;
			case 5:

				printf("Hash Table destroyed\n");
				//hashTableDestroy(&inverted_HT);
			//	print_hashTable(&inverted_HT);
				break;
			case 6:
				print_hashTable(&inverted_HT);
				break;
		
		
			default:
				printf("Invalid option\n");
				break;
		}

		/* check for continue */
        	printf("Continue (y/n): ");
        	scanf("\n%c", &option);
            
    	} while (option == 'y');
	return 0;	
}

