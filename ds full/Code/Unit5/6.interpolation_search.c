
#include <stdio.h>
#define MAX 20

int interpolation_search(int a[], int low, int high, int key)
{
int mid;
while(low <= high)
{
    //mid = (low+high)/2;  // Binary search
    mid = low + (high - low)*((key - a[low]) / (a[high] - a[low])); // Interpolation search
    printf("%d\n", mid);

    if(key == a[mid])
    {
         return mid;
    }
    if(key < a[mid])

        high = mid - 1;
    else
        low = mid + 1;
}
return -1;
}

int main()
{
    int arr[MAX], i, n, val, pos;
    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\n Enter the elements : ");
    for(i = 0; i <n; i++)
    scanf("%d", &arr[i]);
    printf("\n Enter the value to be searched : ");
    scanf("%d", &val);
    pos = interpolation_search(arr, 0, n-1, val);
    if(pos == -1)
        printf("\n %d is not found in the array", val);
    else
        printf("\n %d is found at position %d", val, pos);
    return 0;
}
