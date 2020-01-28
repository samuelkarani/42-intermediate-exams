int    count_of_2(int n)
{
	if (n <= 1)
		return 0;
	int c = 0;
	for (int i = 0; i <= n; i++)
		for (int k = i; k; k /= 10)
			if (k % 10 == 2)
				c++;
	return c;
}

/*
#include <stdio.h>
int main()
{
	printf("%d\n", count_of_2(25));
	printf("%d\n", count_of_2(2));
	printf("%d\n", count_of_2(9));
}*/
