int     find_pivot(int *arr, int n)
{
	int i, j, asum, bsum;
	i = 0;
  	j = n - 1;
	asum = arr[i++], bsum = arr[j--];
	while (i < j)
	{
		while (arr[i] == 0)
			i++;
		while (arr[j] == 0)
			j--;
		if (bsum < asum)
			bsum += arr[j--];
		else if (asum < bsum)
			asum += arr[i++];
		if (asum == bsum)
		{
			if (i == j)
				return i;
			asum += arr[i++];
			bsum += arr[j--];
		}
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
