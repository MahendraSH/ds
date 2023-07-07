// Application: Binary search tree(BST) creation  in iterative way & 3 traversals.
#include<stdio.h>
#include<stdlib.h>

struct nodetype{
	int info;
	struct nodetype *left;
	struct nodetype *right;
};


/* Given a binary tree, print its trees in inorder*/
void intrav(struct nodetype * tree);
void pretrav(struct nodetype * tree);
void posttrav(struct nodetype * tree);

struct nodetype * getnode();
struct nodetype * maketree(int x);

void setleft(struct nodetype * p, int x);
void setright(struct nodetype * p, int x);


int main(){
	struct nodetype * ptree = NULL ;
	struct nodetype * p, *q;
	int number;
	int i;

	int array[] = {10,5,15,10,3,4,18,13};
	int count = sizeof(array)/sizeof(array[0]);

	printf("Size = %d\n", count);

     // Constructing a Binary Search Tree iteratively by picking data
     // from above array
	 i = 0;
	 while (i<count)
        {
          // Taking out number from array to insert into tree
          number = array[i];
          if(i == 0)
          {
            // Creating the root first time.
            ptree = maketree(number);
            i++;
            continue;
          }
          p = q = ptree;
          while (q != NULL){
            p = q;
            if (number < p->info)
                q = p->left;
            else
                q = p->right;
          }
          if (number < p->info)
                setleft(p, number);
          else
                setright(p, number);
          i++;
	 } //end of while

	 // Traversals

	 printf("Inorder Traversal:");
	 intrav(ptree);
	 printf("\n");

	 printf("Pre-order Traversal:");
	 pretrav(ptree);
	 printf("\n");

	 printf("Post-order Traversal:");
	 posttrav(ptree);
	 printf("\n");

	 return 0;
}

/* Given a binary tree, print its trees in inorder*/
void intrav(struct nodetype * tree)
{
    if (tree != NULL)
	{
     intrav(tree->left);
     printf("%d ", tree->info);
     intrav(tree->right);
	}
}

/* Given a binary tree, print its trees in pre-order*/
void pretrav(struct nodetype * tree)
{
     if (tree != NULL)
	{
     printf("%d ", tree->info);
     pretrav(tree->left);
     pretrav(tree->right);
	}
}

/* Given a binary tree, print its trees according to the
  "bottom-up" postorder traversal. */
void posttrav(struct nodetype * tree)
{
     if (tree != NULL)
	{
		posttrav(tree->left);
		posttrav(tree->right);
		printf("%d ", tree->info);
	}
}

struct nodetype * getnode()
{
	struct nodetype * temp;
    temp=(struct nodetype * )malloc(sizeof(struct nodetype));
    return temp;
}

struct nodetype * maketree(int x){
	struct nodetype * p = getnode();
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void setleft(struct nodetype * p, int x){
	if (p == NULL)
		printf("void insertion\n");
	else if (p->left != NULL)
		printf("invalid insertion\n");
	else p->left = maketree(x);
}

void setright(struct nodetype * p, int x){
	if (p == NULL)
		printf("void insertion\n");
	else if (p->right != NULL)
		printf("invalid insertion\n");
	else p->right = maketree(x);
}

