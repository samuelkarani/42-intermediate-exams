#include <stdlib.h>

void print(int **a, int n);

void free_all(int **a, int n)
{
	int i = 0;
	while (i < n)
		free(a[i++]);
	free(a);
}

int max(int *a, int n)
{
	int max = a[0];
	int i = 1;
	while (i < n)
	{
		if (a[i] > max)
			max = a[i];
		i++;
	}
	return max;
}

int gold_gain_h(int **mine, int n, int i, int j, int **cache);

int	cache_or_r(int **mine, int n, int i, int j, int **cache)
{
	if (cache[i][j] == -1)
		return gold_gain_h(mine, n, i, j, cache);
	else
		return cache[i][j];
}

int gold_gain_h(int **mine, int n, int i, int j, int **cache)
{
	if (j == n - 1)
		return mine[i][j];
	int su, sc, sd, max_ret;
	su = sc = sd = max_ret = -1;
	while (i < n)
	{
		if (i > 0)
			su = mine[i][j] + cache_or_r(mine, n, i - 1, j + 1, cache);
		sc = mine[i][j] + cache_or_r(mine, n, i, j + 1, cache);
		if (i < n - 1)
			sd = mine[i][j] + cache_or_r(mine, n, i + 1, j + 1, cache);
		int maxn = max((int[]){su, sc, sd}, 3);
		cache[i][j] = maxn;
		if (maxn > max_ret)
			max_ret = maxn;
		i++;
	}
	return max_ret;
}

int N;
int	**create(int a[][N], int z)
{
	int **ret = malloc(N * sizeof(int *));
	int i = 0;
	while (i < N)
		ret[i++] = malloc(N * sizeof(int));
	i = 0;
	while (i < N)
	{
		int j = 0;
		while (j < N)
		{
			ret[i][j] = z == -1 ? -1 :a[i][j];
			j++;
		}
		i++;
	}
	return ret;
}

int gold_gain(int **mine, int n)
{
	int a[n][n];
	int **cache = create(a, -1);
	int ret = gold_gain_h(mine, n, 0, 0, cache);
	free_all(cache, n);
	return ret;
}

#include <stdio.h>
void	print(int **a, int n)
{
	int i = 0;
	while (i < n)
	{
		int j = 0;
		while (j < n)
		{
			printf("%2d ", a[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

int main(void)
{
	int **arr;
	int a[3][3] = {
		{1, 0, 0},
		{0, 3, 4},
		{0, 0, 0},
	};
	N = 3;
	printf("%d\n", gold_gain(arr = create(a, 1), N));
	free_all(arr, N);

	int b[3][3] = {
		{1, 2, 3},
		{3, 4, 8},
		{9, 6, 7},
	};
	N = 3;
	printf("%d\n", gold_gain(arr = create(b, 1), N));
	free_all(arr, N);

	int c[4][4] = {
		{ 1, 3, 1, 5 },
		{ 2, 2, 4, 1 },
		{ 5, 0, 2, 3 },
		{ 0, 6, 1, 2 }
	};
	N = 4;
	printf("%d\n", gold_gain(arr = create(c, 1), N));
	free_all(arr, N);
}
