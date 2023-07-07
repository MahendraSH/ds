// Right-in threaded BST(Iteratively) & its iterative
// in-order traversal.(Implementation 1)

#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

struct nodetype {

	int info;
	struct nodetype *left, *right;
	int rthread;  // TRUE if right pointer is NULL or
                        // pointing to in-order successor.
                        // FALSE if there is a right subtree.
};

typedef struct nodetype * NODEPTR;


void intrav(NODEPTR tree);
NODEPTR maketree(int x);
void setleft(NODEPTR tree, int x);
void setright(NODEPTR tree, int x);


void intrav(NODEPTR tree)
{
	NODEPTR p, q;
	// Set p to the root and go as far
	// down to the left as possible
	p = tree;

	do {
		q = NULL;
		while (p != NULL) {
			q = p;
			p = p -> left;
		}

		if (q != NULL)
		{
			printf("%d ", q -> info);
			p = q -> right;

			while (q->rthread && p != NULL) {
				printf("%d ", p -> info);
				q = p;
				p = p -> right;
			}
		} // end if

	} while (q != NULL);
}



NODEPTR maketree(int x)
{
    NODEPTR p;
    p = (NODEPTR )malloc(sizeof(struct nodetype));
    p -> info = x;
    p -> left = p-> right = NULL;
    p-> rthread = TRUE;
    return(p);
}

void setleft(NODEPTR p, int x)
{
	NODEPTR q;
	if (p == NULL)
		printf("Void insertion\n");
	else if (p -> left != NULL)
		printf("Invalid insertion\n");
	else
	{
		q = maketree(x);
		p -> left = q;
		q -> right = p;
		q -> rthread = TRUE;
	}
}


void setright(NODEPTR p, int x)
{
	NODEPTR q, r;
	if (p == NULL)
		printf("Void insertion\n");
	else if (p -> rthread == FALSE)
		printf("Invalid insertion\n");
	else{
		q = maketree(x);
		r = p -> right;
		p -> right = q;
		p -> rthread = FALSE;
		q -> right = r;
		q -> rthread = TRUE;
		}
}


/*
 *    				 10
 *  			   = -  =
 * 				  = -    =
 * 				5        15
 *  		   = -      = - =
 * 			  = -      = -   =
 * 			 4-      13      18
 *
 */


int main(){

	NODEPTR ptree;
	NODEPTR p, q;
	int number;
	int i = 0;

	int array[] = {10,5,15,13,4,18};
	int count = sizeof(array)/sizeof(array[0]);

	printf("Size = %d\n", count);

	 while (i<count){
	  // Taking out number from array to inset into tree
	  number = array[i];
	  if(i == 0)
	  {
		// Creating the root first time.
		ptree = maketree(number);
		i++;
		continue;
	  }

	  p = q = ptree;
	  while (q != NULL ){
		   p = q;
		   if (number < p->info)
				q = p->left;
		   else
			{
			if(q->rthread == FALSE)
				q = p->right;
			else break;
			}
	  }

	  if (number < p->info)
		setleft(p, number);
	  else
		setright(p, number);

	  i++;

	 } //end of while

	 // Traversals
	 printf("Inorder Traversal:\n");
	 intrav(ptree);
	 printf("\n");

	 return 0;
}



