#include "dlist.h"

int main()
{
	DLink *head = NULL;
	
	int data, a_data, result;
	int choice;
	char option;	

	do
	{

		printf("Enter the option:\n");
		printf("1. Insert At Last\n");	
		printf("2. Insert At First\n");	
		printf("3. Insert After Element\n");	
		printf("4. Insert Before Element\n");	
		printf("5. Delete First\n");	
		printf("6. Delete Last\n");	
		printf("7. Delete Element\n");
		printf("8. Delete List\n");
		printf("9. Display List\n");

		printf("Choice: ");
		scanf("%d", &choice);

		switch(choice)
		{	
			case 1:
				printf("Enter the element to be inserted at last: ");
				scanf("%d", &data);
				result = insert_at_last(&head, data);
				(result == SUCCESS)? printf("insert_at_last SUCCESS\n"): printf("insert_at_last FAILURE\n") ;
				break;
			case 2:
				printf("Enter the element to be inserted at First: ");
				scanf("%d", &data);
				result = insert_at_first(&head, data);
				(result == SUCCESS)? printf("insert_at_first SUCCESS\n"): printf("insert_at_first FAILURE\n") ;
				break;
			case 3: 
				printf("Enter the element after which you want to insert new data: ");
				scanf("%d", &a_data);
				printf("Enter the element to be inserted after the element %d: ", a_data);
				scanf("%d", &data);
				result = insert_after(&head, a_data, data);
				(result == SUCCESS)? printf("insert_after SUCCESS\n"): printf("insert_after FAILURE\n") ;
				if (result == NOELEMENT)
    				{
      				  	printf("No such element found\n");
    				}
				else if (result == EMPTYLIST)
				{
					printf("List is empty\n");
				}
				break;
			case 4: 
				printf("Enter the element before which you want to insert new data: ");
				scanf("%d", &a_data);
				printf("Enter the element to be inserted before the element %d: ", a_data);
				scanf("%d", &data);
				result = insert_before(&head, a_data, data);
				(result == SUCCESS)? printf("insert_before SUCCESS\n"): printf("insert_before FAILURE\n") ;
				if (result == NOELEMENT)
    				{
      				  	printf("No such element found\n");
    				}
				else if (result == EMPTYLIST)
				{
					printf("List is empty\n");
				}
				break;
			case 5:
				result = delete_first(&head);
				(result == SUCCESS)? printf("delete_first SUCCESS\n"): printf("delete_first FAILURE\n") ;
				if (result == EMPTYLIST)
    				{
      				  	printf("List is empty\n");
    				}
				break;
			case 6:
				result = delete_last(&head);
				(result == SUCCESS)? printf("delete_last SUCCESS\n"): printf("delete_last FAILURE\n") ;
				if (result == EMPTYLIST)
    				{
      				  	printf("List is empty\n");
    				}
				break;
			case 7:
				printf("Enter the element that needs to be deleted: ");
				scanf("%d", &data);
				result = delete_element(&head, data);
				(result == SUCCESS)? printf("delete_element SUCCESS\n"): printf("delete_element FAILURE\n") ;
				if (result == NOELEMENT)
    				{
      				  	printf("No such element found\n");
    				}
				else if (result == EMPTYLIST)
				{
					printf("List is empty\n");
				}
				break;
			case 8:
				result = delete_list(&head);
				(result == SUCCESS)? printf("delete_list SUCCESS\n"): printf("delete_list FAILURE\n") ;
				if (result == EMPTYLIST)
    				{
      				  	printf("List is empty\n");
    				}
				break;
			case 9:	
				print_list(head);
				break;
			default:
				printf("Invalid entry.\n");
				break;
		}

		//check the list for validating
		print_list(head);
	
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
