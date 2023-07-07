//Simple dynamic memory allocation & freeing
#include<stdio.h>
int main()
{

    int *p ;

    int n =10;

    p = (int*)malloc(sizeof(int)*n);

    *p =  100;
    *(p+1) = 200;
    printf("*p = %d  *(p+1) = %d",*p, *(p+1));

    free(p);

}

/*
OUTPUT:
*p = 100  *(p+1) = 200
*/
