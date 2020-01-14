#include <stdio.h>

int is_alpha(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 32;
	return c;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int m[127] = {0};
		char *s = av[1];
		int count = 0;
		for (int i = 0; s[i]; i++)
		{
			unsigned char c = lower(s[i]);
			if (is_alpha(c) && !m[c])
			{
				int n = 0;
				for (int j = i; s[j]; j++)
					if (lower(s[j]) == c)
						n++;
				if (count)
					printf(", ");
				printf("%d%c", n, c);
				m[c] = 1;
				count++;
			}
		}
	}
	printf("\n");
}
