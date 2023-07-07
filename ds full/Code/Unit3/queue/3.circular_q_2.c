// Circular queue using structure. No dynamic memory allocation.   Local Queue created in MAIN.

#include <stdio.h>

#define MAXSIZE 5

struct Queue
{
int items[MAXSIZE];
int front, rear;
};

int isFull(struct Queue *cq)
{
    if( (cq->front == cq->rear + 1) || (cq->front == 0 && cq->rear == MAXSIZE-1)) return 1;
    return 0;
}

int isEmpty(struct Queue *cq)
{
    if(cq->front == -1) return 1;
    return 0;
}

void insert(struct Queue *cq, int element)
{
    if(isFull(cq)) printf("\n Queue is full!! \n");
    else
    {
        if(cq->front == -1) cq->front = 0;
        cq->rear = (cq->rear + 1) % MAXSIZE;
        cq->items[cq->rear] = element;
        printf("\n Inserted -> %d", element);
    }
}


int delete(struct Queue *cq)
{
    int element;
    if(isEmpty(cq)) {
        printf("\n Queue is empty !! \n");
        return(-1);
    } else {
        element = cq->items[cq->front];
        if (cq->front == cq->rear){
            /* Q has only one element, so we reset the queue after dequeing it. */
            cq->front = -1;
            cq->rear = -1;
        }
        else {
            // Increment front of queue
            cq->front = (cq->front + 1) % MAXSIZE;
        }
        printf("\n Deleted element -> %d \n", element);
        return(element);
    }
}




void display(struct Queue *cq)
{
    int i;
    if(isEmpty(cq)) printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d ",cq->front);
        printf("\n Items -> ");
        for( i = cq->front; i!=cq->rear; i=(i+1)%MAXSIZE) {
            printf("%d ",cq->items[i]);
        }
        printf("%d ",cq->items[i]);
        printf("\n Rear -> %d \n",cq->rear);
    }
}

int main()
{
	struct Queue q;
	q.front = q.rear = -1;
    // Fails because front = -1
    delete(&q);

    insert(&q,1);
    insert(&q,2);
    insert(&q,3);
    insert(&q,4);
    insert(&q,5);

    // Fails to insert because front == 0 && rear == MAXSIZE - 1
    insert(&q,6);

    display(&q);
    delete(&q);

    display(&q);

    insert(&q,7);
    display(&q);

    // Fails to insert because front == rear + 1
    insert(&q,8);

    delete(&q);
    delete(&q);
    insert(&q,8);
    insert(&q,9);
    insert(&q,10);

    display(&q);

    delete(&q);
    display(&q);

    delete(&q);
    display(&q);

    delete(&q);
    display(&q);

    delete(&q);
    display(&q);

    delete(&q);
    display(&q);

    delete(&q);
    display(&q);
    return 0;
}
