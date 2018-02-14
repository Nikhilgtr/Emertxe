#include "tree.h"

int getTotalNodes(TreeLink *root)
{
	//count nodes while Traversing
	if (root == NULL)
	{
		return 0;
	}
	
	return( getTotalNodes(root -> left) + 1 + getTotalNodes(root -> right) );
	
}

