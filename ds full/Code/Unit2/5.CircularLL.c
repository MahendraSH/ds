// Implementation of Circular Singly Linked List
// Program from book by Reema Thareja
// Modified by TM
// Uses a local pointer to starting node of linked list

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};

struct node *create_cll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);

void drawLink(int countChar);  // Styling function by TM :-)

int main()
{
    int option;
    struct node *start = NULL;  // Local pointer to 1st node of CLL
    do
    {
    printf("\n\n *****MAIN MENU *****");
    printf("\n 1: Create a list");
    printf("\n 2: Display the list");
    printf("\n 3: Add a node at the beginning");
    printf("\n 4: Add a node at the end");
    printf("\n 5: Delete a node from the beginning");
    printf("\n 6: Delete a node from the end");
    printf("\n 7: Delete a node after a given node");
    printf("\n 8: Delete the entire list");
    printf("\n 9: EXIT");
    printf("\n\n Enter your option : ");
    scanf("%d", &option);
    switch(option)
    {
        case 1:
            start = create_cll(start);
            display(start);
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            display(start);
            break;
        case 4:
            start = insert_end(start);
            display(start);
            break;
        case 5: start = delete_beg(start);
            display(start);
            break;
        case 6:
            start = delete_end(start);
            display(start);
            break;
        case 7:
            start = delete_after(start);
            display(start);
            break;
        case 8:
            start = delete_list(start);
            printf("\n CIRCULAR LINKED LIST DELETED");
            break;
        }
    }while(option !=9);

return 0;
}


struct node *create_cll(struct node *start)
{
struct node *new_node, *ptr;
int num;
printf("\n Enter -1 to end");
printf("\n Enter the data : ");

scanf("%d", &num);
while(num != -1)
{
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = num;
    if(start == NULL)
    {
        new_node -> next = new_node;
        start = new_node;
    }
else
    {
        ptr = start;

        while(ptr -> next != start) // Goto last node
            ptr = ptr -> next;

        ptr -> next = new_node;
        new_node -> next = start;
    }
display(start);
printf("\n Enter the data(-1 to stop) : ");
scanf("%d", &num);
}
return start;
}


struct node *display(struct node *start)
{
     struct node* temp=start;
     int countChar = 0,n;

    if(temp==NULL)
    {
		printf("{List is Empty}\n");
		return;
    }
    printf("\nThe Circular List is : \n");
    while(temp->next != start)
    {
		n = printf("%d-->",temp->data);
		temp=temp->next;

		countChar+=n;
    }
    n = printf("%d\n",temp->data);
    countChar += n;
    drawLink(countChar);
    return start;
}

void drawLink(int countChar)
{

    printf("^");
    int i;
    for(i = 3; i<countChar;i++)
    printf(" ");
    printf("|\n|");
  for(i = 2; i<countChar-1;i++)
    printf("-");
    printf("v");
    // printf("%d",start->data);
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr = start;
    if(start == NULL)
    {
        new_node -> next = new_node;
        start = new_node;
    }
    else
    {
    while(ptr -> next != start)
        ptr = ptr -> next;

    ptr -> next = new_node;
    new_node -> next = start;
    start = new_node;
    }

    return start;
}


struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;

    ptr = start;
    if(start == NULL)
    {
        new_node -> next = new_node;
        start = new_node;
    }
    else
    {
    while(ptr -> next != start)
        ptr = ptr -> next;

    ptr -> next = new_node;
    new_node -> next = start;
    }

    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;

    if(start == start->next) // only 1 node
    {
        free(start);
        start = NULL;
        return start;
    }

    // more than one node in list
    while(ptr -> next != start)
        ptr = ptr -> next;

        ptr -> next = start -> next;
        free(start);
        start = ptr -> next;
    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    if(start == start->next) // only 1 node
    {
        free(start);
        start = NULL;
        return start;
    }

    while(ptr -> next != start)
    {
    preptr = ptr;
    ptr = ptr -> next;
    }
    preptr -> next = ptr -> next;
    free(ptr);
    return start;
}
struct node *delete_after(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value after which the node has to deleted : ");
    scanf("%d", &val);
    ptr = start;
    preptr = ptr;

    while(preptr -> data != val)
    {
        preptr = ptr;
        ptr = ptr -> next;
    }

    preptr -> next = ptr -> next;
    if(ptr == start)
    start = preptr -> next;
    free(ptr);
    return start;
}


struct node *delete_list(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr -> next != start)
        start = delete_end(start);
    free(start);
    start =  NULL;

    return start;
}
