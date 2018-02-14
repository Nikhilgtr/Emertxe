#include <stdio.h>
#include <stdlib.h>
//#include "common.h"

 struct node_d
{
	int data;
	struct node_d *next;
	struct node_d *prev;
};
typedef struct node_d dlist_t;


dlist_t * create_dl_node(int );
void dl_insert_first( dlist_t **,int);
void dl_insert_last(dlist_t **, int );
void print_list(dlist_t *);
void dl_delete_first(dlist_t **);
void dl_delete_last(dlist_t **);
void dl_delete_list(dlist_t **);
void dl_delete_element(dlist_t **, int );
void dl_insert_after(dlist_t **head, int , int );
void dl_insert_before(dlist_t **head, int , int );
int main()
{
    int op,x,y;
    char ch;
    dlist_t *head=NULL;
    while(1)
    {
        printf("Enter Choice\n\t1.Insert First\n\t2.Print List\n\t3.Insert last\n\t4.Delete First\n\t5.Delete Last");
        printf("\n\t6.Delete list\n\t7.Delete Element\n\t8.Insert after\n\t9.Insert Before\nChoice :");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("Enter the number : ");
            scanf("%d",&x);
            dl_insert_first(&head,x);
            break;

        case 2:
            print_list(head);
            break;

        case 3:
            printf("Enter the number : ");
            scanf("%d",&x);
            dl_insert_last(&head,x);
            break;

        case 4:
            dl_delete_first(&head);
            break;

        case 5:
            dl_delete_last(&head);
            break;

        case 6:
            dl_delete_list(&head);
            break;
        case 7:
            printf("Enter the number which to be deleted : ");
            scanf("%d",&x);
            dl_delete_element(&head,x);
            break;

        case 8:
            printf("Enter the number after which a number is required to be inserted : ");
            scanf("%d",&x);
            printf("Enter the value to be inserted : ");
            scanf("%d",&y);
            dl_insert_after(&head,x,y);
            break;

            case 9:
            printf("Enter the number before which a number is required to be inserted : ");
            scanf("%d",&x);
            printf("Enter the value to be inserted : ");
            scanf("%d",&y);
            dl_insert_after(&head,x,y);
            break;

        default:
            printf("Invalid argument\n");
            break;
        }
        printf("Are You Want to continue\n");
        scanf("\n%c",&ch);
            if(ch =='y' || ch == 'Y')
                continue;
            else
                break;
    }

return 0;
}
void dl_insert_first( dlist_t **head,int val)
 {
     if(NULL == (*head))
     {
         dlist_t *new;
         new=create_dl_node(val);
         (*head)=new;
         printf("\tNode is created at starting\n");


     }
     else
     {
        dlist_t *new,*temp;
        new=create_dl_node(val);
        temp=(*head);

        temp -> prev = new;
        new -> next = temp;
        (*head) = new;
        printf("\tNode is created at starting\n");


     }
 }

void print_list(dlist_t *head)
 {
    if(NULL == head)
    {
        printf("\t!!No List Found\n");
        return;
    }
    else
    {
     dlist_t *ptr;
     ptr=head;
     printf("List :");
     while(ptr)
     {

        printf(" %d ",ptr->data);
        ptr=ptr->next;

     }
     printf("\n");
    }
 }

void dl_insert_last(dlist_t **head, int val)
 {
     if(NULL == (*head))
     {
         dlist_t *new;
         new=create_dl_node(val);
         (*head)=new;
         printf("\tNode is created at starting\n");

     }
        else
        {
            dlist_t *new, *ptr;
            ptr=(*head);
            new=create_dl_node(val);
            while(ptr->next != NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new;
            new->prev=ptr;
            printf("\tNode is created at last\n");
        }

 }

dlist_t* create_dl_node(int val)
{

	dlist_t *new;
	new=malloc(sizeof(dlist_t));
	new->data=val;
	new->next=NULL;
	new->prev=NULL;
	return new;
}

void dl_delete_first(dlist_t **head)
{
    if(NULL == (*head))
    {
        printf("No list found\n");
        return ;
    }
    else
    {
        dlist_t *ptr;
        ptr=(*head);
        (*head)=ptr->next;
        free(ptr);
        printf("\tFirst node is deleted\n");
    }


}
void dl_delete_last(dlist_t **head)
{
    if(NULL == (*head))
    {
        printf("/tNo list found\n");
        return ;
    }
    else
    {
        dlist_t *ptr,*temp;
        ptr=(*head);
        while(ptr->next != NULL)
        {
            ptr=ptr->next;
        }

        temp=ptr->prev;
        temp->next=NULL;
        free(ptr);
        printf("\tLast Node is deleted\n");

    }
}

void dl_delete_list(dlist_t **head)
{
    if(NULL == (*head))
    {
        printf("\tNo list found\n");
        return ;
    }
    else
    {
        dlist_t *temp;
        temp=(*head);
            while(temp->next)
            {
                temp = temp -> next;
			// unlink the previous node
                (temp -> prev) -> next  = NULL;
			// free the previous node
                free((temp -> prev));
            }
            (*head)=NULL;
        }

}

void dl_delete_element(dlist_t **head, int data)
{
	/* take a local reference of head */
	dlist_t *temp;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		return ;
	}

	/* check for if list has only one node */
	if ( ((*head) -> next) == NULL)
	{
		/* check if the element is the one that needs to be deleted */
		if (((*head) -> data) == data)
		{
			/* free the node, and head with null */
			free(temp);
			(*head) = NULL;
			return ;
		}
		else
		{
			return ;
		}
	}
	/* if list has multiple nodes */
	else
	{
		/* If the element is in the head then check for next values */
		if( ((*head) -> data) == data)
		{
			//update the head to next value
			(*head) = (*head) -> next;
			//unlink the previous node and free
			((*head) -> prev) -> next = NULL;
			free((*head) -> prev);
			//update the prev of head to null
			(*head) -> prev = NULL;
		}
		/* iterate till last node */
		else
		{
			while(temp)
			{
				// check if node is given element
				if ((temp-> data ) != data)
                		{
					// if no element is found at all then return
					if (temp -> next == NULL)
                    			{
                        			return ;
                    			}
				}
				else
				{
					// if element is present break
					break;
				}
				temp = temp -> next;
			}
			//check for end node
			if (temp -> next == NULL )
			{
				// unlink the node
				(temp -> prev) -> next = NULL;
				free(temp);
			}
			else
			{
				/* update that node's link, free the node that contains element */
				(temp -> prev) -> next = temp -> next;
				(temp -> next) -> prev = temp -> prev;

				/* unlink the node that has element */
				temp -> prev = NULL;
				temp -> next = NULL;
				free(temp);
			}
		}

		return ;
	}
	return ;
}

void dl_insert_after(dlist_t **head, int a_data, int n_data)
{
	/* take a local reference of head */
	dlist_t *temp;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		return ;
	}

	//create newNode and update newnode data and link
	dlist_t *new = malloc(sizeof(dlist_t));
	new -> data = n_data;
	new -> next = NULL;
	new -> prev = NULL;

	/* check for if list has only one node */
	if ( ((*head) -> next) == NULL)
	{
		/* if the node is the given element after which we need to add newNode*/
		if (((*head) -> data) == a_data)
		{
			/* update first + newNode */
			((*head) -> next) = new;
			(new -> prev) = *head;
			return ;
		}
		else
		{
			return ;
		}
	}
	/* check for multi node case */
	else
	{
		/* iterate through the list till you find the element after which new data has to be added */
		while(temp)
		{
			// check if node is given element
			if ((temp-> data ) != a_data)
                	{
				// if no element is found at all then return
				if (temp -> next == NULL)
            {
                return ;
			}
			else
			{
				// if element is present break
				break;
			}
			temp = temp -> next;
		}
		//check for end node
		if (temp -> next == NULL )
		{
			/* update last + newNode */
			(temp -> next) = new;
			/* update prev of newNode */
			new -> prev = temp;
			return ;
		}
		else
		{
			/* update the newNode's next */
			new -> next = temp -> next;
			/* update the newNode's prev */
			new -> prev = temp;
			/* update current node + newNode*/
			temp -> next = new;

			return ;
		}
	}
	return ;
}
}

void dl_insert_before(dlist_t **head, int b_data, int n_data)
{
    /* take a local reference of head */
	dlist_t *temp;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		return ;
	}

	//create newNode and update newnode data and link
	dlist_t *new = malloc(sizeof(dlist_t));
	new -> data = n_data;
	new -> next = NULL;
	new -> prev = NULL;

	/* check for if list has only one node */
	if ( ((*head) -> next) == NULL)
	{
		/* if the node is the given element before which we need to add newNode*/
		if (((*head) -> data) == b_data)
		{
			//establish link between newnode and first node
			new -> next = *head;
			(*head) -> prev = new;

			//update head
			(*head) = new;
			return ;
		}
		else
		{
			return ;
		}
	}
	/* check for multi node case */
	else
	{
		/* If the element is in the head */
		if( ((*head) -> data) == b_data)
		{
			//establish link between newnode and first node
			new -> next = *head;
			(*head) -> prev = new;

			//update head
			(*head) = new;
			return ;
		}
		/* If the element is in the middle or end */
		else
		{
			/* if list has multiple nodes then, iterate till tail node */
           		while(temp)
			{
				// check if node is given element
				if ((temp-> data ) != b_data)
                		{
					// if no element is found at all then return
					if (temp -> next == NULL)
                    			{//pf(no element
                        			return ;
                    			}
				}
				else
				{
					// if element is present break
					break;
				}
				temp = temp -> next;
			}

			/* update new Node's next to temp that contains b_data */
			new -> next = temp;
			/* update new Node's prev to temp->prev */
			new -> prev = temp -> prev;

			/* update previous Node's next to new Node*/
			(temp -> prev) -> next = new;
			/* update temp -> prev to new Node */
			temp -> prev = new;
			return ;
		}
	}
	return ;
}
