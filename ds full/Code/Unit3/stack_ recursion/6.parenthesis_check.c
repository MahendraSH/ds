// Parenthesis Checker using stack
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 20
int top = -1;
int stk[MAX];
void push(char);
char pop();

void main()
{
char exp[MAX],temp;
int i, flag=1; // assume expression is valid w.r.t to brackets

printf("Enter an expression : ");
gets(exp);
for(i=0;i<strlen(exp);i++)
{
    if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
    push(exp[i]);

    if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
    {
    if(top == -1)
        {
            flag=0; break;
        }
    else
        {
            temp=pop(); // pop the top element from stack
            if(exp[i]==')' && temp!= '(')
                {flag=0; break;}
            if(exp[i]=='}' && temp!= '{')
                {flag=0; break;}
            if(exp[i]==']' && temp!= '[')
                {flag=0; break;}
        }
    }
}
if(top>=0)  // Stack should be empty now for a valid expression
    flag=0;

// Final verdict
if(flag == 1)
    printf("\nValid expression");
else
    printf("\nInvalid expression");
}


void push(char c)
{
    if(top == MAX-1)
        printf("Stack Overflow\n");
    else
    {
        stk[++top] = c;
    }
}

char pop()
{
    if(top == -1)
        printf("\n Stack Underflow");
    else
        return(stk[top--]);
}
