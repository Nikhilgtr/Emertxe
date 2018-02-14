#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1
#define STACKEMPTY -2
#define STACKFULL -3
#define STACKSIZE 25

typedef char data_t;
typedef struct
{
	int top;
	data_t Sarray[STACKSIZE];
}Stack;

int push(Stack *, data_t);
int pop(Stack *, data_t *);
int peep(Stack);
int peek(Stack);

int infixToprefix(char infixexp[STACKSIZE], char prefixexp[STACKSIZE]);
int infixTopostfix(char infixexp[STACKSIZE], char postfixexp[STACKSIZE]);
int postfixEval(char postfixexp[STACKSIZE]);
int prefixEval(char prefixexp[STACKSIZE]);
int infixEval(char infixexp[STACKSIZE]);

int isOperator(char sym);
int checkPrecedence(char sym);
void reverseString( char *string);
int expressionEvaluation(int valueA, int valueB, char sym );


