        int     find_pivot(int *arr, int n)
{
	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
		a += arr[i];
	for (int i = n - 1; i >= 0; i--)
	{
		if (a - arr[i] == b)
			return i;
		b += arr[i];
		a -= arr[i];
	}
	return -1;
}

/*
#include <stdio.h>
int main()
{
	printf("%d\n", find_pivot((int[]){1, 2, 3, 4, 0, 6}, 6));
	printf("%d\n", find_pivot((int[]){-5, 10, 2, 5}, 4));
	printf("%d\n", find_pivot((int[]){1, 100, 0, 0, 1}, 5));
	printf("%d\n", find_pivot((int[]){7, 9, 8}, 3));
	printf("%d\n", find_pivot((int[]){1 , 2}, 2));
}
*/
