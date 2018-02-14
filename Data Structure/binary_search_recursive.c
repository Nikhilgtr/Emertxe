#include<stdio.h>

int binarySearchRecursive(int*,int,int,int);
int find_min(int [],int, int);
void print_array(int *,int);

int main()
{
    int n,i,val;
    printf("Enter the number of elements int the array\n");
    scanf("%d",&n);
    int arr[n];
     /*Entering the elements*/
     printf("****Enter the elements int the Array****\n");
          for(i=0;i<n;i++)
    {
        printf("Enter [%d] : ",i);
        scanf("%d",&arr[i]);
    }
    /*selection sort*/
    selection(arr,n);
    print_array(arr,n);
    printf("Enter the value you want to search\n:");
    scanf("%d",&val);
    if(0==binarySearchRecursive(arr,0,n,val))
    {
        printf("No element");
    }
    else
     {
        i=binarySearchRecursive(arr,0,n,val);
        printf("%d",i);
     }
    return 0;


}

int find_min(int arr[],int n, int k)
{
    int MIN,LOC,j;
    LOC=k;
    MIN=arr[k];
    for(j=k+1;j<n;j++)
    {
        if(MIN>arr[j])
         {
            MIN=arr[j];
            LOC=j;
         }
    }
    return(LOC);
}

int selection(int *arr, int n)
{
    int k,LOC,temp;
    for(k=0;k<n-1;k++)
        {
            LOC=find_min(arr,n,k);
            temp=arr[k];
            arr[k]=arr[LOC];
            arr[LOC]=temp;
        }
}

void print_array(int *arr,int n)
{
    int i;
     printf("Array :");
    for(i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }
    printf("\n");

}


int binarySearchRecursive(int *arr,int left, int right, int data)
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
    return 0;
}
