// Stack implementation with structure & array
// Global stack
#include <stdio.h>

#define MAX 10

struct stack
{
    int elements[MAX];
    int  top;
};

struct stack st; // Global stack

void initialize()
{
    st.top = -1;
}

void push(int val);
int pop();
int peek();
void display();
int main()
{
int val, option;

// Initialze stack
initialize();
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
        push(val);
        break;
    case 2:
        val = pop();
        if(val != -1)
        printf("\n The value deleted from stack is : %d", val);
        break;
    case 3:
        val = peek();
        if(val !=  -1)
        printf("\n The value stored at top of stack is : %d", val);
    break;
    case 4:
        display();
        break;
    }
}while(option != 5);

return 0;
}
void push(int val)
{
    if(st.top == MAX-1)
    {
    printf("\n STACK OVERFLOW");
    }
    else
    {
    st.top++;
    st.elements[st.top] = val;
    }
}


int pop()
{
    int val;
    if(st.top == -1)
    {
        printf("\n STACK UNDERFLOW");
        return -1;
    }
    else
    {
        val = st.elements[st.top];
        st.top--;
        return val;
    }
}

void display()
{
    int i;
    if(st.top == -1)
        printf("\n STACK IS EMPTY");
    else
    {
        for(i=st.top; i>=0; i--)
        printf("\n POS[%d] ==> VAL[%d]",i,st.elements[i]);
    }
}
int peek()
{
    if(st.top == -1)
    {
        printf("\n STACK IS EMPTY");
        return -1;
    }
    else
        return (st.elements[st.top]);
}
