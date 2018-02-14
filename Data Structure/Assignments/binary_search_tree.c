#include <stdio.h>
#include <stdlib.h>

struct bsnode
{
    int data;
    struct bsnode *left;
    struct bsnode *right;
};
typedef struct bsnode bstree_t;

void in_order(bstree_t* );
bstree_t* create_bsnode(int );
bstree_t* insert_data(bstree_t*,int);
void in_order(bstree_t *);
void pre_order(bstree_t *);
void post_order(bstree_t *);
int find_min(bstree_t *);
int find_max(bstree_t *);
bstree_t * find_data(bstree_t *,int );

int main()
{
    int x,op;
    char ch;
    bstree_t *root=NULL;
    bstree_t *temp=NULL;
        while(1)
        {
            printf("\t1.Insert Data\n\t2.In order Transversal\n\t3.Pre order Transversal\n\t4.Post order Transversal\n");
            printf("\t5.Find data\n\t6.Find Min\n\t7.Find Max\nChoice :");
            scanf("%d",&op);
            switch(op)
            {
            case 1:
                printf("Enter the value :");
                scanf("%d",&x);
             //   printf("\n");
                root=insert_data(root,x);
                break;
            case 2:
                printf("BST : ");
                in_order(root);
                printf("\n");
                break;
            case 3:
                printf("BST : ");
                pre_order(root);
                printf("\n");
                break;
            case 4:
                printf("BST : ");
                post_order(root);
                printf("\n");
                break;
            case 5:

                printf("Enter the data to be found out :");
                scanf("%d",x);
                temp=find_data(root,x);
                printf("[%p] this is the address of the data",temp);
                break;
            case 6:
                x=find_min(root);
                printf("%d -> is the minimum value\n",x);
                break;
            case 7:
                x=find_max(root);
                printf("%d -> is the maximum value\n",x);

                break;
            default :
                printf("Invalid Input\n");
            }
            printf("Are you want to continue :");
            scanf("\n%c",&ch);
            printf("\n");
            if(ch=='y' || ch =='Y')
                continue;
            else
                return;

        }
    return 0;
}


bstree_t* create_bsnode(int val)
 {
     bstree_t *new=NULL;

     new=malloc(sizeof(bstree_t));

     new->data = val;
     new->left = NULL;
     new->right = NULL;
    return new;
}

bstree_t* insert_data(bstree_t *root,int data)
{

    if(root == NULL)
        return (create_bsnode(data));
    if(data < root->data)
       root->left=insert_data(root->left,data);
    else if(data > root->data)
        root->right=insert_data(root->right,data);

    else
    {
        printf("Node Not create\n");
    }

    return root;
}

void in_order(bstree_t *root)
{
    if(root == NULL)
    {
       // printf("No BST found\n");
        return ;
    }
    else
    {
        in_order(root->left);
        printf(" %d ",root->data);
        in_order(root->right);
    }

}


void pre_order(bstree_t *root)
{
    if(root == NULL)
        {
       // printf("No BST found\n");
        return ;
        }
    else
    {
        printf(" %d ",root->data);
        in_order(root->left);
        in_order(root->right);
    }

}

void post_order(bstree_t *root)
{
    if(root == NULL)
    {
       // printf("No list found\n");
        return ;
    }
    else
    {
        in_order(root->left);
        in_order(root->right);
        printf(" %d ",root->data);
    }

}

int find_min(bstree_t *root)
{
    if (root->left != NULL)
    {
        return (find_min(root->left));
    }
    else
        return root->data;
}

int find_max(bstree_t *root)
{
    if (root->right != NULL)
    {
        return (find_min(root->right));
    }
    else
        return root->data;
}


bstree_t * find_data(bstree_t *root,int data)
{//if tree is empty
	if ( NULL == root)
	{
	    printf("No BST found\n");
		return;
	}

	bstree_t *temp;
	temp = (root);

	while((temp != NULL))
    	{
		if (temp -> data != data)
		{
			//if leadf node is reached with no element match
			if ( (NULL == temp -> left) && (NULL == temp -> right))
			{
			    printf("No element matched");
				return ;
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
			return temp;
		}
		else
		{
			printf("No matched element");
		}
	}

}


