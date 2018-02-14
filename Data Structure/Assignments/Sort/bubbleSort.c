#include "sort.h"

int bubbleSort(int array[], int narray)
{
	int i, j, flag;

	//check for each n*n times
	for (i = 0; i < narray-1; i++)
	{
		//everytime set flag to false
		flag = 0;
		for (j = 0; j < narray-i-1; j++)
		{
			//check with adjacent elements
			if (array[j] > array[j+1])
			{
				//if jth value is greater than j+1th value swap
				swap(&array[j], &array[j+1]);
				flag = 1;
			}
		}
		
		// IF no two elements were swapped by inner loop, then break
		if (!flag)
		{
			break;	
		}	
	}	
	return SUCCESS;		
}


