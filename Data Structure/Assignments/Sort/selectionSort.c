#include "sort.h"


int selectionSort(int array[], int narray)
{
	int i, j, min_idx;
 
    	// One by one move boundary of unsorted subarray
    	for (i = 0; i < narray-1; i++)
    	{
        	// Find the minimum element in unsorted array
        	min_idx = i;
        	for (j = i+1; j < narray; j++)
		{
		          if (array[j] < array[min_idx])
			   {
				min_idx = j;
			  }
 		}
	        // Swap the found minimum element with the first element
        	swap(&array[min_idx], &array[i]);
    	}
	return SUCCESS;
}

