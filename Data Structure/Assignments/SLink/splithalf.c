#include "slist.h"

int splithalf(SLink **head, SLink **ahead, SLink **bhead)
{
	//take local reference to traverse through the link
	SLink *temp, *temp2, *temp3;
	temp = *head;
	
	//get the mid_value of the given list that needs to be split
	int mid_value, i;
	mid_value = find_mid(*head);
	
	//check if list is empty
	if (mid_value == EMPTYLIST)
	{
		return EMPTYLIST;
	}
	
	//if head has only one element,
	if((*head) -> link == NULL)
	{
		*ahead = *head;
		*bhead = NULL;
		return SUCCESS;
	}		
	//if mid_value is > 0
	else
	{
		//iterate to the mid of a list and copy this into alist
		while(temp)
		{
			if(temp -> data == mid_value)
			{
				break;
			}
			insert_at_last(ahead, temp -> data); 
			temp = temp -> link;
		}
		temp3 = temp;
		
		// blist will be updated with temp2 which has second half
		*bhead = temp3; 	
		return SUCCESS;
	}
	
	return FAILURE;
}

/*METHOD 2*/
/*

// Uses the fast/slow pointer strategy
void FrontBackSplit2(struct node* source, struct node** frontRef, struct node** backRef) {
	struct node* fast;
	struct node* slow;
	if (source==NULL || source->next==NULL) { // length < 2 cases
		*frontRef = source;
		*backRef = NULL;
	}
	else {
		slow = source;
		fast = source->next;
		// Advance 'fast' two nodes, and advance 'slow' one node
		while (fast != NULL) {
			fast = fast->next;
			if (fast != NULL) {
				slow = slow->next;
				fast = fast->next;
			}
		}
		// 'slow' is before the midpoint in the list, so split it in two
		// at that point.
		*frontRef = source;
		*backRef = slow->next;
		slow->next = NULL;
	}
}

*/
