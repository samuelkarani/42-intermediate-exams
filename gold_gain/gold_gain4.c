#include <stdlib.h>
int mx(int a, int b, int c)
{
	return a > b ? (a > c ? a : c ) : (b > c ? b : c);
}

int     gold_gain(int **mine, int n)
{
    int i, j, a, b, c, l;
    if (n < 2)
        return mine[0][0];
    l = 0;
    j = n - 2;
    while (j >= 0)
    {
        i = 0;
        while (i < n)
        {
            a = b = c = 0;
            if (i > 0)
                a = mine[i - 1][j + 1];
            b = mine[i][j + 1];
            if (i + 1 < n)
                c = mine[i + 1][j + 1];
            mine[i][j] += mx(a, b, c);
            if (mine[i][j] > l)
                l = mine[i][j];
            i++;
        }
        j--;
    }
    return l;
}

#include <stdio.h>
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
	{ 9, 6, 7 }
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
