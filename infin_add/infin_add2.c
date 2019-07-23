#include <unistd.h>
#include <stdlib.h>

void fputstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int num(char c)
{
	return c - '0';
}

char chr(int n)
{
	return n + '0';
}

int fstrlen(char *s)
{
	int n = 0;
	while (*s++)
		n++;
	return n;
}

char *bigger(char *a, char *b, int aneg, int bneg)
{
	int al = fstrlen(a) - aneg, bl = fstrlen(b) - bneg;
	if (aneg == bneg)
		return a[aneg] > b[bneg] ? a : b;
	return al > bl ? a : b;
}

int fdigit(int c)
{
	return c >= '0' && c <= '9';
}

char  *zero(char *s)
{
	if (!s || !*s)
		return s;
	int neg = *s == '-';
	if (neg)
		s++;
	while (*(s + 1))
	{
		if (*s == '0' && fdigit(*(s + 1)))
			s++;
		else
			break ;
	}
	if (neg)
		*--s = '-';
	return s;
}

char *add(char *a, char *b, int neg)
{
	int i, j, idx, av, bv, carry, al, bl, sum;
	char c, *res;
	al = fstrlen(a);
	bl = fstrlen(b);
	idx = neg + 1 + (al > bl ? al : bl);
	res = malloc(idx + 1);
	res[idx] = 0;
	carry = 0;
	i = al - 1;
	j = bl - 1;
	while (i >= 0 || j >= 0)
	{
		av = i >= 0 ? num(a[i]) : 0;
		if (carry)
		{
			av += 1;
			carry = 0;
		}
		bv = j >= 0 ? num(b[j]) : 0;
		sum = av + bv;
		carry = sum / 10;
		c = chr(sum % 10);
		res[--idx] = c;
		i--;
		j--;
	}
	if (carry)
		res[--idx] = chr(1);
	if (neg)
		res[--idx] = '-';
	return zero(res + idx);
}

char *sub(char *a, char *b, int neg)
{
	int i, j, borrow, av, bv, idx,  al, bl;
	char c, *res;
	al = fstrlen(a);
	bl = fstrlen(b);
	idx = neg + (al > bl ? al : bl);
	res = malloc(idx + 1);
	res[idx] = 0;
	i = al - 1;
	j = bl - 1;
	borrow = 0;
	while (i >= 0 || j >= 0)
	{
		av = i >= 0 ? num(a[i]) : 0;
		if (borrow)
		{
			if (av == 0)
			{
				av = 9;
				borrow = 1;
			}
			else
			{
				av -= 1;
				borrow = 0;
			}
		}
		bv = j >= 0 ? num(b[j]) : 0;
		if (av < bv)
		{
			av = 10 + av;
			borrow = 1;
		}
		c = chr(av - bv);
		res[--idx] = c;
		i--;
		j--;
	}
	if (neg)
		res[--idx] = '-';
	return zero(res + idx);
}

int main(int ac, char **av)
{
	char *res;
	int aneg, bneg, neg;
	if (ac == 3)
	{
		char *big, *small;
		aneg = av[1][0] == '-';
	  	bneg = av[2][0] == '-';
		av[1] = zero(av[1]), av[2] = zero(av[2]);
		if (!aneg && !bneg)
			res = add(av[1], av[2], 0);
		else if (aneg && bneg)
			res = add(&av[1][1], &av[2][1], 1);
		else
		{
			big = bigger(av[1], av[2], aneg, bneg);
			small = big == av[1] ? av[2] : av[1];
			neg = *big == '-';
			if (*big == '-')
				big++;
			if (*small == '-')
				small++;
			res = sub(big, small, neg);
		}
		fputstr(res);
	}
	fputstr("\n");
}
