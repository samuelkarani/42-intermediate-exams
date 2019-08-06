int     find_pivot(int *arr, int n)
{
	int i, bsum, asum = 0;
	for (i = 0; i < n; i++)
		asum += arr[i];
	bsum = 0;
	for (int j = i - 1; j >= 0; j--)
	{
		if (asum - arr[j] == bsum)
			return j;
		asum -= arr[j];
		bsum += arr[j];
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
