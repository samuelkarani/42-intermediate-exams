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
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return 1;
	}
	return 0;
}

/*
#include <stdlib.h>
struct s_node *c(int v)
{
	struct s_node *res = malloc(sizeof(struct s_node));
	res->value = v;
	res->next = NULL;
	return res;
}

#include <stdio.h>
int main()
{
	struct s_node *one = c(1);
	printf("%d\n", is_looping(one));
	one->next = one;
	printf("%d\n", is_looping(one));
	one->next = c(2);
	one->next->next = one;
	printf("%d\n", is_looping(one));
}
*/
