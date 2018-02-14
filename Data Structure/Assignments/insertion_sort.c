#include <stdio.h>

int main()
{
	int arr[5]={1,9,8,5,7};

	int i,j,n=5,temp;
	
	for(i=1;i<n;i++)
	{
		j=i-1;
		temp=arr[i];
	while(j >= 0 && arr[j]< temp)
		{
			arr[j++]=arr[j];
			j--;
		}

		arr[j+1]=temp;
		
	}

	i=0;
	while(i<10)
	{
		printf(" %d ",arr[i]);
		i++;
	}
		return 0;
}
