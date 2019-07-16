struct s_node {
        int value;
        struct s_node *next;
};

int     is_looping(struct s_node *node)
{
	struct s_node *fast, *slow;
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
#include <stdio.h>
int main(void)
{
	struct s_node c = {3, 0};
	struct s_node b = {2, &c};
	struct s_node a = {1, &b};
	printf("%d\n", is_looping(&a));
	c.next = &c;
	printf("%d\n", is_looping(&a));
}
*/
