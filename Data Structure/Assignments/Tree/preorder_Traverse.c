#include "tree.h"

void preorder_Traverse(TreeLink * root)
{
	
	//print data while pre order Traversing
	if(root)
	{
		printf("%d ", root -> data);
		//move to left sub tree
		preorder_Traverse(root -> left);
		//move to right sub tree		
		preorder_Traverse(root -> right);
	}
}
