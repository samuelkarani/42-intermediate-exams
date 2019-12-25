#include <unistd.h>
#include <stdlib.h>

int fstrlen(char *s)
{
	int i = 0;
	while (*s++)
		i++;
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

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		char *s = av[1], *p;
		int mn = fstrlen(s);
		for (int i = 2; i < ac; i++)
		{
			int mx = 0;
			for (int j = 0; s[j]; j++)
			{
				for (char *r = av[i]; *r; r++)
				{
					int n = 0;
					char *_r = r;
					char *_s = s + j;
					while (*_s && *_r && *_r == *_s)
					{
						_s++;
						_r++;
						n++;
					}
					if (n > mx)
					{
						mx = n;
						p = fstrsub(r, n);
						r = _r - 1;
					}
				}
			}
			if (mx == 0)
			{
				s = "";
				break;
			}
			else if (mx < mn)
			{
				mn = mx;
				s = p;
			}
		}
		fpr(s);
	}
	fpr("\n");
}
