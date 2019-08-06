#include <stdlib.h>
#include <string.h>

int factorial(int n)
{
	int res = n;
	while (--n > 0)
		res *= n;
	return res;
}

void rest(int *rst, int n, int i, int *res)
{
	int idx = 0;
	for (int j = 0; j < n; j++)
		if (j != i)
			res[idx++] = rst[j];
}

int helper(int *cur, int d, int *rst, int n, int idx, int **res)
{
	if (d == n)
	{
		memcpy(res[idx], cur, n * sizeof(int));
		return idx + 1;
	}
	int nrst[n - d - 1];
	for (int i = 0; i < n - d; i++)
	{
		rest(rst, n - d, i, nrst);
		cur[d] = rst[i];
		idx = helper(cur, d + 1, nrst, n, idx, res);
	}
	return idx;
}

int    **range_comb(int n)
{
	if (n <= 0)
		return NULL;
	int size = factorial(n);
	int **res = malloc((size + 1) * sizeof(int *));
	for (int i = 0; i < size; i++)
		res[i] = malloc(n * sizeof(int));
	res[size] = NULL;
	int cur[n], rst[n];
	for (int i = 0; i < n; i++)
		rst[i] = i;
	helper(cur, 0, rst, n, 0, res);
	return res;
}

/*
#include <stdio.h>
void print(int **a, int n)
{
	if (!a)
		return ;
	for (int i = 0; a[i]; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

int main()
{
	print(range_comb(0), 0);
	print(range_comb(1), 1);
	print(range_comb(2), 2);
	print(range_comb(3), 3);
	print(range_comb(4), 4);
	print(range_comb(5), 5);
}
*/
