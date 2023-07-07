// Dynamic memory allocation for structure types
#include<stdio.h>
struct node
{
    char type;
    int num;
};

// call by reference
void display1(struct node *spr)
{
    printf("Type = %c\n", spr->type);
    printf("Data = %d\n", spr->num);
}

int main()
{
struct node *p =NULL;
p = (struct node*)malloc(sizeof(struct node)); // on heap

p->type = 'A';
p->num =  10;

display1(p);

return 0;
}


/*
OUTPUT:
Type = A
Data = 10
*/
