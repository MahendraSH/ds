// Demonstration use of void pointer (void*)
#include<stdio.h>

void display(void *p, int type)
{
    if(type == 1)
        printf("*p = %d\n", *((int*)p)  );
    else if(type == 2)
        printf("*p = %f\n", *(float*)p);

}

int main()
{

    int x = 100;
    float y =999;

    void *ptr = &x;
    ptr = &y;

   // printf("*ptr = %f", *(float*)ptr);

    display(&x, 1);
    display(&y, 2);
}

/*
OUTPUT:
*p = 100
*p = 999.000000
*/
