#include "tree.h"

/* Iteratively */
int search_BST(TreeLink * root, data_t data)
{
	//if tree is empty
	if ( NULL == root)
	{
		return NOELEMENT;
	}

	//if non empty 
	//take local reference to traverse along the tree nodes 
	TreeLink *temp;
	temp = (root);

	while((temp != NULL))
    	{
		if (temp -> data != data)
		{
			//if leaf node is reached with no element match
			if ( (NULL == temp -> left) && (NULL == temp -> right))
			{
				return NOELEMENT;
			}
			if(data < temp -> data)
			{
				//search in left side of the tree
				temp = temp -> left;
			}
			else
			{
				//search in right side of the tree
				temp = temp -> right;
			}
		}
		else if (temp -> data == data)
		{
			return SUCCESS;
		}	
		else
		{
			return NOELEMENT;
		}
	}
	return FAILURE;
}

