struct s_node {
        int value;
        struct s_node *next;
};

int     is_looping(struct s_node *node)
{
	struct s_node *slow, *fast;
	slow = fast = node;
	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return 1;
	}
	return 0;
}

/*
#include <stdlib.h>
struct s_node *c(int n)
{
	struct s_node *s = malloc(sizeof(struct s_node));
	s->value = n;
	s->next = NULL;
	return s;
}

#include <stdio.h>
int main()
{
	struct s_node *a = c(1);
	printf("%d\n", is_looping(a));
	a->next = a;
	printf("%d\n", is_looping(a));
}
*/
