int     find_pivot(int *arr, int n)
{
	int i, j, suma, sumb;
	i = suma = 0;
	while (i < n)
	{
		suma += arr[i];
		i++;
	}
	i = n - 1;
	sumb = 0;
	while (i >= 0)
	{
		if (suma - arr[i] == sumb)
			return i;
		sumb += arr[i];
		suma -= arr[i];
		i--;
	}
	return -1;
}

#include <stdio.h>
int main()
{
	printf("%d\n", find_pivot((int[]){1, 2, 3, 4, 0, 6}, 6));
	printf("%d\n", find_pivot((int[]){-5, 10, 2, 5}, 4));
	printf("%d\n", find_pivot((int[]){1, 100, 0, 0, 1}, 5));
	printf("%d\n", find_pivot((int[]){7, 9, 8}, 3));
	printf("%d\n", find_pivot((int[]){1 , 2}, 2));
	printf("%d\n", find_pivot((int[]){1 , 0}, 2));
	printf("%d\n", find_pivot((int[]){0, 1}, 2));
}
