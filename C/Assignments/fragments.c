/*
 *  Q. Read n for fragments (<=32). Read ki as the number of integer elements (<=32) in each fragment.
 *	Read all the elements of all the fragments. Sort each fragment and store their average as (ki + 1) th element.
 *	Sort the fragments based on their average value and print all.
 *  Re-sort the fragments based on their median and print all.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define ARR_ROW 20
#define ARR_COL 20
#define MAXVAL 200

void sortintNumbers(int array[], int intCount);
void swap_generic(void * aptr, void * bptr, int size);
int averageOfArray(int intArray[], int intCount);
int medianOfArray(int intArray[], int intCount);

int main()
{
    int no_of_fragments, i, no_of_elements_in_each_fragment, j;
	
	printf("Enter the number of fragments.\n");
	scanf("%d", &no_of_fragments);
	
	int ** const dp = (int **) malloc(no_of_fragments * sizeof(int *));
	int avgbuffer[MAXVAL], fragment_length_buffer[MAXVAL];
	int median_buffer[MAXVAL];
	
	if (NULL == dp)
	{
		printf("Error: Malloc allocation failed\n");
		return 1;
	}
    
	for(i = 0; i < no_of_fragments; i++)
	{
	
		printf("Enter the number of elements in fragment[%d]: ", i);
		scanf("%d", &no_of_elements_in_each_fragment);
		fragment_length_buffer[i] = no_of_elements_in_each_fragment;
		
		dp[i] = (int *) malloc((no_of_elements_in_each_fragment+1) * sizeof(int));
		
		if (NULL == dp[i])
		{
			printf("Error: Malloc allocation failed for fragment[%d].\n", i);
			return 1;
		}
		
		for(j = 0; j < no_of_elements_in_each_fragment; j++)
		{
			scanf("%d", &dp[i][j]);
		}
		
		/*
		printf("enter the elements\n");
		for( j = 0; j < no_of_elements_in_each_fragment; j++)
		{
			printf("dp[%d][%d] = %d", i, j, dp[i][j]);
		}
		printf("\n");
		*/
		
		//sort the numbers
		sortintNumbers(dp[i], no_of_elements_in_each_fragment);
		
		/*
		printf("entered elements after sort \n");
		for( j = 0; j < no_of_elements_in_each_fragment; j++)
		{
			printf("dp[%d][%d] = %d", i, j, dp[i][j]);
		}
		printf("\n");
		*/
		
		//to get median
		median_buffer[i] = medianOfArray(dp[i], no_of_elements_in_each_fragment);
		
		//to get the average
		dp[i][j] = averageOfArray(dp[i], no_of_elements_in_each_fragment);
		avgbuffer[i] = dp[i][j];
		/*
		printf("entered elements after sort and average \n");
		for( j = 0; j < (no_of_elements_in_each_fragment+1); j++)
		{
			printf("dp[%d][%d] = %d", i, j, dp[i][j]);
		}
		printf("\n");
		*/
		
	}
	
	int *tempptr;
	int tempval;
	
	printf("entered elements after sort and average \n");
	for(i = 0; i < no_of_fragments; i++)
	{
		//printf("%d", fragment_length_buffer[i]);
		
		for( j = 0; j < (no_of_fragments-1-i); j++)
		{
			
			// based on median value
			if (median_buffer[j] > median_buffer[j+1])
			{
				//swap fragment_length_buffer
				tempval = fragment_length_buffer[j];
				fragment_length_buffer[j] = fragment_length_buffer[j+1];
				fragment_length_buffer[j+1] = tempval;
				
				//swap actual arrays
				tempptr = dp[j];
				dp[j] = dp[j+1];
				dp[j+1] = tempptr;

				//swap median to correspond to the same arrangement
				tempval = median_buffer[j];
				median_buffer[j] = median_buffer[j+1];
				median_buffer[j+1] = tempval;
				
				//swap avg to correspond to same arrangement
				tempval = avgbuffer[j];
				avgbuffer[j] = avgbuffer[j+1];
				avgbuffer[j+1] = tempval;
			}		
		
		
			/*
			// based on avg value
			if (avgbuffer[j] > avgbuffer[j+1])
			{
				//swap fragment_length_buffer
				tempval = fragment_length_buffer[j];
				fragment_length_buffer[j] = fragment_length_buffer[j+1];
				fragment_length_buffer[j+1] = tempval;
				
				//swap actual arrays
				tempptr = dp[j];
				dp[j] = dp[j+1];
				dp[j+1] = tempptr;

				//swap median to correspond to the same arrangement
				tempval = median_buffer[j];
				median_buffer[j] = median_buffer[j+1];
				median_buffer[j+1] = tempval;
				
				//swap avg to correspond to same arrangement
				tempval = avgbuffer[j];
				avgbuffer[j] = avgbuffer[j+1];
				avgbuffer[j+1] = tempval;
			}	
			*/
		}
		printf("\n");
		
		printf("Output \n");
		for(i = 0; i < no_of_fragments; i++)
		{
			printf("median : %d -->", median_buffer[i]);
			for( j = 0; j < (fragment_length_buffer[i]+1); j++)
			{
				printf("%d  ", dp[i][j]);
			}
			printf("\n");
		}
		
	}
	
    return 0;
}


void sortintNumbers(int array[], int intCount)
{
    int i, j;
    
    for (i = 0; i < intCount; i++)
    {
        for (j = 0; j < intCount - i - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                swap_generic((array+j), (array+j+1), sizeof(int));
            }
        }
    }
}


void swap_generic(void * aptr, void * bptr, int size)
{
    int i;
    char temp;
    
    for ( i = 0; i < size; i++ )
    {
        temp = * (char *) aptr;
        * (char *) aptr++ = * (char *) bptr;
        * (char *) bptr++ = temp;
    }
}

int averageOfArray(int intArray[], int intCount)
{
	int average = 0, sum = 0, i;
	
	/*  Compute the mean of all elements */
    for (i = 0; i < intCount; i++)
    {
        sum += intArray[i];
    }
    average = sum / intCount;
    sum = 0;
	
	return average;
}

int medianOfArray(int intArray[], int intCount)
{
	int median;
	
	/* To get the median */
    /* if intCount is odd, median is the middle number in sorted array */
    if ( ( intCount % 2) != 0)
    {
        median = intArray[intCount/2];
    }
    /* if intCount is even, take the 2 middle numbers ((intCount / 2) and (intCount / 2) - 1 elements) and median will be average of them. */
    else
    {
        median = ((intArray[intCount/2] + intArray[(intCount/2)-1])/2);
    }
	return median;
}