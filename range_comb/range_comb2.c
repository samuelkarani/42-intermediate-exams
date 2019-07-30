#include <stdlib.h>
#include <string.h>

#include <stdio.h>
void print(int **arr, int n);
void parr(int *arr, int n);

int factorial(int n)
{
	int res = 1;
	while (n > 1)
		res *= n--;
	return res;
}

void get_rest(int *arr, int n, int i, int *res)
{
	int k = 0;
	for (int j = 0; j < n; j++)
		if (j != i)
			res[k++] = arr[j];
}

int helper(int *cur, int j, int *rst, int n, int idx, int **res)
{
	if (j == n)
	{
		memcpy(res[idx], cur, sizeof(int) * j);
		return idx + 1;
	}
	int nrst[n - 1];
	for (int i = 0; i < n - j; i++)
	{
		cur[j] = rst[i];
		get_rest(rst, n, i, nrst);
		idx = helper(cur, j + 1, nrst, n, idx, res);
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

void print(int **arr, int n)
{
	if (!arr)
		return ;
	for (; *arr; arr++)
	{
		for (int i = 0; i < n; i++)
			printf("%d ", (*arr)[i]);
		printf("\n");
	}
}

void parr(int *arr, int n)
{
	int j = -1;
	while (++j < n)
		printf("%d ", arr[j]);
	printf("\n");
}

int main()
{
	print(range_comb(1), 1);printf("\n");
	print(range_comb(2), 2);printf("\n");
	print(range_comb(3), 3);printf("\n");
	print(range_comb(4), 4);
}
