// Insert an element at given position(index)
#include<stdio.h>
int main()
{
int x[10]={5,9,8,7,10};
int n = 5;
int i,index =2;


printf("Before deletion:");
for(i=0;i<n;i++)
    printf("%d ",x[i]);

if(index >= n)
{
    printf("Invalid index");
    return -5;
}

// Shifting elements from index to n-1 by 1position to right
for(i = index; i< n-1; i++)
{
    x[i] = x[i+1];
}
n--;

printf("\nAfter deletion:");
for(i=0;i<n;i++)
    printf("%d ",x[i]);

return 0;
}


/*
OUTPUT:
 Before deletion:5 9 8 7 10
After deletion:5 9 7 10
*/
