#include <stdio.h>

void    equation(int n)
{
	int a, b, c;
	a = 0;
	while (a <= 9)
	{
		b = 0;
		while (b <= 9)
		{
			c = 0;
			while (c <= 9)
			{
				if ((a*10+b + c*10+a) == n)
					printf("A = %d, B = %d, C = %d\n", a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}

int main(void)
{
	equation(42);
	equation(111);
	equation(0);
}
