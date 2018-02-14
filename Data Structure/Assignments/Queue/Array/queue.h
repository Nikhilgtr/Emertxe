#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define QEMPTY 1
#define QFULL 2
#define QSIZE 25

typedef int data_t;
typedef struct
{
	int rear;
	int front;
	data_t Qarray[QSIZE];
}Queue;

int enqueue(Queue *, data_t);
int dequeue(Queue *, data_t *);
