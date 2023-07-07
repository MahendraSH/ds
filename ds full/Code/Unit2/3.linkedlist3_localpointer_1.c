// Linked list implementation with local pointer
// Approach 1: Return the new start pointer from functions as function return value
#include<stdio.h>
#include<stdlib.h>

// node definition
struct node
{
    int data;
    struct node *next;
};

struct node* getnode();				 	// Creates a new empty node and return the address
struct node* insert_at_start(struct node* st, int newData); 		// Insert new node at start of the list.
void  display(struct node* st);

int  main()
{
    int i,num,elem;
    struct node *list = NULL;  // list is local pointer to starting of the list;

    while(1)
    {
        printf("\nList Operations\n");
        printf("===============\n");
        printf("1.Insert At Start\t");
        printf("8.Display\t\t");
        printf("9.Exit\n\n");


        printf("Enter your choice : ");
        if(scanf("%d",&i)<=0){
            printf("Error! Enter only an Integer\n");
            exit(0);
        }
        else
        {
            switch(i)
            {
            case 1:  printf("Enter the number to insert : ");
                     scanf("%d",&num);
                     list = insert_at_start(list, num);
                     display(list);
                     break;
            case 8:
                    display(list);
                    break;
            case 9:     return 0;

            default:    printf("Invalid option\n");
            }
        }
    }
    return 0;
}


struct node* getnode()
{
	struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->next  = NULL;
    return temp;
}

struct node*  insert_at_start(struct node* st, int newData){

	// Creation on new node
	struct node *temp;
	temp  =  getnode();

    // Store data
    temp->data=newData;
    if (st== NULL)
    {
    printf("First node\n");
    temp->next=NULL;
    st=temp;
    }
    else
    {
    temp->next=st;
    st=temp;
    }

    return st;
}



void  display(struct node* st)
{
    struct node* temp=st;
    if(temp==NULL)
    {
		printf("{List is Empty}\n");
		return;
    }
    printf("The List is : ");
    while(temp!=NULL)
    {
		printf("%d-->",temp->data);
		temp=temp->next;
    }
    printf("NULL\n");
}
