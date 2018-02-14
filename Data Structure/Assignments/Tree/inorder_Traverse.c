#include "tree.h"

void inorder_Traverse(TreeLink * root)
{
	
	//print data while inorder Traversing
	if(root)
	{
		//move to left sub tree
		inorder_Traverse(root -> left);
		printf("%d ", root -> data);
		//move to right sub tree
		inorder_Traverse(root -> right);
	}
}
