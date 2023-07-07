// Simple circular queue with global container array and pointers.

#include <stdio.h>

#define MAXSIZE 5

int items[MAXSIZE];
int front = -1, rear =-1;

int isFull()
{
    if( (front == rear + 1) ||
        (front == 0 && rear == MAXSIZE-1)) return 1;

    // if((rear+1)%MAXSIZE == front)
        // return 1;
    return 0;
}

int isEmpty()
{
    if(front == -1) return 1;
    return 0;
}

void insert(int element)
{
    if(isFull()) printf("\n Queue is full!! \n");
    else
    {
        if(front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % MAXSIZE;
            // if(rear = MAXSIZE-1) rear = 0; else rear = rear+1; // ALT
        items[rear] = element;
        printf("\n Inserted -> %d", element);
    }
}


int delete()
{
    int element;
    if(isEmpty()) {
        printf("\n Queue is empty !! \n");
        return(-1);
    } else {
        element = items[front];
        if (front == rear){
			/* Q has only one element, so we reset the queue after dequeing it. */
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % MAXSIZE;  // ALT: if(front == MAXSIZE -1)  front = 0; else front = front+1;
        }
        printf("\n Deleted element -> %d \n", element);
        return(element);
    }
}




void display()
{
    int i;
    if(isEmpty()) printf(" \n Empty Queue\n");
    else
    {
        printf("\n Front -> %d ",front);
        printf("\n Items -> ");
        for( i = front; i!=rear; i=(i+1)%MAXSIZE) {
            printf("%d ",items[i]);
        }
        printf("%d ",items[i]);
        printf("\n Rear -> %d \n",rear);
    }
}

int main()
{
    // Fails because front = -1
    delete();

    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    // Fails to insert because front == 0 && rear == MAXSIZE - 1
    insert(6);

    display();
    delete();

    display();

    insert(7);
    display();

    // Fails to insert because front == rear + 1
    insert(8);

    delete();
    delete();
    insert(8);
    insert(9);
    insert(10);

    display();

    delete();
    display();

    delete();
    display();

    delete();
    display();

    delete();
    display();

    delete();
    display();

    delete();
    display();
    return 0;
}
