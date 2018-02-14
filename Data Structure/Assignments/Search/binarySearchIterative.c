#include "search.h"

int binarySearchIterative(int arr[], int left, int right, int data)
{
	while (left <= right)
	{
		int mid = left + (right - left)/2;
	
		// Check if data is present at mid
		if (arr[mid] == data) 
		{
			return mid;
		} 
		// If data greater, ignore left half	
		if (arr[mid] < data) 
		{
			left = mid + 1; 
		}
		// If data is smaller, ignore right half
		else 
		{
			right = mid - 1;
		} 
	}	
	// if we reach here, then element was not present
	return NOELEMENT;
}
