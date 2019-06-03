#include <unistd.h>
#include <stdlib.h>

struct node
{
	char *word;
	struct node *next;
	int len;
};

struct node	*create(char *word, int len)
{
	struct node *lst = malloc(sizeof(struct node));
	lst->word = word;
	lst->next = NULL;
	lst->len = len;
	return lst;
}

void add(struct node **lst, char *word, int len)
{
	if (*lst)
	{
		struct node *s = *lst;
		while (s->next)
			s = s->next;
		s->next = create(word, len);
	}
	else
		*lst = create(word, len);
}

void destroy(struct node *lst)
{
	struct node *next;
	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}

int fspace(char c)
{
	return (c == ' ' || c == '\t');
}

void fputstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int fisupper(char c)
{
	return c >= 'A' && c <= 'Z';
}

int fislower(char c)
{
	return c >= 'a' && c <= 'z';
}

int flower(char c)
{
	return c += 32;
}

int fisapha(char c)
{
	return (fislower(c) || fisupper(c));
}

int fstrlen(char *s)
{
	int count = 0;
	while (*s++)
		count++;
	return count;
}

int compare(char a, char b)
{
	if (fisupper(a) && fislower(b))
		return flower(a) - b;
	else if (fislower(a) && fisupper(b))
		return a - flower(b);
	else
		return a - b;
}

int fstrcmp(char *a, char *b)
{
	while (*a && *b && compare(*a, *b) == 0)
	{
		a++;
		b++;
	}
	return compare(*a, *b);
}

int	lcmp(struct node *a, struct node *b)
{
	return fstrcmp(a->word, b->word) <= 0;
}

int	hcmp(struct node *a, struct node *b)
{
	return a->len <= b->len;
}

char *fstrsub(char *s, int start, int end)
{
	char *ret = malloc((1 + end - start) * sizeof(char));
	int i = 0;
	while (start < end)
		ret[i++] = s[start++];
	ret[i] = 0;
	return ret;
}

void swap(struct node *a, struct node *b)
{
	int tmp_l = a->len;
	char *tmp_w = a->word;
	a->word = b->word;
	a->len = b->len;
	b->word = tmp_w;
	b->len = tmp_l;
}

void fsort(struct node *lst, int (*cmp)(struct node *a, struct node *b))
{
	struct node *i, *j, *tmp;
	i = lst;
	while (i->next)
	{
		j = lst;
		while (j->next)
		{
			if ((*cmp)(j, j->next) == 0)
				swap(j, j->next);
			j = j->next;
		}
		i = i->next;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *s = av[1];
		int n = 0;
		int i = 0;
		while (s[i])
		{
			if (fspace(s[i]) && i > 0 && !fspace(s[i - 1]))
				n++;
			else if (!s[i + 1] && !fspace(s[i]))
				n++;
			i++;
		}

		char *words[n];
		int start = 0;
		int idx = 0;
		i = 0;
		while (s[i])
		{
			if (!fspace(s[i]) && i > 0 && fspace(s[i - 1]))
				start = i;
			if (fspace(s[i]) && i > 0 && !fspace(s[i - 1]))
				words[idx++] = fstrsub(s, start, i);
			else if (!s[i + 1] && !fspace(s[i]))
				words[idx++] = fstrsub(s, start, i + 1);
			i++;
		}

		struct node *lst = NULL;
		i = 0;
		while (i < n)
		{
			add(&lst, words[i], fstrlen(words[i]));
			i++;
		}

		fsort(lst, &lcmp);
		fsort(lst, &hcmp);

		struct node *lstp = lst;
		while (lst)
		{
			fputstr(lst->word);
			if (lst->next)
			{
				if (lst->len != lst->next->len)
					fputstr("\n");
				else
					fputstr(" ");
			}
			lst = lst->next;
		}
		fputstr("\n");
		destroy(lstp);
	}
	else
		fputstr("\n");
}
