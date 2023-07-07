#include <stdio.h>
int exp_rec(int, int);

int main()
{
    int num1, num2, res;
    printf("\nEnter the two numbers: ");
    scanf("%d %d", &num1, &num2);
    res = exp_rec(num1, num2);
    printf ("\nRESULT = %d", res);
    return 0;
}


int exp_rec(int x, int y)
{
    if(y==0)
        return 1;
    else
        return (x * exp_rec(x, y-1));
}
