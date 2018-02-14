#include "search.h"

int main()
{
	int elementArray[ARRAYSIZE];

	int totalElements, result, data;
	int choice, i = 0;
	char option;

	do
	{
	
		printf("Enter the option:\n");
		printf("1. create an array\n");	
		printf("2. Binary Search Iterative\n");	
		printf("3. Binary Search Recursive\n");	
		printf("4. display array\n");

		printf("Choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("Enter the total number of element to be inserted ain array: ");
				scanf("%d", &totalElements);
		
				for(i = 0; i < totalElements; i++)
				{
					printf("%d: ", i);
					scanf("%d", &elementArray[i]);
				}
				break;
			case 2:
				printf("Enter the element that needs to be searced: ");
				scanf("%d", &data);
				
				result = binarySearchIterative(elementArray, 0, totalElements-1, data);
				(result == NOELEMENT)? printf("Element is not present in array \n")
				: printf("Element is present at index %d \n", result);
				
				break;
			case 3: 
				printf("Enter the element that needs to be searced: ");
				scanf("%d", &data);
				
				result = binarySearchRecursive(elementArray, 0, totalElements-1, data);
				(result == NOELEMENT)? printf("Element is not present in array \n")
				: printf("Element is present at index %d \n", result);
		
				break;
			case 4:
				print_array(elementArray, totalElements);
				break;
			default:
				printf("Invalid entry.\n");
				break;
		}

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
