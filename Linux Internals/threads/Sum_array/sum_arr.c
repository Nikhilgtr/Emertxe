#include<stdio.h>
#include<string.h>
#include<pthread.h>

#define col 5

/* structure to be passed as an argument to the thread function */
typedef struct
{
	int *ptr;
	int sum;
}arr_sum_t;

/* function to calculate sum of elements of an array */
void * sum_row(void *param)
{
	/* initialize a void pointer to a valid pointer type */
	arr_sum_t *row=param;
	int i;
	/* iterate through elements of array */
	for(i=0;i<col;i++)
		row->sum+=row->ptr[i];

	return NULL;
}

/* main thread */
int main()
{
	int row,max=0,max_row,i,j;

	printf("Enter the number of rows : ");
	scanf("%d",&row);
    
	/* array of thread Id's */
	pthread_t tid[row];
	/* array of structures */
	arr_sum_t data[row];
	/* clear array of structures */
	memset(&data,0,sizeof(data));

	/* 2-D array declaration */
	int arr[row][col];

	/* initialing 2-D array */
	for(i=0;i<row;i++)
	{
		printf("Enter %d elements for row %d\n",col,i+1);
		for(j=0;j<col;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
 
	/* loop to create multiple thread */
	for(i=0;i<row;i++)
	{
		/* pass base address of a 1-D array */
		data[i].ptr=arr[i];

		/* Creating thread which will execute function that calculates sum of 1-D array */
		pthread_create(&tid[i],NULL,sum_row,&data[i]);

		/* store sum of first array for reference */
		if(i==0)
			max=data[i].sum;
	}
    
	/* loop to prevent main thread from terminating before other threads */
	for(i=0;i<row;i++)
	{
		/* wait for thread termination */
		pthread_join(tid[i],NULL);
		/* store row and sum if greater than previous sum */
		if(max < data[i].sum)
		{
			max=data[i].sum;
			max_row=i;
		}
	}

	/* diplay result */
	printf("Maximum sum : %d\nrow : %d\n",max,max_row+1);
	return 0;
}
