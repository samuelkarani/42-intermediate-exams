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
		if (slow == fast)
			return 1;
	}
	return 0;
}

/*
#include <stdio.h>
int main()
{
	typedef struct s_node t_node;
	t_node c = (t_node){3, NULL};
	t_node b = (t_node){2, &c};
	t_node a = (t_node){1, &b};
	t_node *p = &c;
	p->next = &a;
	printf("%d\n", is_looping(&a));
}
*/
