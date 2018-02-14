#include "queue.h"

int main()
{
	//initialize the queue
	Queue queueArray;
	queueArray.rear = -1;
	queueArray.front = -1;

	int data, result;
	int choice;
	char option;
	
	do
	{

		printf("Enter the option:\n");
		printf("1. enqueue\n");	
		printf("2. dequeue\n");	
		
		printf("Choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("Enter the element to be enqueued onto queue: ");
				scanf("%d", &data);
				result = enqueue(&queueArray, data);
				(result == SUCCESS)? printf("enque SUCCESS\n"): printf("enque FAILURE\n") ;
				if (result == QFULL)
				{
					printf("Queue is full\n");
				}
				break;
			case 2:
				result = dequeue(&queueArray, &data);
				(result == SUCCESS)? printf("dequeue SUCCESS\n"): printf("dequeue FAILURE\n") ;
				if (result == QEMPTY)
				{
					printf("Queue is empty\n");
				}
				break;
			default:
				printf("Invalid option\n");
				break;
		}

		//check the stack for validating
		print_queue(queueArray);
	
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
