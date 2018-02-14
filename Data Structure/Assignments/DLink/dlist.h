#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define EMPTYLIST 1
#define NOELEMENT 2

typedef int data_t;

typedef struct dnode
{
	struct dnode *prev;
	data_t data;
	struct dnode *next;
}DLink;

void print_list(DLink *);
int insert_at_last(DLink **, data_t);
int insert_at_first(DLink **head, data_t data);
int delete_first(DLink **head);
int delete_last(DLink **head);
int delete_list(DLink **head);
int delete_element(DLink **head, data_t data);
int insert_after(DLink **head, data_t a_data, data_t n_data);
int insert_before(DLink **head, data_t b_data, data_t n_data);
