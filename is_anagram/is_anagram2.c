int is_anagram(char *a, char *b)
{
	unsigned char arr[255] = {0};

	for (int i = 0; a[i]; i++)
		arr[(unsigned char)a[i]] += 1;
	for (int i = 0; b[i]; i++)
		arr[(unsigned char)b[i]] -= 1;
	for (unsigned char i = 0; i < 255; i++)
		if (arr[i] != 0)
			return 0;
	return 1;
}

#include <stdio.h>
int main()
{
	printf("%d\n", is_anagram("a", "f"));
	printf("%d\n", is_anagram("a", "a"));
	printf("%d\n", is_anagram("abcdef", "fabcde"));
	printf("%d\n", is_anagram(".123?.", "?321.."));
	printf("%d\n", is_anagram("abca", "bcab"));
}
