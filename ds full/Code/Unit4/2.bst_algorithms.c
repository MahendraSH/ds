//Binary search tree(BST) creation & Algorithms
#include<stdlib.h>
#define COUNT 10 // For Tree graphical display

struct node
{
	int key;
	struct node *left;
	struct node *right;
};

// Typedef
typedef struct node*  NODEPTR;

// BST Traversals
void intrav(NODEPTR tree);
void pretrav(NODEPTR tree);
void posttrav(NODEPTR tree);

// Dynamically allocates memory for a tree node
NODEPTR getnode();

// Makes a tree with 1 node & given data
NODEPTR maketree(int x);

// Create a BST from predefined data elements
struct node* createBST();

// BST algorithms
struct node* search(struct node* root, int key);
struct node * minValueNode(struct node* node);
struct node * maxValueNode(struct node* node);
struct node* insert(struct node* tree, int key);
struct node* deleteNode(struct node* root, int key);

int Height(struct node* tree);
int TotalNodes(struct node* tree);
int TotalInternalNodes(struct node* tree);
int TotalLeafNodes(struct node* node);
void mirrorTree(struct node* tree);

//Util functions to display graphical representation of tree
void displayTree(struct node *root);
void print2DUtil(struct node *root, int space);

int main()
{
    NODEPTR bst_root = NULL;

    while(1)
    {
    printf("\nTree Operations\n");
    printf("===============\n");
    printf("1.Create BST    \t");
    printf("2.Insert Node\t\t");
    printf("3.Delete node\n");
    printf("4.Find Min Value\t");
    printf("5.Find Max Value\t");
    printf("6.Find Height\n");
    printf("7.Search\t\t");
    printf("8.Total Nodes\t\t");
    printf("9.Total Int.Nodes\n");
    printf("10.TotalLeafNodes\t");
    printf("11.Pre-order Traversal\t");
    printf("12.In-order Traversal\n");
    printf("13.Post-order Traversal\t");
    printf("14.Display Tree\t\t");
    printf("15.Mirror Tree\n\n");
    printf("0.Exit\n\n");


    int choice,num,elem;
    printf("Enter your choice : ");
    if(scanf("%d",&choice)<=0){
        printf("Enter only an Integer\n");
        exit(0);
    } else {
        switch(choice)
        {
        case 0:
            return 0; // Terminate program

        case 1:
                 bst_root = createBST();
                 displayTree(bst_root);
                 break;

        case 2:
                printf("Enter the number to insert : ");
                scanf("%d",&num);
                bst_root = insert(bst_root,num);
                displayTree(bst_root);
                break;

        case 3:
                printf("Enter the number to delete : ");
                scanf("%d",&num);
                bst_root = deleteNode(bst_root,num);
                displayTree(bst_root);
                // pretrav(bst_root);
                break;

        case 4:
                {
                   printf("Smallest element is %d\n",minValueNode(bst_root)->key);
                }
                break;

        case 5:
                {
                   printf("Largest element is %d\n",maxValueNode(bst_root)->key);
                }
                break;

        case 6:
                {
                   printf("Height of tree is %d\n",Height(bst_root));
                }
                break;
        case 7:
                {
                    int key;
                    printf("Enter key to search:");
                    scanf("%d",&key);
                    NODEPTR res = search(bst_root,key);
                    if(res!=NULL)
                    {
                        printf("Element found:%d\n", res->key);
                    }
                    else
                    {
                        printf("Element not found!");
                    }
                }
                break;
		case 8:
                {
                   printf("Total nodes in tree: %d\n",TotalNodes(bst_root));
                }
                break;

        case 9:
                {
                   printf("Total Internal nodes in tree: %d\n",TotalInternalNodes(bst_root));
                }
                break;
        case 10:
                {
                   printf("Total Leaf nodes in tree: %d\n",TotalLeafNodes(bst_root));
                }
                break;
        case 11:
                {
                   displayTree(bst_root);
                   printf("PREORDER:");
                   pretrav(bst_root);
                }
                break;
        case 12:
                {
                   displayTree(bst_root);
                   printf("INORDER:");
                   intrav(bst_root);
                }
                break;
        case 13:
                {
                   displayTree(bst_root);
                   printf("POSTORDER:");
                   posttrav(bst_root);
                }
                break;
        case 14:
                {
                   printf("\nTHE BST\n");
                   displayTree(bst_root);
                }
                break;
        case 15: // Mirror Tree
                {
                   displayTree(bst_root);
                   mirrorTree(bst_root);
                   displayTree(bst_root);
                }
                break;

        default:    printf("Invalid option\n");
        }
    }
    }
    return 0;
}

/* Given a binary tree, print its trees in in-order*/

void intrav(NODEPTR tree)
{
    if (tree != NULL)
	{
     intrav(tree->left);
     printf("%d ", tree->key);
     intrav(tree->right);
	}
}

/* Given a binary tree, print its trees in pre-order*/
void pretrav(NODEPTR tree)
{
     if (tree != NULL)
	{
     printf("%d ", tree->key);
     pretrav(tree->left);
     pretrav(tree->right);
	}
}

/* Given a binary tree, print its trees according to the
  "bottom-up" postorder traversal. */
void posttrav(NODEPTR tree)
{
     if (tree != NULL)
	{
		posttrav(tree->left);
		posttrav(tree->right);
		printf("%d ", tree->key);
	}
}

NODEPTR getnode()
{
	NODEPTR temp;
    temp=(NODEPTR )malloc(sizeof(struct node));
    return temp;
}

// Make a 1-node tree
NODEPTR maketree(int x){
	NODEPTR p = getnode();
	p->key = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

// C function to search a given key in a given BST
struct node* search(struct node* root, int key)
{
	// Base Cases: root is null or key is present at root
	if (root == NULL || root->key == key)
	return root;

	// Key is greater than root's key
	if ( key <  root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}


/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* sub_tree, int key)
{
    if (sub_tree == NULL)
        return maketree(key);

    if (key < sub_tree->key)
        sub_tree->left  = insert(sub_tree->left, key);
    else if (key > sub_tree->key)
        sub_tree->right = insert(sub_tree->right, key);
    return sub_tree;
}

/*
// Min value - iterative
struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    if(current == NULL)

    while (current && current->left != NULL)
        current = current->left;
    return current;
}
*/

/* Min value = recursive
Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched for BST. */
struct node * minValueNode(struct node* node)
{
    if(node == NULL || node->left == NULL)
        return node;
    else
        return minValueNode(node->left);
}


/*
// Max value node in tree - iterative
struct node * maxValueNode(struct node* node)
{
    struct node* current = node;

    // loop down to find the leftmost leaf
    while (current && current->right != NULL)
        current = current->right;

    return current;

};
*/

// Max value node - recursive
struct node * maxValueNode(struct node* node)
{
    if(node == NULL || node->right == NULL)
        return node;
    else
        return maxValueNode(node->right);

};



/*
Given a binary search tree and a key, this function deletes the key
   and returns the new root
   */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL)
    {
        printf("Key not found in tree!\n");
        return root;
    }
    else if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else // We found the node to delete
    {
        if(root->left!=NULL&& root->right !=NULL)  // Victim has two child nodes
        {
            // 2 Possibilities - 1 Min. of right subtree  2: Max of left subtree
            //#define IN_SUCCESSOR  // Pre-processor
            #ifdef IN_SUCCESSOR
                // replace current node with In-order successor
                //& delete in-order successor
                struct node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            #else
                // replace current node with In-order predecessor
                // & delete inorder predecessor
                struct node* temp = maxValueNode(root->left);
                root->key = temp->key;
                root->left = deleteNode(root->left, temp->key);
            #endif
        }
        else if(root->left == NULL && root->right == NULL) // Victim is a leaf node
        {
            free(root);
            root = NULL;
        }
        else if(root->left == NULL) // Only right child there
        {
            struct node *temp = root;
            root = root->right;
            free(temp);
        }
        else // Only left child exists
        {
            struct node *temp = root;
            root = root->left;
            free(temp);
        }
    }

    return root;
}

int Height(struct node* tree)
{
   if (tree==NULL)
       return 0;
   else
   {

       int lDepth = Height(tree->left);
       int rDepth = Height(tree->right);
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}

int TotalNodes(struct node* tree)
{
    if(tree == NULL)
        return 0;
    else
    {
        return TotalNodes(tree->left) + TotalNodes(tree->right)+1;
    }
}

int TotalInternalNodes(struct node* tree)
{
    if(tree == NULL)
        return 0;
    if(tree->left == NULL && tree->right == NULL)
        return 0;
    else
    {
        return 1+ TotalInternalNodes(tree->left) + TotalInternalNodes(tree->right);
    }
}

int TotalLeafNodes(struct node* node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    else
        return TotalLeafNodes(node->left) +
                            TotalLeafNodes(node->right);
}


// Function to print binary tree in 2D
// It does reverse in-order traversal
void print2DUtil(struct node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
    // Increase distance between levels
    space += COUNT;

    // Process right child first
    if(root->right)
        print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n",root->key);

    // Process left child
    if(root->left)
        print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void displayTree(struct node *root)
{
    // Pass initial space count as 0
    if(root)
        print2DUtil(root, 0);
    else
    {
        printf("Empty Tree!!");
    }
}

struct node* createBST()
{
    NODEPTR root = NULL;
	int key;
	int i;
	//int array[] = {10,5,15,3,4,18,13,7,4,2,8};
	int array[] = {10,5,15,3,4};
	int count = sizeof(array)/sizeof(array[0]);

	printf("Size = %d\n", count);

    i = 0;
    // Constructing a Binary Search Tree
    while (i<count)
    {
        // Taking out element from array to insert into tree
        key = array[i];
        root = insert(root, key);
        i++;
    } //end of while
    return root;
}


void mirrorTree(struct node* tree)
{
  if (tree == NULL)
    return;
  else
  {
    struct node* temp;
    mirrorTree(tree->left);
    mirrorTree(tree->right);

    /* swap the pointers in this node */
    temp        = tree->left;
    tree->left  = tree->right;
    tree->right = temp;
  }
}
