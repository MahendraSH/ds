#include <stdio.h>
#include <math.h>

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       for (j = i-1; j >= 0 && arr[j] > key; j--)
       {
           arr[j+1] = arr[j];
       }
       arr[j+1] = key;
   }
}


// A utility function to print an array of size n
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

/* Driver program to test insertion sort */
int main()
{
    int arr[] = {12, 11, 13, 5, 6,17};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array before sorting:");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("\nArray after sorting :");
    printArray(arr, n);

    return 0;
}
