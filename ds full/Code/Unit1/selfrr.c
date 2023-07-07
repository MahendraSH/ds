// self referencing structure : 2 Linked nodes  & traversal
#include<stdio.h>

struct node
{
    char type;
    int num;
    struct node *next;
};

// call by reference
void display(struct node *spr)
{
    printf("Type = %c\n", spr->type);
    printf("Data = %d\n", spr->num);

}

// call by reference
void displayAll(struct node *start)
{
    struct node *temp1 = start;
    printf("Type = %c\n", temp1->type);
    printf("Data = %d\n", temp1->num);

    // pointing to next node
    temp1 = temp1->next;

    printf("Type = %c\n", temp1->type);
    printf("Data = %d\n", temp1->num);
}

int main()
{
struct node *start =NULL;
start = (struct node*)malloc(sizeof(struct node)); // on heap

start->type = 'A';
start->num =  10;
start->next = NULL;

struct node *temp =NULL;
temp = (struct node*)malloc(sizeof(struct node)); // on heap
temp->type = 'B';
temp->num =  20;
temp->next = NULL;

start->next = temp;
displayAll(start);
return 0;
}

/*
OUTPUT:
    Type = A
    Data = 10
    Type = B
    Data = 20
*/
