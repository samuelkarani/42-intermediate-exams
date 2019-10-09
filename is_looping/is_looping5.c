struct s_node {
        int value;
        struct s_node *next;
};

int     is_looping(struct s_node *node)
{
	struct s_node *fast, *slow;
	fast = slow = node;
	while (slow && fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
			return 1;
	}
	return 0;
}

/*
#include <stdlib.h>
#include <stdio.h>

struct s_node *cr(int value)
{
	struct s_node *node = malloc(sizeof(struct s_node));
	node->value = value;
	node->next = NULL;
	return node;
}
int main()
{
	struct s_node *a, *b, *c;
	a = cr(1);
	a->next = b = cr(2);
	b->next = c = cr(3);
	printf("%d\n", is_looping(a));
	c->next = a;
	printf("%d\n", is_looping(a));
	a->next = a;
	printf("%d\n", is_looping(a));
	a->next = b;
	c->next = NULL;
	printf("%d\n", is_looping(a));
	c->next = c;
	printf("%d\n", is_looping(a));
}
*/
