#include <stdlib.h>
#include <string.h>

char    *longest_subarray(char *arr)
{
	if (!arr)
		return NULL;
	char *s;
	int i, n = 0;
	for (i = 0; arr[i]; i++)
	{
		int e = 0, o = 0;
		for (int j = i; arr[j]; j++)
		{
			int v = arr[j] - '0';
			if (v % 2 == 0)
				e++;
			else
				o++;
			if (e == o && e + o > n)
			{
				s = arr + i;
				n = e + o;
			}
		}
	}
	char *res = malloc(n + 1);
	for (i = 0; i < n; i++)
		res[i] = s[i];
	res[i] = 0;
	return res;
}

/*
#include <stdio.h>
int main()
{
	printf("%s\n", longest_subarray("134"));
	printf("%s\n", longest_subarray("454"));
	printf("%s\n", longest_subarray("1357913579024680213579"));
	printf("%s\n", longest_subarray("2010102"));

	printf("%s\n", longest_subarray("1"));
	printf("%s\n", longest_subarray(""));
	printf("%s\n", longest_subarray(NULL));
}
*/
