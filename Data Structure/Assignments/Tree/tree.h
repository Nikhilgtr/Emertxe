#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define NOELEMENT -2
#define DUPLICATE -3

typedef int data_t;

typedef struct treenode
{
	struct treenode *left;
	data_t data;
	struct treenode *right;
}TreeLink;

int create_BST(TreeLink **, data_t);
int search_BST(TreeLink * root, data_t data);
TreeLink* delete_BST(TreeLink * root, data_t data);

void inorder_Traverse(TreeLink * root);
void preorder_Traverse(TreeLink * root);
void postorder_Traverse(TreeLink * root);

/* Compute the number of nodes in a tree
 */
int getTotalNodes(TreeLink * root);

/* Compute the height or maximum depth of a tree
 */
int getTreeHeight(TreeLink * root);

/* To find minimum most in BST
 */
int findMin_BST(TreeLink * root);

/* To find maximum most in BST
 */
int findMax_BST(TreeLink * root);

/* Send the index of the minimum value */
TreeLink * findMin_index_BST(TreeLink * root);
