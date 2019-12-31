#include <stdio.h>

void    print_doublon(int *a, int na, int *b, int nb)
{
	int i, j, n;
	i = j = n = 0;
	while (i < na && j < nb)
	{
		if (a[i] < b[j])
			i++;
		else if (b[j] < a[i])
			j++;
		else {
			if (n)
				printf(" ");
			printf("%d", a[i]);
			n++;
			i++;
			j++;
		}
	}
	printf("\n");
}

/*
int main()
{
int a[] = {1,  2, 10, 15};
int b[] = {2, 20, 40, 70};
print_doublon(a, 4, b, 4);
int c[] = {-5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
int d[] = {2,  4,  5,  6,  7, 10,  40,  70};
print_doublon(c, 11, d, 8);
int e[] = {100,  200, 300};
int f[] = {1,    2,   3, 4};
print_doublon(e, 3, f, 4);
}
*/
