    typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

  void  flood_fill(char **tab, t_point size, t_point begin)
{
	int x = begin.x, y = begin.y;
	char c = tab[y][x];
	tab[y][x] = 'F';
	if (x > 0 && tab[y][x - 1] == c)
		flood_fill(tab, size, (t_point){x - 1, y});
	if (x + 1 < size.x && tab[y][x + 1] == c)
		flood_fill(tab, size, (t_point){x + 1, y});	
	if (y > 0 && tab[y - 1][x] == c)
		flood_fill(tab, size, (t_point){x, y - 1});
	if (y + 1 < size.y && tab[y + 1][x] == c)
		flood_fill(tab, size, (t_point){x, y + 1});	
}
/*
#include <stdlib.h>
#include <stdio.h>
char** make_area(char** zone, t_point size)
{
        char** new;

        new = malloc(sizeof(char*) * size.y);
        for (int i = 0; i < size.y; ++i)
        {
                new[i] = malloc(size.x + 1);
                for (int j = 0; j < size.x; ++j)
                        new[i][j] = zone[i][j];
                new[i][size.x] = '\0';
        }

        return new;
}

int main(void)
{
        t_point size = {8, 5};
        char *zone[] = {
                "11111111",
                "10001001",
                "10010001",
                "10110001",
                "11100001",
        };

        char**  area = make_area(zone, size);
        for (int i = 0; i < size.y; ++i)
                printf("%s\n", area[i]);
        printf("\n");

        t_point begin = {1, 1};
        flood_fill(area, size, begin);
        for (int i = 0; i < size.y; ++i)
                printf("%s\n", area[i]);
        return (0);
}
*/
