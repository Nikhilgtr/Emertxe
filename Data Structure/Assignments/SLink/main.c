#include "slist.h"

int main()
{
	SLink *head = NULL;
	SLink *ahead = NULL;
	SLink *bhead = NULL;

	int data, a_data, result, index;
	int choice;
	char option;
	int aListElement, bListElement, i;
	
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
	printf("10. get Nth value\n");
	printf("11. insert at Nth value\n");
	printf("12. get mid value\n");
	printf("13. insert in sorted list\n");
	printf("14. sort list\n");
	printf("15. append list\n");
	printf("16. split list\n");
	printf("17. remove duplicates\n");
	printf("18. merge 2 links in sorted order\n");	
	printf("19. Reverse the list\n");	
	printf("20. Length of the list\n");	
	printf("21. Split list Alternatively\n");	
	printf("22. Occurance count of the given key in the list\n");	

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
		case 10:
			printf("Enter the index value to get that value [starts from 0]: ");
			scanf("%d", &index);	
			result = getNth(head, index);
			if (result == NOELEMENT)
    			{
      			  	printf("Index out of bound\n");
				break;
    			}
			else if (result == EMPTYLIST)
			{
				printf("List is empty\n");
				break;
			}
			(result == FAILURE)? printf("getNth FAILURE.\n"): printf("Nth value is: %d\n", result);
			
			break;
		case 11:
			printf("Enter the index value to insert the value [starts from 0]: ");
			scanf("%d", &index);	
			printf("Enter the element to be inserted at index %d: ", index);
			scanf("%d", &data);
			
			result = insert_Nth(&head, index, data);
			(result == SUCCESS)? printf("insert_Nth SUCCESS\n"): printf("insert_Nth FAILURE\n") ;
			
			if (result == NOELEMENT)
    			{
      			  	printf("Index out of bound\n");
			}
			else if (result == EMPTYLIST)
			{
				printf("List is empty\n");
			}
			
			break;
		case 12:
			result = find_mid(head);
			if (result == EMPTYLIST)
			{
				printf("List is empty\n");
				break;
			}
			(result == FAILURE)? printf("find_mid FAILURE.\n"): printf("mid value is: %d\n", result);
			
			break;
		case 13:
			printf("Enter the element to be inserted in the sorted list: ");
			scanf("%d", &data);
			result = sorted_insert(&head, data);
			(result == SUCCESS)? printf("sorted_insert SUCCESS\n"): printf("sorted_insert FAILURE\n") ;
			break;
		case 14:
			result = insert_sort(&head);
			(result == SUCCESS)? printf("insert_sort SUCCESS\n"): printf("insert_sort FAILURE\n") ;
			if (result == EMPTYLIST)
			{
				printf("List is empty\n");
				break;
			}
			break;
		case 15: 
			ahead = NULL; 
			printf("Enter the number of elements in list a [ordered in asc]: ");
			scanf("%d", &aListElement);
			printf("Enter the elements:\n");
			for(i = 0; i < aListElement;i++)
			{
				printf("%d: ", i);
				scanf("%d", &data);
				result = insert_at_last(&ahead, data);
				//(result == SUCCESS)? printf("insert in alist SUCCESS\n"): printf("insert in alist FAILURE\n") ;
			}
	
			printf("Enter the number of elements in list b [ordered in asc]: ");
			scanf("%d", &bListElement);
			printf("Enter the elements:\n");
			for(i = 0; i < bListElement;i++)
			{
				printf("%d: ", i);
				scanf("%d", &data);
				result = insert_at_last(&bhead, data);
				//(result == SUCCESS)? printf("insert in blist SUCCESS\n"): printf("insert in blist FAILURE\n") ;
			}
			result = append(&ahead, &bhead);
			(result == SUCCESS)? printf("append blist to alist SUCCESS\n"): printf("append blist to alist FAILURE\n") ;
			
			print_list(ahead);			
			break;
		case 16:
			bhead = NULL;
			ahead = NULL;
			result = splithalf(&head, &ahead, &bhead);
			if (result == EMPTYLIST)
			{
				printf("List is empty\n");
				break;
			}
			(result == SUCCESS)? printf("split list into b and a SUCCESS\n"): printf("split list into b and a FAILURE\n") ;
			printf("A List: ");			
			print_list(ahead);
			printf("B List: ");			
			print_list(bhead);
			printf("\n");
			break;
		case 17:
			result = remove_duplicate(&head);
			(result == SUCCESS)? printf("insert_sort SUCCESS\n"): printf("insert_sort FAILURE\n") ;
			if (result == EMPTYLIST)
			{
				printf("List is empty\n");
				break;
			}
			
			break;
		case 18:
			ahead = NULL; 
			 
			printf("Enter the number of elements in list a: ");
			scanf("%d", &aListElement);
			printf("Enter the elements:\n");
			for(i = 0; i < aListElement;i++)
			{
				printf("%d: ", i);
				scanf("%d", &data);
				result = insert_at_last(&ahead, data);
				//(result == SUCCESS)? printf("insert in alist SUCCESS\n"): printf("insert in alist FAILURE\n") ;
			}
	
			bhead = NULL;
			printf("Enter the number of elements in list b: ");
			scanf("%d", &bListElement);
			printf("Enter the elements:\n");
			for(i = 0; i < bListElement;i++)
			{
				printf("%d: ", i);
				scanf("%d", &data);
				result = insert_at_last(&bhead, data);
				//(result == SUCCESS)? printf("insert in blist SUCCESS\n"): printf("insert in blist FAILURE\n") ;
			}

			head = merge_sortedlinks(ahead, bhead);
						
			break;
		case 19:
			result = reverse(&head);
			(result == SUCCESS)? printf("reverse SUCCESS\n"): printf("reverse FAILURE\n") ;
			if (result == EMPTYLIST)
    			{
      			  	printf("List is empty\n");
    			}
			break;
		case 20:
			result = findLength(head);
			if (result == EMPTYLIST)
			{
				printf("List is empty\n");
				break;
			}
			(result == FAILURE)? printf("findLength FAILURE.\n"): printf("length of list is: %d\n", result);
			
			break;
		case 21:
			bhead = NULL;
			ahead = NULL;
			result = split_alternatively(head, &ahead, &bhead);
			if (result == EMPTYLIST)
			{
				printf("List is empty\n");
				break;
			}
			(result == SUCCESS)? printf("split list into b and a SUCCESS\n"): printf("split list into b and a FAILURE\n") ;
			printf("A List: ");			
			print_list(ahead);
			printf("B List: ");			
			print_list(bhead);
			printf("\n");
			break;
		case 22:
			printf("Enter the value whose occurance count you need: ");
			scanf("%d", &data);
			result = countKey(head, data);
			if (result == EMPTYLIST)
			{
				printf("List is empty\n");
				break;
			}
			(result == FAILURE)? printf("countKey FAILURE.\n"): printf("occurance count of %d in list is: %d\n", data, result);
			
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
