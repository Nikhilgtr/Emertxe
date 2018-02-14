#include <stdio.h>

int main()
{
int i,k,n,LOC,temp;
   // Asking number of elements in the array
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    int Arr[n];

        //Inserting the values in the array
        for(i=0;i<n;i++)
        {
            printf("[%d]->  : ",i);
            scanf("%d",&Arr[i]);
        }
        // printing the original array
    printf(" Array :");
    for(i=0;i<n;i++)
    {
        printf(" %d",Arr[i]);
    }
    printf("\n");

    //selection sorting the array
    for(k=0;k<=n-2;k++)
        {
            LOC=min(Arr,k,n);
            temp=Arr[k];
            Arr[k]=Arr[LOC];
            Arr[LOC]=temp;
        }
    printf(" Array :");
    for(i=0;i<n;i++)
    {
        printf(" %d",Arr[i]);
    }
return 0;

}

int min(int A[],int k,int n)
{
    int MIN,LOC,j;
    LOC=k;
    MIN=A[k];
    for(j=k+1;j<=n-1;j++)
    {
        if(MIN>A[j])
         {

            MIN=A[j];
            LOC=j;
         }
    }
    return(LOC);
}

