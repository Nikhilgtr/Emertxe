#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct
{
	int *arr1,*arr2,*out;
	int row,col;
}matrix_t;

void *matrix_mul(void *param)
{
	matrix_t *data=param;
	int sum=0,i,j;
	for(i=0;i<data->row;i++)
	{
		for(j=0;j<data->col;j++)
		{
			sum+=data->arr1[j]*data->arr2[i+j*data->col];
		}
		data->out[i]=sum;
		sum=0;
	}
	return NULL;
}

int main()
{
	int row1,col1,row2,col2,i,j;
	printf("Enter number of rows and coloums for matrix 1 : ");
	scanf("%d %d",&row1,&col1);
	printf("Enter number of rows and coloums for matrix 2 : ");
	scanf("%d %d",&row2,&col2);
	if(col1!=row2)
	{
		printf("Invalid Matrix format!!\n");
		return 1;
	}
	int *(matrix1[col1])=malloc()
	int matrix2[row2][col2];
	int matrix2t[col2][row2];
	int output[row1][col2];
	memset(&output,0,sizeof(output));
	matrix_t data[row1];
	pthread_t tid[row1];
	printf("Matrix 1\n");
	for(i=0;i<row1;i++)
	{
		printf("Enter %d elements for row %d:",col1,i+1);
		for(j=0;j<col1;j++)
		{
			scanf("%d",&matrix1[i][j]);
		}
	}
	printf("Matrix 2\n");
	for(i=0;i<row2;i++)
	{
		printf("Enter %d elements for row %d:",col2,i+1);
		for(j=0;j<col2;j++)
		{
			scanf("%d",&matrix2[i][j]);
		}
	}
	for(i=0;i<col2;i++)
	{
		for(j=0;j<row2;j++)
		{
			matrix2t[i][j]=*(*(matrix2+(j*1))+i);
		}
	}

	for(i=0;i<row1;i++)
	{
		data[i].arr1=matrix1[i];
		data[i].arr2=matrix2t;
		data[i].out=output[i];
		data[i].row=row2;
		data[i].col=col2;
		pthread_create(&tid[i],NULL,matrix_mul,&data[i]);
		pthread_join(tid[i],NULL);
	}
	for(i=0;i<row1;i++)
		pthread_join(tid[i],NULL);

	for(i=0;i<row1;i++)
	{
		for(j=0;j<col2;j++)
			printf("%d ",output[i][j]);
		printf("\n");
	}
	printf("\n");
	return 0;
}
