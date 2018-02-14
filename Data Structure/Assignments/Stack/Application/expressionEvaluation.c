#include "stack.h"

int expressionEvaluation(int valueA, int valueB, char sym )
{
	int a, b;
	if(  valueA >= '0' && valueA <= '9' )
	{
		a = (valueA - '0');
	}
	else
	{
		a = valueA;
	}	
	
	if( valueB >= '0' && valueB <= '9' )
	{
		b = (valueB - '0');
	}
	else
	{
		b = valueB;
	}

	switch(sym)
	{
		case '+':
			return (a + b);
			break;
		case '-':
			return (a - b);
			break;
		case '*':
			return (a * b);
			break;
		case '/':
			return (a / b);
			break;
		case '%':
			return (a % b);
			
			break;
		default:
			break;
	}	
}		


