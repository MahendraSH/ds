#include  <stdio.h>

/* function to sort array using shellSort */
int shellSort(int x[], int n)
{
	int i,j,gap;
    // Start with a big gap(say n/2 for total n elems, then reduce the gap till 1
    for (gap = n/2; gap > 0; gap /= 2)
    {
        // gap is the size of the increment
        for (i = gap; i < n; i++)
        {
            // insert element x[j] into its proper position
            int temp = x[i];

            // shift earlier gap-sorted elements up until the correct
            for (j = i-gap; j >= 0 && temp < x[j]; j -= gap)
            {
                x[j+gap] = x[j];
            }
            //  put y (the original x[i]) in its correct location
            x[j+gap] = temp;
        }
    }
    return 0;
}


void printArray(int arr[], int n)
{
	int i;
    for (i=0; i<n; i++)
        printf("%d ",arr[i]);
}

int main()
{
    int arr[] = {12, 34, 54, 2, 3,3,6,7,2,1,23,45,87};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array before sorting:");
    printArray(arr, n);

    shellSort(arr, n);

    printf("\nArray after sorting :");
    printArray(arr, n);

    return 0;
}
