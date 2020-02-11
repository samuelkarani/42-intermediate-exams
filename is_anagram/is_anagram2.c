int is_anagram(char *a, char *b)
{
	unsigned int arr[255] = {0};
	for (unsigned int i = 0; a[i]; i++)
		arr[(unsigned int)a[i]] += 1;
	for (unsigned int i = 0; b[i]; i++)
		arr[(unsigned int)b[i]] -= 1;
	for (unsigned int i = 0; i < 255; i++)
		if (arr[i] != 0)
			return 0;
	return 1;
}

#include <stdio.h>
int main()
{
	printf("%d\n", is_anagram("abcdef", "fabcde"));
	printf("%d\n", is_anagram(".123?.", "?321.."));
	printf("%d\n", is_anagram("abca", "bcab"));
}