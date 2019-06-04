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
		if (!(*s == 'X' || *s == '.' || *s == '\n'))
			return 1;
		s++;
	}
	return 0;
}

int fstrjoin(char **a, int l, char b)
{
	char *tmp = *a;
	char *ret = malloc((l + 2) * sizeof(char));
	int i = 0;
	while (i < l)
	{
		ret[i] = tmp[i];
		i++;
	}
	ret[i++] = b;
	ret[i] = 0;
	free(tmp);
	*a = ret;
	return l + 1;
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
				count(h, w, map, i, j, idx++);
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

void print_map(char **map, int h, int w)
{
	int i = 0;
	while (i < h)
		write(1, map[i++], w);
}

#include <stdio.h>
int main(int ac, char **av)
{
	if (ac == 2)
	{
		int fd;
		if ((fd = open(av[1], O_RDWR)) != -1)
		{
			int n, h, w, err, len;
			char buf[1], *line;
			t_node *lst = NULL;
			h = err = len = 0;
			w = -1;
			line = NULL;
			while (!err && (n = read(fd, buf, 1)) > 0)
			{
				len = fstrjoin(&line, len, *buf);
				if (invalid_characters(line))
					err = 1;
				if (*buf == '\n')
				{
					if (w == -1 && h == 0)
						w = len;
					else if (len != w)
						err = 1;
					if (!err)
					{
						write(0, line, len);
						add(&lst, line);
						len = 0;
						line = NULL;
						h++;
					}
				}
			}
			if (!err && n != -1)
			{
				int endline, no_endline;
				endline = *buf == '\n' && len == w;
				no_endline = *buf != '\n' && len == w - 1;
				if (endline || no_endline)
				{
					if (no_endline)
					{
						add(&lst, line);
						write(0, line, len);
						write(1, "\n\n", 2);
						h++;
					}
					char *map[h];
					convert(lst, map);
					count_island(h, w, map);
					print_map(map, h, w);
				}
			}
			close(fd);
		}
	}
	fputstr("\n");
}