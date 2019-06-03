#include <unistd.h>
#include <stdlib.h>

int fstrlen(char *s)
{
	int count = 0;
	while (*s++)
		count++;
	return (count);
}

void fputstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

char *fstrsub(char *s, int start, int end)
{
	char *ret = malloc((end - start + 1) + sizeof(char));
	int idx = 0;
	while (start < end)
		ret[idx++] = s[start++];
	ret[idx] = 0;
	return ret;
}

char *fstrdup(char *s)
{
	int l = fstrlen(s);
	char *ret = malloc(l + 1 * sizeof(char));
	int i = 0;
	while (i < l)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return ret;
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		char *tmp, *ret;
		ret = fstrdup(av[1]);
		int idx = 2;
		while (idx < ac)
		{
			char *s = av[idx];
			char *retn = NULL;
			int l = 0;
			int i = 0;
			while (ret[i])
			{
				int si = i;
				int j = 0;
				while (s[j])
				{
					int sj = j;
					while (ret[i] && s[j] && ret[i] == s[j])
					{
						i++;
						j++;
					}
					if (j - sj > l)
					{
						tmp = retn;
						retn = fstrsub(s, sj, j);
						l = j - sj;
						free(tmp);
					}
					if (s[j])
						j++;
					i = si;
				}
				i = si + 1;
			}
			if (l < fstrlen(ret))
			{
				tmp = ret;
				ret = retn;
				free(tmp);
			}
			if (!ret)
				break ;
			idx++;
		}
		if (ret)
		{
			fputstr(ret);
			free(ret);
		}
	}
	fputstr("\n");
}
