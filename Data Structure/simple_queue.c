#include <stdio.h>
#define SIZE 5

static int rear=-1;
static int front=-1;

void enqueue(int *,int,int);
int dequeue(int *);
void print_queue(int *);
int is_empty();
int is_full(int);

int main()
{
    int queue[SIZE],op,x;
    char ch;

    while(1)
    {
        printf("\t1.ENQUEUE\n\t2.DEQUEUE\n\t3.PRINT QUEUE\nChoice :");
        scanf("%d",&op);

        switch(op)
        {
        case 1:
            {
                printf("Enter the value to be enqueued\n");
                scanf("%d",&x);
                enqueue(queue,SIZE,x);
                break;
            }
        case 2:
            {
                printf("\tVAL=%d\n",dequeue(queue));
                break;
            }
        case 3:
            {
                print_queue(queue);
                break;
            }
        }
    printf("Are you want to continue ?\n");
    scanf("\n%c",&ch);
    if (ch=='y' || ch == 'Y')
        continue;
    else
        break;
    }
    return 0;

}


int is_empty()
{
    if (front == rear)
        return 1;
    else
        return 0;
}

int is_full(int size)
{
    if (rear == size-1)
        return 1;
    else
        return 0;
}

void enqueue(int *queue,int size,int val)
{
    if (is_full(size)==1)
    {
        printf("QUEUE IS FULL\n");
        return ;
    }
    else
    {
        queue[++rear]=val;
        return;
    }
}

int dequeue(int *queue)
{
    if(is_empty()==1)
    {
        printf("QUEUE is empty\n");
        return ;
    }
    else
    {
        return (queue[++front]);
    }
}

print_queue(int *queue)
{
    if(is_empty() ==1)
    {
        printf("QUEUE is empty\n");
        return ;
    }
    else
    {
        int temp=front;
        printf("QUEUE :");
        while(front != rear)
        {
            printf(" %d ",queue[++front]);
        }
        printf("\n");
        front=temp;
        return ;
    }
}
