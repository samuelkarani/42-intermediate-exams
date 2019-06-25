#include <stdlib.h>

int helper(int **mine, int n, int i, int j, int *cache[n]);

int mx(int a, int b, int c)
{
	return (a > b ? (a > c ? a : c) : (b > c ? b : c));
}

int mx_col(int *cache[], int n, int j)
{
	int mx = 0, i = 0;
	while (i < n)
	{
		if (cache[i][j] > mx)
			mx = cache[i][j];
		i++;
	}
	return mx;
}

int get(int **mine, int n, int i, int j, int *cache[])
{
	if (cache[i][j] != -1)
		return cache[i][j];
	return helper(mine, n, i, j, cache);
}

int helper(int **mine, int n, int i, int j, int *cache[n])
{
	if (j == n - 1)
		return mine[i][j];
	int a, b, c;
	while (i < n)
	{
		a = b = c = 0;
		if (i > 0)
			a = get(mine, n, i - 1, j + 1, cache);
		b = get(mine, n, i, j + 1, cache);
		if (i < n - 1)
			c = get(mine, n, i + 1, j + 1, cache);
		cache[i][j] = mine[i][j] + mx(a, b, c);
		i++;
	}
	if (j == 0)
		return mx_col(cache, n, j);
	return cache[i - 1][j];
}

int     gold_gain(int **mine, int n)
{
	int *cache[n];
	int i, j;
	i = -1;
	while (++i < n)
	{
		j = -1;
		cache[i] = malloc(sizeof(int) * n);
		while (++j < n)
			cache[i][j] = -1;
	}
	return helper(mine, n, 0, 0, cache);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	int n = 3;
	int **mine = malloc(n * sizeof(int *));
	mine[0] = memcpy(malloc(4 * n), (int[]){1, 0, 0}, 4 * n);
	mine[1] = memcpy(malloc(4 * n), (int[]){0, 3, 4}, 4 * n);
	mine[2] = memcpy(malloc(4 * n), (int[]){0, 0, 0}, 4 * n);
	printf("%d\n", gold_gain(mine, n));

	mine[0] = memcpy(malloc(4 * n), (int[]){1, 2, 3}, 4 * n);
	mine[1] = memcpy(malloc(4 * n), (int[]){3, 4, 8}, 4 * n);
	mine[2] = memcpy(malloc(4 * n), (int[]){9, 6, 7}, 4 * n);
	printf("%d\n", gold_gain(mine, n));

	n = 4;
	mine = malloc(n * sizeof(int *));
	mine[0] = memcpy(malloc(4 * n), (int[]){1, 3, 1, 5}, 4 * n);
	mine[1] = memcpy(malloc(4 * n), (int[]){2, 2, 4, 1}, 4 * n);
	mine[2] = memcpy(malloc(4 * n), (int[]){5, 0, 2, 3}, 4 * n);
	mine[3] = memcpy(malloc(4 * n), (int[]){0, 6, 1, 2}, 4 * n);
	printf("%d\n", gold_gain(mine, n));
}
*/
