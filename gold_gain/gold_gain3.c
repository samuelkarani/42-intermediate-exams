#include <stdlib.h>

int helper(int **mine, int n, int i, int j, int **cache);

int checker(int **mine, int n, int i, int j, int **cache)
{
	if (cache[i][j] == -1)
		return helper(mine, n, i, j, cache);
	return cache[i][j];
}

int mx(int a, int b, int c)
{
	return a > b ? (a > c ? a : c ) : (b > c ? b : c);
}

int helper(int **mine, int n, int i, int j, int **cache)
{
	if (j == n - 1)
		return mine[i][j];
	int a, b, c, m, l;
	l = 0;
	while (i < n)
	{
		a = b = c = 0;
		if (i > 0)
			a = checker(mine, n, i - 1, j + 1, cache);
		b = checker(mine, n, i, j + 1, cache);
		if (i < n - 1)
			c = checker(mine, n, i + 1, j + 1, cache);
		m = mx(a, b, c) + mine[i][j];
		cache[i][j] = m;
		if (m > l)
			l = m;
		i++;
	}
	if (j == 0)
		return l;
	return cache[i - 1][j];
}

int     gold_gain(int **mine, int n)
{
	int **cache, i, j;
	cache = malloc(sizeof(int *) * n);
	i = -1;
	while (++i < n)
	{
		cache[i] = malloc(sizeof(int) * n);
		j = -1;
		while (++j < n)
			cache[i][j] = -1;
	}
	return helper(mine, n, 0, 0, cache);
}


int **create(int n, int a[n][n])
{
	int **ret, i, j;
   	ret	= malloc(sizeof(int *) * n);
	i = -1;
	while (++i < n)
	{
		ret[i] = malloc(sizeof(int) * n);
		j = -1;
		while (++j < n)
			ret[i][j] = a[i][j];
	}
	return ret;
}
#include <stdio.h>
int main(void)
{
	int a[3][3] = {
		{ 1, 0, 0 },
		{ 0, 3, 4 },
		{ 0, 0, 0 }
	};
	printf("%d\n", gold_gain(create(3, a), 3));
	int b[3][3] = {
	{ 1, 2, 3 },
		{ 3, 4, 8 },
			{9, 6, 7 }
			};
	printf("%d\n", gold_gain(create(3, b), 3));
	int c[4][4] = {
	{ 1, 3, 1, 5 },
		{ 2, 2, 4, 1 },
			{ 5, 0, 2, 3 },
				{ 0, 6, 1, 2 }
				};
	printf("%d\n", gold_gain(create(4, c), 4));
}
