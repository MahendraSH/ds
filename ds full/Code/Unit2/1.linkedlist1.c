// Linear Linked List Implementation
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;  // Start pointer of lined list

struct node* getnode()
{
    struct node* temp  = (struct node*)malloc(sizeof(struct node));
    return temp;
};

int isSingle()
{
    return start->next == NULL?1:0;
}

int isEmpty()
{
    return start == NULL?1:0;
}

void createList(int x);
void traverse();

// Insert operations
void insert_begin(int x);
void insert_after(int data, int newdata);
void insert_end(int x);

// Delete operations
void delete_begin();
void delete_after(int data);
void delete_end();
void delete_node(int x);

int main()
{

    createList(10);     //List: 10
    traverse();

    insert_begin(20); // List: 20 10
    traverse();

    insert_begin(50); // List: 50 20 10
    traverse();

    insert_after(20,15); // List: 50 20  1510
    traverse();

    insert_end(5); //List: 50 20 15 10 5
    traverse();

    delete_begin(); //List: 20 15 10 5
    traverse();

    delete_after(20);  //List: 20 10 5
    traverse();

    delete_end();   //List: 20 10
    traverse();

    delete_end(); //List: 20
    traverse();

    delete_end(); // List : empty
    traverse();

    delete_end(); // Underflow

    insert_begin(20); //  List :  20
    insert_begin(50); //  List :  50 20
    insert_end(5);      //  List :  50 20 5
    traverse();

    delete_node(50);  // List :20 5
    traverse();

    delete_node(20); // List : 5
    traverse();
    delete_node(5); // List :  empty
    traverse();

    delete_node(5); // Underflow

    return 0;
}

void delete_begin()
{
    if(isEmpty())
    {
        printf("Underflow\n");
         return ;
    }

    struct node *temp = start;
    start = start->next;
    free(temp);
}

void createList(int x)
{
    if(start == NULL)
    {
        start = getnode();
        start->data = x;
        start->next = NULL;
    }
}


void insert_begin(int x)
{
    struct node *temp = NULL;
    if(start ==NULL)
        createList(x);
    else
    {
        temp = getnode();
        temp->data = x;
        temp->next = NULL;
        temp->next = start;
        start = temp;
    }
}


void traverse()
{
    struct node * temp = start;
    if(isEmpty())
    {
        printf("List is empty\n");
        return;
    }

    printf("Curr. List: ");
    while(temp!=NULL)
    {
        printf("%d ", temp->data);  // Processing
        temp =temp->next;
    }
    printf("\n");
}

void insert_after(int d, int newdata)
{
    if(isEmpty())
        createList(newdata);
    else
    {
        struct node * temp = start;
        while(temp != NULL)
        {
            if(temp->data != d)
            {
                temp = temp->next;
            }
            else{
                struct node * newnode = getnode();
                newnode->data = newdata;
                newnode->next = temp->next;
                temp->next = newnode;
                break;
            }
        }
    }
}


void insert_end(int x)
{

    struct node *temp = NULL;
    if(isEmpty())
        createList(x);
    else
    {

        struct node * temp = start;
        while(temp->next != NULL)
        {
                temp = temp->next;
        }
        struct node * newnode = getnode();
        newnode->data = x;
        newnode->next = NULL;
        temp->next = newnode;
    }

}

void delete_after(int d)
{
    if(isEmpty())
    {
        printf("Underflow\n");
         return ;
    }
    struct node * temp = start;
    while(temp != NULL)
    {
        if(temp->data != d)
        {
            temp = temp->next;
        }
        else
        {
            struct node* t = temp->next;

            temp->next = t->next; // t == NULL?

            //if(isSingle())  // Only 1 node in list. Deleting that.
             //   start = NULL;
            free(t);
            break;
        }
    }
}


void delete_end()
{
    if(isEmpty())
    {
        printf("Underflow\n");
        return;
    }

    struct node *cur,*prev;
    prev = cur = start;
    while(cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    // cur points to last node.
    // prev points to second last node
    free(cur);
    if(cur == prev) // Only 1 node existed in the list. Removed that
    {
        start = NULL;
    }
    else
    {
        prev->next = NULL;
    }

}

void delete_node(int x)
{
    if(isEmpty())
    {
        printf("Underflow\n");
        return;
    }
    struct node *cur, *prev;
    cur = prev = start;
    while(cur!= NULL)
    {
        if(cur->data != x)
        {
            prev = cur;
            cur = cur->next;
        }
        else
        {
            if(isSingle())
            {
                // Only1 node exists. removing that
                start = NULL;
                free(cur);
                return;
            }
            prev->next = cur->next;
            if(cur == start) // First node is the node to be deleted
                start = start->next;
            free(cur);
            break;
        }
    }
}


/*
Curr. List: 10
Curr. List: 20 10
Curr. List: 50 20 10
Curr. List: 50 20 15 10
Curr. List: 50 20 15 10 5
Curr. List: 20 15 10 5
Curr. List: 20 10 5
Curr. List: 20 10
Curr. List: 20
List is empty
Underflow
Curr. List: 50 20 5
Curr. List: 20 5
Curr. List: 5
List is empty
Underflow
*/



