#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1
#define NOELEMENT -2
#define EMPTYLIST -3

#define SIZE 26
#define BUFF_SIZE 255
#define NAMELENGTH 20

//inverted table

typedef struct file_table
{
	char f_name[NAMELENGTH];
	int data;
	struct file_table *link;
}SLink;

typedef struct node
{
	char word[NAMELENGTH];
	struct node *link;
	SLink *filetable;
	int f_count;
}node_t;

typedef struct database
{
	node_t *table[SIZE];
}hash_table_t;


//forward table
struct word_count_table_t
{
	char each_word[NAMELENGTH];
	int frequency;
};


void databaseHTinit(hash_table_t *HT);	
int createDatabase(hash_table_t *HT, char *pathname, int file_count);			
int hash_function(char *value);
int process_word_count(FILE *fd, hash_table_t *HT, char *pathname, int file_count);
int hashTableInsert(hash_table_t *HT, int index, char *word, int file_count, int total_word_count, SLink *file_word_array[]);
int print_hashTable(hash_table_t *HT);
int hashTableSearch(hash_table_t *HT, char *value);
void hashTableDestroy(hash_table_t *HT);

