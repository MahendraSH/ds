// Heap Sort
#include <stdio.h>
#include <stdlib.h>

// Create a max-heap at given node if it's left & right sub-tree are max-heaps
void heapify(int arr[], int n, int i)
{
   // Find largest among root, left child and right child
   int largest = i;
   int left = 2*i + 1;  // Compute index  of left child of i(if any)
   int right = 2*i + 2; // Compute index  of right child of i(if any)

   // finding the largest among node,left child and right child
   if (left < n && arr[left] > arr[largest])
        largest = left;

   if (right < n && arr[right] > arr[largest])
        largest = right;

   // Swap and continue heapifying if one of the children is larger than root
   if (largest != i)
   {
	 // swap parent node value & larger child value
	 int temp = arr[i];
	 arr[i] = arr[largest];
	 arr[largest]  = temp;

	 // Continue to heapify affected subtree
     heapify(arr, n, largest);
   }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
   // Build max heap
    int i,j;

	/* Heapify applied from node n/2-1 to 0 to
	create a heap out of an array
	n/2-1 is index of first non-leaf node in
	bottom up order of almost complete tree. */
   for ( i = n/2-1; i >= 0; i--)
     heapify(arr, n, i);


   // Heap sort
   for (j=n-1; j>=0; j--)
   {

     int temp = arr[0];
	 arr[0] = arr[j] ;
	 arr[j]  = temp;
     // Heapify root element to get highest element at root again
     // i =  size of the array to do heapify
     // 0 = index of the root node where heapify to be applied.
     heapify(arr, j, 0);
   }
}

void printArray(int arr[], int n)
{  int i;
   for ( i=0; i<n; ++i)
		printf("%d ",arr[i] );
	printf("\n");
}

int main()
{
   int arr[] = {1,12,9,5,6,1,10};
   int n = sizeof(arr)/sizeof(arr[0]);

   printf("Array before sorting:");
   printArray(arr, n);

   heapSort(arr, n);

   printf("Sorted array is:");
   printArray(arr, n);
   return 0;
}
