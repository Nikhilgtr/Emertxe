#include "invertedIndex.h"

int save_to_database(hash_table_t *HT)
{
	FILE *fd;
	
	/* To open file to read */
	fd = fopen("backup_database.txt", "w");
        if (NULL == fd)
        {
            perror("fopen");
            return FAILURE;
        }

	save_hashTable(fd, HT);
	
	/* close the file */
	fclose(fd);

	return SUCCESS;	
}

void save_hashTable(FILE *fd, hash_table_t *HT)
{
	int i;	
	
	//take local reference to Link
	node_t *element;
	fprintf(fd, " ");
	//iterate through each link in each table row
	for(i = 0; i < SIZE; i++)
	{
		fprintf(fd, "%d.", i);
		for(element = HT -> table[i]; element != NULL; element = element -> link)
		{
			//print values
			fprintf(fd, "%s: ", element -> word);
			fprintf(fd, "%s ", element -> filetable -> f_name);
			fprintf(fd, "%d ;\t", element -> filetable -> data);	
			
		}
		fprintf(fd,"\n ");	
	}
	fprintf(fd,"\n ");
}
