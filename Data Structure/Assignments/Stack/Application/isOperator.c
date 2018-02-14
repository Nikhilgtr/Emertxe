#include "stack.h"


int isOperator(char sym)
{
	switch(sym)
	{
		case '*':
		case '+':
		case '-':
		case '{':
		case '}':
		case '(':
		case ')':
		case '/':
		case '%':
			return 1;
			 break;
		default:
			return 0;
		
	}
}


