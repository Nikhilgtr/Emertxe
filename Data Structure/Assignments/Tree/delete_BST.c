#include "tree.h"

/* Iteratively */
TreeLink* delete_BST(TreeLink * root, data_t data)
{

	//local refernce to the tree
	TreeLink *temp;

	// base case: if tree is empty 
	if ( NULL == root)
	{
		return root;
	}

	// If the key to be deleted is less than the root's key, then it lies in left subtree
    	if (data < root->data)
	{
        	root->left = delete_BST(root->left, data);
 	}
 	
    	// If the key to be deleted is greater than the root's key, then it lies in right subtree
    	else if (data > root->data)
	{
        	root->right = delete_BST(root->right, data);
 	}

	// if key is same as root's key, then This is the node to be deleted
    	else
    	{
		//check for leaf node
		if (root->left == NULL && root->right == NULL)
        	{
            		temp = NULL;
            		free(root);
            		return temp;
        	}
        	// node with only one child or no child
        	if (root->left == NULL && root->right != NULL)
        	{
            		temp = root->right;
            		free(root);
            		return temp;
        	}
        	else if (root->right == NULL && root->left != NULL)
        	{
            		temp = root->left;
            		free(root);
           		return temp;
       		}
 		else
		{
			// node with two children: Get the inorder successor (smallest in the right subtree)
			//temp -> data = findMin_BST(root->right);
			 			

        		// Copy the inorder successor's content to this node
        		temp = findMin_index_BST(root->right);
			
			root->data = temp->data; 			
			
        		// Delete the inorder successor
       			root->right = delete_BST(root->right, temp->data);
		}
    	}

	return root;
}

