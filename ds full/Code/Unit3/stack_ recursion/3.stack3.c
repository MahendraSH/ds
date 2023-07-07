// Stack implementation with structure & array
// Local stack
#include <stdio.h>
#define MAX 10

struct stack
{
    int elements[MAX];
    int  top;
};

void initialize(struct stack *st)
{
    st->top = -1;
}
void push(struct stack *st, int val);
int pop(struct stack *st);
int peek(struct stack *st);
void display(struct stack *st);

int main()
{
int val, option;
struct stack st; // Local stack

// Initialize stack
initialize(&st);

do
{
    printf("\n *****MAIN MENU*****");
    printf("\n 1. PUSH");
    printf("\n 2. POP");
    printf("\n 3. PEEK");
    printf("\n 4. DISPLAY");
    printf("\n 5. EXIT");
    printf("\n Enter your option : ");
    scanf("%d", &option);
    switch(option)
    {
    case 1:
        printf("\n Enter the number to be pushed on stack : ");
        scanf("%d", &val);
        push(&st, val);
        break;
    case 2:
        val = pop(&st);
        if(val != -1)
        printf("\n The value deleted from stack is : %d", val);
        break;
    case 3:
        val = peek(&st);
        if(val !=  -1)
        printf("\n The value stored at top of stack is : %d", val);
    break;
    case 4:
        display(&st);
        break;
    }
}while(option != 5);

return 0;
}

void push(struct stack *s,int val)
{
    if(s->top == MAX-1)
    {
    printf("\n STACK OVERFLOW");
    }
    else
    {
    s->top++;
    s->elements[s->top] = val;
    }
}

int pop(struct stack *s)
{
    int val;
    if(s->top == -1)
    {
        printf("\n STACK UNDERFLOW");
        return -1;
    }
    else
    {
        val = s->elements[s->top];
        s->top--;
        return val;
    }
}
void display(struct stack *s)
{
    int i;
    if(s->top == -1)
        printf("\n STACK IS EMPTY");
    else
    {
        for(i=s->top; i>=0; i--)
        printf("\n POS[%d] ==> VAL[%d]",i,s->elements[i]);
    }
}
int peek(struct stack *s)
{
    if(s->top == -1)
    {
        printf("\n STACK IS EMPTY");
        return -1;
    }
    else
        return (s->elements[s->top]);
}
