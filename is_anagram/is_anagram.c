int     is_anagram(char *a, char *b)
{
	long asum, bsum;
	int alen, blen, i;

	asum = 0;
	i = 0;
	while (a[i])
	{
		asum += a[i];
		i++;
	}
	alen = i;
	bsum = 0;
	i = 0;
	while (b[i])
	{
		bsum += b[i];
		i++;
	}
	blen = i;
	if (alen == blen && asum == bsum)
		return 1;
	else
		return 0;
}


#include <stdio.h>
int main(void)
{
	printf("%d\n", is_anagram("abcdef", "fabcde"));
	printf("%d\n", is_anagram(".123?.", "?321.."));
	printf("%d\n", is_anagram("cinema", "iceman"));
	printf("%d\n", is_anagram("abca", "bcab"));
}
