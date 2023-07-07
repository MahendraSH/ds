#include <stdio.h>

// C recursive function to solve tower of hanoi puzzle
void ToH(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\n Move top disc from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    ToH(n-1, from_rod, aux_rod, to_rod);
    ToH(1, from_rod, to_rod, aux_rod);
    ToH(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
	int n = 4; // Number of disks
	// S- SOurce, D - Destination and X - Auxiliary.
	ToH(3, 'S', 'D', 'X');
	return 0;
}
