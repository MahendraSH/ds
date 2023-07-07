
// Doubly Linked list implementation.
#include<stdio.h>
#include<stdlib.h>

// node definition
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *list = NULL;  // list is global pointer to starting of the list


struct node* getnode();				 	// Creates a new empty node and return the address
void insert_at_start(int newData); 		// Insert new node at start of the list.
void insert_at_end(int newData);  		// Insert new node at end of list
void insert_after(int existingData, int newData); // Insert new node after given element value
int delete_element(int elem);  			// delete node with given element.
void delete_first_node(); 				// delete first node of list
void delete_last_node();  				// delete last node of list
struct node* search(int x); 			// Search for  an element & return the pointer of the node
void  display();                        // Display element from start

void  displayFromLast();                // Display element from end


int  main()
{
    int i,num,elem;
    list=NULL;
    while(1)
    {
    printf("\nList Operations\n");
    printf("===============\n");
    printf("1.Insert At Start\t");
    printf("2.Insert At End\t\t");
    printf("3.insert_after given element\n");
    printf("4.delete At Start\t");
    printf("5.delete At End\t\t");
    printf("6.Delete Given element\n");
    printf("7.Search\t\t");
    printf("8.Display\t\t");
    printf("9.Exit\n\n");

    printf("Enter your choice : ");
    if(scanf("%d",&i)<=0){
        printf("Enter only an Integer\n");
        exit(0);
    }
    else
    {
        switch(i)
        {
        case 1:
                 printf("Enter the number to insert : ");
                 scanf("%d",&num);
                 insert_at_start(num);
                 display();
                 break;

        case 2:  printf("Enter the number to insert : ");
                 scanf("%d",&num);
                 insert_at_end(num);
                 display();
                 break;

        case 3:
			    printf("Enter the number to insert :");
                scanf("%d",&num);

                printf("Enter the existing elem :");
                scanf("%d",&elem);
                insert_after(elem,num);
                display();
                break;

        case 4:
                 delete_first_node();
                 display();
                 break;

        case 5:
                 delete_last_node();
                 display();
                 break;

        case 6:
				if(list==NULL)
					printf("List is Empty\n");
				else
				{
					printf("Enter the number to delete : ");
					scanf("%d",&num);
					if(delete_element(num))
						printf("%d deleted successfully\n",num);
					else
						printf("%d not found in the list\n",num);
				}
				display();
                break;
        case 7:
                {
                printf("Enter the element to search :");
                scanf("%d",&elem);
                struct node *res = search(elem);
                if(res == NULL)
					printf("Element not found in list\n");
				else
					printf("Element found in list at node %p(address)\n",res);

                break;
                }

		case 8:
                display();
                displayFromLast();
                break;
        case 9:
            return 0;

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
    temp->prev  = NULL;
    return temp;
}

void insert_at_start(int newData){

	// Creation on new node
	struct node *temp;
	temp  =  getnode();

    // Store data
    temp->data=newData;
    if (list== NULL)
    {
    printf("First node\n");
    list=temp;
    list->next=NULL;
    list->prev = NULL;
    }
    else
    {
    temp->next=list;
    list->prev = temp;
    list=temp;
    }
}


void delete_first_node()
{
    struct node *temp;
    temp=list;

    if(list != NULL)
    {
		list = list->next;
		if(list) // If list not empty
            list->prev = NULL;
		free(temp);
	}
	else
		printf("List is already empty\n");

    return;
}

void insert_at_end(int num)
{
	// Create new node
	struct node *cur;
	if(list == NULL)
		insert_at_start(num);
	else
	{
		cur = list;
		// Novigate to end of the list
		while(cur->next != NULL)
		{
			cur=cur->next;
		}

		// Creation on new node
		struct node *temp;
		temp  =  getnode();

		// Insert
		temp->data=num;
		cur->next =temp;
		temp->next  = NULL;
		temp->prev = cur;
	}
}


void delete_last_node()
{
    struct node *prev = NULL,*cur;
    cur=list;

    if(list != NULL)
    {
		// Navigate to last node
		while(cur->next != NULL)
		{
		prev = cur;
		cur = cur->next;
		}

		if(prev == NULL)
		{
			printf("Only one node in list. Deleting it to result in empty list.\n");
			free(cur);
			list = NULL;
		}
		else
		{
			free(cur);
			prev->next = NULL;

		}
	}
	else
		printf("List is already empty\n");

    return;
}

int delete_element(int num)
{
    struct node *cur, *prev = NULL;
    cur=list;
    while(cur!=NULL)
    {
		if(cur->data==num)
		{
			if(cur==list)
			{
			// deleting first node itself. So list need to be updated
			list=list->next;
			list->prev = NULL;
			free(cur);
			return 1;
			}
			else
			{
			prev->next=cur->next;
			if(cur->next) // If not last element
                cur->next->prev = prev;
			free(cur);
			return 1; // Success
			}
		}
		else
		{
			prev=cur;
			cur= cur->next;
		}
    }

    return 0;  // Element not found
}

void insert_after(int val, int newData) // place
{
    struct node *cur;
    cur = list;
    while(cur!=NULL)
    {
    if(cur->data == val)
		break;

    cur=cur->next;
    }

    if(cur!=NULL)
    {
	// Create new node
	// Creation on new node
	struct node *temp;
	temp  =  getnode();

    // insert
    temp->data=newData;

    temp->next = cur->next;
    temp->prev = cur;
    cur->next = temp;
    if(temp->next) // If not last node
        temp->next->prev = temp;
	}
	else
	{
		printf("Element not found!!");
	}
    return;

}


struct node* search(int x)
{
	struct node *cur;
    cur = list;
    while(cur!=NULL)
    {
    if(cur->data == x)
		break;
    cur=cur->next;
    }

    return cur;
}



void  display()
{
    struct node* temp=list;
    if(temp==NULL)
    {
		printf("{List is Empty}\n");
		return;
    }
    printf("The List is : ");
    printf("NULL");
    while(temp!=NULL)
    {
		printf("<==>%d<==>",temp->data);
		temp=temp->next;
    }
    printf("NULL\n");
}

void  displayFromLast()
{
    struct node* temp=list;
    if(temp==NULL)
    {
		printf("{List is Empty}\n");
		return;
    }
    // Goto last node
    while(temp->next!=NULL)
    {
		temp=temp->next;
    }

    printf("The Reverse List is : ");
    printf("NULL");
    while(temp!=NULL)
    {
		printf("<==>%d<==>",temp->data);
		temp=temp->prev;
    }
    printf("NULL\n");
}


// Count number of nodes in the list
int count()
{
    struct node *temp;
    int c=0;
    temp=list;
    while(temp!=NULL)
    {
    temp=temp->next;
    c++;
    }
    return c;
}


