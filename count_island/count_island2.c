#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void fputchar(char c)
{
	write(1, &c, 1);
}

void fputstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int fstrlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

char *fstrdup(char *s)
{
	int l;
	char *res = malloc((l = fstrlen(s)));
	int i = -1;
	while (++i < l)
		res[i] = s[i];
	res[i] = 0;
	return res;
}

typedef struct s_node
{
	char *row;
	struct s_node *next;
} t_node;

t_node *create(char *s)
{
	t_node *res = malloc(sizeof(t_node));
	res->row = fstrdup(s);
	res->next = NULL;
	return res;
}

int fstrchr(char *s, char c)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return i;
		i++;
	}
	return -1;
}

int check(char *s)
{
	while (*s)
	{
		if (*s != 'X' && *s != '.')
			return 0;
		s++;
	}
	return 1;
}

void convert(t_node *node, char **map)
{
	int i = 0;
	while (node)
	{
		map[i++] = node->row;
		node = node->next;
	}
}

void number(char **map, int h, int w, int no, int i, int j)
{
	map[i][j] = no + '0';
	if (i > 0 && map[i - 1][j] == 'X')
		number(map, h, w, no, i - 1, j);
	if (i + 1 < h && map[i + 1][j] == 'X')
		number(map, h, w, no, i + 1, j);
	if (j > 0 && map[i][j - 1] == 'X')
		number(map, h, w, no, i, j - 1);
	if (j + 1 < w && map[i][j + 1] == 'X')
		number(map, h, w, no, i, j + 1);
}

void run(char **map, int h, int w)
{
	int no = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (map[i][j] == 'X')
				number(map, h, w, no++, i, j);
}

void print(char **map, int h, int w)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			fputchar(map[i][j]);
		fputchar('\n');
	}
}

int main(int ac, char **av)
{
	int ok = 0;
	if (ac == 2)
	{
		int fd;
		if ((fd = open(av[1], O_RDONLY)) != -1)
		{
			t_node *node, *head;
			char buf[1024];
			int n, w, h, err;
			n = read(fd, buf, 1024);
			buf[n] = 0;
			w = fstrchr(buf, '\n');
			err = w == -1;
			close(fd);
			fd = open(av[1], O_RDONLY);
			h = 0; node = NULL;
			while (!err && (n = read(fd, buf, w)))
			{
				buf[n] = 0;
				//fputstr(buf);
				//fputstr("\n");
				if (n != w || !check(buf))
				{
					err = 1;
					break;
				}
				if (!node)
					head = node = create(buf);
				else
				{
					node->next = create(buf);
					node = node->next;
				}
				n = read(fd, buf, 1);
				if (n != 1 || buf[0] != '\n')
				{
					err = 1;
					break ;
				}
				h++;
			}
			if (!err)
			{
				char *map[h];
				convert(head, map);
				run(map, h, w);
				print(map, h, w);
				ok = 1;
			}
			close(fd);
		}
	}
	if (!ok)
		fputstr("\n");
}
