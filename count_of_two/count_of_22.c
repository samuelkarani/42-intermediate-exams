int    count_of_2(int n)
{
	if (n <= 1)
		return 0;
	int i, c, j;
	i = 2; c = 0;
	while (i <= n)
	{
			j = i;
			while (j)
			{
				if (j % 10 == 2)
					c++;
				j /= 10;
			}
			i++;
	}
	return c;
}

/*
#include <stdio.h>
int main()
{
	printf("%d\n", count_of_2(25));
	printf("%d\n", count_of_2(1));
	printf("%d\n", count_of_2(2));
}
*/
