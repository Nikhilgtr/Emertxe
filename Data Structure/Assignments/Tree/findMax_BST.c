#include "tree.h"

int findMax_BST(TreeLink * root)
{
	
	//if no elements are there in a tree
	if (NULL == root)
	{
		return NOELEMENT;
	}

	//if non empty 

	//take local reference to traverse along the tree nodes 
	TreeLink *temp;
	temp = (root);
	
	//go to right most element
	while(temp -> right != NULL)
	{
		temp = temp -> right;	
	}
	return temp -> data;
	
}

