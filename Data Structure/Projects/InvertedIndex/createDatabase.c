#include "invertedIndex.h"

int createDatabase(hash_table_t *HT, char *pathname, int file_count)
{
	FILE *fd;
	
	/* To open file to read */
	fd = fopen(pathname, "r");
        if (NULL == fd)
        {
            perror("fopen");
            return FAILURE;
        }

	/* to get the words and its count in the file */
	if ( process_word_count(fd, HT, pathname, file_count) == FAILURE )
	{
		perror("process_word_count");
		return FAILURE;	
	}

	/* close the file */
	fclose(fd);

	return SUCCESS;	
}

