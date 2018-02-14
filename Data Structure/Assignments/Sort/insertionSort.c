#include "sort.h"


int insertionSort(int array[], int narray)
{
	int i, j, flag;

	//check for each n*n times
	for (i = 0; i < narray; i++)
	{
		//check with adjacent elements
		for(j = i; j >= 0; j--)
		{
			if( array[j - 1] > array[j])
			{
				swap(&array[j], &array[j-1]);
			}		
			else
			{
				break;
			}
		
		}
	}
	return SUCCESS;
}

