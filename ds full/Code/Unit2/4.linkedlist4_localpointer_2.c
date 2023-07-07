// Linked list implementation with a getnode function.
// Approach 2: Using a double pointer as function argument

#include<stdio.h>
#include<stdlib.h>

// node definiton
struct node
{
    int data;
    struct node *next;
};

struct node* getnode();				 	// Creates a new empty node and return the address
void insert_at_start(struct node** start, int newData); 		// Insert new node at start of the list.
void  display(struct node* start);

int  main()
{
    int i,num,elem;
    struct node *list = NULL;  // list is local pointer to starting of the list;

    struct node ** plist;
    plist = &list; // storing address of list in double pointer plist.

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
    } else {
        switch(i)
        {
        case 1:  printf("Enter the number to insert : ");
                 scanf("%d",&num);
                 insert_at_start(plist, num); // &list  is also acceptable instead plist here.
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

void insert_at_start(struct node** pstart, int newData){

	// Creation on new node
	struct node *temp;
	temp  =  getnode();

    // Store data
    temp->data=newData;

    if (*pstart== NULL)
    {
    printf("First node\n");
    temp->next = NULL;
    *pstart=temp;
    }
    else
    {
    temp->next=*pstart;
    *pstart=temp;
    }
}



void  display(struct node* start)
{
    struct node* temp=start;
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
