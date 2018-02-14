#include "slist.h"

int append(SLink **ahead, SLink **bhead)
{
	//take local reference to traverse through the link
	SLink *temp;
	temp = *ahead;
	
	//check if ahead is empty
	if ((*ahead) == NULL)
	{
		//append b to a i.e a will be as a is empty
		(*ahead) = (*bhead);
	}
	else
	{
		//iterate to the end of a list
		while(temp -> link)
		{
			temp = temp -> link;
		}
		//add the b list at the end of alist
		temp -> link = (*bhead);
	}
	// NULL the original b, since it has been appended above
	*bhead = NULL; 	
	return SUCCESS;
}
