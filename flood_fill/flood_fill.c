#include "flood_fill.h"

void flood_fill(char **tab, t_point size, t_point begin)
{
    int x, y, c;
    y = begin.y, x = begin.x;
    c = tab[y][x];
    tab[y][x] = 'F';
    if (y > 0 && tab[y - 1][x] == c)
        flood_fill(tab, size, (t_point){x, y - 1});
	if (y < size.y - 1 && tab[y + 1][x] == c)
		flood_fill(tab, size, (t_point){x, y + 1});
    if (x > 0 && tab[y][x - 1] == c)
        flood_fill(tab, size, (t_point){x - 1, y});
	if (x < size.x - 1 && tab[y][x + 1] == c)
		flood_fill(tab, size, (t_point){x + 1, y});
}
#include <stdio.h>
#include <stdlib.h>
void print_tab(char **a, t_point size)
{
    int i;
    int j;
    i = 0;
    while (i < size.y)
    {
        j = 0;
        while (j < size.x)
        {
            printf("%c ", a[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
}
char** make_area(char **a, t_point size)
{
    char **res;
    int  i, j;
    res = malloc(sizeof(char *) * size.y);
    i = 0;
    while (i < size.y)
    {
        res[i] = malloc(sizeof(char) * size.x);
        j = 0;
        while (j < size.x)
        {
            res[i][j] = a[i][j * 2];
            j++;
        }
        i++;
    }
    return (res);
}

#include <unistd.h>
int main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {0, 0};
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};
	area = make_area((char **)zone, size);
	print_tab(area, size);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area, size);
}
