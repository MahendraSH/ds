// Self referencing node and a
// minimal linked list display function.
#include<stdio.h>

struct node
{
    int x;
    char y;
    struct node *next;
};
struct node *start = NULL;

void display()
{
    struct node *temp = start;
    while(temp!=NULL)
    {
        printf("%d  %c ==>", temp->x,temp->y);
        temp = temp->next;
    }
}

int xyz;
int main()
{
    struct node s, p;
    s.x = 100;
    s.y= 'A';

    p.x = 200;
    p.y= 'B';
    p.next = NULL;

    s.next =  &p;

    start = &s;
    struct node *temp = start;
    printf("%d  %c ==>", temp->x,temp->y);
    temp = temp->next;
    printf("%d  %c ==>", temp->x,temp->y);
    printf("NULL\n");
    temp = start;

    printf("================================\n");
    display();
    printf("NULL\n");
    return 0;
}
