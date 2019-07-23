#include <stdlib.h>

typedef struct s_index
{
	int e;
	int o;
} t_index;

int even(int c)
{
	c -= '0';
	return c % 2 == 0;
}

char *fstrsub(char *s, int start, int len)
{
	char *res = malloc(len + 1);
	s += start;
	char *p = res;
	while (len-- > 0)
		*res++ = *s++;
	*res = 0;
	return p;
}

char    *longest_subarray(char *arr)
{
	int i = 0, j, o, e;
	t_index ret = (t_index){0, 0};
	i = 0;
	while (arr[i])
	{
		j = i;
		o = e = 0;
		while (arr[j])
		{
			if (even(arr[j]))
				e++;
			else
				o++;
			if (e == o && (j - i + 1) > ret.o)
				ret = (t_index){i, j - i + 1};
			j++;
		}
		i++;
	}
	return fstrsub(arr, ret.e, ret.o);
}

/*
#include <stdio.h>
int main()
{
	printf("%s\n", longest_subarray("134"));
	printf("%s\n", longest_subarray("454"));
	printf("%s\n", longest_subarray("1357913579024680213579"));
	printf("%s\n", longest_subarray("2010102"));
}
*/
