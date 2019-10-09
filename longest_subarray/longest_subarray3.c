#include <string.h>
#include <stdlib.h>

struct s_elem
{
	int o;
	int e;
};

void calc(struct s_elem *s, char c)
{
	if ((c - '0') % 2 == 0)
		s->e += 1;
	else
		s->o += 1;
}

char *longest_subarray(char *arr)
{
	struct s_elem s;
	int start, end, l, n;
	start = end = n = 0;
	l = strlen(arr);
	for (int i = 0; i < l - 1; i++)
	{
		s = (struct s_elem){0, 0};
		calc(&s, arr[i]);
		for (int j = i + 1; j < l; j++)
		{
			calc(&s, arr[j]);
			if (s.o == s.e && s.o > n)
			{
				n = s.o;
				start = i;
				end = j;
			}
		}
	}
	char *ret = malloc(end - start + 2);
	if (start == end)
	{
		*ret = 0;
		return ret;
	}
	int i = 0;
	while (start <= end)
		ret[i++] = arr[start++];
	ret[i] = 0;
	return ret;
}

/*
#include <stdio.h>
int main()
{
	printf("%s\n", longest_subarray(""));
	printf("%s\n", longest_subarray("1"));
	printf("%s\n", longest_subarray("13"));
	printf("%s\n", longest_subarray("12"));
	printf("%s\n", longest_subarray("134"));
	printf("%s\n", longest_subarray("454"));
	printf("%s\n", longest_subarray("1357913579024680213579"));
	printf("%s\n", longest_subarray("2010102"));
}
*/
