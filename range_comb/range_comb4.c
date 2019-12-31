#include <stdlib.h>
#include <string.h>

void rest(int *nrst, int *rst, int k, int n)
{
	int a = 0;
	for (int i = 0; i < n; i++)
		if (i != k)
			nrst[a++] = rst[i];
}

int helper(int *arr, int *rst, int d, int n, int idx, int **ret)
{
	if (d == n)
	{
		memcpy(ret[idx], arr, n * sizeof(int));
		return idx + 1;
	}
	int nrst[n - d - 1];
	for (int i = 0; i < n - d; i++)
	{
		arr[d] = rst[i];
		rest(nrst, rst, i, n);
		idx = helper(arr, nrst, d + 1, n, idx, ret);
	}
	return idx;
}

int factorial(int n)
{
	int p = 1;
	for (int i = 2; i <= n; i++)
		p *= i;
	return p;
}

int    **range_comb(int n)
{
	if (n <= 0)
		return NULL;
	int f = factorial(n);
	int **ret = malloc(sizeof(int *) * (f + 1));
	ret[f] = NULL;
	for (int i = 0 ; i < f; i++)
		ret[i] = malloc(sizeof(int) * n);
	int rst[n];
	for (int i = 0; i < n; i++)
		rst[i] = i;
	int arr[n];
	helper(arr, rst, 0, n, 0, ret);
	return ret;
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

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int n = atoi(av[1]);
		print(range_comb(n), n);
	}
}*/
