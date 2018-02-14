#include "tree.h"

int getTreeHeight(TreeLink *root)
{
	int lHeight;
	int rHeight;

	//count nodes while Traversing
	if (root == NULL)
	{
		return 0;
	}
	// compute the depth of each subtree
	
	lHeight = getTreeHeight(root->left);
	rHeight = getTreeHeight(root->right);
	
	// use the larger one
	if (lHeight > rHeight) return(lHeight+1);
	else return(rHeight+1);
	
}

