#include <unistd.h>
#include <stdlib.h>

int fstrlen(char *s)
{
	int i = 0;
	while (*s++)
		i++;
	return i;
}

void strpr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void pr(char *s, int neg)
{
	while (*s && *s == '0')
		s++;
	if (!*s)
		s -= 1;
	int z = *s == '0' && !*(s + 1);
	if (neg && !z)
		strpr("-");
	strpr(s);
}

char *zero(int n)
{
	char *res = malloc(n + 1);
	for (int i = 0; i < n; i++)
		res[i] = '0';
	res[n] = 0;
	return res;
}

char *strnew(char *s, int n)
{
	char *res = zero(n);
	int l = fstrlen(s);
	int idx = n - 1;
	for (int i = l - 1; i >= 0; i--)
		res[idx--] = s[i];
	return res;
}

int bigger(char *a, int alen, char *b, int blen)
{
	if (alen > blen)
		return 1;
	if (blen > alen)
		return 0;
	return *a > *b;
}

char *add(char *a, int alen, char *b, int blen)
{
	int mx = alen > blen ? alen : blen;
	a = strnew(a, mx);
	b = strnew(b, mx);
	char *res = zero(mx + 1);

	for (int i = mx - 1; i >= 0; i--)
	{
		int v = (a[i] - '0') + (b[i] - '0') + (res[i + 1] - '0');
		res[i + 1] = v % 10 + '0';
		res[i] = v / 10 + '0';
	}
	return res;
}

char *sub(char *a, int alen, char *b, int blen)
{
	int mx = alen > blen ? alen : blen;
	a = strnew(a, mx);
	b = strnew(b, mx);
	char *res = zero(mx);
	int br = 0;

	for (int i = mx - 1; i >= 0; i--)
	{
		if (br)
		{
			if (a[i] == '0')
				a[i] = '9';
			else
			{
				a[i] -= 1;
				br = 0;
			}
		}
		int av = a[i] - '0', bv = b[i] - '0';
		if (av < bv)
		{
			br = 1;
			av += 10;
		}
		res[i] = (av - bv) + '0';
	}
	return res;
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		char *a = av[1], *b = av[2];
		int an = *a == '-', bn = *b == '-';
		if (an)
			a++;
		if (bn)
			b++;
		int alen = fstrlen(a), blen = fstrlen(b);
		if (!an && !bn)
			pr(add(a, alen, b, blen), 0);
		else if (an && bn)
			pr(add(a, alen, b, blen), 1);
		else
		{
			if (bigger(a, alen, b, blen))
				pr(sub(a, alen, b, blen), an);
			else
				pr(sub(b, blen, a, alen), bn);
		}
	}
	strpr("\n");
}
