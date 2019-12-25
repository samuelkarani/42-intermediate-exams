#include <unistd.h>
#include <stdlib.h>

int fstrlen(char *s)
{
	int i;
	for (i = 0; s[i]; i++)
		s++;
	return i;
}

void fpr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

char *fstrsub(char *src, int n)
{
	char *dst = malloc(n + 1);
	int i;
	for (i = 0; i < n; i++)
		dst[i] = src[i];
	dst[i] = 0;
	return dst;
}

#include <stdio.h>
int main(int ac, char **av)
{
	if (ac >= 2)
	{
		int n, mx;
		char *s = av[1], *p;
		int mn = fstrlen(s);
		for (int i = 2; i < ac; i++)
		{
			mx = 0;
			for (int j = 0; s[j]; j++)
			{
				for (char *r = av[i]; *r; r++)
				{
					n = 0;
					char *rs = r;
					char *sp = s + j;
					while (*sp && *r && *r == *sp)
					{
						sp++;
						r++;
						n++;
					}
					if (n > mx)
						p = fstrsub(rs, n);
					else
						r = rs;
				}
			}
			if (mx < mn)
			{
				mn = mx;
				s = p;
				printf("%s %d\n", s, mn);
			}
		}
		fpr(s);
	}
	fpr("\n");
}
