// n-th term in fibonacci series (0th term is 0, 1st term is 1)
#include <stdio.h>
int Fibonacci(int);
int main()
{
int n, i = 0, res=-1;
printf("Enter the number of terms\n");
scanf("%d",&n);

if(n>=0)
    res = Fibonacci(n);
printf("Term %d in fib series = %d\t",n,res);

return 0;
}

// Nth term of fibonacci series.
// Assume first number 0 is 0th term.
int Fibonacci(int n)
{
if ( n == 0 || n == 1)
    return n;
else
    return ( Fibonacci(n-1) + Fibonacci(n-2) );
}
