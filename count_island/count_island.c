#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_node
{
	char		*line;
	struct		s_node *next;
}				t_node;

t_node *create(char *line)
{
	t_node *ret = malloc(sizeof(t_node));
	ret->line = line;
	ret->next = NULL;
	return ret;
}

void add(struct s_node **lst, char *line)
{
	if (*lst)
	{
		t_node *s = *lst;
		while (s->next)
			s = s->next;
		s->next = create(line);
	}
	else
		*lst = create(line);
}

void fputstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int invalid_characters(char *s)
{
	while (*s)
	{
		if (*s != 'X' || *s != '.')
			return 1;
		s++;
	}
	return 0;
}

void convert(t_node *lst, char *map[])
{
	t_node *next;
	int idx = 0;
	while (lst)
	{
		next = lst->next;
		map[idx++] = lst->line;
		free(lst);
		lst = next;
	}
	map[idx] = NULL;
}

void count(int h, int w, char *map[h], int i, int j, int idx)
{
	map[i][j] = idx + '0';
	if (i + 1 < h && map[i + 1][j] == 'X')
		count(h, w, map, i + 1, j, idx);
	if (j + 1 < w && map[i][j + 1] == 'X')
		count(h, w, map, i, j + 1, idx);
	if (i > 0 && map[i - 1][j] == 'X')
		count(h, w, map, i - 1, j, idx);
	if (j > 0 && map[i][j - 1] == 'X')
		count(h, w, map, i, j - 1, idx);
}

void count_island(int h, int w, char *map[h])
{
	int i, j, idx;
	i = idx = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (map[i][j] == 'X')
			{
				count(h, w, map, i, j, idx);
				while (j < w && map[i][j] == 'X')
					j++;
				if (j == w)
					break ;
			}
			else
				j++;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int fd = open(av[1], O_RDWR);
		if (fd != -1)
		{
			int size, n, h, w, err, last;
			size = 1025;
			char buf[size];
			t_node *lst = NULL;
			h = err = last = 0;
			w = -1;
			while (!err && (n = read(fd, buf, size)))
			{
				if (last)
				{
					err = 1;
					break ;
				}
				buf[n] = 0;
				add(&lst, buf);
				if (w == -1)
					w = n;
				else if (n != w)
				{
					if (n == w - 1)
						last = 1;
					else
						err = 1;
				}
				if (invalid_characters(buf))
					err = 1;
				h++;
			}
			if (!err)
			{
				char *map[h + 1];
				convert(lst, map);
				count_island(h, w, map);
			}
		}
	}
	fputstr("\n");
}