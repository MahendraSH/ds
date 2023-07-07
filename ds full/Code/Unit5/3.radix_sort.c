#include <stdio.h>

int largest(int arr[], int n);
void radix_sort(int arr[], int n);
int main()
{
    int arr[10], i, n;

    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\n Enter the elements of the array ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    radix_sort(arr, n);
    printf("\n The sorted array is : \n");
    for(i=0;i<n;i++)
    printf("%d\t", arr[i]);
    return 0;
}

int largest(int arr[], int n)
{
    int large=arr[0], i;
    for(i=1;i<n;i++)
    {
        if(arr[i]>large)
            large = arr[i];
    }
    return large;
}

void radix_sort(int arr[], int n)
{
    int bucket[10][15], bucket_count[10];
    int i, j, k, remainder, NOP=0, large, pass;
    large = largest(arr, n);
    int divisor=1; // To pick 1's position digits initially

    // Count the number of digit in largest numbers.
    // This is the total number of passes to perform.
    while(large>0)
    {
        NOP++;
        large/=10;
    }

    for(pass=0;pass<NOP;pass++) // Initialize the buckets
    {
        // Initialize all buckets count to 0 for current PASS
        for(i=0;i<10;i++)
            bucket_count[i]=0;

        // Taking each element and adding to corresponding bucket
        for(i=0;i<n;i++)
        {
            // Pick each number and put in to corresponding bucket
            remainder = (arr[i]/divisor)%10;
            bucket[remainder][bucket_count[remainder]] = arr[i];
            bucket_count[remainder] += 1;
        }
        // collect the numbers from all buckets
        // after the current pass to form the array for next pass
        i=0;
        for(k=0;k<10;k++)
        {
            for(j=0;j<bucket_count[k];j++)
            {
                arr[i] = bucket[k][j];
                i++;
            }
        }
        // divisor to pick next digit position from right to left
        divisor *= 10;
    }
}
