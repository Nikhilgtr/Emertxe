#include "tree.h"

void postorder_Traverse(TreeLink * root)
{
	
	//print data while post order Traversing
	if(root)
	{
		//move to left sub tree
		postorder_Traverse(root -> left);
		//move to right sub tree		
		postorder_Traverse(root -> right);
		printf("%d ", root -> data);
		
	}
}
