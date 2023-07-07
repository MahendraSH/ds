// Simple Queue(Linear) Implementation with arrays.

#include<stdio.h>
#define MAXSIZE 5

int items[MAXSIZE];
int front = -1, rear = -1; // Initial empty state

void insert(int value){
    if(rear == MAXSIZE-1)
        printf("\nQueue is Full!!");
    else {
        if(front == -1)
            front = 0;
        rear++;
        items[rear] = value;
        printf("\nInserted -> %d", value);
    }
}

void delete(){
    if(front == -1)
        printf("\nQueue is Empty!!");
    else{
        printf("\nDeleted : %d", items[front]);
        front++;
        if(front > rear)
            front = rear = -1;
    }
}

void display(){
    if(rear == -1)
        printf("\nQueue is Empty!!!");
    else{
        int i;
        printf("\nQueue elements are:\n");
        for(i=front; i<=rear; i++)
            printf("%d\t",items[i]);
    }
}


int main()
{
    //delete is not possible on empty queue
    delete();

    //insert 5 elements
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    //6th element can't be added to queue because queue is full
    insert(6);
    display();
    //delete removes element entered first i.e. 1
    delete();
    //Now we have just 4 elements
    display();
    delete();
    display();
    insert(6);
    return 0;
}
