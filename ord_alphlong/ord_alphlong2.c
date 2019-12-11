#include <unistd.h>
#include <stdlib.h>

int is_upper(char c)
{
	return c >= 'A' && c <= 'Z';
}

int flower(char c)
{
	if (is_upper(c))
		return c + 32;
	return c;
}

int fstrlen(char *s)
{
	int i = 0;
	for (; s[i]; i++)
		;
	return i;
}

void fputstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int fis(char c)
{
	return c == ' ' || c == '\t';
}

char *fstrsub(char *s, int start, int end)
{
	char *res = malloc(end - start);
	int i = 0;
	while (start < end)
		res[i++] = s[start++];
	res[i] = 0;
	return res;
}

int cmp_alpha(char *a, char *b)
{
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}
	return flower(*a) <= flower(*b);
}

int cmp_len(char *a, char *b)
{
	return fstrlen(a) <= fstrlen(b);
}

void fsort(char *arr[], int n, int(*cmp)(char*, char*))
{
	char *tmp;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
		{
			if ((*cmp)(arr[j], arr[j + 1]) == 0)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *s = av[1];
		int start = 0, idx = 0;
		char *words[fstrlen(s) / 2 + 1];
		for (int i = 0; s[i]; i++)
		{
			if (!fis(s[i]) && i > 0 && fis(s[i - 1]))
				start = i;
			if (fis(s[i]) && i > 0 && !fis(s[i - 1]))
				words[idx++] = fstrsub(s, start, i);
			if (!s[i + 1] && !fis(s[i]))
				words[idx++] = fstrsub(s, start, i + 1);
		}
		fsort(words, idx, &cmp_alpha);
		fsort(words, idx, &cmp_len);
		for (int i = 0; i < idx - 1; i++)
		{
			fputstr(words[i]);
			if (fstrlen(words[i]) < fstrlen(words[i + 1]))
				fputstr("\n");
			else
				fputstr(" ");
		}
		fputstr(words[idx - 1]);
	}
	fputstr("\n");
}
