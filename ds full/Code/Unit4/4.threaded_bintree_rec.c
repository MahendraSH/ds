// Right threaded binary node implementation 2(Recursive)
// Creates a right threaded BST(Recursive)
// and displays iterative in-order traversal
// without using a stack
#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

    struct node
    {
        int val;
        struct node *right;
        struct node *left;
        int rthread;
    };

typedef struct node* NODEPTR;

struct node *root = NULL;

struct node* insert_node(struct node *sub_tree, struct node *newnode, struct node *inorder_s)
{
    if(sub_tree == NULL)
    {
    sub_tree = newnode;
    if(inorder_s != NULL)
        {
            sub_tree->right = inorder_s;
            sub_tree->rthread = 1;
        }
    }
    else if(newnode->val < sub_tree->val)
        sub_tree->left = insert_node(sub_tree->left, newnode, sub_tree);
    else if(sub_tree->rthread == 1)
        {
        sub_tree->right = insert_node(NULL, newnode, inorder_s);
        sub_tree->rthread=0;
        }
    else
        sub_tree->right = insert_node(sub_tree->right, newnode, inorder_s);
    return sub_tree;
}


struct node* makenode(int x)
{
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    p -> val = x;
    p -> left = p-> right = NULL;
    p-> rthread = FALSE;
    return(p);
}


struct node* create_threaded_node()
{
    struct node *ptr = NULL;
    int num;
    printf("\n Enter the elements, press -1 to terminate ");
    scanf("%d", &num);
    while(num != -1)
    {
        ptr = makenode(num);
        root = insert_node(root, ptr, NULL);
        printf(" \n Enter the next element ");
        scanf("%d", &num);
    }
    return root;
}

void inorder(struct node *root)
{
struct node *ptr = root, *prev;

do
{
    while(ptr != NULL)
    {
        prev = ptr;
        ptr = ptr->left;
    }

    if(prev != NULL)
    {
        printf(" %d", prev->val);
        ptr = prev->right;
        while(prev != NULL && prev->rthread)
        {
        printf(" %d", ptr->val);
        prev = ptr;
        ptr = ptr->right;
        }
    }
}
while(ptr != NULL);
}


// Utility function to find leftmost node in a node rooted with n
struct node* leftmost(struct node *n)
{
    if (n == NULL)
       return NULL;

    while (n->left != NULL)
        n = n->left;
    return n;
}

// C code to do inorder traversal in a threaded binary node
void inOrder(struct node *root)
{
    struct node *cur = leftmost(root);
    while (cur != NULL)
    {
        printf("%d ", cur->val);

        // If this node is a thread node, then go to
        // inorder successor
        if (cur->rthread)
            cur = cur->right;
        else // Else go to the leftmost child in right subnode
            cur = leftmost(cur->right);
    }
}

void main()
{
    create_threaded_node();
    printf(" \n The in-order traversal of the node can be given as : ");
    if(root) // Not Empty node
        inOrder(root);
}
