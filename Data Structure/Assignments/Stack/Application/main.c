#include "stack.h"

int main()
{
	//initialize the stack
	Stack stackArray;
	stackArray.top = -1;

	//to hold infix, prefix and postfix exp
	char infixexp[STACKSIZE];
	char prefixexp[STACKSIZE];
	char postfixexp[STACKSIZE];
	

	int infixlen, i;
	int choice, result;
	char option;
	

	do
	{

		printf("Enter the option:\n");
		printf("1. infix exp to prefix exp\n");	
		printf("2. infix exp to postfix exp\n");	
		printf("3. infix evaluation\n");	
		printf("4. prefix evaluation\n");	
		printf("5. postfix evaluation\n");	
		

		printf("Choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("Enter the infix expression: ");
				scanf("%s", infixexp);

				result = infixToprefix(infixexp, prefixexp);
				(result == SUCCESS)? printf("infixToprefix SUCCESS\n"): printf("infixToprefix FAILURE\n") ;
				printf("%s \n", prefixexp);
				break;
			case 2:
				printf("Enter the infix expression: ");
				scanf("%s", infixexp);

				result = infixTopostfix(infixexp, postfixexp);
				(result == SUCCESS)? printf("infixTopostfix SUCCESS\n"): printf("infixTopostfix FAILURE\n") ;
				printf("%s \n", postfixexp);
				break;
			case 3:
				printf("Enter the infix expression: ");
				scanf("%s", infixexp);

				result = infixEval(infixexp);
				printf("in fix evaluation: %d \n", result);
				break;
			case 4:
				result = prefixEval(prefixexp);
				printf("pre fix evaluation: %d \n", result);
				break;
			case 5:
				result = postfixEval(postfixexp);
				printf("post fix evaluation: %d \n", result);
				break;
			default:
				printf("Invalid option\n");
				break;
		}

		//check the stack for validating
		peep(stackArray);

		/* check for continue */
	        printf("Continue (y/n): ");
	        scanf("\n%c", &option);
        
	        if ( option == 'y' )
	        {
	            continue;
	        } 
		else
	        {
	            break;
	        }
        
	} while (1);
		
 	return 0;
}
