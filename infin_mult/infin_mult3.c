#include <unistd.h>
#include <stdlib.h>

int len(char *s)
{
	int i = 0;
	while (*s++)
		i++;
	return i;
}

void pr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

char *zero(int n)
{
	char *s = malloc(n + 1);
	for (int i = 0; i < n; i++)
		s[i] = '0';
	s[n] = 0;
	return s;
}

void add(char *a, char *b, int n)
{
	int c = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int s = (a[i] - '0') + (b[i] - '0') + c;
		c = s / 10;
		a[i] = (s % 10) + '0';
	}
}

void multiply(char *a, int al, char *b, int bl, char *res)
{
	int l = al + bl;
	for (int i = bl - 1, k = 0; i >= 0; i--, k++)
	{
		char *buf = zero(l);
		int idx = l - k, c = 0;
		for (int j = al - 1; j >= 0; j--)
		{
			int p = (a[j] - '0') * (b[i] - '0') + c;
			c = p / 10;
			buf[--idx] = (p % 10) + '0';
		}
		if (c)
			buf[--idx] = c + '0';
		add(res, buf, l);
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		char *a = av[1], *b = av[2];
		int an = a[0] == '-', bn = b[0] == '-';
		int al = len(a), bl = len(b);
		char *res = zero(al + bl - an - bn);
		multiply(a + an, al - an, b + bn, bl - bn, res);
		while (*res == '0')
			res++;
		if (!*res)
			pr("0");
		else if ((an && bn) || (!an && !bn))
			pr(res);
		else
		{
			pr("-");
			pr(res);
		}
	}
	pr("\n");
}
