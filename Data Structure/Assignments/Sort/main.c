#include "sort.h"

int main()
{
	int elementArray[ARRAYSIZE];

	int totalElements, result;
	int choice, i = 0;
	char option;
	
	do
	{
	
	printf("Enter the option:\n");
	printf("1. create an array\n");	
	printf("2. quickSort\n");	
	printf("3. mergeSort\n");
	printf("4. bubbleSort\n");	
	printf("5. insertionSort\n");	
	printf("6. selectionSort\n");	
	printf("7. display array\n");
	
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
			quickSort(elementArray, elementArray[0], elementArray[totalElements - 1]);

			//check the list for validating
			print_array(elementArray, totalElements);
	
			break;
		case 3: 
			result = mergeSort(elementArray, totalElements);
			//(result == SUCCESS)? printf("mergeSort SUCCESS\n"): printf("mergeSort FAILURE\n") ;
			
			//check the list for validating
			print_array(elementArray, totalElements);
	
			break;
		case 4: 
			result = bubbleSort(elementArray, totalElements);
			(result == SUCCESS)? printf("bubbleSort SUCCESS\n"): printf("bubbleSort FAILURE\n") ;
			
			//check the list for validating
			print_array(elementArray, totalElements);
	
			break;

		case 5: 
			result = insertionSort(elementArray, totalElements);
			(result == SUCCESS)? printf("insertionSort SUCCESS\n"): printf("insertionSort FAILURE\n") ;
			
			//check the list for validating
			print_array(elementArray, totalElements);
	
			break;
		case 6: 
			result = selectionSort(elementArray, totalElements);
			(result == SUCCESS)? printf("selectionSort SUCCESS\n"): printf("selectionSort FAILURE\n") ;
			
			//check the list for validating
			print_array(elementArray, totalElements);
	
			break;

		case 7: 
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
        } else
        {
            break;
        }
        
    } while (1);
		
    return 0;
}
