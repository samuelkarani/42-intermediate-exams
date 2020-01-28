#include <unistd.h>
#include <stdlib.h>

void pr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int len(char *s)
{
	int i = 0;
	while (*s++)
		i++;
	return i;
}

char *zero(int n)
{
	char *res = malloc(n + 1);
	for (int i = 0; i < n; i++)
		res[i] = '0';
	res[n] = 0;
	return res;
}

char *bigger(char *a, char *b)
{
	int alen = len(a), blen = len(b);
	if (alen > blen)
		return a;
	if (blen > alen)
		return b;
	return *a > *b ? a : b;
}

char *move(char *s)
{
	while (*s == '0')
		s++;
	if (!*s)
		return s - 1;
	return s;
}

char *cp(char *s, int n, int m)
{
	char *res = zero(m);
	int idx = m - 1;
	for (int i = n - 1; i >= 0; i--)
		res[idx--] = s[i];
	return res;
}

char *add(char *a, char *b)
{
	int alen = len(a), blen = len(b);
	int m = alen > blen ? alen : blen;
	char *res = zero(m + 1);
	if (alen < m)
		a = cp(a, alen, m);
	if (blen < m)
		b = cp(b, blen, m);
	for (int i = m - 1; i >= 0; i--)
	{
		int av = a[i] - '0', bv = b[i] - '0', cv = res[i + 1] - '0';
		int n = av + bv + cv;
		res[i] = (n / 10) + '0';
		res[i + 1] = (n % 10) + '0';
	}
	return move(res);
}

char *sub(char *a, char *b)
{
	int alen = len(a), blen = len(b), br = 0;
	int m = alen > blen ? alen : blen;
	char *res = zero(m);
	if (blen < m)
		b = cp(b, blen, m);
	for (int i = m - 1; i >= 0; i--)
	{
		if (br)
		{
			if (a[i] == '0')
			{
				br = 1;
				a[i] = '9';
			}
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
	return move(res);
}

int streq(char *a, char *b)
{
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}
	return *a - *b == 0;
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		char *a = av[1];
		char *b = av[2];
		int aneg = a[0] == '-';
		int bneg = b[0] == '-';
		if (!aneg && !bneg)
		{
			pr(add(a, b));
		}
		else if (aneg && bneg)
		{
			char *s = add(a + 1, b + 1);
			if (!streq(s, "0"))
				pr("-");
			pr(s);
		}
		else
		{
			if (aneg)
				a++;
			if (bneg)
				b++;
			char *y = bigger(a, b);
			char *z = y == a ? b : a;
			char *s = sub(y, z);
			if (((y == a && aneg) || (y == b && bneg)) && !streq(s, "0"))
				pr("-");
			pr(s);
		}
	}
	pr("\n");
}
