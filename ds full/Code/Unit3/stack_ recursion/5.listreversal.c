#include <stdio.h>
#define MAX_SIZE 10

int stk[MAX_SIZE];
int top=-1;
int pop();
void push(int);

int main()
{
    int val, n, i,
    arr[10];

    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\n Enter the elements of the array : ");
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);

    for(i=0;i<n;i++)
        push(arr[i]);

    for(i=0;i<n;i++)
    {
        arr[i] = pop();
    }

    printf("\n The reversed array is : ");
    for(i=0;i<n;i++)
    printf("%d ", arr[i]);

    return 0;
}

void push(int val)
{
    stk[++top] = val;
}

int pop()
{
    return(stk[top--]);
}

