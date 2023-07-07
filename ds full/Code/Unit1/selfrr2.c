// self referencing structure : 3 Linked nodes  & traversal
#include<stdio.h>
// self referencing structure
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
void displayAll(struct node *st)
{
    struct node *temp1 = st;
    printf("Type = %c\n", temp1->type);
    printf("Data = %d\n", temp1->num);

    // pointing to next node
    temp1 = temp1->next;

    printf("Type = %c\n", temp1->type);
    printf("Data = %d\n", temp1->num);

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


struct node *temp1= (struct node*)malloc(sizeof(struct node));
temp1->type = 'C';
temp1->num =  30;
temp1->next = NULL;

temp->next = temp1;

displayAll(start);
return 0;
}

/*
OUTPUT:

Type = A
Data = 10
Type = B
Data = 20
Type = C
Data = 30

*/
