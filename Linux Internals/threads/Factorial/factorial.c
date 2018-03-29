#include<stdio.h>
#include<pthread.h>
#include<string.h>

/* structure */
typedef struct
{
	int val;
	int limit;
	long int *result;
}mul_t;

/* function read by thread to calculate parital factorial */
void *multiply(void *param)
{
	/* void pointer to required pointer type */
	mul_t *data=param;
	int i;
	/* initialize result */
	*data->result=1;
	/* loop to iterate through values */
	for(i=0;i<data->limit;i++)
	{
		(*data->result)*=(data->val)-i;
	}
	return NULL;
}

/* main thread */
int main()
{
	int val,i=0;
	printf("Enter the number : ");
	scanf("%d",&val);
	int count; //thread count
	printf("Enter the limit : ");
	scanf("%d",&count);
	pthread_t tid[count];  //array of thread ids
	mul_t data[count];   //array of structures
	memset(&data,0,sizeof(data)); //clearing the structure array
	long int result[count],total=1;
	memset(&result,1,sizeof(result));
	/* loop to run multiple threads */
	for(i=0;i<count;i++)
	{
		/* initializing the structure to passed as an argument to the function */
		data[i].result=&result[i];
		data[i].val=val-i*count;
		/* conditions for getting limit */
		if(i==count-1 && data[i].val>count)   //last thread and excess values
			data[i].limit=data[i].val;

		else if(i<=count-1 && data[i].val<=0) //value less than or equal to 0
			data[i].limit=0;

		else if(i<=count-1 && data[i].val<count) //value less than count
			data[i].limit=val%count;
		else
			data[i].limit=count;
		/* creating a thread which will execute the multiply function */
		pthread_create(&tid[i],NULL,multiply,&data[i]);
	}
	/* loop for main thread to wait for other threads */
	for(i=0;i<count;i++)
	{
		pthread_join(tid[i],NULL);
		total*=result[i]; //calculate partial result
	}
	/* display output */
	printf("%d!=%ld\n",val,total);
	return 0;
}
