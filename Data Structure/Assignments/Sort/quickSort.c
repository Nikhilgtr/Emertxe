#include "sort.h"


void quickSort(int array[], int low, int high)
{
	int i;

	if (low < high)
	{
		//to get the split value
		i = split(array, low, high);
		//quickSort left sub array
		quickSort(array, low, i);
		//quickSort right sub array
		quickSort(array, i+1, high);
	}			
}
