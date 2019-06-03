#include <stdlib.h>

int *create(int n)
{
	int *ret = malloc(n * sizeof(int));
	int i = 0;
	while (i < n)
	{
		ret[i] = i;
		i++;
	}
	return ret;
}

int factorial(int n)
{
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

int *rest(int *rst, int rlen, int j)
{
	if (rlen - 1 == 0)
		return NULL;
	int *ret = malloc((rlen - 1) * sizeof(int));
	int i, idx;
	i = idx = 0;
	while (i < rlen)
	{
		if (i != j)
			ret[idx++] = rst[i];
		i++;
	}
	return ret;
}

int *join(int *a, int alen, int *b, int blen)
{
	int *ret = malloc((alen + blen) * sizeof(int));
	int i, j;
	i = 0;
	while (i < alen)
	{
		ret[i] = a[i];
		i++;
	}
	j = 0;
	while (j < blen)
		ret[i++] = b[j++];
	return ret;
}

int idx;
void range(int **ret, int *cur, int c, int *rst, int r)
{
	if (!r)
	{
		ret[idx++] = cur;
		return ;
	}
	int i = 0;
	while (i < r)
	{
		int *ncur = join(cur, c, rst + i, 1);
		int *nrst = rest(rst, r, i);
		range(ret, ncur, c + 1, nrst, r - 1);
		i++;
	}
	free(cur);
	free(rst);
}

int    **range_comb(int n)
{
	if (n <= 0)
		return NULL;
	int **ret = malloc((factorial(n) + 1) * sizeof(int *));
	int *rst = create(n);
	idx = 0;
	range(ret, NULL, 0, rst, n);
	ret[idx] = NULL;
	return ret;
}

#include <stdio.h>
void parr(int *arr, int width)
{
	int j = 0;
	while (j < width)
	{
		printf("%d ", arr[j]);
		j++;
	}
}

void print(int **arr, int len, int width)
{
	int i;
	i = 0;
	while (i < len)
	{
		parr(arr[i++], width);
		printf("\n");
	}
}

void free_all(int **arr, int len)
{
	while (--len >= 0)
		free(arr[len]);
	free(arr);
}

// no leaks!
int main(void)
{
	int **ret, n;
	n = 2;
	ret = range_comb(n);
	print(ret, idx, n);
	free_all(ret, idx);
	printf("\n");
	n = 3;
	ret = range_comb(n);
	print(ret, idx, n);
	free_all(ret, idx);
	printf("\n");
	n = 5;
	ret = range_comb(n);
	print(ret, idx, n);
	free_all(ret, idx);
}
