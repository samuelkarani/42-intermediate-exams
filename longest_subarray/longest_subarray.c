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

#include <stdio.h>
int main(void)
{
	char *ret;
	printf("%s\n", ret = longest_subarray("134"));
	free(ret);
	printf("%s\n", ret = longest_subarray("454"));
	free(ret);
	printf("%s\n", ret = longest_subarray("1357913579024680213579"));
	free(ret);
	printf("%s\n", ret = longest_subarray("2010102"));
	free(ret);
}