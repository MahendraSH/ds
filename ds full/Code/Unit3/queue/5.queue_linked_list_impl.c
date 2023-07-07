// Dynamic implementation of queue

#include<stdio.h>
#include<stdlib.h>

// node definiton
struct node
{
    int data;
    struct node *next;
};


struct node *front = NULL;  // Pointer to front of Q. NULL for empty Q
struct node *rear = NULL;  // Pointer to rear of Q


struct node* getnode(); // Creates a new empty node and return the address
void freenode(struct node* n);


struct node* getnode()
{
	struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->next  = NULL;
    return temp;

}
void freenode(struct node* n)
{
	free(n);
}


//Insert at rear end of Q
void insert(int num)
{
	// Create new node

	// Creation & init of new node
	struct node *temp;
	temp  =  getnode();
	temp->data=num;
	temp->next  = NULL;


	if(rear == NULL)
		front = rear = temp;
	else
	{
		rear->next = temp;
		rear =temp; // Update rear to new node added
	}
}



// remove from front end Q
void delete()
{
    struct node *temp;
    temp = front;

    if(front != NULL)
    {
		front = front->next; // Advance front next node in queue
		freenode(temp);

		if(front == NULL)
			rear = NULL;  // List is empty
	}
	else
		printf("List is already empty\n");

    return;  // Element not found
}




void  display()
{
    struct node* temp=front;
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




int  main()
{
    int choice,num;
    front = NULL;
    while(1)
    {
    printf("\nList Operations\n");
    printf("===============\n");
    printf("1.Insert At End\t\t");
    printf("2.delete At Start\t");
    printf("3.Display\t\t");
    printf("4.Exit\n\n");

    printf("Enter your choice : ");
    if(scanf("%d",&choice)<=0){
        printf("Enter only an Integer\n");
        exit(0);
    } else {
        switch(choice)
        {

        case 1:  printf("Enter the number to insert : ");
                 scanf("%d",&num);
                 insert(num);
                 display();
                 break;
        case 2:
                 delete(num);
                 display();
                 break;
		case 3:
                display();

                break;
        case 4:     return 0;
        default:    printf("Invalid option\n");
        }
    }
    }
    return 0;
}
