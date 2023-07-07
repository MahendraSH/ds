// Nested structures 1

#include<stdio.h>

typedef struct P
{
    int x,y;
} Point;

typedef struct L
{
    Point p1,p2;
}Line;

int main()
{

Point p;
p.x =4;
p.y = 5;

Line l1;
l1.p1 = p;
l1.p2.x = 10;
l1.p2.y = 12;
return 0;
}


/*
OUTPUT:

*/
