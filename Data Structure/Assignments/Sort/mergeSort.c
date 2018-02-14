#include "sort.h"


int mergeSort(int array[], int narray)
{
	int i, mid;

	//if array has no elements then return no elements, else if only one element is present, then return that element
	if (narray == 1)
	{	
		return SUCCESS;
	}
	else if (narray <= 1)
	{	
		printf("No elements\n");
		return FAILURE;
	}

	//initailize
	mid = narray/2;

	//allocate memory for left sub array
	int *left = (int *)malloc (mid * sizeof(int));
	if(NULL == left)
	{
		printf("No memory\n");
		return FAILURE;
	}

	//allocate memory right sub array
	int *right = (int *)malloc ((narray-mid) * sizeof(int));
	if(NULL == right)
	{
		printf("No memory\n");
		return FAILURE;
	}

	//add the elements from 0 to mid-1 in left 
	for (i = 0; i < mid; i++)
	{
		left[i] = array[i];
	}

	//add the elements from mid to n-1 in left 
	for (i = mid; i < narray; i++)
	{
		right[i-mid] = array[i];
	}

	//divide the array into left and right till one element on each leg
	mergeSort(left, mid);
	mergeSort(right, (narray - mid));

	//start merging the arrays, recurssively
	merge(array, narray, left, mid, right, (narray - mid));

	//free the memory given for left and sub arrays
	free(left);
	free(right);	
}
