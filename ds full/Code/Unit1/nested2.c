// Nested structures 2

#include<stdio.h>
struct Line
{
    struct Point1
    {
        int x,y;
    } ;

    struct Point1 p1,p2;
};

int main()
{

struct Point1 p;
p.x =4;
p.y = 5;

struct Line l1;
l1.p1 = p;
l1.p2.x = 10;
l1.p2.y = 12;
return 0;
}

/*
OUTPUT:

*/
