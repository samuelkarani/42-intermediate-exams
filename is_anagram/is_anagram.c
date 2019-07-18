int     is_anagram(char *a, char *b)
{
	int alpha[128] = {0};
	while (*a)
		alpha[(unsigned int)*a++]++;
	while (*b)
		alpha[(unsigned int)*b++]--;
	int i = -1;
	while (++i < 128)
		if (alpha[i])
			return 0;
	return 1;
}


#include <stdio.h>
int main(void)
{
	printf("%d\n", is_anagram("abcdef", "fabcde"));
	printf("%d\n", is_anagram(".123?.", "?321.."));
	printf("%d\n", is_anagram("cinema", "iceman"));
	printf("%d\n", is_anagram("abca", "bcab"));
}
