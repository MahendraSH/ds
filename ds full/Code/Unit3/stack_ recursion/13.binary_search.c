// Recursion : Binary Search
#include <stdio.h>

int binsearch_1(int [], int, int, int);  // Iterative Solution
int binsearch_2(int a[], int lo, int hi, int x);  // Recursive Solution 1
int binsearch_3(int a[], int lo, int hi, int x);  // Recursive Solution 2



int main()
{
    int x, size, i,pos = -1;
    int a[25];

    printf("Enter size of array a: ");
    scanf("%d", &size);
    printf("Enter the numbers in sorted order:\n");
    for(i = 0; i < size; i++)
    {
		scanf("%d", &a[i]);
    }
    printf("\n\n");
    printf("Enter x to search\n");
    scanf("%d", &x);


    pos = binsearch_1(a, 0, size-1, x);
    if(pos == -1)
		printf("Element  not found\n");
	else
		printf("Element  found at index %d\n",pos);

    pos = binsearch_2(a, 0, size-1, x);
    if(pos == -1)
		printf("Element  not found\n");
	else
		printf("Element  found at index %d\n",pos);


    pos = binsearch_3(a, 0, size-1, x);
    if(pos == -1)
		printf("Element  not found\n");
	else
		printf("Element  found at index %d\n",pos);


	return 0;
}



// Iterative implementation

int binsearch_1(int a[], int lo, int hi, int x)
{
    int mid,pos =-1;

    while (lo <= hi)
    {
		mid = (lo + hi) / 2;
		if (a[mid] == x)
		{
			pos =  mid;
			break;
		}
		else if (a[mid] > x)
		{
			hi = mid -1;
		}
		else if (a[mid] < x)
		{
			lo = mid +1;
		}

	}
    return pos;
}



// Recursive implementation : Elaborative way
int binsearch_2(int a[], int lo, int hi, int x)
{
    int mid,pos;

    if (lo > hi)
    {
		pos = -1;
        return pos;
    }
    mid = (lo + hi) / 2;
    if (a[mid] == x)
    {
        pos =  mid;
    }
    else if (a[mid] > x)
    {
        pos =  binsearch_2(a, lo, mid - 1, x);
    }
    else if (a[mid] < x)
    {
        pos =  binsearch_2(a, mid + 1, hi, x);
    }

    return pos;
}



// Recursive implementation : Simplified way
int binsearch_3(int a[], int lo, int hi, int x)
{
    int mid;

    if (lo > hi)
    {
        return -1;
    }
    mid = (lo + hi) / 2;
    return (a[mid] == x?  mid : a[mid] > x? binsearch_3(a, lo, mid - 1, x)
							:  binsearch_3(a, mid + 1, hi, x));

}



