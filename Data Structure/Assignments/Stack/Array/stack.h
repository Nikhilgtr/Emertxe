#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define STACKEMPTY -2
#define STACKFULL -3
#define STACKSIZE 25

typedef int data_t;
typedef struct
{
	int top;
	data_t Sarray[STACKSIZE];
}Stack;

int push(Stack *, data_t);
int pop(Stack *, data_t *);
int peep(Stack);
int peek(Stack);
