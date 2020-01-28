#include <stdlib.h>
#include <string.h>

int factorial(int n)
{
	int res = 1;
	for (; n >= 2; n--)
		res *= n;
	return res;
}

void rest(int *rst, int i, int n, int *nrst)
{
	int idx = 0;
	for (int j = 0; j < n; j++)
		if (i != j)
			nrst[idx++] = rst[j];
}

int helper(int *rst, int *cur, int d, int idx, int n, int **res)
{
	if (d == n)
	{
		memcpy(res[idx], cur, n * sizeof(int));
		return idx + 1;
	}
	int nrst[n - 1];
	for (int i = 0; i < n - d; i++)
	{
		cur[d] = rst[i];
		rest(rst, i, n, nrst);
		idx = helper(nrst, cur, d + 1, idx, n, res);
	}
	return idx;
}

int    **range_comb(int n)
{
	if (n <= 0)
		return NULL;
	int f = factorial(n);
	int **res = malloc(sizeof(int *) * (f + 1));
	res[f] = NULL;
	for (int i = 0; i < f; i++)
		res[i] = malloc(sizeof(int) * n);
	int rst[n], cur[n];
	for (int i = 0; i < n; i++)
		rst[i] = i;
	helper(rst, cur, 0, 0, n, res);
	return res;
}
/*
#include <stdio.h>
void print(int **arr, int n)
{
	for (int i = 0; arr[i]; i++)
	{	
		for (int j = 0; j < n; j++)
			printf("%d ", arr[i][j]);	
		printf("\n");
	}
}

int main()
{
	int n = 1;
	print(range_comb(n), n);
	n = 2;
	print(range_comb(n), n);
	n = 3;
	print(range_comb(n), n);
	n = 4;
	print(range_comb(n), n);
}
*/
