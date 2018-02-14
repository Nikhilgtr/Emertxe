#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1
#define NOMEMORY -2
#define DUPLICATE -3
#define INITIAL_SIZE 26
#define NAMELENGTH 10
#define MAX_LOAD_FACTOR 1
#define GROWTH_FACTOR 2
#define NOELEMENT -4

typedef struct node
{
	int key;
	char value[NAMELENGTH];	
	struct node *link;
}Link;

struct table
{
	Link *table[INITIAL_SIZE]; 	  /* array of pointers to data type LInk*/
};

 
typedef struct table *HashTable;

/* create a new empty HashTable */
HashTable hashTableCreate(void);

/* hash function */
int hash_function(char *value);

/* insert a new key-value pair into an existing table */
int hashTableInsert(HashTable, int key, char *value);

/* print all the elements in the hashTable*/
int print_hashTable(HashTable hash_table);

/* destroy a table */
void hashTableDestroy(HashTable);

/* delete the value in record if present */
/* if there is no such record, has no effect */
void hashTableDelete(HashTable, char *value);
//helper to delete in a list
int delete_element(Link **head, char *value);

/* return the most recently inserted value associated with a key */
/* or 0 if no matching key is present */
int hashTableSearch(HashTable, char *value);


