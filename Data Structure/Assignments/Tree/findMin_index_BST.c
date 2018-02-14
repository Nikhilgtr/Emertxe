#include "tree.h"

TreeLink * findMin_index_BST(TreeLink * root)
{
	
	//if no elements are there in a tree
	if (NULL == root)
	{
		return NULL;
	}

	//if non empty 

	//take local reference to traverse along the tree nodes 
	TreeLink *temp;
	temp = (root);
	
	//go to left most element
	while(temp -> left != NULL)
	{
		temp = temp -> left;	
	}
	return temp;
	
}

