#include "sort.h"


void merge(int *array, int narray, int *left, int nleft, int *right, int nright)
{
	int i, j, k;

	//initialize
	i = 0;
	j = 0;
	k = 0;


	while ((i < nleft) && (j < nright))
	{
		//if left value is less than rigt value, update array with left value 
		if (left[i] < right[j])
		{
			array[k] = left[i];
			//increment the count of left and array
			k++;
			i++;
		}
		//else if update array with right value 
		else
		{
			array[k] = right[j];
			//increment the count of right and array
			k++;
			j++;
		}
	}
	//if right is greater than left side, rest all values of right are added into array	
	while(j < nright)
	{
		array[k++] = right[j++];
	}
	//if left is greater than right side, rest all values of left are added into array	
	while(i < nleft)
	{
		array[k++] = left[i++];
	} 		
}
