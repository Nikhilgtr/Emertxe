#include "slist.h"

// removes the front node from the second list and pushes it onto the front of the first. 
void MoveNode(SLink** destRef, SLink** sourceRef) 
{
	SLink* newNode = *sourceRef; // the front source node local reference
	if (newNode != NULL)
	{	
		*sourceRef = newNode->link; // Advance the source pointer
		newNode->link = *destRef; // Link the old dest off the new node
		*destRef = newNode; // Move dest to point to the new node
	}	
}


SLink * merge_sortedlinks(SLink *ahead, SLink *bhead)
{
	//local copy to get mergedlink
	SLink *result = NULL;
	

	//take a reference pointer to the last result pointer
	SLink** last = &result;

	while (1) 
	{
		//if only alist is empty return empty list
		if ((ahead == NULL) && (bhead == NULL))
		{
			return NULL;
		}
		//if only alist is empty, update the list with b list data
		if (ahead == NULL) 
		{
			*last = bhead;
			break;
		}
		//if only blist is empty, update the list with a list data
		else if (bhead == NULL)
		{
			*last = ahead;
			break;
		}
		//if alist element is less than b list element, add 1st element of a list into result pointed by last
		if ((ahead -> data) <= (bhead -> data))
		{
			MoveNode(last, &ahead);
		}
		else
		{
			//else add 1st element of b list into result pointed by last
			MoveNode(last, &bhead);
		}
		
		last = &((*last) -> link); // advance to point to
		
	}
	return (result);
}

