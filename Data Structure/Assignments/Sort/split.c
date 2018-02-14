#include "sort.h"
void swapa(int *a, int *b);

int split(int array[], int low, int high)
{
	int pivot, p, q;

	//initialize values
	pivot = low;
	p = low +1;			
	q = high;

	//while p and q does not cross over repeat
	while(p <= q)
	{
		//if the p value is less than pivot, keep incrementing by 1
		while (array[p] < array[pivot])
		{
			p++;
		}
		//if the q value is greater than pivot, keep decrement by 1
		while (array[q] > array[pivot])
		{
			q--;
		}
		//if p crossover q, swap p and q
		if(p < q)
		{
			swap(&array[p], &array[q]);
		}		
	}	
	//swap the pivot value with q 
	swap( &array[q], &array[pivot]);
	return q;
}

