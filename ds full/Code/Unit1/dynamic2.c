//Simple dynamic memory allocation for array
#include<stdio.h>

int main()
{

    int *p ;
    int n =10;
    int i;
    p = (int*)calloc(sizeof(int) , n);

    for(i=0;i<n;i++)
        *(p+i)= i;

    for(i=0;i<n;i++)
        printf("%d ", p[i]);

    free(p);
}

/*
OUTPUT:
        0 1 2 3 4 5 6 7 8 9
*/
