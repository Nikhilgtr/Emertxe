#include "stack.h"

int checkPrecedence(char sym)
{
	switch(sym)
	{
		case '{':
		case '}':
		case '(':
		case ')': 
			return 1;
			break;
		case '+':
		case '-':
			return 2;
			break;
		case '*':
		case '/':
		case '%':
			return 3;
			break;
		default:
			return 0;
	}	
}		


