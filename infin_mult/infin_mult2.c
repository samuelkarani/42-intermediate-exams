#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> // remove

struct s_elem
{
	int v;
	int c;
};

int fstrlen(char *s)
{
	int i = 0;
	while (*s++)
		i++;
	return i;
}

void fputstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void zero(char *s, int n)
{
	for (int i = 0; i < n; i++)
		s[i] = '0';
}

char *fcpy(char *src, int n)
{
	char *res, *dst;
	res = dst = malloc(n + 1);
	res[n] = 0;
	while (n--)
		*dst++ = *src++;
	return res;
}

int add(char *a, int alen, char *b, int blen)
{
	int s, c, i, j;
	i = alen - 1, j = blen - 1;
	c = 0;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0 && j >= 0)
		{
			int x = a[i--] - '0';
			int y = b[j--] - '0';
			s = x + y + c;
		}
		else if (i >= 0 || j >= 0)
		{
			int v = (i >= 0 ? a[i--] : b[j--]) - '0';
			s = v + c;
		}
		c = s >= 10 ? 1 : 0;
		a[i + 1] = (s % 10) + '0';
	}
	if (c)
	{
		printf("here\n");
		a[i] = c + '0';
		return i;
	}
	return i + 1;
}

void multiply(char a, char b, struct s_elem *e)
{
	int x = a - '0';
	int y = b - '0';
	int p = x * y + e->c;
	e->c = p / 10;
	e->v = p % 10;
}

char *mult(char *a, int alen, char *b, int blen)
{
	struct s_elem s;
	int n, idx;
	n = alen + blen;
	char res[n + 1], tmp[n + 1];
	res[n] = 0;
	zero(res, n);
	for (int i = blen - 1, k = 0; i >= 0; i--, k++)
	{
		s = (struct s_elem){0, 0};
		tmp[n] = 0;
		zero(tmp, n);
		int jdx = n - k;
		for (int j = alen - 1; j >= 0; j--)
		{
			multiply(a[j], b[i], &s);
			tmp[--jdx] = s.v + '0';
		}
		if (s.c)
			tmp[--jdx] = s.c + '0';
		idx = add(res, n, tmp, n);
	}
	printf("%d\n", idx);
	if (s.c)
		res[--idx] = s.c + '0';
	return fcpy(res, n);
}

int main(int ac, char **av)
{
	char *a = av[1];
	char *b = av[2];
	int aneg = *a == '-';
	int bneg = *b == '-';
	int pos = (aneg && bneg) || (!aneg && !bneg);
	if (aneg)
		a++;
	if (bneg)
		b++;
	char *res = mult(a, fstrlen(a), b, fstrlen(b));
	if (!pos)
		fputstr("-");
	fputstr(res);
}
