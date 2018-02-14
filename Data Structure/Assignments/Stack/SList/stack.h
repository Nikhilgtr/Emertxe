#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define STACKEMPTY 1
#define STACKFULL 2

typedef int data_t;

typedef struct snode
{
	data_t data;
	struct snode *link;
}SLink;


typedef struct
{
	SLink *top;
}Stack;

int push(Stack *, data_t);
int pop(Stack *, data_t *);
int peep(Stack);
int peek(Stack);
