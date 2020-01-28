#include <stdlib.h>
#include <unistd.h>

void strpr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int streq(char *a, char *b)
{
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}
	return *a == *b;
}

void pr(char *num, int neg)
{
	while (*num == '0')
		num++;
	if (!*num)
		num--;
	if (neg && !streq(num, "0"))
		strpr("-");
	strpr(num);	
}

int fstrlen(char *s)
{
	int i = 0;
	while (*s++)
		i++;
	return i;
}

int bigger(char *a, int alen, char *b, int blen)
{
	if (alen > blen)
		return 0;
	if (blen > alen)
		return 1;
	return *a > *b ? 0 : 1;
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
		int av = a[i] - '0', bv = b[i] - '0';
		if (br)
		{
			if (a[i] == '0')
				av = 9;
			else
			{
				av -= 1;
				br = 0;
			}
		}
		if (bv > av)
		{
			av += 10;
			br = 1;
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
		int aneg = *a == '-', bneg = *b == '-';
		a += aneg; b += bneg;
		int alen = fstrlen(a), blen = fstrlen(b);
		if (!aneg && !bneg)
			pr(add(a, alen, b, blen), 0);
		else if (aneg && bneg)
			pr(add(a, alen, b, blen), 1);
		else {
			int i = bigger(a, alen, b, blen);
			if (i == 0)
				pr(sub(a, alen, b, blen), aneg);
			else
				pr(sub(b, blen, a, alen), bneg);
		}
	}
	strpr("\n");
}
