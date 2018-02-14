#include "tree.h"

int main()
{
	int result, data;
	int choice, i = 0;
	char option;
	TreeLink * root = NULL;

	do
	{
	
	printf("Enter the option:\n");
	printf("1. create BST\n");	
	printf("2. in order Traversal\n");	
	printf("3. pre order Traversal\n");	
	printf("4. post order Traversal\n");
	printf("5. get the Tree height\n");
	printf("6. get Total number of nodes in a tree\n");
	printf("7. search data in BST\n");
	printf("8. Find minimum most data in BST\n");
	printf("9. Find maximum most data in BST\n");
	printf("10. delete Node in BST\n");	

	printf("Choice: ");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
			printf("Enter the element to be inserted with first node as root: ");
			scanf("%d", &data);
			result = create_BST(&root, data);
			(result == SUCCESS)? printf("create_BST SUCCESS\n"): printf("create_BST FAILURE\n") ;
			if (result == DUPLICATE)
    			{
      			  	printf("Duplicate found\n");
    			}
				
			break;
		case 2:
			inorder_Traverse(root);	
			printf("\n");
			break;
		case 3: 
			preorder_Traverse(root);	
			printf("\n");	
			break;
		case 4: 
			postorder_Traverse(root);	
			printf("\n");	
			break;
		case 5: 
			printf("Tree height is: %d\n", getTreeHeight(root));		
			break;
		case 6: 
			printf("Nodes are: %d\n", getTotalNodes(root));	
			break;
		case 7:
			printf("Enter the element to be searched: ");
			scanf("%d", &data);
			result = search_BST(root, data);
			(result == SUCCESS)? printf("search_BST SUCCESS.\nKey found."): printf("search_BST FAILURE\n") ;
			if (result == NOELEMENT)
    			{
      			  	printf("NO ELEMENT found\n");
    			}
				
			break;
		case 8: 
			result = findMin_BST(root);
			if (result == NOELEMENT)
    			{
      			  	printf("NO ELEMENT found\n");
				break;
    			}
			printf("Minimum most Node is: %d\n", result);	
			break;
		case 9: 
			result = findMax_BST(root);
			if (result == NOELEMENT)
    			{
      			  	printf("NO ELEMENT found\n");
				break;
    			}
			printf("Maximum most Node is: %d\n", result);	
			break;	
		case 10:
			printf("Enter the element to be deleted from BST: ");
			scanf("%d", &data);
			root = delete_BST(root, data);
							
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
