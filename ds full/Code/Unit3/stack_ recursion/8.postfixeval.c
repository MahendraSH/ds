// Evaluates  postfix expression of the form 567*-  i.e 5+6*7 in infix
// Assumes the input postfix expression is valid
#include<stdio.h>
#include<ctype.h>


int stack[20];
int top = -1;

void push(int x)
{
        stack[++top] = x;
}

int pop()
{
        return stack[top--];
}

int main()
{
        char exp[20];
        char *e;
        int n1,n2,n3,num;
        printf("Enter the expression:: ");
        scanf("%s",exp);
        e = exp;
        while(*e != '\0')
        {
                if(isdigit(*e))
                {
                        //48 is ascii value of zero.
                        num = *e - '0'; // Coverts character to corresponding digit
                        push(num);
                }
                else
                {
                        n2 = pop();
                        n1 = pop();
                        switch(*e)
                        {
                                case '+':
                                {
                                    n3 = n1 + n2;
                                    break;
                                }
                                case '-':
                                {
                                        n3 = n1 - n2;
                                        break;
                                }
                                case '*':
                                {
                                        n3 = n1 * n2;
                                        break;
                                }
                                case '/':
                                {
                                        n3 = n1 / n2;
                                        break;
                                }
                        }
                        push(n3);
                }
                e++;
        }
        printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
        return 0;

}
