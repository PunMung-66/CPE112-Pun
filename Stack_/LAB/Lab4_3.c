// Punnawat Mungakalarungsi 66070503436
#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod, int *count)
{
	if (n == 1)
	{
		printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        (*count)++;
		return;
	}
	towerOfHanoi(n-1, from_rod, aux_rod, to_rod, count);
	printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    (*count)++;
	towerOfHanoi(n-1, aux_rod, to_rod, from_rod, count);
}

int main()
{
	int n, *count;
    *count = 0;
    scanf("%d", &n);
	towerOfHanoi(n, 'A', 'C', 'B', count);
    printf("Total moves: %d", *count);
	return 0;
}
