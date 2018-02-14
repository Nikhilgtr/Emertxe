#include "search.h"

int binarySearchRecursive(int arr[], int left, int right, int data)
{

	if (right >= left)
	{
		int mid = left + (right - left)/2;

		// If the element is present at the middle itself
		if (arr[mid] == data) return mid;

		// If element is smaller than mid, then it can only be present
		// in left subarray
		if (arr[mid] > data) return binarySearchRecursive(arr, left, mid-1, data);

		// Else the element can only be present in right subarray
		return binarySearchRecursive(arr, mid+1, right, data);
	}

	// We reach here when element is not present in array
	return NOELEMENT;
}
