#include <stdlib.h>

int mx(int a, int b, int c)
{
	if (a > b)
		return a > c ? a : c;
	return b > c ? b : c;
}

int     gold_gain(int **mine, int n)
{
	int ret = 0;
	for (int j = n - 2; j >= 0; j--)
	{
		for (int i = 0; i < n; i++)
		{
			int a = 0, c = 0, b, m;
			if (i > 0)
				a = mine[i - 1][j + 1];
			if (i < n - 1)
				c = mine[i + 1][j + 1];
			b = mine[i][j + 1];
			m = mx(a, b, c);
			mine[i][j] += m;
			if (mine[i][j] > ret)
				ret = mine[i][j];
		}
	}
	return ret;
}

/*
#include <stdio.h>
#include <string.h>
int **cr(int n, int arr[n][n])
{
	int **res = malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
	{
		res[i] = malloc(sizeof(int) * n);
		memcpy(res[i], arr[i], n * sizeof(int));
	}
	return res;
}

int main()
{
	int n = 3;
	int arr1[3][3] = {
		{ 1, 0, 0 },
		{ 0, 3, 4 },
		{ 0, 0, 0 }
	};
	int **arr = cr(n, arr1);
	printf("%d\n", gold_gain(arr, n));

	int arr2[3][3] = {
		{ 1, 2, 3 },
		{ 3, 4, 8 },
		{ 9, 6, 7 }
	};
	arr = cr(n, arr2);
	printf("%d\n", gold_gain(arr, n));

	n = 4;
	int arr3[4][4] = {
		{ 1, 3, 1, 5 },
		{ 2, 2, 4, 1 },
		{ 5, 0, 2, 3 },
		{ 0, 6, 1, 2 }
	};
	arr = cr(n, arr3);
	printf("%d\n", gold_gain(arr, n));

	n = 2;
	int arr4[2][2] = {
		{3, 1},
		{2, 4}
	};
	arr = cr(n, arr4);
	printf("%d\n", gold_gain(arr, n));
}
*/
