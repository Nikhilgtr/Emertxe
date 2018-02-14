#include "invertedIndex.h"
int update_wordfreq(struct word_count_table_t s[], const char unit[], int count);
int insert_at_last(SLink **head, int data, char *pathname);
void print_list(SLink *head);

int process_word_count(FILE *fd, hash_table_t *HT, char *pathname, int file_count)
{
	int read_len;
	char buff[BUFF_SIZE];
	char unit[BUFF_SIZE];
	//struct word_count_table_t word_freq_array[BUFF_SIZE + 1]; //array of datatype struct word_count_table_t

	//forward index	
	struct word_count_table_t *word_freq_array; //array of datatype struct word_count_table_t
	word_freq_array = malloc(sizeof(struct word_count_table_t) * 10);

	//update file and word count table
		
	int index, count = 0;
	int word_freq;
	
	int i, j = 0;

	//inverted index
	SLink* file_word_table[BUFF_SIZE];
	for(i = 0; i < BUFF_SIZE; i++)
	{
		 file_word_table[i] = NULL;
	}

	//read the file and store all the words in a buff
	if ((read_len = fread(buff, sizeof(char), BUFF_SIZE, fd)) == 0) 
	{
	        fputs("Error reading file", stderr);
    	} 
	else 
	{
	        buff[read_len++] = '\0'; /* Just to be safe. */
	}    

	//get each words and save in unit and update the struct
	for (i = 0; i < strlen(buff); i++)
    	{
		//get only the word
        	while (i < strlen(buff) && buff[i] != ' ' && isalnum(buff[i]))
        	{
        		unit[j++] = buff[i++]; 
        	}
		//update the struct with the word and word frequency
        	if (j != 0)
        	{
        		unit[j] = '\0';
			
			//count and save the number of occurances of each word
        		count = update_wordfreq(word_freq_array, unit, count);

			j = 0;
        	}	
	}

	//check
	for (i = 0; i < count; i++)
	{
		//to generate key 
        	index = hash_function(word_freq_array[i].each_word);
		//printf(" %s\t   %d : %d\n", word_freq_array[i].each_word, word_freq_array[i].frequency, index);
		
		//update inverted index
		insert_at_last(&file_word_table[i], word_freq_array[i].frequency, pathname);
		//printf("%s: ", word_freq_array[i].each_word);
		//print_list(file_word_table[i]);
		
		//insert the values in the hash table
		hashTableInsert(HT, index, word_freq_array[i].each_word, file_count, count, &file_word_table[i]);
		
      	}
	printf("\n");
}

int update_wordfreq(struct word_count_table_t s[], const char unit[], int count)
{
    int i;
 
    for (i = 0; i < count; i++)
    {
        if (strcmp(s[i].each_word, unit) == 0)
        {
            s[i].frequency++;
            return count;
        }
    }

    // If control reaches here, it means no match found in struct
    strcpy(s[count].each_word, unit);
    s[count].frequency++;
 
    // count represents the number of fields updated in array s
    return (count + 1);
}

int insert_at_last(SLink **head, int data, char *pathname)
{
	/* take a local reference of head */
	SLink *temp;
	temp = *head;

	SLink *new = malloc(sizeof(SLink));

	if (NULL == new)
	{
		return FAILURE;
	}

	/* update the data and link */
	strcpy(new -> f_name, pathname);
	new -> data = data;
	new -> link = NULL;
	
	/* If empty list */
	if ( NULL == (*head) )
	{
		
		/* update head and tail */
		(*head) = new;
		return SUCCESS;
	} 
	else
	{
		//iterate till the last
		while(temp->link)
		{
			temp = temp -> link;
		}
		/* establish link between last + new Node and updte tail */
		(temp -> link) = new;
	}

	return SUCCESS;
}

void print_list(SLink *head)
{
	//take local reference to traverse through the link
	SLink *temp = head;
	
	//iterate and print 
	while(temp)
	{
		printf("%s: %d ", temp -> f_name, temp -> data);
		temp = temp -> link;
	}
	printf("\n");
}
