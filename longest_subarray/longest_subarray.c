#include <stdlib.h>
#include <string.h>

int even(int c)
{
	return c % 2 == 0;
}

int check(char *arr, int start, int end)
{
	int o, e;
	o = e = 0;
	while (start <= end)
	{
		if (even(arr[start++]))
			e++;
		else
			o++;
	}
	return o == e;
}

char *fstrsub(char *arr, int start, int end)
{
	char *ret = malloc((2 + end - start) * sizeof(char));
	int i = 0;
	while (start <= end)
		ret[i++] = arr[start++];
	ret[i] = 0;
	return ret;
}

char *longest_subarray(char *arr)
{
	if (arr)
	{
		char *ret = NULL;
		int i, j, l;
		i = l = 0;
		while (arr[i + 1])
		{
			j = i + 1;
			while (arr[j])
			{
				if (j - i + 1 > l && check(arr, i, j))
				{
					char *tmp = ret;
					ret = fstrsub(arr, i, j);
					l = j - i + 1;
					free(tmp);
				}
				j++;
			}
			i++;
		}
		return ret;
	}
	else
		return NULL;
}

int fstrlen(char *s)
{
	int n = 0;
	while (*s++)
		n++;
	return n;
}

char *fstrsub2(char *arr, int start, int end)
{
	char *ret = malloc((1 + end - start) * sizeof(char));
	int i = 0;
	while (start < end)
		ret[i++] = arr[start++];
	ret[i] = 0;
	return ret;
}

typedef struct s_score
{
	int even;
	int odd;
}	t_score;

char *longest_subarray2(char *arr)
{
	char *res;
	t_score sum, idx;
	int i, j, k, l, s, n, lg;
	l = fstrlen(arr);
	i = lg = 0;
	while (i < l)
	{
		j = i;
		sum = (t_score){0, 0};
		while (j < l)
		{
			if (even(arr[j]))
				sum.even++;
			else
				sum.odd++;
			if (sum.even == sum.odd && (k = (j - i + 1)) > lg)
			{
				lg = k;
				idx = (t_score){i, j + 1};
				i = j;
			}
			j++;
		}
		i++;
	}
	return fstrsub2(arr, idx.even, idx.odd);
}

#include <stdio.h>
int main(void)
{
	char *ret;
	printf("%s\n", ret = longest_subarray("134"));
	printf("%s\n", ret = longest_subarray2("134"));
	free(ret);
	printf("%s\n", ret = longest_subarray("454"));
	printf("%s\n", ret = longest_subarray2("454"));
	free(ret);
	printf("%s\n", ret = longest_subarray("1357913579024680213579"));
	printf("%s\n", ret = longest_subarray2("1357913579024680213579"));
	free(ret);
	printf("%s\n", ret = longest_subarray("2010102"));
	printf("%s\n", ret = longest_subarray2("2010102"));
	free(ret);
}