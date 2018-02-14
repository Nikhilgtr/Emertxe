#include<stdio.h>

void b_search(int,int *,int);
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
    printf("Enter the value you want to search\n :");
    scanf("%d",&val);
    b_search(val,arr,n);

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
     printf(" Array :");
    for(i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }
    printf("\n");

}


void b_search(int val, int *arr,int n)
{
    int mid,upper=n,lower=0;

     mid=(lower+upper)/2;        //middle point
    while(upper>=lower)
    {
        if(val < *(arr+mid))
        {
          upper=mid-1;
          mid=(lower+upper)/2;
        }

        if(val > *(arr+mid))
        {
            lower=mid+1;
            mid=(lower+upper)/2;
        }
        if(val == *(arr+mid))
        {
            break;
        }

    }
        printf("Your item is Avail on [%d]",mid);
}
