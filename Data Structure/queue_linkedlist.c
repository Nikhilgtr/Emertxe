// A C program to demonstrate linked list based implementation of queue
#include <stdlib.h>
#include <stdio.h>

// A linked list (LL) node to store a queue entry
struct QNode
{
    int key;
    struct QNode *next;
};

// The queue, front stores the front node of LL and rear stores ths
// last node of LL
struct Queue
{
    struct QNode *front, *rear;
};

// A utility function to create a new linked list node.
struct QNode* newNode(int k)
{
    struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

// A utility function to create an empty queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// The function to add a key k to q
void enQueue(struct Queue *q, int k)
{
    // Create a new LL node
    struct QNode *temp = newNode(k);

    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL)
    {
       q->front = q->rear = temp;
       return;
    }

    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove a key from given queue q
struct QNode *deQueue(struct Queue *q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
       return NULL;

    // Store previous front and move front one node ahead
    struct QNode *temp = q->front;
    q->front = q->front->next;

    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
       q->rear = NULL;
    return temp;
}

// Driver Program to test anove functions
int main()
{
    struct Queue *q = createQueue();
    int op,x;
    char ch;
    while(1)
    {
        printf("\t1.Enqueue\n\t2.Dequeue\nChoice :");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("Enter The number\n");
            scanf("%d",&x);
            enQueue(q,x);
            break;
        case 2:
            deQueue(q);
        break;
        default:
            printf("Invalid Entry\n");
            break;
        }
    printf("Are you want to continue\n");
    scanf("\n%c",&ch);
    if(ch=='y' || ch=='Y')
        continue;
    else
        break;

    }
          struct QNode *n = deQueue(q);
    if (n != NULL)
      printf("Dequeued item is %d", n->key);
    return 0;
}
