#include <stdlib.h>
#include <unistd.h>
// #include <stdio.h>

void fpn(int n)
{
	if (n >= 10)
		fpn(n / 10);
	char c = n % 10 + '0';
	write(1, &c, 1);
}

int fatoi(char **s)
{
	int n = 0;
	while (**s >= '0' && **s <= '9')
	{
		n *= 10;
		n += **s - '0';
		*s += 1;
	}
	return n;
}

int *clear(int *v, int n)
{
	for (int i = 0; i < n; i++)
		v[i] = 0;
	return v;
}

// void print_graph(int **g, int n)
// {
// 	for (int i = 0; i < n; i++)
// 	{
// 		for (int j = 0; j < n; j++)
// 			fpn(g[i][j] ? 1 : 0);
// 		write(1, "\n", 1);
// 	}
// }

int **create_graph(int n)
{
	int **g = malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
	{
		g[i] = malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++)
			g[i][j] = 0;
	}
	return g;
}

int dfs(int **g, int n, int *v, int r, int mx)
{
	v[r] = 1;
	int c, ret = mx;
	for (int i = 0; i < n; i++)
		if (g[r][i] && !v[i])
			if ((c = dfs(g, n, v, i, mx + 1)) > ret)
				ret = c;
	v[r] = 0;
	return ret;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *s = av[1];
		int a, b, n = 0;
		while (1)
		{
			a = fatoi(&s);
			s++;
			b = fatoi(&s);
			n = a > n ? (a > b ? a : b) : (b > n ? b : n);
			if (!*s)
				break;
			s++;
		}
		int **g = create_graph(n);
		s = av[1];
		while (1)
		{
			a = fatoi(&s);
			s++;
			b = fatoi(&s);
			g[a - 1][b - 1] = g[b - 1][a - 1] = 1;
			if (!*s)
				break;
			s++;
		}
		// print_graph(g, n);
		int *v = malloc(sizeof(int) * n);
		int mx = 0, c;
		for (int i = 0; i < n; i++)
			if ((c = dfs(g, n, clear(v, n), i, 1)) > mx)
				mx = c;
		fpn(mx);
	}
	write(1, "\n", 1);
}