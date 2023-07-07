// Tree sort
// Create a ordered BST. Do Inorder traversal
#include<stdio.h>

struct node
{
	int key;
	struct node *left;
	struct node *right;
};

void intrav(struct node *tree)
{
    if (tree != NULL)
	{
     intrav(tree->left);
     printf("%d ", tree->key);
     intrav(tree->right);
	}
	return;
}


/* A utility function to insert a new node with given value in BST */
// Repeat values allowed in the tree
struct node* insert(struct node* sub_tree, int x)
{
    if (sub_tree == NULL)
    {
        struct node* temp = (struct node* )malloc(sizeof(struct node));
        temp->key = x;
        temp->left = temp->right = NULL;
        return temp;
    }
    else if (x < sub_tree->key)
        sub_tree->left  = insert(sub_tree->left, x);
    else
        sub_tree->right = insert(sub_tree->right, x);
    return sub_tree;
}

int main()
{
    int arr[20], i, n;
    struct node* tree = NULL;
    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\n Enter the elements : ");
    for(i = 0; i <n; i++)
    {
        scanf("%d", &arr[i]);
        tree = insert(tree,arr[i]);
    }

    // Inorder traversal to get ascending order
    intrav(tree);
    return 0;
}
