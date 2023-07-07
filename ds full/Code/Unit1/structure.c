//Structure , dynamic memory allocation.
// Pointer to structure etc.
#include<stdio.h>

struct node
{
    int x;
    char y;
};

int xyz;
int main()
{
    struct node s;
    s.x = 100;
    s.y= 'A';
    struct node *p;
    p =&s;

    // dynamic memory allocation
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    t->x = 200;
    t->y = 'X';

    printf("Address: %d\n", &s);
    printf("Address: %d\n", p);

    printf("%d %c\n", s.x,s.y);

    printf("%d %c\n", t->x, t->y);
    return 0;
}
