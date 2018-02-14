#include <stdlib.h>
#include <stdio.h>
#include "common.h"
void reverse_i(slist_t**);
void reverse_r(slist_t**);
void delete_element(slist_t *,int );
void remove_duplicates(slist_t **);
void swap_d(slist_t *,slist_t *);
void bubbleSort_d(slist_t **);
void insert_first(slist_t **,int);
slist_t * create_node(int val);
void print_list(slist_t *);
void delete_first(slist_t **);
void insert_last( slist_t **,int);
void insert_before(slist_t **,int,int);
void delete_last(slist_t **);
void insert_after(slist_t **,int, int);
void find_node(slist_t *,int);
void delete_list(slist_t **);
void getnth(slist_t **,int);
void findmid(slist_t **);
void insert_sorted(slist_t **,int);
void merge_sort(slist_t **);


int main()
{
	int op,x;
	char ch;
	int val, element;

	slist_t *head=NULL;

	while(1)
	{
		printf("Enter your choice\n\t1.Insert First\n\t2.Insert Last\n\t3.Print List\n\t4.Delete First\n\t5.Delete Last\n");
		printf("\t6.Insert before\n\t7.Insert After\n\t8.Find Node\n\t9.Delete List\n\t10.Get nth\n\t11.Find mid");
		printf("\n\t12.Sort\n\t13.Remove Duplicates\n\t14.Insert sorted\n\t15.Iterative reverse\n\t16.Recursive reverse\n");
		printf("\t17.Merge sorted\nChoice :");

		scanf("%d",&op);

        switch(op)
		{
			case 1:
				{
					printf("Enter the number\n");
					scanf("%d",&x);
					insert_first(&head, x);
					break;
				}
			case 2:
				{

					printf("Enter the number\n");
					scanf("%d",&x);
					insert_last(&head, x);
					break;
				}

			case 3:
				{
					print_list(head);
					break;
				}
			case 4:
				{
					delete_first(&head);
					break;
				}
			case 5:
				{
					delete_last(&head);
					break;
				}
			case 6:
				{

					printf("Enter the element before which value to insertetd\n");
					scanf("%d",&element);
					printf("Enter the value to be added\n");
					scanf("%d",&val);
					insert_before(&head,val,element);

					break;
				}
			case 7:
				{

					printf("Enter the element After which value to insertetd\n");
					scanf("%d",&element);
					printf("Enter the value to be added\n");
					scanf("%d",&val);
					insert_after(&head,val,element);
					break;
				}
			case 8:
				{
					printf("Enter the value to be found out?\n");
					scanf("%d",&x);
					find_node(head,x);
					break;
				}
			case 9:
				{
					delete_list(&head);
					break;
				}
            case 10:
                {
                    printf("Enter the nth podtion of list?\n");
                    scanf("%d",&x);
                    getnth(&head,x);
                    break;
                }
            case 11:
                {
                    findmid(&head);
                    break;
                }
            case 12:
                {
                    bubbleSort_d(&head);
                    break;
                }
            case 13:
                {
                    remove_duplicates(&head);
                    break;
                }
            case 14:
				{
                    printf("Enter the number\n");
					scanf("%d",&x);
					insert_sorted(&head, x);
					break;
				}
            case 15:
				{
					reverse_i(&head);
					printf("Iterative Reverse Done\n");
					break;
				}
			case 16:
				{
					reverse_r(&head);
					printf("Recursive Reverse Done\n");
					break;
				}

			case 17:
				{
					merge_sort(&head);
                    break;
				}

			default:
				printf("Invalid Selection\n");
				break;

		}
	printf("Are you want to continue?\n");
		scanf("\n%c",&ch);
	if(ch=='y'||ch =='Y')
		continue;
	else
	break;
}

	return 0;


}



void print_list(slist_t *head)
{
	if(head== NULL)
	{
		printf("Error: No Linked lIst found\n");
		return;
	}
	else
	{
	slist_t *ptr;
	ptr=head;
	printf("List :");
	while(ptr != NULL)
	{

		printf(" %d ",ptr->data);
		ptr=ptr->next;
	}
		printf("\n");

	}
}
slist_t* create_node(int val)
{
	slist_t* new= malloc( sizeof(slist_t));
	new->data=val;
	new->next=NULL;
	return new;
}


void insert_first(slist_t **head,int var)
{

	if(*head == NULL)
	{

		*head=create_node(var);
	}
	else
	{
		slist_t *new= create_node(var);
		new->next=*head;
		*head=new;
	}
}

void insert_last( slist_t ** head,int var)
{
	if(*head==NULL)
	{
		*head = create_node(var);
	}
	else
	{
		slist_t *new=create_node(var);
		slist_t *ptr;
		ptr=*head;
		while(ptr->next)
		{
			ptr=ptr->next;
		}
		ptr->next=new;
		new->next=NULL;
	}
}
void delete_first(slist_t **head)
{
	if (*head== NULL)
	{
		printf("Error: No first element found\n");
		return ;
	}
	else
	{
		slist_t *ptr=*head;
		*head=ptr->next;
		free(ptr);
	}
}
void delete_last(slist_t **head)
{
	if(*head == NULL)
	{
		printf("Error: List not found\n");

	}
	else
	{
		slist_t *ptr=*head,*prev;

		while(ptr->next)
		{
			prev=ptr;
			ptr=ptr->next;
		}
		prev->next=NULL;
		free(ptr);
	}
}
void insert_before(slist_t **head,int n_data, int b_data)
{
/* take a local reference of head */
	slist_t *temp;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		return;
	}

	//create newNode and update newnode data and link
	slist_t *new = malloc(sizeof(slist_t));
	if (NULL == new)
	{
		return ;
	}

	new -> data = n_data;
	new -> next = NULL;

	/* check for if list has only one node */
	if ( ((*head) -> next) == NULL)
	{
		/* if the node is the given element before which we need to add newNode*/
		if (((*head) -> data) == b_data)
		{
			//establish link between newnode and first node
			new -> next = *head;
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
			//update head
			(*head) = new;
			return ;
		}
		/* If the element is in the middle or end */
		else
		{
			/* if list has multiple nodes then, iterate till tail node */
           		 while ((temp -> next))
            		{
				/* check if next node is given element */
               			 if (((temp->next)-> data ) != b_data)
                		 {
					/* if no element is found at all then return */
                    			if (((temp->next)-> next ) == NULL)
					{
						return ;
					}
					temp = temp -> next;
				}
				else
                		{
                    			/* if element is present break */
                    			break;
                		}
			}
			/* temp -> link will have the b_data before which we have to add newNode */
			/* establish link between newNode + b_data containing node */
			//temp2 = temp;
			new -> next = temp -> next;
			/* insert */
			(temp -> next) = new;
			return ;
		}
	}
	return ;
}

void insert_after(slist_t **head,int val, int element)
{
/* take a local reference of head */
	slist_t *temp;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		printf("No list Found\n");
		return ;
	}

	//create newNode and update newnode data and link
	slist_t *new = create_node(val);

	/* check for if list has only one node */
	if ( ((*head) -> next) == NULL)
	{
		/* if the node is the given element after which we need to add newNode*/
		if (((*head) -> data) == element)
		{
			/* update first + newNode */
			((*head) -> next) = new;
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
			if ((temp-> data ) != element)
                	{
				// if no element is found at all then return
				if (temp -> next == NULL)
                    		{
								printf("Element Not found\n");
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
			/* update last + newNode */
			(temp -> next) = new;
			return ;
		}
		else
		{
			/* update the newNode's next */
			new -> next = temp -> next;
			/* update current node + newNode*/
			temp -> next = new;
			return ;
		}
	}
	return ;
}
void find_node(slist_t	*head,int val)
{	if(head == NULL)
	{
		printf("List Not Found \n");
		return;
	}
	else
	{
	slist_t *ptr;
	ptr=head;
	while(ptr->data != val)
	{
		ptr=ptr->next;
	}
	printf("Address of the for the value is %p\n",ptr);
	}
}

void delete_list(slist_t **head)
{
	if(*head == NULL)
	{
		printf("No list Found\n");
	}
	else
	{
	slist_t *ptr,*ptr2;
	ptr=*head;
	while(ptr != NULL)
	{
		ptr2=ptr;
			ptr=ptr->next;
		free(ptr2);
	}

	*head=NULL;
	}
}

void getnth(slist_t **head, int n)
{

    if((*head)== NULL)
    {
        printf("No list found\n");
        return;
    }
    else
    {
            int i;
        slist_t *ptr;
        ptr=(*head);

        for(i=1;i<n;i++)
        {
            if(ptr->next == NULL)
            {
                printf("Position not found\n");
                return;
            }
            ptr=ptr->next;
        }
        printf(" The nth value is %d\n",ptr->data);
    }
}

void findmid(slist_t **head)
{
    slist_t *ptr,*ptr2;
    ptr=(*head);
    ptr2=(*head);

    while(ptr->next !=NULL && ptr->next->next != NULL)
    {
        ptr2=ptr2->next;
        ptr=ptr->next->next;

    }
    printf("Mid Point is %d\n",ptr2->data);
}

void bubbleSort_d(slist_t **start)
{
    int swapped, i;
    slist_t*ptr1;
    slist_t *lptr = NULL;

    /* Checking for empty list */
    if (ptr1 == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = (*start);

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap_d(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}


void swap_d(slist_t *a, slist_t *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void remove_duplicates(slist_t **head)
{
    slist_t *p, *q, *prev, *temp;

    p = q = prev = *head;
    q = q->next;
    while (p != NULL)
    {
        while (q != NULL && q->data != p->data)
        {
            prev = q;
            q = q->next;
        }
        if (q == NULL)
        {
            p = p->next;
            if (p != NULL)
            {
                q = p->next;
            }
        }
        else if (q->data == p->data)
        {
            prev->next = q->next;
            temp = q;
            q = q->next;
            free(temp);
        }
    }
}

void insert_sorted(slist_t **head,int data)
{
	/* take a local reference of head */
	slist_t *temp;
	temp = (*head);

	slist_t *new = malloc(sizeof(slist_t));

	if (NULL == new)
	{
		return;
	}

	//update newnode data and link
	new -> data = data;
	new -> next = NULL;

	//if empty link
	if (NULL == (*head))
	{
		(*head) = new;
		return ;
	}

	//case for single node
	if ((*head) -> next == NULL)
	{
		if ( ((*head) -> data) >= data )
		{
			new -> next = *head;
			(*head) = new;
			return ;
		}
		else
		{
			(*head) -> next = new;
			return ;
		}
	}
	//multi node
	else
	{
		//traverse through the list
		while(temp)
		{
			//if list data is greater than the given data, then add before this node
			if ( (temp -> data) >= data )
			{
				insert_before(head, temp -> data, data);
				return ;
			}
			//if the list data is less than given data that needs to be inserted
			else if ( (temp -> data) < data )
			{
				/* if no element is found at all then return */
                    		if ((temp->next) == NULL)
				{
					//if last node is reached, then add the new node in the end
					temp -> next = new;
					return ;
				}
			}
			//update the link
			temp = temp -> next;
		}

	}
	return ;
}

 void reverse_i(slist_t ** head)
{
    slist_t* prev   = NULL;
    slist_t* current = (*head);
    slist_t* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    (*head) = prev;
}

void reverse_r(slist_t** head)
{
    slist_t* first;
    slist_t* rest;

    /* empty list */
    if ((*head) == NULL)
       return;

    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = (*head);
    rest  = first->next;

    /* List has only one node */
    if (rest == NULL)
       return;

    /* reverse the rest list and put the first element at the end */
    reverse_r(&rest);
    first->next->next  = first;

    /* tricky step -- see the diagram */
    first->next  = NULL;

    /* fix the head pointer */
    (*head) = rest;
}

void merge_sort(slist_t **head)
{
    int x,op;
    char ch;
    slist_t *s1=NULL,*s2=NULL,*ptr=NULL,**temp=NULL;

    while(1)
    {
        printf("Enter the elements in the first list\n");
        printf("\t1.Insert first\n\t2.Insert last\n\t3.Print List\nChoice\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
				{
					printf("Enter the number\n");
					scanf("%d",&x);
					insert_first(&s1, x);
					break;
				}
        case 2:
				{

					printf("Enter the number\n");
					scanf("%d",&x);
					insert_last(&s1, x);
					break;
				}
        case 3:
				{
					print_list(s1);
					break;
				}
        default :
            printf("Invalid input\n");
            break;
        }

        printf("Are you done with first List\n");
        scanf("\n%c",&ch);
        if (ch=='y'||ch == 'Y')
            break;
        else
            continue;
    }


    while(1)
    {
        printf("Enter the elements in the second list\n");
        printf("\t1.Insert first\n\t2.Insert last\n\t3.Print list\nChoice\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
				{
					printf("Enter the number\n");
					scanf("%d",&x);
					insert_first(&s2, x);
					break;
				}
        case 2:
				{

					printf("Enter the number\n");
					scanf("%d",&x);
					insert_last(&s2, x);
					break;
				}
        case 3:
				{
					print_list(s2);
					break;
				}
        default :
            printf("Invalid input\n");
            break;
        }

        printf("Are you done with second List\n");
        scanf("\n%c",&ch);
        if (ch=='y'||ch == 'Y')
            break;
        else
            continue;
    }
    ptr=s1;
    while(ptr->next != NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=s2;
//    print_list(s1);

    bubbleSort_d(&s1);
    (*head)=s1;

}
