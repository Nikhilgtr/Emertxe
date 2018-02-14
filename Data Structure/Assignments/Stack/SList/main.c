#include "stack.h"

int main()
{
	//initialize the stack
	Stack stackList;
	stackList.top = NULL;

	int data, result;
	int choice;
	char option;
	
	do
	{

		printf("Enter the option:\n");
		printf("1. push\n");	
		printf("2. pop\n");	
		printf("3. peep\n");	
		printf("4. peek\n");	

		printf("Choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("Enter the element to be pushed onto stack: ");
				scanf("%d", &data);
				result = push(&stackList, data);
				(result == SUCCESS)? printf("push SUCCESS\n"): printf("push FAILURE\n") ;
				if (result == STACKFULL)
				{
					printf("Stack is full\n");
				}
				break;
			case 2:
				result = pop(&stackList, &data);
				(result == SUCCESS)? printf("pop SUCCESS\n"): printf("pop FAILURE\n") ;
				if (result == STACKEMPTY)
				{
					printf("Stack is empty\n");
				}
				
				break;
			case 3: 
				result = peep(stackList);
				(result == SUCCESS)? printf("peep SUCCESS\n  "): printf("peep FAILURE\n") ;
				if (result == STACKEMPTY)
				{
					printf("Stack is empty\n");
				} 
				
				break;
			case 4:
				result = peek(stackList);
				(result == STACKEMPTY)? printf("peek FAILURE.\nStack is empty\n"): printf("peek value: %d\n", result) ;	
								
				break;
			default:
				printf("Invalid option\n");
				break;
		}

		//check the stack for validating
		peep(stackList);
	
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
