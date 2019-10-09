#include <stdio.h>

void    print_doublon(int *a, int na, int *b, int nb)
{
	int i, j, n;
	i = j = n = 0;
	while (i < na && j < nb)
	{
		if (a[i] > b[j])
			j++;
		else if (b[j] > a[i])
			i++;
		else
		{
			if (n)
				printf(" ");
			n++;
			printf("%d", a[i]);
			i++;
			j++;
		}
	}
	printf("\n");
}

/*
int main(void)
{
	print_doublon((int[]){1, 2, 10, 15}, 4, (int[]){2, 20, 40, 70}, 4);
	print_doublon((int[]){1, 1, 2, 2, 10, 15}, 6, (int[]){2, 20, 40, 70}, 4);
	print_doublon((int[]){-5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000}, 11, (int[]){ 2,  4,  5,  6,  7, 10,  40,  70}, 8);
	print_doublon((int[]){100,  200, 300}, 3, (int[]){ 1,    2,   3, 4}, 4);
}
*/
